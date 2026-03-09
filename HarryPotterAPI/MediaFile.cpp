#include <iostream>
#include <sstream> //access to stringstream functionality
#include <fstream>
#include "MediaFile.h"

//max load limit
const int MAX_PAGE_LOAD_LIMIT = 3;

MediaFile::MediaFile() : 
	pagesLoaded(0) // constructor

{
	m_img.load("unknown.png");
}

bool MediaFile::openFile(int pageId, const string location)
{
	m_page_id = pageId;
	// Open File for Reading
	bool rtn = json.open(location);
	return rtn;
}


const auto& MediaFile::readAttributes(int pageId)
{
    // Output json data to console for reference
	return json["data"][pageId]["attributes"];
}

bool MediaFile::loadAttributes(int pageId)
{
	bool success = true;
	totalPages = json["data"].size() - 1;
	const auto& attributes = readAttributes(pageId);
	
	
	// sets the title
	if (attributes.isMember("title")) {
		m_media_info.setTitle(attributes["title"].asString());
	}
	else if (attributes.isMember("name")) {
		m_media_info.setTitle(attributes["name"].asString());
	}

	// sets the summary
	m_media_info.setSummary(attributes["summary"].asString());

	// sets the image URL
	if (attributes.isMember("poster")) {
		m_media_info.setImageUrl(attributes["poster"].asString());
	}
	else if (attributes.isMember("image")) {
		m_media_info.setImageUrl(attributes["image"].asString());
	}
	else if (attributes.isMember("cover")) {
		m_media_info.setImageUrl(attributes["cover"].asString());
	}
	
	return success;

}
// Loads the image from URL
ofImage MediaFile::loadImage() {
	if (!m_media_info.getImageUrl().empty()) {
		// Load image 
		ofHttpResponse response = ofLoadURL(m_media_info.getImageUrl());
		m_img.load(response.data);
		
	}
	else {
		// If image cant be loaded. Load the unknown image as a replacement
		cout << "image has not been loaded" << endl;
		m_img.load("unknown.png");
	}
	return m_img;
}

ofImage MediaFile::getImage()
{
	return m_img;
}

int MediaFile::getMaxPages()
{
	return totalPages;
}

int MediaFile::getTotalPages() {
	return totalPages;
}


MediaInfo MediaFile::getMediaInfo()
{
	return m_media_info;
}

void MediaFile::setPagesLoaded(const int pages)
{
	pagesLoaded = pages;
}

int MediaFile::getPagesLoaded() const {
	return pagesLoaded;
}