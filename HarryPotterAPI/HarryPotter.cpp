#include "HarryPotter.h"
#include "Review.h"

// Define data set locations
const string MOVIES_STR = "https://api.potterdb.com/v1/movies";
const string BOOKS_STR = "https://api.potterdb.com/v1/books";
const string CHARS_STR = "https://api.potterdb.com/v1/characters";
const string POTIONS_STR = "https://api.potterdb.com/v1/potions";
const string SPELLS_STR = "https://api.potterdb.com/v1/spells";

// Define the Page Id values
const int MOVIES_PAGE_ID = 0;
const int BOOKS_PAGE_ID = 1;
const int CHARS_PAGE_ID = 2;
const int POTIONS_PAGE_ID = 3;
const int SPELLS_PAGE_ID = 4;

ofApp::ofApp() : page(0), mediaId(0), maxPage(5)
{
}

//--------------------------------------------------------------
// When the user launches the app
void ofApp::setup() {

	//Intilisers
	setScreen = Display::Menu;
	textInput = false;

	maxPage = 0;
	title = "The Harry Potter\nreviews";

	bool thumbsUpSelected = false;
	bool thumbsDownSelected = false;

	//Fonts
	mainFont.load("arial_black.ttf", 36);
	normalFont.load("SatyrSP.otf", 20);

	//Images
	banner.load("HPbanner.png");

	//https://www.iconfinder.com/icons/3917277/thumbs_thumbs_up_up_icon
	// load and sets the position of thumbs up image 
	thumbsUp.load("thumbs_up.png");
	thumbsUpBtn.set(700, 680, thumbsUp.getWidth(), thumbsUp.getHeight());

	// load and sets the position of thumbs down image 
	thumbsDown.load("thumbs_down.png");
	thumbsDownBtn.set(750, 680, thumbsDown.getWidth(), thumbsDown.getHeight());

	whiteBox.set(30, 20, 460, 600);

	filmBtn.set(40, 550, 150, 50);
	bookBtn.set(200, 550, 150, 50);
	charBtn.set(360, 550, 150, 50);
	potionBtn.set(120, 610, 150, 50);
	spellBtn.set(290, 610, 150, 50);

	reviewsBtn.set(650, 550, 150, 50);

	nextBtn.set(850, 700, 150, 50);
	prevBtn.set(40, 700, 150, 50);
	homeBtn.set(850, 40, 150, 50);

	submitBtn.set(800, 630, 150, 50);
	reviewBox.set(300, 630, 500, 100);
	

	// open media file
	setMediaFile(MOVIES_STR,0);

	setMediaFile(BOOKS_STR, 1);

	setMediaFile(CHARS_STR, 2);

	setMediaFile(POTIONS_STR, 3);

	setMediaFile(SPELLS_STR, 4);
	
	page = 0;
	mediaId = 0;
	
}


// Open and load in the attributes and images for the Media file on start up
void ofApp::setMediaFile(const string& mediaStr, const int mediaIdVal)
{
	page = 0;
	if (mediaFile[page][mediaIdVal].getPagesLoaded()) return; {
		do {
			if (false == mediaFile[page][mediaIdVal].openFile(page, mediaStr)) {
				// Write out error opening file
				cout << "Unable to open that media page from file" << endl;
			}
			else
			{
				mediaFile[page][mediaIdVal].loadAttributes(page);
				
			}
		} while (++page <= (mediaFile[0][mediaIdVal].getMaxPages()));
	}
}



