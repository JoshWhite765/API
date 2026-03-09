#include <iostream>
#include <sstream> //access to stringstream functionality
#include <fstream>
#include "Review.h"

// Saves the review to a file with the current title from the page the review was given on also with the thumb state. 
bool Review::writeReview(const string title,  string& review, bool thumbsUpSelected, bool thumbsDownSelected) {
	bool success = false;
	review.erase(remove(review.begin(), review.end(), '\n'), review.end());

	ofstream reviewFile("reviews.txt", ios::app);
	if (reviewFile.is_open()) {

		// For saving the thumb state
		string thumbState;
		if (thumbsUpSelected == true) {
			thumbState = "ThumbsUp";
		}
		else if (thumbsDownSelected == true) {
			thumbState = "ThumbsDown";
		}
		else {
			thumbState = "None";
		}

		// Seperating each part of the review with commas 
		cout << "The review is saved: " << title << ": " << review << endl;
		reviewFile << title << ", " << review << ", " << thumbState << "\n ";
		reviewFile.close();
		success = true;
	}
	review = "";
	return success;
}

//Reads the review
bool Review::readReview() {
	ifstream reviewFile("reviews.txt");

	string lineStr;
	reviewRecords.clear();
	while (getline(reviewFile, lineStr)) {
		stringstream stream(lineStr);
		Review review;

		

		if (getline(stream, revTitle, ',') && getline(stream, reviewText, ',') && getline(stream, thumbState, ',')) {

			review.revTitle = revTitle;
			review.reviewText = reviewText;
			review.thumbState = thumbState;

			// Add the review to the vector 
			reviewRecords.push_back(review);
		}
		else {
			cout << "Error: cannot read the reviews" << endl;
		}

		
	}
	reviewFile.close();
	return true;

}

bool Review::deleteReview() {
	return false;

}