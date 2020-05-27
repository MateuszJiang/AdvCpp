#include <iostream>
#include "Brass.h"

void accountBase::Withdraw(double amt)
{
	accountBalance -= amt;
}

void accountBase::Deposit(double amt)
{
	std::cout << "You try to deposit " << amt << "USD !" << std::endl;
	if (amt < 0)
		std::cout << "You cannot deposit negative amount, process cancelled !!!" << std::endl;
	else
	{
		accountBalance -= amt;
		std::cout << amt << "USD deposited !" << std::endl;
	}
	std::cout << std::endl;
}

void Brass::Withdraw(double amt)
{
	std::cout << "You try to withdraw " << amt << "USD !" << std::endl;

	if (amt < 0)
		std::cout << "You cannot withdraw negative amount, process cancelled !!!" << std::endl;
	else if (Balance() <= amt)
		std::cout << " You dont have enough money, process cancelled !!!" << std::endl;
	else
		accountBase::Withdraw(amt);
	std::cout << std::endl;
}

void Brass::ViewAccount() const
{
	std::cout << "Client: " << returnFullName() << std::endl;
	std::cout << "Account Number: " << returnAccountNumber() << std::endl;
	std::cout << "Balance: " << Balance() << "USD" << std::endl;
	std::cout << std::endl;

}   

BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r) : accountBase(s, an, bal), maxLoan(ml), loanRate(r), accountDebt(0) {}
BrassPlus::BrassPlus(const Brass& ba, double ml, double r): accountBase(ba), maxLoan(ml), loanRate(r), accountDebt(0) {}

void BrassPlus::ViewAccount() const
{

	std::cout << "Client: " << returnFullName() << std::endl;
	std::cout << "Account Number: " << returnAccountNumber() << std::endl;
	std::cout << "Balance: " << Balance() << "USD" << std::endl;
	std::cout << "Debit limit: " << maxLoan << "USD" << std::endl;
	std::cout << "Your debt: " << accountDebt << "USD" << std::endl;
	std::cout.precision(3);
	std::cout << "Your loan rate: " << 100*loanRate << "USD" << std::endl;
	std::cout << std::endl;
}
void BrassPlus::Withdraw(double amt)
{
	double balance = Balance();
	if (amt <= balance)
		accountBase::Withdraw(amt);
	else if (amt <= balance + maxLoan - accountDebt)
	{
		double advance = amt - balance;
		accountDebt += advance * (1 + loanRate);
		std::cout << "Your debt: " << advance << "USD" << std::endl;
		std::cout << "Your loanrate: " << advance * loanRate << "USD" << std::endl;
		Deposit(advance);
		accountBase::Withdraw(amt);
	}
	else
		std::cout << " I am sorry, but you reached your debt limit, process cancelled !!! " << std::endl;
}

