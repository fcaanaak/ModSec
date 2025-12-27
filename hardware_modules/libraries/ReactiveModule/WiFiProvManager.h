#ifndef WIFI_PROV_MANAGER_H
#define WIFI_PROV_MANAGER_H

#include <WiFiProvisioner.h>
#include <Preferences.h>

class WiFiProvManager{

 private:

  // Fields
  WiFiProvisioner provisioner;
  Preferences prefObject;
  
  // Methods

  void setupProvConfig();

  // - Setup callbacks
  void setupCallbacks();
  void setupProvCallback();
  void setupSuccessCallback();

 public:

  void setup();
  void activateProvisioning();
  
}



#endif
