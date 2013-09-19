//
//  ofxCodbar.cpp
//  readerUp_dummyScan
//
//  Created by Dudley Smith on 14/08/13.
//
//

#include "ofxCodbar.h"

ofxCodbar::ofxCodbar(){
    
    init();
}

ofxCodbar::ofxCodbar(string _start, string _end, int _size){
    // Always define :
    // - start sequence
    // - end sequence
    // - length of the codbar awaited
    m_sStartSequence    = _start;
    m_sEndSequence      = _end;
    m_iSizeDefined      = _size;
    
    init();
}

ofxCodbar::~ofxCodbar(){
    
}

void ofxCodbar::init(){

    m_iLastScan = ofGetElapsedTimeMillis();
    m_iGiveUpTime = 1000;   // Give up time is 1000ms = 1 second
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    openCode();
    
}

// Return Codbar
string ofxCodbar::get_codbar(){

    return m_sCodbarTempReceived;
    
}

// Open the code to be
void ofxCodbar::openCode(){
    
    m_bCobarClosed=false;
    m_sCodbarTempReceived.clear();
    
    ofLogVerbose() << "Opening a new code";
    
}

void ofxCodbar::closeCode(){
    m_bCobarClosed=true;
    
    ofLogVerbose() << "Closing with this code value : " << m_sCodbarTempReceived;
}

void ofxCodbar::addKeyToCode(int _keyCode){
    
    if((ofGetElapsedTimeMillis() - m_iLastScan)>m_iGiveUpTime){
        // after the delay, it re-opens the code and
        openCode();
        ofLogVerbose() << "Old Code given up";
    }
    m_iLastScan = ofGetElapsedTimeMillis();
    
    // even you could add
    // before you add, control
    // 48 = Code Ascii of 0
    // 57 = Code Ascii of 9
    // It just take numbers
    if (_keyCode>=48 && _keyCode<57) {
        m_sCodbarTempReceived += _keyCode;
        ofLogNotice() << "Code Received : " << ofToString(m_sCodbarTempReceived.size()) << "/" << m_iSizeDefined << ":" << m_sCodbarTempReceived;
        
    }
}

bool ofxCodbar::isFullyScanned(){
    
    bool m_bStartOK = true;
    bool m_bEndOK = true;
    bool m_bSizeOK = false;
    
    // Check if start/end sequences check required
    if(m_sStartSequence.size()>0){
        if(m_sStartSequence == m_sCurrentStartSequence){
            m_bStartOK = true;
        }else{
            m_bStartOK = false;
        }
    }
    
    if(m_sEndSequence.size()>0){
        if(m_sEndSequence == m_sCurrentEndSequence){
            m_bEndOK = true;
        }else{
            m_bEndOK = false;
        }
    }
    
    // Check the size
    if(m_sCodbarTempReceived.size()==m_iSizeDefined){
        m_bSizeOK = true;
    }
    
    if(m_bStartOK==true && m_bEndOK==true && m_bSizeOK==true){
        return true;
    }else{
        return false;
    }
    
    
}

void ofxCodbar::keyPressed(int key){
    
}
void ofxCodbar::keyReleased(int key){
    
}