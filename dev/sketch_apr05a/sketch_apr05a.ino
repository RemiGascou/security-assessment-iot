void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

void print_sensors(int sensor_light, int sensor_sound){
  Serial.print("{\"light\":");
  Serial.print(sensor_light);
  Serial.print(", ");
  Serial.print("\"sound\":");
  Serial.print(sensor_sound);
  Serial.println("}");  // print the sound value to serial
}

void loop() {
  int sensor_light = -1; // Connect mic sensor to Analog 0
  int sensor_sound = -1; // Connect mic sensor to Analog 0
  if (Serial.available() > 0){
    if (Serial.read() == '?'){
      sensor_light = analogRead(1);
      sensor_sound = analogRead(0);
      print_sensors(sensor_light, sensor_sound);
    }
  }
}
