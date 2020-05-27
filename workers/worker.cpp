#include "worker.h"
#include <iostream>

Worker::~Worker() {}

void Worker::Data() const
{
	std::cout << "Name and Surname of worker :" << fullName << std::endl;
	std::cout << "Worker's ID: " << ID << std::endl;
}

void Worker::Get()
{
	std::cout << "Name and Surname of worker: ";
	std::getline(std::cin, fullName);
	std::cout << "ID: ";
	std::cin >> ID;
	while (std::cin.get() != '\n')
		continue;
}

void Waiter::Get()
{
	std::cout << "what is the skill of waiter ? " << std::endl;
	std::cin >> skill;
	while (std::cin.get() != '\n')
		continue;
}
void Waiter::Set()
{
	Worker::Get();
	Get();
}
void Waiter::Data() const
{
	std::cout << "Skill of waiter: " << skill << std::endl;
}
void Waiter::Show() const
{
	Worker::Data();
	Data();
}

void Singer::Get()
{
	std::cout << "Give the quality of singer's voice: ";
	do
	{
		std::cin >> voiceLevel;
	}while (voiceLevel < 0 || voiceLevel > 7);
	
}
void Singer::Set()
{
	Worker::Get();
	Get();
}
void Singer::Data() const
{
	std::cout << "Skill of singer: " << voiceLevel << std::endl;
}
void Singer::Show() const
{
	Worker::Data();
	Data();
}

void SingingWaiter::Data() const
{
	Worker::Data();
	Singer::Data();
	Waiter::Data();
}
void SingingWaiter::Show() const
{
	Data();
}
void SingingWaiter::Get()
{
	Worker::Get();
	Singer::Get();
	Waiter::Get();
}
void SingingWaiter::Set()
{
	Get();
}