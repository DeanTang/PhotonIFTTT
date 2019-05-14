int photosensor = A0;
char light[50];
void setup() {
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    
    Particle.variable("light_intensity", light);
    
}

void loop() {
    int analogValue = analogRead(photosensor);
    
    sprintf(light,"%d", analogValue);
    
    if (analogValue < 4000)
    {
        Particle.publish("light_intensity", "low", PRIVATE);
    }
    else
    {
        Particle.publish("light_intensity", "high", PRIVATE);
    }
    delay(5000);
    
}
