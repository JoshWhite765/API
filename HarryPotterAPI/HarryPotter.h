#pragma once

#include "ofMain.h"
#include <string> //access to string functionality
#include <sstream> //access to stringstream functionality
#include <algorithm>
#include <fstream>
#include "Review.h"
#include "MediaFile.h"

using namespace std;

//constants
const int MAX_NO_OF_PAGES = 1000;
const int MAX_NO_OF_MEDIAS = 5;

class ofApp : public ofBaseApp {

public:
	ofApp();
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void windowResized(int w, int h);

	enum class Display {
		Menu,
		Reviews,
		List
	};

private:
	// private methods
	void setMediaFile(const string& mediaStr, const int mediaIdVal);

	// Private attributes
	Display setScreen;
	int page;
	int mediaId;
	int maxPage;
	bool thumbsUpSelected;
	bool thumbsDownSelected;

	// string variables
	string title, reviewText;
	string text, newText;

	ofImage banner, home, thumbsUp, thumbsDown;
	ofTrueTypeFont mainFont, normalFont;
	ofRectangle filmBtn, bookBtn, charBtn, spellBtn, potionBtn, reviewsBtn, submitBtn, nextBtn, prevBtn, homeBtn, reviewBox, thumbsUpBtn, thumbsDownBtn, whiteBox;

	Review review;

	bool isValidKey(int key);
	bool textInput;

	//Private methods
	string ofApp::wrapString(string text, int width); //wrapString function declaration
	
	bool buttonSelection(const int x, const int y, const ofRectangle btn, const int apage, const string location);

	MediaFile mediaFile[MAX_NO_OF_PAGES][MAX_NO_OF_MEDIAS]; // 2D array should be 2D vector 
};

