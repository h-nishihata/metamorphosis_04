#include "pen.h"
float ang;
pen::pen(){
    
    centx = ofRandom(1440);
    centy = ofRandom(900);
    
    waitCnt = ofRandom(0, 300);
    step = 0;
    
    col = 0;
    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
    radius = ofRandom(20);
    radiusNoise = ofRandom(10);
    radLimit = ofRandom(10) + 40;
    speedX = ofRandom(-3,3);
    //    speedY = ofRandom(-5,5);
    
}
//--------------------------------------------------------------
void pen::setup(){
    
}
//--------------------------------------------------------------
void pen::setR(int red){
    r = red;
}

//--------------------------------------------------------------
void pen::setG(int green){
    g = green;
}

//--------------------------------------------------------------
void pen::setB(int blue){
    b = blue;
}

//--------------------------------------------------------------
void pen::setID(int ID){
    identify = ID;
}

//--------------------------------------------------------------
void pen::update(){
    
    if (flag_r == false) {
        
        radius+=0.1;
        if(radius > radLimit) {
            flag_r = true;
        }
        
    }else if (flag_r == true){
        
        radius-=0.1;
        if(radius < 0) {
            flag_r = false;
        }
        
    }
    
    
    
    
    if (flag == false) {
        r+=0.1;
        g+=0.1;
        b+=0.1;
        if(r>=255 || g>=255 || b>=25){
            flag = true;
        }
    }else if (flag == true){
        r-=0.1;
        g-=0.1;
        b-=0.1;
        if(r<=0 || g<=0 || b<=0){
            flag = false;
        }
    }
    
    if(waiting < 80){
        waiting++;
    }else{
        if(a > 0){ a --; }else{ a = 255;}
    }
    
    
    //  **********
    
    centx += speedX;
    centy += speedY;
    
    if (centx >= 1440 || centx <= 0) {
        speedX = speedX * -1;
    }
    if (centy >= 900 || centy <= 0) {
        speedY = speedY * -1;
    }
    
    time++;
    
    //     float ax = 0.0;
    //     float ay = 0.0;
    //     int lencon = ofRandom(50)+10;
    //
    //     for (int n=0; n<10; n++) { // 10
    //
    //     float ddx = this[n].centx-centx;
    //     float ddy = this[n].centy-centy;
    //     float d = sqrt(ddx*ddx + ddy*ddy);
    //     float t = atan2(ddy,ddx);
    //
    //     if (this[n].identify > identify) {
    //
    //     if (d>lencon) {
    //     ax += 10.0 * cos(t);
    //     ay += 10.0 * sin(t); // 10.0
    //     }
    //     } else {
    //
    //     if (d<lencon) {
    //     ax += (lencon-d)/10 * cos(t+PI); //(lencon-d)/10 *
    //     ay += (lencon-d)/10 * sin(t+PI);
    //     }
    //     }
    //
    //     }
    //
    //
    
    if (flag_t == false) {
        speedX += ofRandom(-1,1);
        speedY += ofRandom(-1,1);
        if(time > 100){
            flag_t = true;
        }
        
    }else if (flag_t == true){
        speedX += ofRandom(-0.9, 1);
        speedY += ofRandom(-0.9, 1);
        if(time > 300){
            flag_t = false;
            time = 0;
        }
        
    }
    
    speedX *= 0.95; // *= 0.95
    speedY *= 0.95;
    
    if (speedX == speedY) {
        speedX += ofRandom(-0.1, 0.1);
        speedY += ofRandom(-0.1, 0.1);
    }
    
    if (speedX == 0) {
        speedX = ofRandom(-0.1, 0.1);
    }
    
    if (speedY == 0) {
        speedY = ofRandom(-0.1, 0.1);
    }
    
}

//--------------------------------------------------------------
void pen::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();

    if (step < waitCnt) {
        step++;
    }
    else {
        ofSetColor(r, g, b);
        //        ofBeginShape();
        
//        for (float ang=0; ang <= 360; ang+=5) {
        
//            radiusNoise += 0.05;
//            thisRadius = radius + (ofNoise(radiusNoise)*10)-5;
//            x = centx + (thisRadius * cos(ang * 3.1415926/180));
//            y = centy + (thisRadius * sin(ang * 3.1415926/180));
//            oppx = centx + (thisRadius * cos(ang * 3.1415926/180+PI));
//            oppy = centy + (thisRadius * sin(ang * 3.1415926/180+PI));
//            ofCircle(centx, centy, 1);
            
//        }
        //        ofEndShape();
        
        
        
        for (int n=0; n<50; n++) { // 10
            
            float dx = this[n].centx-centx;
            float dy = this[n].centy-centy;
            float d = sqrt(dx*dx + dy*dy);
            
            if (d < this[n].radius+radius) {
                if (d > abs(this[n].radius-radius)) {
                    
                    for (int i=0; i < numsands; i++) {
                        
                        sands[i].render(centx, centy, this[n].centx, this[n].centy);
                        
                        
                    }
                    
                    
                }
            }
            
        }
        
        
        
        //    }
        
    }
}

/*
 //--------------------------------------------------------------
 void pen::connectTo(int f){
 
 if (numcon < maxcon) {
 if (! friendOf(f)) {
 connections[numcon] = f;
 numcon++;
 }
 }
 
 }
 
 //--------------------------------------------------------------
 bool pen::friendOf(int x){
 
 bool isFriend = false;
 for (int n=0; n<numcon; n++) {
 if (connections[n] == x) {
 isFriend = true;
 }
 }
 return isFriend;
 
 }
 */

