package com.example.modsecapp.pages.devices

import android.app.AlertDialog
import android.app.Dialog
import android.content.Context
import android.content.DialogInterface
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.fragment.app.DialogFragment
import com.example.modsecapp.R
import androidx.activity.viewModels

class DevicePairingDialog : DialogFragment() {


    override fun onCreateDialog(savedInstanceState: Bundle?): Dialog {


        return activity?.let {
            // Build the dialog and set up the button click handlers.
            val builder = AlertDialog.Builder(it)

            builder.setMessage("ddddddd")
                .setPositiveButton("Positive"){dialog, which ->
                    Toast.makeText(it,"hi",Toast.LENGTH_SHORT)
                }

            builder.create()
        } ?: throw IllegalStateException("Activity cannot be null")
    }






}