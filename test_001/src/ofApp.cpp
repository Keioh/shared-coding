#include "ofApp.h"

void ofApp::setup() {
	logo.setup((ofGetWindowWidth() / 2) - 140,(ofGetWindowHeight() / 2) - 75, 2);
}

void ofApp::update(){
	logo.update(120);
}

void ofApp::draw(){
	logo.draw();
}

void ofApp::mouseMoved(int x, int y){

}

void ofApp::mousePressed(int x, int y, int button) {

}

void ofApp::mouseReleased(int x, int y, int button){

}