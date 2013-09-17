//
//  ofxCodbar.h
//
//  
//
//  Created by Dudley Smith on 14/08/13.
//

#pragma once

#define LF   195
#define CR   123

#include "ofMain.h"

class ofxCodbar : public ofBaseApp{
    
public:
    
    ofxCodbar();
    ofxCodbar(string _start, string _end, int _size);
    virtual ~ofxCodbar();
    
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
    
    //void keyReleased(int key);

    // MEMBERS ---------------------------------------------------------
private:
    string  m_sCodbarTempReceived;
    bool    m_bCobarClosed;
    
    string      m_sStartSequence;
    string      m_sEndSequence;
    
    string      m_sCurrentStartSequence;
    string      m_sCurrentEndSequence;
    
    int         m_iSizeDefined;
    
    int         m_iGiveUpTime;
    long        m_iLastScan;
    
    // METHODS -------------------------------------------------------
public:
    string get_codbar();
    
    void openCode();
    void closeCode();
    void addKeyToCode(int _key);
    
    void init();
    
    bool isFullyScanned();
    
};