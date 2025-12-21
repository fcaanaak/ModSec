package com.example.modsecapp.pages.report

import android.app.DatePickerDialog
import android.app.TimePickerDialog
import android.os.Bundle
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.modsecapp.R
import java.util.Calendar
import com.example.modsecapp.pages.report.filter.ReportFilter
import com.google.android.material.chip.Chip
import com.google.android.material.chip.ChipGroup
import java.time.LocalDateTime

/**
 * A simple [androidx.fragment.app.Fragment] subclass.
 * Use the [ReportFragment.newInstance] factory method to
 * create an instance of this fragment.
 */
class ReportFragment : Fragment() {



    // UI Widgets
    private lateinit var dateFilterButton: Button
    private lateinit var timeFilterButton: Button
    private lateinit var reportFiltersChipGroup: ChipGroup
    private lateinit var reportFilterChipYear: Chip
    private lateinit var reportFilterChipMonth: Chip
    private lateinit var reportFilterChipDay: Chip
    private lateinit var reportFilterChipHour: Chip
    private lateinit var reportFilterChipMinute: Chip

    private lateinit var reportRecyclerView: RecyclerView
    private lateinit var reportEntryAdapter: ReportAdapter

    // Entry arrays

    private lateinit var originalEntries: MutableList<ReportEntry>
    private lateinit var dynamicEntries: MutableList<ReportEntry>


    // Filter Object

    private lateinit var reportFilter: ReportFilter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?

    ): View? {

        reportFilter = ReportFilter()

        // Inflate the layout for this fragment
        val view: View? = inflater.inflate(R.layout.fragment_report, container, false)
        setupReportData(view)

        dateFilterButton = view!!.findViewById(R.id.reportFilterDateButton)
        timeFilterButton = view!!.findViewById(R.id.reportFilterTimeButton)

        reportFiltersChipGroup = view!!.findViewById(R.id.reportFiltersChipGroup)

        reportFilterChipYear = view!!.findViewById(R.id.reportFilterChipYear)
        reportFilterChipMonth = view!!.findViewById(R.id.reportFilterChipMonth)
        reportFilterChipDay = view!!.findViewById(R.id.reportFilterChipDay)
        reportFilterChipHour = view!!.findViewById(R.id.reportFilterChipHour)
        reportFilterChipMinute = view!!.findViewById(R.id.reportFilterChipMinute)

        reportFiltersChipGroup.setOnCheckedStateChangeListener { group, checkedIds ->

            reportFilter.disableAllFilters()

            for (id in checkedIds){

                when (id){
                    R.id.reportFilterChipYear -> reportFilter.yearKey.active = true
                    R.id.reportFilterChipMonth -> reportFilter.monthKey.active = true
                    R.id.reportFilterChipDay -> reportFilter.dayKey.active = true
                    R.id.reportFilterChipHour -> reportFilter.hourKey.active = true
                    R.id.reportFilterChipMinute -> reportFilter.minuteKey.active = true

                }

            }

            // Testing out filtration, delete later if needed
            reportEntryAdapter.updateList(
                originalEntries.filter{
                    it.year == reportFilter.yearKey.data
                }.toMutableList()

            )

        }


           /*
            originalEntries.filterTo(dynamicEntries){
               it.year
           }
           */


        setupDateFilter(view,dateFilterButton)
        setupTimeFilter(view,timeFilterButton)


        return view
    }


    private fun setupTimeFilter(view: View?, timeFilterButton: Button){

        val leastDoubleDigitNumber = 10

        timeFilterButton.setOnClickListener {

            val c = Calendar.getInstance()

            val hour = c.get(Calendar.HOUR)
            val minute = c.get(Calendar.MINUTE)

            val timePickerDialog = this.context?.let {it ->
                TimePickerDialog(
                    it,
                    { view, hour, minute ->

                        val hourString = if (hour < leastDoubleDigitNumber) "0$hour" else hour
                        val minuteString = if (minute < leastDoubleDigitNumber) "0$minute" else minute

                        timeFilterButton.text = "Time Filter $hourString:$minuteString"

                        reportFilter.minuteKey.data = minute
                        reportFilter.hourKey.data = hour

                        reportFilterChipHour.text = getString(R.string.report_filter_chip_hour_text, hour)
                        reportFilterChipMinute.text = getString(R.string.report_filter_chip_minute_text, minute)

                    },
                    hour,
                    minute,
                    false
                ).apply { show() }
            }
        }

    }
    private fun setupDateFilter(view: View?, dateFilterButton: Button){

        dateFilterButton.setOnClickListener {
            val c = Calendar.getInstance()

            // on below line we are getting
            // our day, month and year.
            val year = c.get(Calendar.YEAR)
            val month = c.get(Calendar.MONTH)
            val day = c.get(Calendar.DAY_OF_MONTH)

            // on below line we are creating a
            // variable for date picker dialog.
            val datePickerDialog = this.context?.let { it1 ->
                DatePickerDialog(

                    it1,
                    { view, year, monthOfYear, dayOfMonth ->
                        val dat = "Date Filter ${(dayOfMonth.toString() + "-" + (monthOfYear + 1) + "-" + year)}"
                        dateFilterButton.text = dat

                        reportFilter.yearKey.data = year
                        reportFilter.monthKey.data = monthOfYear
                        reportFilter.dayKey.data = dayOfMonth

                        setDateChipsText(year,monthOfYear,dayOfMonth)
                    },
                    year,
                    month,
                    day
                )
            }
            datePickerDialog!!.show()
        }
    }

    private fun setDateChipsText(year:Int, month:Int, day: Int){

        val monthNames: Array<String> = arrayOf(
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "July", "Aug", "Sept", "Oct" , "Nov", "Dec"
        )

        reportFilterChipYear.text = getString(
            R.string.report_filter_chip_year_text,
            year
        )

        reportFilterChipMonth.text = getString(
            R.string.report_filter_chip_month_text,
            monthNames[month]
        )

        reportFilterChipDay.text = getString(
            R.string.report_filter_chip_day_text,
            day
        )
    }

    private fun setupReportData(view: View?){
        /**
         *
         * Hook up the data array that holds the reports to the UI
         */

        // Ignore the warning here, we are passing in a view created earlier
        reportRecyclerView = view!!.findViewById<RecyclerView>(R.id.recyclerView)

        originalEntries = generateTestDataList()
        dynamicEntries = originalEntries.toMutableList()

        reportRecyclerView.layoutManager = LinearLayoutManager(this@ReportFragment.context)

        reportEntryAdapter = ReportAdapter(dynamicEntries)
        reportRecyclerView.adapter = reportEntryAdapter

    }

    private fun generateTestDataList(): MutableList<ReportEntry>{
        /**
         * Method to generate sample data array for Reports (remove later)
         *
         */

        return mutableListOf<ReportEntry>(
            ReportEntry("123456789012345678901234567890", LocalDateTime.of(
                2005, 11, 23, 11, 59,12
            )),
            ReportEntry("123456789012345678901234567890", LocalDateTime.of(
                2011, 1, 11, 5, 1,9
            )),
            ReportEntry("123456789012345678901234567890", LocalDateTime.of(
                2025, 8, 2, 2, 2,2
            )),
            ReportEntry("123456789012345678901234567890", LocalDateTime.of(
                2005, 11, 23, 22, 59,12
            )),

            )
    }

}

