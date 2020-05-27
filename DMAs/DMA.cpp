#include "DMA.h"
#include <cstring>


baseDMA::baseDMA(const char* l, int r) : rating(r)
{
	label = new char[std::strlen(l)];
	std::strcpy(label, l);
}
baseDMA::baseDMA(const baseDMA& baseDMA)
{
	label = new char[std::strlen(baseDMA.label)];
	std::strcpy(label, baseDMA.label);
	rating = baseDMA.rating;
}
baseDMA::~baseDMA()
{
	delete[] label;
}
baseDMA& baseDMA::operator=(const baseDMA& baseDMA)
{
	if (this == &baseDMA)
		return *this;
	delete[] label;
	label = new char[std::strlen(baseDMA.label)];
	std::strcpy(label, baseDMA.label);
	rating = baseDMA.rating;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& baseDMA)
{
	os << "Label: " << baseDMA.label << std::endl
		<< "Rating: " << baseDMA.rating << std::endl;
	return os;
}

simpleDMA::simpleDMA(const char* color, const char* label, int rating) : baseDMA(label, rating)
{
	std::strcpy(Color, color);
	Color[39] = '\0';
}
simpleDMA::simpleDMA(const char* color, const baseDMA& rs) :baseDMA(rs)
{
	std::strcpy(Color, color);
	Color[39] = '\0';
}

std::ostream& operator<<(std::ostream& os, const simpleDMA& ls)
{
	os << (const baseDMA &) ls;
	os << "Kolor: " << ls.Color << std::endl;
	return os;
}

advancedDMA::advancedDMA(const char* color, const char* label, int rating): baseDMA(label,rating)
{
	style = new char[std::strlen(color)];
	std::strcpy(style, color);
}
advancedDMA::advancedDMA(const char* color, const baseDMA& rs) : baseDMA(rs)
{
	style = new char[std::strlen(color)];
	std::strcpy(style, color);
}
advancedDMA::advancedDMA(advancedDMA& hs) : baseDMA(hs)
{
	style = new char[std::strlen(hs.style)];
	std::strcpy(style, hs.style);
}

advancedDMA::~advancedDMA()
{
	delete[] style;
}
advancedDMA& advancedDMA::operator=(const advancedDMA& hs)
{
	if (this == &hs)
		return *this;
	baseDMA::operator=(hs);
	delete[] style;
	style = new char[std::strlen(hs.style)];
	std::strcpy(style, hs.style);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const advancedDMA& hs)
{
	os << (const baseDMA&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}
