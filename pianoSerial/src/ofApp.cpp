#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetFrameRate(120);
    
    if(wiringPiSetup() == -1){
        printf("Error on wiringPi setup\n");
    }
    
    int gpios[] = {29,28,27,26,25,24,23,22,21,30,14,13,7,12,0,6};
    
    arduino.setup("/dev/ttyACM0",38400);
    message = "";
	messageBuffer = "";
    
    for(int i = 0; i < 16;  i++){
	int numMp3 = 30+i;
	tecla t;
	t.setup("mp3/"+ofToString(numMp3)+".mp3", i+1, gpios[i]);
	
	teclas.push_back(t);
    }
    
    inicializado = false;

    sonidoCorrecto.load("piano_listo.mp3");
    sonidoError.load("error_en_piano.mp3");
    
}

//--------------------------------------------------------------
void ofApp::update(){
// if we've got new bytes
	if (arduino.available() > 0)
	{
		// we will keep reading until nothing is left
		while (arduino.available() > 0)
		{
			// we' rofAppNoWindowll put the incoming bytes into bytesReturned
			arduino.readBytes(bytesReturned, NUM_BYTES);

			// if we find the splitter we put all the buffered messages
			//   in the final message, stop listening for more data and
			//   notify a possible listener
			// else we just keep filling the buffer with incoming bytes.
			if (*bytesReturned == '\n')
			{
				message = messageBuffer;
				messageBuffer = "";
				cout << "mesnage " << message << endl;
				procesaData(message);
				break;
			}
			else
			{
				if (*bytesReturned != '\r')
					messageBuffer += *bytesReturned;
			}
			//cout << "  messageBuffer: " << messageBuffer << "\n";
		}

		// clear the message buffer
		memset(bytesReturned, 0, NUM_BYTES);
	}
	
	//cout << ofGetFrameRate() << endl;
}
//--------------------------------------------------------------
void ofApp::procesaData(string str){
    // recibimos la data pa procesar
    
    vector<string> respuestas = ofSplitString(str,";");
    if(respuestas.size() == teclas.size()){
	if(!inicializado){
		checkTeclasPiano(str);
	}
	
        for(int i = 0; i < teclas.size(); i++){
           teclas.at(i).update(ofToInt(respuestas.at(i)));
        }
    }
}
//--------------------------------------------------------------

void ofApp::draw(){
    //ofDrawBitmapString(ofToString(ofGetFrameRate()), 50,50);
}


//--------------------------------------------------------------

void ofApp::checkTeclasPiano(string str){
    inicializado = true;
    bool correcto = true;
    
    // comprobamos que no hay ningun -1
    vector<string> respuestas = ofSplitString(str,";");
    for(int i = 0; i < respuestas.size(); i++){
	if(respuestas.at(i)=="-1"){
	    correcto = false;
	}
    }
    
    if(correcto){
	sonidoCorrecto.play();
	}else{
	sonidoError.play();
    }
}
