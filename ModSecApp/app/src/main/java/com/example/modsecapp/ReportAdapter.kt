package com.example.modsecapp

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView


class ReportAdapter( val reportList: List<ReportEntry>) :
    RecyclerView.Adapter<ReportAdapter.MyViewHolder>() {

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.report_entry, parent, false)
        return MyViewHolder(view)
    }

    override fun onBindViewHolder(holder: MyViewHolder, position: Int) {
        val ReportEntry = reportList[position]

        holder.entryDeviceName.text = ReportEntry.reportingDevice
        holder.entryDate.text = ReportEntry.date
        holder.entryTime.text = ReportEntry.time

    }

    override fun getItemCount(): Int {
        return reportList.size
    }

    // ViewHolder class
    class MyViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        val entryDeviceName: TextView = itemView.findViewById(R.id.entryDeviceName)
        val entryDate: TextView = itemView.findViewById(R.id.entryDate)
        val entryTime: TextView = itemView.findViewById(R.id.entryTime)


    }
}
