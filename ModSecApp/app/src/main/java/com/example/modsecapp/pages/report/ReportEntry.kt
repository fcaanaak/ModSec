package com.example.modsecapp.pages.report

import java.time.LocalDateTime


data class ReportEntry(var reportingDevice:String, var dateTimeObject: LocalDateTime){


    val year = dateTimeObject.year
    val month = dateTimeObject.month
    val day = dateTimeObject.dayOfMonth
    val hour = dateTimeObject.hour
    val minute = dateTimeObject.minute

    val displayDate = "Date: ${dateTimeObject.toLocalDate()}"
    val displayTime = "Time: ${dateTimeObject.toLocalTime()}"

}