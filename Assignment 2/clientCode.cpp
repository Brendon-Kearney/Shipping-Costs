#include "Package.h"

// client code
//By: Brendon Kearney

void shipCost(const Package* packagePtr)  //polymorphic function
{
	cout << endl << "Shipping Cost: " << packagePtr->computeShipCost() << endl;
}


int main()
{
	Package* PackageOne = new Package("source", "destination");
	assert(PackageOne);
	cout << "Source: " << PackageOne->getSource() << endl;
	cout << "Destination: " << PackageOne->getDestination() << endl;
	shipCost(PackageOne); //polymorphic function
	delete PackageOne;

	Box* PackageTwo = new Box(2, "source", "destination");
	assert(PackageTwo);
	cout << endl << "Weight: " << PackageTwo->getWeight() << endl;
	shipCost(PackageTwo); //polymorphic function
	delete PackageTwo;

	Letter* PackageThree = new Letter(20, "source", "destination");
	assert(PackageThree);
	cout << endl << "Number Of Pages: " << PackageThree->getNoPages() << endl;
	shipCost(PackageThree); //polymorphic function
	delete PackageThree;
}