#pragma once

#ifndef WORKER_H_
#define WORKER_H_

#include <string>

class Worker
{
private:
	std::string fullName;
	long ID;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker(): fullName("none"), ID(0L) {}
	Worker(const std::string& fN, int id) : fullName(fN), ID(id) {}
	virtual ~Worker() = 0;
	virtual void Set() = 0;
	virtual void Show() const = 0;
};

class Waiter :public virtual Worker
{
private:
	int skill;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Waiter(): Worker(), skill(0) {}
	Waiter(const std::string& fN, int id, int p = 0) : Worker(fN,id), skill(p) {}
	Waiter(const Worker& worker, int p = 0) : Worker(worker), skill(p) {}
	void Set();
	void Show() const;
};

class Singer :virtual public Worker
{
private:
	int voiceLevel;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Singer() : Worker(), voiceLevel(1) {}
	Singer(const std::string& fN, int id, int vL = 1) : Worker(fN, id), voiceLevel(vL) {}
	Singer(const Worker& worker, int vL = 1) : Worker(worker), voiceLevel(vL) {}
	void Set();
	void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
	virtual void Data() const;
	virtual void Get();
public:
	SingingWaiter() {}

	SingingWaiter(const std::string& fullname, int id, int skill = 0, int voicelevel = 1) :
		Worker(fullname, id), Singer(fullname, id, voicelevel), Waiter(fullname, id, skill) {}
	SingingWaiter(const Worker& worker, int skill = 0, int voicelevel = 1) :
		Worker(worker), Waiter(worker, skill), Singer(worker, voicelevel) {}
	SingingWaiter(const Singer& singer, int skill = 0) :
		Worker(singer), Waiter(singer, skill), Singer(singer) {}
	SingingWaiter(const Waiter& waiter, int voicelevel = 1) :
		Worker(waiter), Waiter(waiter), Singer(waiter, voicelevel) {}

	void Set();
	void Show() const;
};

#endif