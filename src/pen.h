#ifndef _OF_PEN
#define _OF_PEN

#define numsands 10 // 10

#include "ofMain.h"
#include "sandPainter.h"
class pen{
    
public:
    
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
    float x;
    float y;
    float oppx;
    float oppy;

    int r;
    int g;
    int b;
    float col;
    bool flag;
    int a;
    int waiting;
    
    pen();
    void setup();
    void update();
    void draw();
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setID(int ID);

//    int maxcon;
//    int numcon;
//    int connections[];
//    void connectTo(int f);
//    bool friendOf(int x);

    sandPainter sands[numsands];
    
};

#endif
