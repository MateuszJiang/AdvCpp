#pragma once

#ifndef BRASS_H_
#define BRASS_H_
#include <string>


class accountBase
{
private:
	std::string clientFullName;
	long accountNumber;
	double accountBalance;
protected:
	const std::string& returnFullName() const { return clientFullName; }
	long returnAccountNumber() const { return accountNumber; }

public:
	accountBase(const std::string& s = "none", long an = -1, double bal = 0.0) : 
		clientFullName(s), accountNumber(an), accountBalance(bal) {}

	void Deposit(double amt);
	double Balance() const { return accountBalance; }

	virtual void Withdraw(double amt) = 0;
	virtual void ViewAccount() const = 0;
	virtual ~accountBase() {}
};
class Brass : public accountBase
{

public:
	Brass(const std::string& s = "none", long an = -1, double bal = 0.0) : accountBase(s, an, bal) {}
	void Deposit(double amt);

	virtual void Withdraw(double amt);
	virtual void ViewAccount() const;
	virtual ~Brass() {}
};

class BrassPlus : public accountBase
{
private:
	double maxLoan;
	double loanRate;
	double accountDebt;
public:
	BrassPlus(const std::string& s = "none", long an = -1, double bal = -1, double m1 = 2000, double r = 0.11125);
	BrassPlus(const Brass & ba, double ml = 2000, double r = 0.11125);
	virtual void ViewAccount() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { loanRate = r; }
	void resetOwes() { accountDebt = 0; }
};

#endif
