#include "ReactiveModule.h"
#define WIFI_DATABASE "wifiDatabase"
#define READ true
#define READ_WRITE false
#define DEFAULT_CONNECTION_CHECK_TIME 5000
#define MILLIS_TO_SECONDS 1000
// LED Functions


void ReactiveModule::resetToSTA(){
  /**
     @brief Set the esp32 to STA mode in case it wasn't already
   */
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void ReactiveModule::connectToWiFi(const char* ssid,const char* password){
  /**
     @brief Connect to a WiFi network
     @param ssid: The ssid or name of the WiFi network
     @param password: The password of the WiFi network 
   */
  Serial.print("Connecting to Wifi network with credentials: ");
  Serial.print(ssid);
  Serial.print(" ");
  Serial.println(password);

  
  // Add logic if we fail to connect
  WiFi.begin(ssid,password);
  
  // Connecting to WiFi takes time, this will wait
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
}

String ReactiveModule::scanStoredNetworks(){
  /**
     @brief Scans for available Wi-Fi networks and returns the first network
     that is found in the wifi preferences namespace

     @return SSID of the first network that
     is both detected and already stored in the
     wifi namespace or nullptr if no such network can be found
  
  */

  modulePrefs.begin(WIFI_DATABASE,READ);

  int availableNetworks = WiFi.scanNetworks();

  if (availableNetworks > 0) {

    for (int currentNetwork = 0;(currentNetwork < availableNetworks);currentNetwork++){
      
      String ssid = WiFi.SSID(currentNetwork);
      //Serial.println(ssid);// Remove this later
      
      if (modulePrefs.getString(ssid.c_str(),"fail") != "fail"){	

	Serial.print("Found SSID: ");
	Serial.println(ssid);

	WiFi.scanDelete();
	modulePrefs.end();
        return ssid;
      }
     
    }
  }
  
  modulePrefs.end();
  return String();

}

bool ReactiveModule::autoReconnect(){
  /**
     @brief Automatically reconnect to a previously saved WiFi network
     if said network is found during scanning

     @return true if a WiFi network was able to be connected
     to and false otherwise
   */
  String storedSSID = scanStoredNetworks();
  Serial.print("Fuck: ");
  Serial.println(storedSSID);
  if (storedSSID != ""){
    Serial.println(storedSSID);
    modulePrefs.begin(WIFI_DATABASE,READ);
    String password = modulePrefs.getString(storedSSID.c_str());
    const char* password_cstring = password.c_str();
    Serial.print("Password: ");
    Serial.println(password);
    Serial.print("C string password: ");
    Serial.println(password_cstring);

    modulePrefs.end();
    connectToWiFi(storedSSID.c_str(),password_cstring);
    return true;
  }
  
  return false;

}


 void ReactiveModule::onWiFiReconnect(WiFiEvent_t event, WiFiEventInfo_t info){
  //Serial.println("Connected to the wifi lol");

   for (int i =0; i< 3; i++){
     //RGBColor green = {0,255,0};
	//setLEDColor(green);

	delay(100);
	//	disableLED();
	delay(100);
   }

}


void ReactiveModule::registerWiFiConnected(){
  /**
     @brief Register an event handler for whenever
     a WiFi network is successfully connected to

   */
  WiFi.onEvent(
	       onWiFiReconnect,
	       WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_CONNECTED
  );
  
}

void ReactiveModule::registerWiFiEvents(){
  /**
     @brief Register all WiFi even handlers

   */

  registerWiFiConnected();
  

}

void ReactiveModule::testMethod(){
  
  modulePrefs.begin(WIFI_DATABASE,READ_WRITE);

  const char* ssid = "Papparoti";
  String pass = String("coffeebun");

  modulePrefs.clear();
  modulePrefs.putString(ssid,pass);
  Serial.println(modulePrefs.getString(ssid));
  modulePrefs.end();
  
}


void ReactiveModule::setupWiFi(){
  registerWiFiEvents();

  
  if (!autoReconnect()){

    //LEDIndicateNoNetworks();
    currentState = NETWORK_RECOVERY;

  }


  while (currentState == NETWORK_RECOVERY){
    
    delay(autoReconnectSeconds*MILLIS_TO_SECONDS);

    if (autoReconnect()){
     
      currentState = DETECTING;
      
    }
  
  }
  

}
void ReactiveModule::setup(){

  //setupLED();
  resetToSTA();
  setupWiFi();
  
}

ReactiveModule::ReactiveModule(){
  //Serial.begin(9600);
  
  // scanStoredNetworks();
  //  testMethod();
  setup();
  
}
