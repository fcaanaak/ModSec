#include "WifiProvManager.h"





// Setup methods

/**
 * @brief Set up the WiFiProvisioner config object with default values
 *
*/
void WiFiProvManager::setupProvConfig(){

  WiFiProvisioner::Config customConfig(
    "NewModsecDevice",                    // Access Point Name
    "Welcome!",                      // HTML Page Title
    "#007BFF",                       // Theme Color
    R"<svg xmlns="http://www.w3.org/2000/svg" width="200" height="100">
  <rect x="10" y="10" width="200" height="100" fill="blue" />
    </svg>",                // SVG Logo
    "Custom Project",                // Project Title
    "Setup Your Device",             // Project Sub-title
    "Follow these steps:",           // Project Info
    "Connected!",                    // Success Message
    "Reset all?",                    // Reset Confirmation Text
    "Enter Key:",                    // Input Field Label
    6,                               // Input Field Length
    true,                            // Show Input Field
    false                            // Show Reset Field
);
  
}
