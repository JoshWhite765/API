#include "ofMain.h"
#include "HarryPotter.h"

//========================================================================
int main( ){
	cout << "LOADING...." << endl;
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context



	// This kicks off the running of my app
	ofRunApp(new ofApp());
}
