#include "ofApp.h"

float mass = 0.001; //masa del punto
float g = 9.8;      // fuerza g
float time0;   // valor de tiempo usado para computar time steps
ofPoint pos, vel; // posicion y velocidad

void ofApp::setup(){
	
	//setup sample
	sound.load("banjo.wav"); // cargo sample
	sound.setMultiPlay(true); // set multiplay mode
	//model setup
	time0 = ofGetElapsedTimef(); //obtengo el tiempo actual
	pos = ofPoint(ofGetWidth()/2, 100); // posicion inicial de la pelota
	vel = ofPoint(0,0);
	// setemamos el fondo para que no se limpie
	ofSetBackgroundAuto(false);
	ofBackground(50, 50, 50);
	
}

void ofApp::update(){
	
	bool bounced = updateBall();
	if (bounced) {
		// arranca el sample a tocar
		sound.play();
		// setea la velocidad de reproduccion en funcion de x
		float speed = ofMap(pos.x, 0, ofGetWidth(), 1, 1.5);
		sound.setSpeed(speed);
	}
	//update sound engine
	ofSoundUpdate();
}

void ofApp::draw(){
	float bottom = ofGetHeight() -100; // the floor position on the screen
	// dibuja la linea del piso
	ofSetColor(255, 255, 255);
	ofDrawLine(0, bottom, ofGetWidth(), bottom);
	//dibujo la pelota
	ofSetColor(255, 0, 0);
	ofFill();
	ofDrawCircle(pos.x, bottom - pos.y, 3);
}

bool ofApp::updateBall(){
	bool bounced = false;
	//compute dt
	float time = ofGetElapsedTimef();
	float dt = ofClamp(time - time0, 0, 0.1);
	time0 = time;
	//computar la aceleracion de la gravedad
	ofPoint acc(0, -g/mass);
	//Change vel y pos con el metodo de euler
	vel += acc * dt;
	pos += vel * dt;
	// chequear si la bola rebota en el suelo
	if (pos.y < 0){
	// rebote elastico con conservacion del momentum
		pos.y = -pos.y;
		vel.y = -vel.y;
		
		vel.x = ofRandom(-300, 500);
		bounced = true;
	}
	// check si la bola esta afuera de la pantalla
	if(pos.x < 0){ pos.x += ofGetWidth();}
	if(pos.x > ofGetWidth()){pos.x -= ofGetWidth();}
	return bounced;
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
