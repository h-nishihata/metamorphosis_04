#include "TestLayer3.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer3::setup(){
    
    x = -50;
    y = -10;
    speedX = 0.1;
    speedY = 0.1;
    img.loadImage("einoh.jpg");
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::update(){
    
    x += speedX;
    y += speedY;
    
    if (x >= 0 || x <= -313) {
        speedX = speedX*-1;
    }
    if (y >= 0 || y <= -322) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::draw(){
    
    ofEnableAlphaBlending();
    ofBackground(255,255,255,0);
    
    ofSetColor(200,180,100);
    img.draw(x, y, img.width, img.height);
    
}
