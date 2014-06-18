#ifndef _OF_PEN
#define _OF_PEN

#define numsands 10 // 10

#include "ofMain.h"
#include "sandPainter.h"
class pen{
    
public:
    
    //  stroke
    int centx;
    int centy;
    float speedX;
    float speedY;
    int waitCnt;
    int step;

    int identify;
    int time;
    bool flag_r;
    bool flag_t;

    float radius;
    float radiusNoise;
    float thisRadius;
    float radLimit;
    
    
    //  colors
    bool setEraser;
    int r;
    int g;
    int b;
    float col;
    bool flag_c;
    int a;
    int waiting;
    
    
    //  functions
    pen();
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setID(int ID);

    sandPainter sands[numsands];
    
};

#endif
