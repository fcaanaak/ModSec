package com.example.modsecapp

import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

/**
 * A simple [Fragment] subclass.
 * Use the [ReportFragment.newInstance] factory method to
 * create an instance of this fragment.
 */
class ReportFragment : Fragment() {
    // TODO: Rename and change types of parameters


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)



    }
    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?

    ): View? {

        // Inflate the layout for this fragment
        val view: View? = inflater.inflate(R.layout.fragment_report, container, false)
        setupReportData(view)

        return view
    }

    private fun setupReportData(view:View?){
        /**
         *
         * Hook up the data array that holds the reports to the UI
         */

        // Ignore the warning here, we are passing in a view created earlier
        val recyclerView = view!!.findViewById<RecyclerView>(R.id.recyclerView)

        val examData = generateTestDataList()

        recyclerView.layoutManager = LinearLayoutManager(this@ReportFragment.context)

        val adapter = ReportAdapter(examData)
        recyclerView.adapter = adapter
    }

    private fun generateTestDataList(): List<ReportEntry>{
        /**
         * Method to generate sample data array for Reports (remove later)
         *
         */

        return mutableListOf<ReportEntry>(
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
            ReportEntry("Kitchen motion detector","January 16, 2004","14:03:22"),
        )
    }

}