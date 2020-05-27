#pragma once
#ifndef DMA_H_
#define DMA_H_

#include <iostream>

class baseDMA
{
private:
	char* label;
	int rating;
public:
	baseDMA(const char* l = nullptr, int r = 0);
	baseDMA(const baseDMA& baseDMA);
	virtual ~baseDMA();
	baseDMA& operator=(const baseDMA& baseDMA);

	friend std::ostream& operator<<(std::ostream& os, const baseDMA& baseDMA);
};

class simpleDMA : public baseDMA
{
private:
	enum { COLOR_LENGHT = 40};
	char Color[COLOR_LENGHT];
public:
	simpleDMA(const char* color, const char* label, int rating);
	simpleDMA(const char* color, const baseDMA& rs);

	friend std::ostream& operator<<(std::ostream& os, const simpleDMA& rs);
};

class advancedDMA : public baseDMA
{
private:
	char* style;
public:
	advancedDMA(const char* color, const char* label, int rating);
	advancedDMA(const char* color, const baseDMA& rs);
	advancedDMA(advancedDMA& hs);
	~advancedDMA();
	advancedDMA& operator=(const advancedDMA& hs);

	friend std::ostream& operator<<(std::ostream& os, const advancedDMA& rs);
};

#endif