#include "sandPainter.h"
float ag;
sandPainter::sandPainter(){
    
    p = ofRandom(0.1);
    g = ofRandom(0.01, 0.1);
    
}
//--------------------------------------------------------------
void sandPainter::setup(){
    
}

//--------------------------------------------------------------
void sandPainter::update(){


    g += ofRandom(-0.050, 0.050);

}

//--------------------------------------------------------------
void sandPainter::render(float x, float y, float ox, float oy){

//    oy += 10;
    float maxg = 0.22;
//
    if (g < -maxg){
        g = -maxg;
    }else if (g > maxg){
        g = maxg;
    }
//
    float w =g/10.0;
    

    
//    if( ox != 0 && oy != 0){
//        ofSetColor(r,g,b);
        ofCircle(ox+(x-ox)*sin(p),
                 oy+(y-oy)*sin(p), 1);

        for (int i=0; i<10; i++) {
            ofCircle(ox+(x-ox)*sin(p + sin(i*w)),
                     oy+(y-oy)*sin(p + sin(i*w)), 1);
        }
    
//    }


    ofLine(x,y,ox,oy);
//    ofBezier(x, y,
//             x + bX, y + bY,
//             ox, oy,
//             ox + bX, oy + bY);
}
