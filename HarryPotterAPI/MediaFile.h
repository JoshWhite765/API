#pragma once

#include <string> //access to string functionality
#include <sstream>
#include <vector>
#include "ofMain.h"
#include "ofxJSONElement.h"
#include "ofxJson.h" //access to ofxJson addon

using namespace std;

class MediaInfo {
public:
	void setTitle(string title);
	void setSummary(string summary);
	void setImageUrl(string aimageUrl);

	const string getTitle();
	const string getSummary();
	const string getImageUrl();
private:
	string title;
	string summary;
	string imageUrl;
};
inline
void MediaInfo::setTitle(string aTitle)
{
	title = aTitle;
};
inline
void MediaInfo::setSummary(string aSummary)
{
	summary = aSummary;
}
inline
void MediaInfo::setImageUrl(string aImageUrl)
{
	imageUrl = aImageUrl;
};
inline
const string MediaInfo::getTitle()
{
	return title;
};
inline
const string MediaInfo::getSummary()
{
	return summary;
}
inline
const string MediaInfo::getImageUrl()
{
	return imageUrl;
}


class MediaFile {

public:
	MediaFile();
	bool openFile(int pageId, const string location);
	int getMaxPages();
	bool loadAttributes(const int pageId);
	ofImage getImage();
	MediaInfo getMediaInfo();
	void setPagesLoaded(const int page);
	bool isMorePagesToLoad(const int page);
	int getTotalPages();
	int getPagesLoaded() const;
	ofImage loadImage();

private:
	// functions
	const auto& readAttributes(const int pageId);

	// members
	int m_page_id;
	MediaInfo m_media_info;
	ofImage m_img;
	ofxJSONElement json;
	int pagesLoaded;
	int totalPages;
};

