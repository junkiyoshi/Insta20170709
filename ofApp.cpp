#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");

	ofSetLineWidth(1);
	ofSetColor(ofColor(0, 0, 255));

	this->noise_value = ofRandom(10);
	
	this->light.setAreaLight(2048, 2048);
	this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.0, 1.0));
	this->light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.setSpecularColor(ofFloatColor(1.0, 0.0, 0.0));
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	ofRotateZ(90);

	this->light.setPosition(this->cam.getPosition().normalize() * 2048);
	ofEnableLighting();
	this->light.enable();

	float x_span = ofGetWidth() / 6;
	float angle = 0;

	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2; x += 25)
	{
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2; y += 25) {

			float noise_x = ofNoise(x * 0.0025, y * 0.0025, 0, ofGetFrameNum() * 0.025);

			ofPushMatrix();
			ofTranslate(ofVec3f(x, y, 0));

			//box.set(25 * noise_x);
			//box.enableColors();
			//box.draw();

			ofEllipse(ofVec3f(0, 0, 0), 30 * noise_x, 30 * noise_x);


			ofPopMatrix();}
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}