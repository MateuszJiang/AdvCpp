#include "student.h"

std::ostream& Student::arrayOut(std::ostream& os) const
{

	int limit = std::valarray<double>::size();
	if (limit > 0)
	{
		for (int i = 0; i < limit; i++)
		{
			os << std::valarray<double>::operator[](i) << " ";
			if (!(i % 5))
				os << std::endl;
		}
	}
	os << "Empty array!!!" << std::endl;
	return os;
}

double Student::returnAvarage() const
{
	if(std::valarray<double>::size()>0)
		return std::valarray<double>::sum() / std::valarray<double>::size();
	return 0;
}
const std::string& Student::returnName()const
{
	return (const std::string&) *this;
}

double& Student::operator[] (int i)
{
	return std::valarray<double>::operator[](i);
}
double Student::operator[] (int i) const
{
	return std::valarray<double>::operator[](i);
}

std::istream& operator>>(std::istream& is, Student& student)
{
	is >> (std::string&) student;
	return is;
}
std::istream& getline(std::istream& is, Student& student)
{
	std::getline(is, (std::string&) student);
	return is;
}
std::ostream& operator<<(std::ostream& os, Student& student)
{
	os << "Results: " << (std::string&) student;
	student.arrayOut(os);
	return os;
}
