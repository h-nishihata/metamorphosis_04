#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
	ofSetFrameRate(60);
    
    img.loadImage("einoh.jpg");
	
	rgbaFbo.allocate(1920, 1200, GL_RGBA);
    
    rgbaFbo.begin();
	ofClear(255,255,255, 0);
    rgbaFbo.end();
    
    pixels = img.getPixels();
    
    for (int i=0; i<NUM; i++) {
        
        pos = pens[i].centy * 1753 + pens[i].centx;
        red = pixels[pos *3];
        green = pixels[pos *3 +1];
        blue =  pixels[pos *3 +2];
        pens[i].setR(red);
        pens[i].setG(green);
        pens[i].setB(blue);
        pens[i].setID(i);
        
    }
    
    fadeAmnt = 255;
    
    speedX = 0.1;
    speedY = 0.1;
    
    ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (startDraw<20) {
        startDraw ++ ;
    }
    
    ofEnableAlphaBlending();
	
    rgbaFbo.begin();
    drawFboTest();
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    rgbaFbo.end();
    
    y += speedY;
    
    if (y >= 0 || y <= -22) {
        speedY = speedY*-1;
    }
	
}

//--------------------------------------------------------------
void ofApp::drawFboTest(){
    
//	if(startDraw > 10){
//		fadeAmnt = 2;
//	}
//	
//  ofFill();
//	ofSetColor(200,200,100, fadeAmnt);
//    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
	
    ofSetColor(255,255,255);
    img.draw(x, y, 1920, img.height * 1.095);
    rgbaFbo.draw(0,0);
    
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
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
	
}
