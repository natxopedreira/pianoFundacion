//
//  tecla.h
//  piano
//
//  Created by Natxo Pedreira gonzalez on 28/11/18.
//
//

#ifndef __piano__tecla__
#define __piano__tecla__

#include "ofMain.h"
#include "wiringPi.h"
//#include "wiringPi.h"

class tecla {

private:
    
		int minDist, maxDist;
        int numeroTecla;
        int _gpio;
        
		bool pulsada;
        bool encendida;
    
		ofSoundPlayer sonido;
        
        long tiempo, tiempoLuz;
    
public:

		void setup(string _urlPiano, int num, int gpio){
            _gpio = gpio;
            
            numeroTecla = num;
            
            sonido.load(_urlPiano);
            
            encendida = false;
            pulsada = false;
            
            minDist = 50;
            maxDist = 1000;
            
            tiempo = ofGetElapsedTimeMillis();
            
            pinMode(_gpio,OUTPUT);
            digitalWrite(_gpio, 1);
        }
        
        // ------------------------------
		void update(int d){
            if(d<maxDist && d>minDist){
                suena();
            }else{
                pulsada = false;
            }
            
            if(encendida && (ofGetElapsedTimeMillis()-tiempoLuz > 1000)){
                encendida = false;
                digitalWrite(_gpio, 1);
            }
        }
        
        
        // ------------------------------
		void suena(){
            //if (!sonido.isPlaying() && !pulsada){
             if (!pulsada && (ofGetElapsedTimeMillis()-tiempo > 1000)){
                sonido.play();
                pulsada = true;
                
                cout << "suena la " << numeroTecla << endl;
                tiempo = ofGetElapsedTimeMillis();
                tiempoLuz = ofGetElapsedTimeMillis();
                digitalWrite(_gpio, 0);
                
                encendida = true;
            }
        }
    
    
    
};


#endif /* defined(__piano__tecla__) */

