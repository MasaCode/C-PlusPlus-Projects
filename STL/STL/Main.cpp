#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::stack;

#define MainMaxMenuNumber 11
#define VectorMaxMenuNumber 8
#define ListMaxMenuNumber 7
#define DequeMaxMenuNumber 6
#define MapMaxMeuNumber 4
#define MultiMapMaxMenuNumber 4
#define SetMaxMenuNumber 4
#define MultiSetMaxMenuNumber 4
#define StackMaxMenuNumber 4
#define QueueMaxMenuNumer 4
#define PriorityQueueMaxMenuNumber 4


//TODO: I need to think about what if they wanna add the number to too big index.

int MainMenu(){
	int number;
	cout << "\t\t-\t Menu \t\t-" << endl;
	cout << "\t\t| 1. Vectors \t\t|" << endl;
	cout << "\t\t| 2. List \t\t|" << endl;
	cout << "\t\t| 3. Deques \t\t|" << endl;
	cout << "\t\t| 4. Maps \t\t|" << endl;
	cout << "\t\t| 5. MultiMaps \t\t|" << endl;
	cout << "\t\t| 6. Sets \t\t|" << endl;
	cout << "\t\t| 7. MultiSets \t\t|" << endl;
	cout << "\t\t| 8. Stacks \t\t|" << endl;
	cout << "\t\t| 9. Queue \t\t|" << endl;
	cout << "\t\t|10. Priority Queue \t|" << endl;
	cout << "\t\t|11. End \t\t|" << endl;
	cout << endl <<  "\tYour Input : ";
	cin >> number;
	return number;
}


int VectorMenu(){
	int number;
	cout << "\t\t VectorMenu \t\t" << endl;
	cout << "\t 1. Add an Element to the end of vector" << endl;
	cout << "\t 2. Add an element to the beginning of the vector" << endl;
	cout << "\t 3. Add an element to a specific location in the vector" << endl;
	cout << "\t 4. Print the vector  " << endl;
	cout << "\t 5. Show Vector’s size " << endl;
	cout << "\t 6. Access a particular Element in the vector by using Iterator " << endl;
	cout << "\t 7. Access a Particular Element in the vector by using [] operator " << endl;
	cout << "\t 8. return to Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int ListMenu(){
	int number;
	cout << "\t\t ListMenu \t\t" << endl;
	cout << "\t 1. Add an Element to the end of list " << endl;
	cout << "\t 2. Add an element to the beginning of the list " << endl;
	cout << "\t 3. Add an element to a specific location in the list " << endl;
	cout << "\t 4. Print the list using Copy Algorithm and otream   " << endl;
	cout << "\t 5. Print the list using list iterator  " << endl;
	cout << "\t 6. Show list’s size  " << endl;
	cout << "\t 7. return to Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int DequeMenu(){
	int number;
	cout << "\t\t DequeMenu \t\t" << endl;
	cout << "\t 1. Add an Element to the end of list " << endl;
	cout << "\t 2. Add an element to the beginning of the list " << endl;
	cout << "\t 3. Access a particular Element in the Deque by using Iterator " << endl;
	cout << "\t 4. Access a Particular Element in the Deque by using [] operator " << endl;
	cout << "\t 5. Print the Deque" << endl;
	cout << "\t 6. return to Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int MapMenu(){
	int number;
	cout << "\t\t MapMenu \t\t" << endl;
	cout << "\t 1. Add an Element to the Map " << endl;
	cout << "\t 2. Show that Multiple similar Mapped values are ignored (By adding and printing) " << endl;
	cout << "\t 3. Printing the Map " << endl;
	cout << "\t 4. Return to the Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int MultiMapMenu(){
	int number;
	cout << "\t\t MultiMapMenu \t\t" << endl;
	cout << "\t 1. Add an Element to the MultiMap " << endl;
	cout << "\t 2. Show that Multiple similar Mapped values are allowed (By adding and printing) " << endl;
	cout << "\t 3. Printing the MultiMap " << endl;
	cout << "\t 4. Return to the Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int SetMenu(){
	int number;
	cout << "\t\t SetMenu \t\t" << endl;
	cout << "\t 1. Add an Element to the Set " << endl;
	cout << "\t 2. Show that Multiple similar Set values are ignored (By adding and printing) " << endl;
	cout << "\t 3. Printing the Set " << endl;
	cout << "\t 4. Return to the Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int MultiSetMenu(){
	int number;
	cout << "\t\t MultiSetMenu \t\t" << endl;
	cout << "\t 1. Add an Element to the MultiSet " << endl;
	cout << "\t 2. Show that Multiple similar Set values are allowed (By adding and printing) " << endl;
	cout << "\t 3. Printing the MultiSet " << endl;
	cout << "\t 4. Return to the Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int StackMenu(){
	int number;
	cout << "\t\t StackMenu \t\t" << endl;
	cout << "\t 1. Push into the Stack " << endl;
	cout << "\t 2. Pop from the Stack " << endl;
	cout << "\t 3. Print the Stack " << endl;
	cout << "\t 4. Return to the Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int QueueMenu(){
	int number;
	cout << "\t\t QueueMenu \t\t" << endl;
	cout << "\t 1. Push into the Queue " << endl;
	cout << "\t 2. Pop from the Queue " << endl;
	cout << "\t 3. Print the Queue " << endl;
	cout << "\t 4. Return to the Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int PriorityQueueMenu(){
	int number;
	cout << "\t\t PriorityQueueMenu \t\t" << endl;
	cout << "\t 1. Push into the Priority Queue " << endl;
	cout << "\t 2. Pop from the  Priority Queue " << endl;
	cout << "\t 3. Print the Priority Queue " << endl;
	cout << "\t 4. Return to the Main Menu " << endl;
	cout << endl << "\tYour Input : ";
	cin >> number;
	return number;
}

