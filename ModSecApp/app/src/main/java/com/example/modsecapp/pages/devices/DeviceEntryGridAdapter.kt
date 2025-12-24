package com.example.modsecapp.pages.devices

import android.content.Context
import android.content.res.Resources
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ArrayAdapter
import android.widget.TextView
import com.example.modsecapp.R


class DeviceEntryGridAdapter (context: Context, list:List<DeviceEntry>): ArrayAdapter<DeviceEntry?>(context,0,list){

    override fun getView(position: Int, convertView: View?, parent: ViewGroup): View {

        var itemView = convertView
        if (itemView == null){
            itemView = LayoutInflater.from(context).inflate(R.layout.device_entry,parent,false)
        }

        val deviceEntry: DeviceEntry? = getItem(position)

        val deviceEntryNameText: TextView = itemView.findViewById(R.id.deviceEntryNameText)
        val deviceEntryStatusText: TextView = itemView.findViewById(R.id.deviceEntryStatusText)
        val deviceEntryLastCallText: TextView = itemView.findViewById(R.id.deviceEntryLastCallText)

        deviceEntryNameText.text = deviceEntry!!.name
        deviceEntryStatusText.text = deviceEntry!!.status
        deviceEntryLastCallText.text = deviceEntry!!.lastCall

        return itemView

    }

}