#include "testApp.h"

float mass = 0.001; //masa del punto
float g = 9.8;      // fuerza g
float time0;   // valor de tiempo usado para computar time steps
ofPoint pos, vel; // posicion y velocidad

void testApp::setup(){
	
	//setup sample
	sound.load("banjo.wav"); // cargo sample
	sound.setMultiPlay(true); // set multiplay mode
	//model setup
	time0 = ofGetElapsedTimef(); //obtengo el tiempo actual
	pos = ofPoint(ofGetWidth()/2, 100); // posicion inicial de la pelota
	vel = ofPoint(0,0);
	// setemamos el fondo para que no se limpie
	ofSetBackgroundAuto(false);
	ofBackground(255, 255, 255);
	
}

void testApp::update(){
	
	bool bounced = updateBall();
	if (bounced) {
		// arranca el sample a tocar
		sound.play();
		// setea la velocidad de reproduccion en funcion de x
		float speed = ofMap(pos.x, 0, ofGetWidth(), 0.2, 0);
		sound.setSpeed(speed);
	}
	//update sound engine
	ofSoundUpdate();
}

void testApp::draw(){
	float bottom = 300.0; // the floor position on the screen
	// dibuja la linea del piso
	ofSetColor(0, 0, 0);
	ofDrawLine(0, bottom, ofGetWidth(), bottom);
	//dibujo la pelota
	ofSetColor(255, 0, 0);
	ofFill();
	ofDrawCircle(pos.x, bottom - pos.y, 3);
}

bool testApp::updateBall(){
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
	if(pos.y > ofGetWidth()){pos.x -= ofGetWidth();}
	return bounced;		
}