int InputNumber(){
	int input;
	cout << endl << "\tPlease enter the Element : ";
	cin >> input;
	return input;
}

int InputLocation(){
	int location;
	cout << endl << "\tPlase Enter the Location where you manna Add (First Index is 0): ";
	cin >> location;
	return location;
}

int AccessLocation(){
	int accessLocation;
	cout << endl << "\tPlease enter the Location where you wanna Access (First Index is 0) : ";
	cin >> accessLocation;
	return accessLocation;
}

void InputMultiNumber(int *num1, double *num2){
	cout << endl << "\tPlease enter the Integer and Double Value " << endl;
	cout << "\tInteger Value -> ";
	cin >> *num1;
	cout << "\tDouble Value -> ";
	cin >> *num2;
}

void Vectors(){
	int menu,location;
	std::ostream_iterator< int > output(cout, " ");
	std::vector<int>::iterator p;
	std::vector<int> v;
	p = v.begin();

	while (true){
		menu = VectorMenu();
		if (menu <= VectorMaxMenuNumber){
			switch (menu){
			case 1:
				v.push_back(InputNumber());
				break;
			case 2:
				v.insert(v.begin(), InputNumber());
				break;
			case 3:
				location = InputLocation();
				v.insert(v.begin() + location, InputNumber());
				break;
			case 4:
				cout << endl << endl << "\tThe Element of Vector is ";
				std::copy(v.begin(), v.end(), output);
				cout << endl << endl;
				break;
			case 5:
				cout << endl << "\tThe size of Vector is " << v.size() << endl << endl;
				break;
			case 6:
				location = AccessLocation();
				cout << endl << "\tThe Element of location " << location << " is ";
				p = v.begin() + location; //TODO : I need to think about it.
				cout << *p << endl << endl;
				break;
			case 7:
				location = AccessLocation();
				cout << endl <<  "\tThe Element of location v[" << location << "] is " << v[location] << endl << endl;
			default:
				return;
			}
		}
	}
}

