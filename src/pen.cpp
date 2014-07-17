#include "pen.h"

pen::pen(){
    
    centx = ofRandom(1920);
    centy = ofRandom(1200);
    
//    waitCnt = ofRandom(0, 300);
//    step = 0;
    
    radius = ofRandom(100);
    radiusNoise = ofRandom(10);

    speedX = ofRandom(-3,3);
    speedY = ofRandom(-0.1,0.1);
    
    if(ofRandom(100) > 60){
        setEraser = true;
    }else{
        setEraser = false;
    }
    
    a = ofRandom(255) + 100;
    waiting = ofRandom(0,80);
    
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
    
    
    //  *****   radius  *****
    
    if (flag_r == false) {
        
        radius+=0.1;
        if(radius > (r+g+b)*1.2) {
            flag_r = true;
        }
        
    }else if (flag_r == true){
        
        radius-=0.1;
        if(radius < 0) {
            flag_r = false;
        }
        
    }
    
    
    //  *****   colors  *****
    
    if (flag_c == false) {
        r+=0.1;
        g+=0.1;
        b+=0.1;
        if(r>=255 || g>=255 || b>=25){
            flag_c = true;
        }
    }else if (flag_c == true){
        r-=0.1;
        g-=0.1;
        b-=0.1;
        if(r<=0 || g<=0 || b<=0){
            flag_c = false;
        }
    }
    
//    if(waiting < 80){
//        waiting++;
//    }else{
//        if(a < 255){ a +=0.1; }else{ a = 100; }
//    }
    
    
    //  *****   velocity    *****
    
    time++;
    centx += speedX;
    centy += speedY;
    
    if (centx >= 1920 || centx <= 0) {
        speedX = speedX * -1;
    }
    if (centy >= 1200 || centy <= 0) {
        speedY = speedY * -1;
    }
    
    
    
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
    
    speedX *= 0.95;
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
    
    
    if (setEraser) {
        ofSetColor(0, 0, 0, 1);
    }else{
        ofSetColor(r, g, b, a);
    }
    
    
    for (int n=0; n<=50; n++) {
        
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
    
    
    
}