//--------------------------------------------------------------
// Once the user clicks of the text box. the box will update and the text will appear within the box 
void ofApp::update(){
	if (textInput == false) {//if not capturing text input
		reviewText = "Click here to enter you're review\n\nalso click thumbs up or down rating";//set word to provide instruction
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(51, 51, 153); // changes to blue

	// Displays the menu to the user 
	if (setScreen == Display::Menu) {

		ofSetColor(255, 255, 255);
		banner.draw(0, 0);
		banner.resize(ofGetWidth(), 500);

		ofSetColor(0, 0, 0);
		mainFont.drawString(title, 40, 43);
	
		/*ofSetColor(0, 230, 0); */ // green

		ofSetColor(102, 153, 51);
		ofDrawRectangle(filmBtn);
		ofDrawRectangle(bookBtn);
		ofDrawRectangle(charBtn);
		ofDrawRectangle(spellBtn);
		ofDrawRectangle(potionBtn);
		ofDrawRectangle(reviewsBtn);

		ofSetColor(0, 0, 0);
		
		normalFont.drawString("Films", 60, 580);
		normalFont.drawString("Books", 210, 580);
		normalFont.drawString("Characters", 380, 580);
		normalFont.drawString("Potions", 150, 640);
		normalFont.drawString("Spells", 320, 640);
		
		normalFont.drawString("Reviews", 670, 580);
	}

	// Display the page to user on that chosen media
	if (setScreen == Display::List) {
		ofSetColor(255, 255, 255);
		ofImage img = mediaFile[page][mediaId].loadImage();

		// Draw image
		if (img.isAllocated()) {
			img.draw(500, 100, 500, 500);
		}
		else {
			cout << "Image not loaded" << endl;
		}

		// Draws the buttons on the page
		ofSetColor(102, 153, 51);
		ofDrawRectangle(nextBtn);
		ofDrawRectangle(prevBtn);
		ofDrawRectangle(homeBtn);
		ofDrawRectangle(submitBtn);

		// Draws the whitebox that situates behind the text for easire visibility
		ofSetColor(255);
		ofDrawRectangle(whiteBox);

		// Sets the colour of the text. When the user clicks on the box it changes colour
		if (textInput == false) {//if not capturing text input
			ofSetColor(150);//set colour to grey for text box
		}
		else {
			ofSetColor(255); //set color to white for text box
		}

		// Draws the review box
		ofDrawRectangle(reviewBox);
		
		// Draws the thumbs up/down buttons and sets the transparency/colour 
		if (thumbsUpSelected == true) {
			ofSetColor(255, 255, 255); 
			thumbsUp.draw(700, 680, 50, 50); 
			ofSetColor(200, 200, 200, 150);
			thumbsDown.draw(750, 680, 50, 50);
		}
		else if (thumbsDownSelected == true) {
			ofSetColor(200, 200, 200, 150); 
			thumbsUp.draw(700, 680, 50, 50);
			ofSetColor(255, 255, 255); 
			thumbsDown.draw(750, 680, 50, 50); 
		}
		else {
			// both buttons visible
			ofSetColor(255, 255, 255);
			thumbsUp.draw(700, 680, 50, 50);
			thumbsDown.draw(750, 680, 50, 50);
		}

		ofSetColor(0, 0, 0);

		// Gets the information from the specic media and page
		MediaInfo info = mediaFile[page][mediaId].getMediaInfo();

		string wrappedSummary = wrapString(info.getSummary(), 400);

		normalFont.drawString("Home", 870, 70);
		normalFont.drawString("Next", 870, 740);
		normalFont.drawString("Previous", 50, 740);
		normalFont.drawString("Submit", 830, 660);

		// Draws the text 
		normalFont.drawString(info.getTitle(), 40, 50);
		normalFont.drawString(wrappedSummary, 60, 100);
		normalFont.drawString(reviewText, 320, 660);
	}
	// Displays all the reviews to the user
	if (setScreen == Display::Reviews) {

		// Draws the home button
		ofSetColor(102, 153, 51);
		ofDrawRectangle(homeBtn);
		ofSetColor(0, 0, 0);
		normalFont.drawString("Home", 870, 70);
		
		bool success = review.readReview();
		if (success) {
			int yOffset = 100; // Start position for the first review
			int boxHeight = 100;
			int boxSpacing = 20;
			int reviewCount = 0;

			// Displays the reviews onto the screen
			for (const auto& record : review.getReviewRecords()) {

				if (reviewCount >= 5) break;

				ofSetColor(0, 0, 0); // Black
				mainFont.drawString("Reviews", 40, 60);

				ofSetColor(255, 255, 255);
				ofDrawRectangle(50, yOffset, 900, boxHeight);

				// Gets Media titles
				ofSetColor(0, 0, 0); // Black
				normalFont.drawString(record.getTitle(), 60, yOffset + 30);
				//Gets the Review Text
				normalFont.drawString(record.getReviewText(), 60, yOffset + 70);

				ofSetColor(255, 255, 255);
				if (record.getThumbState() == " ThumbsUp") {
					thumbsUp.draw(850, yOffset - 10, 100, 100);
				}
				else if (record.getThumbState() == " ThumbsDown") {
					thumbsDown.draw(850, yOffset - 10, 100, 100);
				}
				else {
					cout << "Unknown thumb state: " << record.getThumbState() << endl;
				}
				yOffset += boxHeight + boxSpacing;
				++reviewCount;
			}
		}
		else {
			ofSetColor(255, 0, 0); // Red
			normalFont.drawString("No reviews available to display.", 60, 100);
		}

	}
}

//--------------------------------------------------------------
// For entering data and ensuring it fits into the review box
void ofApp::keyPressed(int key){
	if (textInput == true && isValidKey(key)) {
		//Removes the last character once the user presses the delete or backspace key 
		if ((key == OF_KEY_BACKSPACE || key == OF_KEY_DEL)) {
			if (reviewText.length() != 0) {
				reviewText.pop_back();
			}
		}
		// For every 40 characters go onto the next line down
		else if (reviewText.length() == 40) {
			reviewText += '\n';
		}
		else if (key == OF_KEY_RETURN) { // Check for Enter key
			if (reviewText.length() < 70) {
				reviewText += '\n';
			}  
		}
		else {
			if (reviewText.length() < 70) {//check string is less than 70 chars
				ofUTF8Append(reviewText, key);
			}
		}
	}
}

// When the user selects one of the subject button. It will open the API and set the max page
bool ofApp::buttonSelection(const int x, const int y, const ofRectangle btn, const int apage, const string location)
{
	bool selected = false;
	if (btn.inside(x, y)) {
		setScreen = Display::List;
		maxPage = mediaFile[apage][mediaId].getMaxPages();
		selected = true;
	}
	return selected;
}


//-------------------------------------------------------------
// Allows the user to press the different subjects
void ofApp::mousePressed(int x, int y, int button){

	if (setScreen == Display::Menu) {

		// Gets the API for films when the film button is pressed 
		if (true == buttonSelection(x, y, filmBtn, MOVIES_PAGE_ID, MOVIES_STR)) {
			cout << "Movies selected" << endl;
			mediaId = 0;
		}
		else if (true == buttonSelection(x, y, bookBtn, BOOKS_PAGE_ID, BOOKS_STR)) {
			cout << "Books selected" << endl;
			mediaId = 1;
		}
		else if (true == buttonSelection(x, y, charBtn, CHARS_PAGE_ID, CHARS_STR)) {
			mediaId = 2;
			cout << "Chars selected" << endl;
		}
		else if (true == buttonSelection(x, y, potionBtn, POTIONS_PAGE_ID, POTIONS_STR)) {
			mediaId = 3;
			cout << "Potions selected" << endl;
		}
		else if (true == buttonSelection(x, y, spellBtn, SPELLS_PAGE_ID, SPELLS_STR)) {
			mediaId = 4;
			cout << "Spells selected" << endl;
		}
		else if (reviewsBtn.inside(x, y)) {
			setScreen = Display::Reviews;

		}
		else {
			cout << "nothing selected" << endl;
		}
	}


	if (setScreen == Display::List) {

		// Changes page when the user clicks NEXT button
		if (nextBtn.inside(x, y)) {
			if (page < mediaFile[0][mediaId].getTotalPages()) {
			thumbsUpSelected = false;
			thumbsDownSelected = false;
			++page;
			return;
			}
		}
		// Changes page when the user PREVIOUS button
		else if ((prevBtn.inside(x, y)) && (page > 0)) {
			thumbsUpSelected = false;
			thumbsDownSelected = false;
			--page;
			return;
		}
		// Changes page when the user HOME button
		else if (homeBtn.inside(x, y)) {
			thumbsUpSelected = false;
			thumbsDownSelected = false;
			page = 0;
			setScreen = Display::Menu;
		}

		// Toggle thumbs-up and thumbs-down buttons
		if (thumbsUpBtn.inside(x, y)) {
			thumbsUpSelected = true;
			thumbsDownSelected = false; // For deselecting the thumb down button
		}
		if (thumbsDownBtn.inside(x, y)) {
			thumbsDownSelected = true;
			thumbsUpSelected = false; // For deselecting the thumb up button
		}

		// entering into the review box 
		if (reviewBox.inside(x, y) && textInput == false) {
			textInput = true;
			reviewText = "";
		}
		//When the submit button is pressed
		else if (submitBtn.inside(x, y)) {
			// Checks the user is in text input 
			if (textInput == true) {
				MediaInfo info = mediaFile[page][mediaId].getMediaInfo();
				bool success = review.writeReview(info.getTitle(), reviewText, thumbsUpSelected, thumbsDownSelected);
				
				// If review submission is successful it exits the text input 
				if (true == success)
				{
					textInput = false;
				}
				else {
					cout << "Failed to save the review" << endl;
				}
			}
		}
		// if the user clicks any where else other than the review box or the submit button text input is disabled
		else {
			textInput = false;
		}
	}
	// Once the home button is pressed. It sends the user back to the menu
	if (setScreen == Display::Reviews) {
		if (homeBtn.inside(x, y)) {
			setScreen = Display::Menu;
		}
	}
}


//--------------------------------------------------------------
// Forces the window size 
void ofApp::windowResized(int w, int h){
	ofSetWindowShape(1024, 768);
}
// Ignores these keys pressed
bool ofApp::isValidKey(int key) {
	if (key == OF_KEY_ALT || key == OF_KEY_CONTROL || key == OF_KEY_SHIFT || key == OF_KEY_COMMAND || key == OF_KEY_LEFT_SHIFT || key == OF_KEY_RIGHT_SHIFT) {
		return false;
	}
	else {
		return true;
	}
}
// Wraps the string so it displays correctly
string ofApp::wrapString(string text, int width) {
	string typeWrapped = "";
	string tempString = "";
	vector <string> words = ofSplitString(text, " "); //create vector full of individual words in string passed in

	for (int i = 0; i < words.size(); i++) { //run through vector
		string wrd = words[i]; //get current word in vector

		// if we aren't on the first word, add a space
		if (i > 0) {
			tempString += " ";
		}
		tempString += wrd; //add current word to temp string

		int stringwidth = normalFont.stringWidth(tempString); //set string width to length of line

		if (stringwidth >= width) {//check string with to add either space or new line before current word
			typeWrapped += "\n"; //if line is now longer than desired width add a new line
			tempString = wrd; // make sure we're including the extra word on the next line
		}
		else if (i > 0) {
			typeWrapped += " "; // if we aren't on the first word, add a space
		}
		typeWrapped += wrd; //add current word to string to be returned with new lines for wrapping
	}

	return typeWrapped;
}