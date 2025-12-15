package com.example.modsecapp

data class ReportEntry(var reportingDevice:String, var date:String,var time:String){

    init{
        date = "Date: $date"
        time = "Time: $time"
    }
}
