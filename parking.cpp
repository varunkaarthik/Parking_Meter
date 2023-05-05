#include "parking.h"
#include<vector>
using namespace std;

// Takes the number of hours a car has been parked as input and returns the corresponding parking fee 

double calculate_fee(double parking_hours)
{
	double fees = 0;

	if (parking_hours < 0.5)

	{
		fees = 0;
	}
	else
		if (parking_hours > 0.5 && parking_hours < 4.0)
		{
			int x;
			x = ceil(parking_hours) - parking_hours;
			if (x < 0.5)
			{
				fees = ceil(parking_hours) / 0.5 - 1;
			}
			else
			{
				fees = (ceil(parking_hours) - 0.5) / 0.5 - 1;
			}
		}
		else
			if (parking_hours > 4)
			{
				fees = ((ceil(parking_hours) - 4) * 1.5) + 7;
			}

	return fees;
}


//returns the parking time as a vector of integers representing the minutes, hours, days, and years parked

vector<int> calculate_parking_time(double cash)
{
	float amount, years, min, days, hours, d, h;
	if (cash < 0) {
		hours = 0.5;
	}
	else
	if (cash > 7) {
		cash = cash - 7;
		hours = floor(cash / 1.5);
		hours += 4;
	}
	else {
		hours = (cash + 1) / 2;
	}
	years = floor(hours / 8760);
	days = (hours / 8760 - years) * 365;
	d = floor(days);
	hours = (days - d) * 24;
	int hrounded = ((hours * 100) + .5) / 100;
	int mrounded = floor(((hours - hrounded) * 6000) + .5) / 100;

	vector<int> v1(0);
	v1.push_back(mrounded);
	v1.push_back(hrounded);
	v1.push_back(d);
	v1.push_back(years);
	return v1;
}

// returns number of coins required to give exact change for the given amount

vector<int> convert_to_coins(double amt)
{
	float cents, e2, n2e, e1, n1e, c50, n50c, c20, n20c, c10, n10c, c5, n5c, c2, n2c, c1, n1c;
	cents = amt * 100;
	if (cents > 0){
		e2 = cents / 200;
		n2e = floor(e2);
		e1 = 2 * (e2 - n2e);
		n1e = floor(e1);
		c50 = 2 * (e1 - n1e);
		n50c = floor(c50);
		c20 = 2.5 * (c50 - n50c);
		n20c = floor(c20);
		c10 = 2 * (c20 - n20c);
		c10 = floor(c10 * 100) / 100 + 0.01;
		n10c = floor(c10);
		c5 = 2 * (c10 - n10c);
		c5 = floor(c5 * 100) / 100 + 0.01;
		n5c = floor(c5);
		c2 = 2.5 * (c5 - n5c);
		c2 = floor(c2 * 100) / 100 + 0.01;
		n2c = floor(c2);
		c1 = 2 * (c2 - n2c);
		c1 = floor(c1 * 100) / 100 + 0.01;
		n1c = floor(c1);

		vector<int> v1(0);
		v1.push_back(n2e);
		v1.push_back(n1e);
		v1.push_back(n50c);
		v1.push_back(n20c);
		v1.push_back(n10c);
		v1.push_back(n5c);
		v1.push_back(n2c);
		v1.push_back(n1c);
		return v1;
	}
	else
	{
		e2 = -(cents) / 200;
		n2e = floor(e2);
		e1 = 2 * (e2 - n2e);
		n1e = floor(e1);
		c50 = 2 * (e1 - n1e);
		n50c = floor(c50);
		c20 = 2.5 * (c50 - n50c);
		n20c = floor(c20);
		c10 = 2 * (c20 - n20c);
		c10 = floor(c10 * 100) / 100 + 0.01; // 
		n10c = floor(c10);
		c5 = 2 * (c10 - n10c);
		n5c = floor(c5);
		c2 = 2.5 * (c5 - n5c);
		n2c = floor(c2);
		c1 = 2 * (c2 - n2c);
		n1c = round(c1);

		vector<int> v1(0);
		v1.push_back(-n2e);
		v1.push_back(-n1e);
		v1.push_back(-n50c);
		v1.push_back(-n20c);
		v1.push_back(-n10c);
		v1.push_back(-n5c);
		v1.push_back(-n2c);
		v1.push_back(-n1c);
		return v1;

	}

}

// calculates the change or remaining balance owed to the customer and returns the minimum number of Euro coins required to represent that amount as a vector of integers

vector<int> bill_customer(double parking_hours, double amount)
{
	double x = calculate_fee(parking_hours);
	double chg;
	if (x > amount)
	{
		vector<int> v2(0);
		chg = -(x - amount);
	}
	else if (x < amount)
	{
		vector<int> v2(0);
		chg = amount - x;
	}
	vector<int> j;

	j = convert_to_coins(chg);

	return j;
}

