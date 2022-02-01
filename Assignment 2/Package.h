#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//By: Brendon Kearney
//Assignment #2 - calculates shipping costs and outputs to console 
//specification file

class Package
{
public:
	Package();
	Package(string/*source*/, string/*destination*/);
	virtual double computeShipCost()const { return 0.0; }
	string getSource()const { return *source; }
	string getDestination()const { return *destination; }
	virtual ~Package();

protected:
	string* source;
	string* destination;
};

class Box : public Package
{
public:
	Box();
	Box(int/*weight*/, string/*source*/, string/*destination*/);
	virtual double computeShipCost()const;
	int getWeight()const { return weight; }

private:
	int weight;
};

class Letter : public Package
{
public:
	Letter();
	Letter(int/*noPages*/, string/*source*/, string/*destination*/);
	virtual double computeShipCost()const;
	int getNoPages()const { return noPages; }

private:
	int noPages;
};