#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // [21, 20, 16, 12, 26, 19, 13, 6]
    
    if(wiringPiSetup() == -1){
        printf("Error on wiringPi setup\n");
    }
    
    // RELAY BOARD 16
    // [29,28,27,26,25,24,23,22,21,30,14,13,12,7,2,0]
    
    // RELAY BOARD 8
    // [31,11,10]
    

     pinMode(29,OUTPUT);
     pinMode(28,OUTPUT);
     pinMode(27,OUTPUT);
     pinMode(26,OUTPUT);
     pinMode(25,OUTPUT);
     pinMode(24,OUTPUT);
     pinMode(23,OUTPUT);
     pinMode(22,OUTPUT);
     pinMode(21,OUTPUT);
     pinMode(30,OUTPUT);
     pinMode(14,OUTPUT);
     pinMode(13,OUTPUT);
     pinMode(12,OUTPUT);
     pinMode(7,OUTPUT);
     pinMode(6,OUTPUT);
     pinMode(0,OUTPUT);
     
     pinMode(31,OUTPUT);
     pinMode(11,OUTPUT);
     pinMode(10,OUTPUT);
     
     digitalWrite(29, 1);
     digitalWrite(28, 1);
     digitalWrite(27, 1);
     digitalWrite(26, 1);
     digitalWrite(25, 1);
     digitalWrite(24, 1);
     digitalWrite(23, 1);
     digitalWrite(22, 1);
     digitalWrite(21,1);
     digitalWrite(30,1);
     digitalWrite(14,1);
     digitalWrite(13,1);
     digitalWrite(12,1);
     digitalWrite(7,1);
     digitalWrite(6,1);
     digitalWrite(0,1);  
     
     digitalWrite(31,1);
     digitalWrite(11,1);
     digitalWrite(10,1); 
     
}

//--------------------------------------------------------------
void ofApp::update(){

     
     ofSleepMillis(2000);

     digitalWrite(29, 0);
     digitalWrite(28, 0);
     digitalWrite(27, 0);
     digitalWrite(26, 0);
     digitalWrite(25, 0);
     digitalWrite(24, 0);
     digitalWrite(23, 0);
     digitalWrite(22, 0);
     digitalWrite(21,0);
     digitalWrite(30,0);
     digitalWrite(14,0);
     digitalWrite(13,0);
     digitalWrite(12,0);
     digitalWrite(7,0);
     digitalWrite(6,0);
     digitalWrite(0,0);   
     
     digitalWrite(31,0);
     digitalWrite(11,0);
     digitalWrite(10,0); 
     
     ofSleepMillis(2000);
     digitalWrite(29, 1);
     digitalWrite(28, 1);
     digitalWrite(27, 1);
     digitalWrite(26, 1);
     digitalWrite(25, 1);
     digitalWrite(24, 1);
     digitalWrite(23, 1);
     digitalWrite(22, 1);
     digitalWrite(21,1);
     digitalWrite(30,1);
     digitalWrite(14,1);
     digitalWrite(13,1);
     digitalWrite(12,1);
     digitalWrite(7,1);
     digitalWrite(6,1);
     digitalWrite(0,1);   
     
     digitalWrite(31,1);
     digitalWrite(11,1);
     digitalWrite(10,1); 
     
}

//--------------------------------------------------------------
void ofApp::draw(){

}