void Lists(){
	int menu,location;
	std::list<int> value;
	std::ostream_iterator< int > output(cout, " ");
	std::list<int>::iterator p;

	while (true){
		menu = ListMenu();
		if (menu <= ListMaxMenuNumber){
			switch (menu){
			case 1 :
				value.push_back(InputNumber());
				break;
			case 2 :
				value.push_front(InputNumber());
				break;
			case 3 :
				location = InputLocation();
				//TODO: I need to find how to add the value to it.
				p = value.begin();
				for (int i = 0; i < location; i++) ++p;
				value.insert(p, InputNumber());
				break;
			case 4 :
				cout << endl << "\tThe Elements of List are ";
				std::copy(value.begin(), value.end(), output);
				cout << endl << endl;
				break;
			case 5 :
				cout << endl << "\tThe Elements of List are ";
				for (p = value.begin(); p != value.end(); ++p){
					cout << *p << " ";
				}
				cout << endl << endl;
				break;
			case 6 :
				cout << endl << "\tThe size of list is " << value.size() << endl << endl;
				break;
			default:
				return;
			}
		}
	}
}

void Deques(){
	int menu,location;
	std::deque<int> value;
	std::deque<int>::iterator p;
	std::ostream_iterator< int > output(cout, " ");

	while (true){
		menu = DequeMenu();
		if (menu <= DequeMaxMenuNumber){
			switch (menu){
			case 1 :
				value.push_back(InputNumber());
				break;
			case 2 :
				value.push_front(InputNumber());
				break;
			case 3 :
				p = value.begin();
				location = AccessLocation();
				p += location;
				cout << endl << "\tThe Element of location " << location << " is " << *p << endl << endl;
				break;
			case 4 :
				location = AccessLocation();
				cout << endl << "\tThe Element of list[" << location << "] is " << value[location] << endl << endl;
				break;
			case 5 :
				cout << endl << "\tThe Element of the deque are ";
				std::copy(value.begin(), value.end(), output);
				cout << endl << endl;
			default :
				return;
			}
		}
	}
}

void Maps(){
	typedef std::map<int, double, std::less<int>> myMap;
	myMap value;
	myMap::iterator mapiter;
	int menu,num1;
	double num2;
	while (true){
		menu = MapMenu();
		if (menu <= MapMaxMeuNumber){
			switch (menu){
			case 1 :
				InputMultiNumber(&num1, &num2);
				value.insert(myMap::value_type(num1, num2));
				break;
			case 2 :
				if (num1 == NULL || num2 == NULL) break;
				cout << "\tAdding (" << num1 << "," << num2 << ") to the map" << endl;
				cout << "\tThe Elements of Map after adding are ";
				value.insert(myMap::value_type(num1, num2));
				for (mapiter = value.begin(); mapiter != value.end(); mapiter++)
					cout << "(" << mapiter->first << "," << mapiter->second << ") ";
				cout << endl << endl;
				break;
			case 3 :
				cout << "\tThe Elements of Map are ";
				for (mapiter = value.begin(); mapiter != value.end(); mapiter++)
					cout << "(" << mapiter->first << "," << mapiter->second << ") ";
				cout << endl << endl;
				break;
			default:
				return;
			}
		}
	}
}

void MultiMap(){
	typedef std::multimap<int, double, std::less<int>> myMultiMap;
	myMultiMap value;
	myMultiMap::iterator MultiMapiter;
	int menu, num1;
	double num2;
	
	while (true){
		menu = MultiMapMenu();
		if (menu <= MultiMapMaxMenuNumber){
			switch (menu){
			case 1 :
				InputMultiNumber(&num1, &num2);
				value.insert(myMultiMap::value_type(num1, num2));
				break;
			case 2 :
				if (num1 == NULL || num2 == NULL) break;
				cout << endl << "\tAdding (" << num1 << "," << num2 << ") to the map" << endl;
				cout << "\tThe Elements of Multi Map after adding are ";
				value.insert(myMultiMap::value_type(num1, num2));
				for (MultiMapiter = value.begin(); MultiMapiter != value.end(); MultiMapiter++)
					cout << "(" << MultiMapiter->first << "," << MultiMapiter->second << ") ";
				cout << endl << endl;
				break;
			case 3 :
				cout << endl << "\tThe Elements of Multi Map are ";
				for (MultiMapiter = value.begin(); MultiMapiter != value.end(); MultiMapiter++)
					cout << "(" << MultiMapiter->first << "," << MultiMapiter->second << ") ";
				cout << endl << endl;
				break;
			default :
				return;
			}
		}
	}


}

