#include "TestLayer3.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer3::setup(){
    
    x = -50;
    y = -10;
    speedX = 0.1;
    speedY = 0.1;
    img.loadImage("renchizu.jpg");
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::update(){
    
    x += speedX;
    y += speedY;
    
    if (x >= 0 || x <= -73) {
        speedX = speedX*-1;
    }
    if (y >= 0 || y <= -254) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::draw(){
    
    ofEnableAlphaBlending();
    ofBackground(255,255,255,0);
    
//    ofSetColor(200,200,100);
//    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    img.draw(x, y, img.width, img.height);
    
}
