package com.example.modsecapp.pages.devices

import android.app.AlertDialog
import android.bluetooth.BluetoothClass
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.GridView
import android.widget.Toast
import androidx.fragment.app.DialogFragment
import androidx.fragment.app.Fragment
import androidx.fragment.app.FragmentActivity
import com.example.modsecapp.R

/**
 * A simple [androidx.fragment.app.Fragment] subclass.
 * Use the [DevicesFragment.newInstance] factory method to
 * create an instance of this fragment.
 */
class DevicesFragment : Fragment() {
    // TODO: Rename and change types of parameters

    private lateinit var devicesAddButton: Button

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {

        val view = inflater.inflate(R.layout.fragment_device_settings, container, false)

        val gridView: GridView = view.findViewById(R.id.gridView)

        val deviceEntries:List<DeviceEntry> = getTestData()

        val adapter = DeviceEntryGridAdapter(requireContext(),deviceEntries)
        gridView.adapter = adapter

        devicesAddButton = view.findViewById(R.id.devicesAddButton)

        devicesAddButton.setOnClickListener { activateDevicePairPopup() }

        return view

    }


    private fun getTestData():List<DeviceEntry>{

        return listOf(
            DeviceEntry("Kitchen Motion Detector","Status: Online","Last Call: 12-01-2025"),
            DeviceEntry("Kitchen Motion Detector","Status: Online","Last Call: 12-01-2025"),
            DeviceEntry("Bathroom Sound Detector","Status: Online","Last Call: 12-01-2025"),
            DeviceEntry("Kitchen Motion Detector","Status: Online","Last Call: 12-01-2025"),
            DeviceEntry("Bathroom Sound Detector","Status: Online","Last Call: 12-01-2025"),
            DeviceEntry("Kitchen Motion Detector","Status: Online","Last Call: 12-01-2025"),

        )
    }

    private fun activateDevicePairPopup(){
        val dialog = DevicePairingDialog()
        dialog.show(parentFragmentManager,"DevicePairingPopup")

    }

}