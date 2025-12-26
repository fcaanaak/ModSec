#ifndef WIFI_PROV_MANAGER_H
#define WIFI_PROV_MANAGER_H

#include <WiFiProvisioner.h>

class WiFiProvManager{

 private:

  // Fields
  WiFiProvisioner provisioner;

  // Methods

  void setupProvConfig();

  // - Setup callbacks
  void setupCallbacks();
  void setupProvCallback();
  void setupSuccessCallback();

 public:

  void setup();
  

}



#endif
