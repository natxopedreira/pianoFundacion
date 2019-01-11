#pragma once

#include "ofMain.h"
#include "tecla.h"

#define NUM_BYTES 1


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void procesaData(string str);
		
		ofSerial arduino;
		unsigned char	bytesReturned[NUM_BYTES];
		string			messageBuffer;
		string message;
	
		vector<tecla> teclas;
		
		bool inicializado;
		
		ofSoundPlayer sonidoCorrecto, sonidoError;
		
		void checkTeclasPiano(string str);
};