void Set(){
	typedef std::set<int, std::less<int>> mySet;
	mySet value;
	int menu,number;
	mySet::iterator Setiter;

	while (true){
		menu = SetMenu();
		if (menu <= SetMaxMenuNumber){
			switch (menu){
			case 1 :
				number = InputNumber();
				value.insert(number);
				break;
			case 2 :
				if (number == NULL) break;
				cout << endl << "\tAdding " << number << "to the Set" << endl;
				cout << "\tThe Elements of the Set after adding are ";
				value.insert(number);
				for (Setiter = value.begin(); Setiter != value.end(); Setiter++)
					cout << *Setiter << " ";
				cout << endl << endl;
				break;
			case 3 :
				cout << endl << "\tThe Elements of the Set are ";
				for (Setiter = value.begin(); Setiter != value.end(); Setiter++)
					cout << *Setiter << " ";
				cout << endl << endl;
				break;
			default :
				return;
			}
		}
	}
}

void MultiSet(){
	typedef std::multiset<int, std::less<int>> myMultiSet;
	myMultiSet value;
	myMultiSet::iterator MultiSetiter;
	int menu, number;
	
	while (true){
		menu = MultiSetMenu();
		if (menu <= MultiSetMaxMenuNumber){
			switch (menu){
			case 1 :
				number = InputNumber();
				value.insert(number);
				break;
			case 2 :
				if (number == NULL) break;
				cout << endl << "\tAdding " << number << " to the Multi Set " << endl;
				cout << "\tThe Elements of the Multi Set after adding are";
				value.insert(number);
				for (MultiSetiter = value.begin(); MultiSetiter != value.end(); MultiSetiter++)
					cout << *MultiSetiter << " ";
				cout << endl << endl;
				break;
			case 3 :
				cout << endl << "\tThe Elements of the Multi Set are";
				for (MultiSetiter = value.begin(); MultiSetiter != value.end(); MultiSetiter++)
					cout << *MultiSetiter << " ";
				cout << endl << endl;
			default :
				return;
			}
		}
	}
}

void Stack(){
	int menu, number;
	stack<int> value;
	while (true){
		menu = StackMenu();
		if (menu <= StackMaxMenuNumber){
			switch (menu){
			case 1 :
				value.push(InputNumber());
				break;
			case 2 :
				if (value.empty()){
					cout << endl << "\tThe Stack is empty...." << endl << endl;
					break;
				}
				cout << endl << "\tPoped " << value.top() << " from Stack" << endl << endl;
				value.pop();
				break;
			case 3 :
				cout << endl <<  "\tThe Elements of Stack are ";
				while (!(value.empty())){
					cout << value.top() << " ";
					value.pop();
				}
				cout << endl << endl;
				break;
			default :
				return;
			}
		}
	}
}

void Queue(){
	int menu, number;
	std::queue<int> value;
	while (true){
		menu = QueueMenu();
		if (menu <= QueueMaxMenuNumer){
			switch (menu){
			case 1 :
				value.push(InputNumber());
				break;
			case 2 :
				if (value.empty()){
					cout << endl << "The Queue is empty..." << endl << endl;
					break;
				}
				cout << endl << "\tPoped " << value.front() << " from Queue" << endl << endl;
				value.pop();
				break;
			case 3 :
				cout << endl << "\tThe Elements of Queue are ";
				while (!value.empty()){
					cout << value.front() << " ";
					value.pop();
				}
				cout << endl << endl;
				break;
			default :
				return;
			}
		}
	}
}

void main(){
	bool isValid = true;
	int menuNumber;


	while (true){
		menuNumber = MainMenu();
		if (menuNumber <= MainMaxMenuNumber && menuNumber != 0){
			switch (menuNumber){
			case 1:
				Vectors();
				break;
			case 2:
				Lists();
				break;
			case 3:
				Deques();
				break;
			case 4:
				Maps();
				break;
			case 5 :
				MultiMap();
				break;
			case 6:
				Set();
				break;
			case 7:
				MultiSet();
				break;
			case 8:
				Stack();
				break;
			case 9 :
				Queue();
				break;
			default:
				break; // end proccess
			}
		}
		if (menuNumber == MainMaxMenuNumber) break;
	}
}