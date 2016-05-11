#include <iostream>
#include <string>

#include "list.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;


// function to test a List
template< class T >
void testList(List< T > &listObject, const string &typeName)
{
	cout << "Testing a List of " << typeName << " values\n";

	instructions();  // display instructions

	int choice;
	T value;

	do {
		cout << "? ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtFront(value);
			listObject.print();
			break;

		case 2:
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObject.insertAtBack(value);
			listObject.print();
			break;

		case 3:
			if (listObject.removeFromFront(value))
				cout << value << " removed from list\n";

			listObject.print();
			break;

		case 4:
			if (listObject.removeFromBack(value))
				cout << value << " removed from list\n";

			listObject.print();
			break;

		} // end switch

	} while (choice != 5);  // end do/while

	cout << "End list test\n\n";

} // end function testList

// display program instructions to user
void instructions()
{
	cout << "Enter one of the following:\n"
		<< "  1 to insert at beginning of list\n"
		<< "  2 to insert at end of list\n"
		<< "  3 to delete from beginning of list\n"
		<< "  4 to delete from end of list\n"
		<< "  5 to end list processing\n";

} // end function instructions

int main()
{
	// test List of int values
	List< int > integerList;
	testList(integerList, "integer");

	// test List of double values
	List< double > doubleList;
	testList(doubleList, "double");

	return 0;

}


/*
void main(){
	List<std::string> list;

	if (list.isEmpty())
		cout << "The list is empty" << endl;

	cout << "inserting Masashi into list" << endl;
	list.insertAtBack("Masashi");
	list.insertAtBack("Satoshi");

	cout << "The list is empty ? : ";
	if (list.isEmpty())
		cout << "True" << endl;
	else
		cout << "False" << endl;

	list.print();

	std::string value;
	list.removeFromBack(value);
	cout << "I am deleting last data " << value << " from list" << endl;

	list.print();
}

*/