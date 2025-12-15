package com.example.modsecapp

import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.google.android.material.bottomnavigation.BottomNavigationView
import androidx.fragment.app.Fragment
import androidx.recyclerview.widget.RecyclerView


class MainActivity : AppCompatActivity() {


    private lateinit var bottomNavigationView: BottomNavigationView
    private lateinit var dashboardFragment: DashboardFragment
    private lateinit var reportFragment: ReportFragment
    private lateinit var devicesFragment: DevicesFragment

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        bottomNavigationView = findViewById(R.id.bottomNavigationView)

        dashboardFragment = DashboardFragment()
        reportFragment = ReportFragment()
        devicesFragment = DevicesFragment()

        setCurrentFragment(dashboardFragment)


        bottomNavigationView.setOnItemSelectedListener {

            when (it.itemId){
                R.id.dashboard -> setCurrentFragment(dashboardFragment)
                R.id.report -> setCurrentFragment(reportFragment)
                R.id.devices -> setCurrentFragment(devicesFragment)
            }
            true

        }


    }

    private fun setCurrentFragment(fragment: Fragment){
        supportFragmentManager.beginTransaction().apply {
            replace(R.id.flFragment,fragment)
            commit()
        }
    }
}