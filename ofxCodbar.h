//
//  ofxCodbar.h
//  readerUp_dummyScan
//
//  Created by Dudley Smith on 14/08/13.
//
//

#pragma once

#include <iostream>

class ofxCodbar : public ofBaseApp{
    
public:
    
    // Classic ofMethods ----------------------
    /*
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    */
    
    void keyReleased(int key);
    
    int     m_timeToReceive_ms;
    string  m_codeReceived;
    
};