#pragma once

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <valarray>
#include <iostream>

class Student: private std::string, private std::valarray<double>
{
private:
	std::ostream& arrayOut(std::ostream& os) const;
public:
	Student() : std::string("none"), std::valarray<double>() {}
	explicit Student(const std::string& s): std::string(s), std::valarray<double>()  {}
	explicit Student(const int& n) : std::string("none"), std::valarray<double>(n) {}
	Student(const int& n, const std::string& s) : std::string(s), std::valarray<double>(n) {}
	Student(std::valarray<double> vn, const std::string& s) : std::string(s), std::valarray<double>(vn) {}
	Student(int n, double* pd, const char* s) : std::string(s), std::valarray<double>(pd,n) {}
	~Student() {}

	double returnAvarage() const;
	const std::string& returnName()const;
	double& operator[] (int i);
	double operator[] (int i) const;

	friend std::istream& operator>>(std::istream& is, Student& student);
	friend std::istream& getline(std::istream& is, Student& student);
	friend std::ostream& operator<<(std::ostream& os, Student& student);
};

#endif
