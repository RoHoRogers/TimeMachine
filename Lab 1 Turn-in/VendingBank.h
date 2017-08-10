#pragma once
#include <iostream>
using namespace std;

class VendingBank
{

struct itemID
{
	char letter;
	int number;
};

public:
	VendingBank();
	VendingBank(int dollar, itemID id);
	VendingBank(int dollar, int quarters, itemID id);
	VendingBank(int dollar, int quarters, int dimes, itemID id);
	VendingBank(int dollar, int quarters, int dimes, int nickles, itemID id);
	VendingBank(int dollar, int quarters, int dimes, int nickles, int pennies, itemID id);
	VendingBank(int quarters, itemID id);
	VendingBank(int quarters, int dimes, itemID id);
	VendingBank(int quarters, int dimes, int nickles, itemID id);
	VendingBank(int quarters, int dimes, int nickles, int pennies, itemID id);
	VendingBank(int dimes, itemID id);
	VendingBank(int dimes, int nickles, itemID id);
	VendingBank(int dimes, int nickles, int pennies, itemID id);
	VendingBank(int nickles, itemID id);
	VendingBank(int nickles, int pennies, itemID id);
	VendingBank(int pennies, itemID id);
	VendingBank(int id);
	~VendingBank();

	int getVendingBankID() const;
	void setVendingBankID(int ID);
	int getDollars() const;
	int getQuarters() const;
	int getDimes() const;
	int getNickles() const;
	int getPennies() const;
	double getBalance() const;

	bool addCoin();
	bool addDollar();
	bool acceptCoin();
	bool acceptDollar();

	bool insufficentFunds();
	bool isAvailable();

	bool haveChange();	
	float makeChange();
	float giveChange();
	float refund();
	bool cancelTransaction();
	
	VendingBank operator+(const VendingBank &vend) const;
	VendingBank& operator+=(const VendingBank &vend);
	VendingBank operator-(const VendingBank &vend) const;
	VendingBank& operator-=(const VendingBank &vend);
	bool operator==(const VendingBank &vend);
	bool operator!=(const VendingBank &vend);

private:
	int dollars, quarters, dimes, nickles, pennies;
	int id;
};

