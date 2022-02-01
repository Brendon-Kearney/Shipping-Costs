#include "Package.h"

//implementation file
//By: Brendon Kearney

Package::Package(string newSource, string newDestination)
{
	source = new string(newSource);
	assert(source);
	*source = (newSource.length() > 0) ? newSource : "no name";
	destination = new string(newDestination);
	assert(destination);
	*destination = (newSource.length() > 0) ? newDestination : "no name";
}

Box::Box(int newWeight, string newSource, string newDestination)
	:Package(newSource, newDestination)
{
	weight = newWeight < 0 || newWeight>1000 ? 0 : newWeight;
}

double Box::computeShipCost() const
{
	double cost;
	if (weight < 5)
		cost = 0.79;
	else if (weight >= 5 && weight <= 15.1)
		cost = 2.75;
	else
		cost = 4.75;
	return cost;
}

Letter::Letter(int newNoPages, string newSource, string newDestination)
	:Package(newSource, newDestination)
{
	noPages = newNoPages < 0 || newNoPages>1000 ? 0 : newNoPages;
}

double Letter::computeShipCost() const
{
	double cost;
	if (noPages >= 1 && noPages <= 5)
		cost = 0.45;
	else if (noPages >= 6 && noPages <= 20)
		cost = 0.70;
	else if (noPages >= 21 && noPages <= 85)
		cost = 1.35;
	else
		cost = 2.89;
	return cost;
}

Package::~Package()
{
	delete source, destination;
}

