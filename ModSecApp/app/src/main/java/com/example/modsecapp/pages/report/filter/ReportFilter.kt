package com.example.modsecapp.pages.report.filter

import com.example.modsecapp.Constants

object ReportFilter {

    var minuteKey = FilterKey(Constants.DEFAULT_FILTER_TIME_VALUE)

        set(value) {
            field = getIfInLimits(
                value,
                Constants.FILTER_MINUTE_MAX,
                Constants.FILTER_TIME_MIN
            )
        }


    var hourKey = FilterKey(Constants.DEFAULT_FILTER_TIME_VALUE)

        set(value) {
            field = getIfInLimits(
                value,
                Constants.FILTER_HOUR_MAX,
                Constants.FILTER_TIME_MIN
            )
        }


    var dayKey = FilterKey(Constants.DEFAULT_FILTER_DATE_VALUE)

        set(value) {
            field = getIfInLimits(
                value,
                Constants.FILTER_DAY_MAX,
                Constants.FILTER_DAY_MIN
            )
        }

    var monthKey = FilterKey(Constants.DEFAULT_FILTER_DATE_VALUE)

        set(value) {
            field = getIfInLimits(
                value,
                Constants.FILTER_MONTH_MAX,
                Constants.FILTER_MONTH_MIN
            )
        }

    var yearKey = FilterKey(Constants.DEFAULT_FILTER_DATE_VALUE)

        set(value) {
            field = getIfInLimits(
                value,
                Constants.FILTER_YEAR_MAX,
                Constants.FILTER_YEAR_MIN
            )
        }


    private fun getIfInLimits(value: FilterKey<Int>, limitUpper:Int, limitLower:Int): FilterKey<Int>{

        if (value.data !in limitLower..limitUpper){
            throw Exception("Exception with setting value to $value with limits [$limitLower,$limitUpper]")
        }
        return value
    }

    fun disableAllFilters(){
        yearKey.active = false
        monthKey.active = false
        dayKey.active = false
        hourKey.active = false
        minuteKey.active = false
    }


}