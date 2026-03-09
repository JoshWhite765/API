#pragma once

#include <string> //access to string functionality
#include <sstream>
#include <vector>

using namespace std;

class Review {

public:

	const vector<Review>& getReviewRecords() const {
		return reviewRecords;
	}

	// For accessing private members
	const string& getTitle() const {
		return revTitle;
	}

	const string& getReviewText() const {
		return reviewText;
	}

	const string& getThumbState() const {
		return thumbState;
	}

	// methods 
	bool writeReview(const string title, string& review, bool thumbsUpSelected, bool thumbsDownSelected);
	bool readReview();
	bool deleteReview();

	
private: 

	string revTitle;
	string reviewText;
	string thumbState;

	vector <Review> reviewRecords;

};

