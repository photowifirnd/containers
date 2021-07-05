 #include "testing.hpp"
 #include <iostream>

/* Prints out the list passed as argument: it sizes are equals it prints out in columns */
template <class T>
void	lPrint(std::list<T> listOrig, ft::list<T> listMio)
{
	typename std::list<T>::iterator itOrig = listOrig.begin();
	typename ft::list<T>::iterator itMio = listMio.begin();

	if (listOrig.size() != listMio.size())
	{
		std::cout << ORANGE << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		for (itOrig = listOrig.begin(); itOrig != listOrig.end(); itOrig++)
			std::cout << *itOrig << " ";
		std::cout << std::endl;
		
		for (itMio = listMio.begin(); itMio != listMio.end(); itMio++)
			std::cout << *itMio << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << GREEN"Original List\t\tMy List"RESET << std::endl;
			for (size_t i = 0; i < listOrig.size(); i++)
				std::cout << ORANGE"\t" << *(itOrig++) << "\t\t"CYAN << *(itMio++) << RESET << std::endl;;
		std::cout << std::endl;
	}
}

/***
 * *
 * */

void	lRelational()
{
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING RELATIONAL OPERATORS ******************" << RESET << std::endl;
	std::cout << CYAN"\nCreating lists with some data:\n" << RESET << std::endl;
	int	intsa[] = {9, 11, 22, 33};
	int	intsb[] = {33, 22, 11, 9};	
	std::list<int> list_a(intsa, intsa + 4);
	std::list<int> list_b(intsa, intsa + 4);
	std::list<int> list_c(intsb, intsb + 4);
	ft::list<int> myList_a(intsa, intsa + 4);
	ft::list<int> myList_b(intsa, intsa + 4);
	ft::list<int> myList_c(intsb, intsb + 4);
	std::cout << CYAN"Print lists list_a and myList_a" << std::endl;
	lPrint(list_a, myList_a);
	std::cout << CYAN"Print lists list_b and myList_b" << std::endl;
	lPrint(list_b, myList_b);
	std::cout << CYAN"Print lists list_c and myList_c" << std::endl;
	lPrint(list_c, myList_c);

	std::cout << GREEN"\n\nTesting the relational operators:" << RESET << std::endl;
	std::cout << GREEN"\n\nList output:\t\t\t\t\tMy list output:" << RESET << std::endl;
	
	if (list_a == list_b) std::cout << ORANGE"list_a and list_b are equal\t\t\t";
	if (myList_a == myList_b) std::cout << CYAN"myList_a and myList_b are equal"RESET << std::endl;

	if (list_b != list_c) std::cout << ORANGE << "list_b and list_c are not equal\t\t\t";
	if (myList_b != myList_c) std::cout << CYAN << "myList_b and myList_c are not equal"RESET << std::endl;;
	
	if (list_b < list_c) std::cout << ORANGE << "list_b is less than list_c\t\t\t";
	if (myList_b < myList_c) std::cout << CYAN << "myList_b is less than myList_c"RESET << std::endl;;
	
	if (list_c > list_b) std::cout << ORANGE << "list_c is greater than list_b\t\t\t";
	if (myList_c > myList_b) std::cout << CYAN << "myList_c is greater than myList_b"RESET << std::endl;;

	if (list_a <= list_b) std::cout << ORANGE << "list_a is less than or equal to list_b\t\t";
	if (myList_a <= myList_b) std::cout << CYAN << "myList_a is less than or equal to myList_b"RESET << std::endl;;
	
	if (list_a >= list_b) std::cout << ORANGE << "List_a is greater than or equal to myList_b\t";
	if (myList_a >= myList_b) std::cout << CYAN << "myList_a is greater than or equal to myList_b"RESET << std::endl;;

	pressAnyKey();
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING NON MEMBER SWAP FUNCTION ******************" << RESET << std::endl;
	std::cout << CYAN"\nConstructing list whith some data on them\n" << RESET << std::endl;
	std::list<int> dummy (2, 77);
	std::list<int> otherDummy (8, 212);
	ft::list<int> oneList (2, 77);
	ft::list<int> anotherList (8, 212);
	std::cout << CYAN"Print dummy and oneList before swap" << std::endl;
	lPrint(dummy, oneList);
	std::cout << CYAN"\nPrint otherDummy and anotherList before swap them" << std::endl;
	lPrint(otherDummy, anotherList);

	std::cout << CYAN"\nUsing Swap() function to interchange lists\n" << RESET << std::endl;
	std::swap(dummy,otherDummy);
	ft::swap(oneList, anotherList);
	std::cout << CYAN"Print dummy and oneList after swap them" << std::endl;
	lPrint(dummy, oneList);
	std::cout << CYAN"\nPrint otherDummy and anotherList after swap them" << std::endl;
	lPrint(otherDummy, anotherList);
	pressAnyKey();
}

void	lOperation_3()
{
	std::list<int> listOrig;
	ft::list<int> listMio;
	std::list<std::string> listOrig2;
	ft::list<std::string> listMio2;
	std::list<std::string>::iterator sit;
	ft::list<std::string>::iterator mysit;
	
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING OPERATION ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTest sort() function:" << RESET << std::endl;
	std::cout << CYAN"\nCreating two lists of string types with 'Pepe', 'Maria', 'Lidia' and 'Marta' values:\n" << RESET << std::endl;
	
	listOrig2.push_back ("Pepe");
	listOrig2.push_back ("Maria");
	listOrig2.push_back ("lidia");
	listOrig2.push_back ("Marta");

	listMio2.push_back ("Pepe");
	listMio2.push_back ("Maria");
	listMio2.push_back ("lidia");
	listMio2.push_back ("Marta");
	
	std::cout << CYAN"\nContent of lists listOrig2 and listMio2 without sorting:\n" << RESET << std::endl;
	lPrint(listOrig2, listMio2);
	std::cout << CYAN"\nSorting lists listOrig2 and listMio2 with sort() function:\n" << RESET << std::endl;
	listOrig2.sort();
	listMio2.sort();
	lPrint(listOrig2, listMio2);

	std::cout << CYAN"\nSorting the lists no matter UpperCase:\n" << RESET << std::endl;
	listOrig2.sort(c_insensitive);
	listMio2.sort(c_insensitive);
	lPrint(listOrig2, listMio2);

	pressAnyKey();
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING OPERATION ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the reverse() function:" << RESET << std::endl;
	std::cout << CYAN"\nAssign values from 11 to 20 to int list:\n" << RESET << std::endl;
	listOrig.clear();
	listMio.clear();
	for (int i = 11; i <= 20; ++i)
	{
		listOrig.push_back(i);
		listMio.push_back(i);
	}
	std::cout << CYAN"\nPrint out the lists of ints: " << std::endl;
	lPrint(listOrig, listMio);
	std::cout << CYAN"\nReversing the lists of ints: " << std::endl;
	listOrig.reverse();
	listMio.reverse();
	lPrint(listOrig, listMio);
	pressAnyKey();
}

void	lOperation_2()
{
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING OPERATION ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the unique() function:" << RESET << std::endl;
	std::cout << CYAN"\nCreate double list with { 2.99, 3.09, 2.75, 3.00, 3, 2.76, 76.82, 33.53, 86.79, 5.74, 20.95, 68.76, 78.43, 5.65, 86.85, 15.30 } values:\n" << RESET << std::endl;
	double mydoubles[]={ 2.99, 3.09, 2.75, 3.00, 3, 2.76, 76.82, 33.53, 86.79, 5.74, 20.95, 68.76, 78.43, 5.65, 86.85, 15.30 };
	std::list<double>	listOrig(mydoubles, mydoubles + 10);
	ft::list<double>	listMio(mydoubles, mydoubles + 10);
	std::cout << CYAN"Print listOrig amd listMio: " << std::endl;
	lPrint(listOrig, listMio);

	std::cout << CYAN"\nSorting list and remove equal values:\n" << RESET << std::endl;
	listOrig.sort();
	listOrig.unique();
	listMio.sort();
	listMio.unique();
	std::cout << CYAN"Print listOrig amd listMio: " << std::endl;
	lPrint(listOrig, listMio);

	std::cout << CYAN"\nRemove values with same integral part:\n" << RESET << std::endl;
	listOrig.unique(same_integral_part);
	listMio.unique(same_integral_part);

	std::cout << CYAN"Print listOrig amd listMio: " << std::endl;
	lPrint(listOrig, listMio);

	pressAnyKey();
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING OPERATION ELEMENTS ******************" << RESET << std::endl;
	std::cout << CYAN"\nPrevoius values of lists before removing\n" << RESET << std::endl;
	lPrint(listOrig, listMio);
	std::cout << CYAN"\nRemove values with difference < 5.0:\n" << RESET << std::endl;
	listOrig.unique(is_near());
	listMio.unique(is_near());
	std::cout << CYAN"Print listOrig amd listMio: " << std::endl;
	lPrint(listOrig, listMio);

	std::cout << ORANGE"\n\nTesting the merge() function:" << RESET << std::endl;
	std::cout << CYAN"\nCreate double list listOrig2 with {3.1, 2.2, 2.9} values and list listOrig3 with {3.7, 7.1, 1.4} values:\n" << RESET << std::endl;
	std::list<double>	listOrig2;
	std::list<double>	listOrig3;
	ft::list<double>	listMio2;
	ft::list<double>	listMio3;
	listOrig2.push_back (3.1);
	listOrig2.push_back (2.2);
	listOrig2.push_back (2.9);
	listOrig3.push_back (3.7);
	listOrig3.push_back (7.1);
	listOrig3.push_back (1.4);
	listMio2.push_back (3.1);
	listMio2.push_back (2.2);
	listMio2.push_back (2.9);
	listMio3.push_back (3.7);
	listMio3.push_back (7.1);
	listMio3.push_back (1.4);
	std::cout << CYAN"Print listOrig2 and ListMio2: " << std::endl;
	lPrint(listOrig2, listMio2);
	std::cout << CYAN"\nPrint listOrig3 and listMio3: " << std::endl;
	lPrint(listOrig3, listMio3);

	pressAnyKey();
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING OPERATION ELEMENTS ******************" << RESET << std::endl;
	std::cout << CYAN"\nSorting lists and merge listOrig3 into listOrig2:\n" << RESET << std::endl;
	listOrig2.sort();
	listOrig3.sort();
	listMio2.sort();
	listMio3.sort();
	listOrig2.merge(listOrig3);
	listMio2.merge(listMio3);
	std::cout << CYAN"Print listOrig2 and ListMio2: " << std::endl;
	lPrint(listOrig2, listMio2);
	std::cout << CYAN"\nPrint listOrig3 and listMio3: " << std::endl;
	lPrint(listOrig3, listMio3);

	std::cout << CYAN"\nPush '2.1' in listOrig3 and merge comparing only integral part:\n" << RESET << std::endl;
	listOrig3.push_back(2.1);
	listMio3.push_back(2.1);
	listOrig2.merge(listOrig3, compLess);
	listMio2.merge(listMio3, compLess);
	std::cout << CYAN"Print listOrig2 and ListMio2: " << std::endl;
	lPrint(listOrig2, listMio2);
	std::cout << CYAN"\nPrint listOrig3 and listMio3: " << std::endl;
	lPrint(listOrig3, listMio3);

	pressAnyKey("Press any key to continue with operation test part 3");
	lOperation_3();
}

void	lOperation()
{
	std::list<int> listOrig1;
	ft::list<int> listMio1;
  	std::list<int> listOrig2;
  	ft::list<int> listMio2;
	std::list<int>::iterator it;
	ft::list<int>::iterator myit;

	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING OPERATION ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the splice() function:" << RESET << std::endl;
	std::cout << CYAN"\nSet some initial values to listOrig1, listMio1 list" << RESET << std::endl;
	for (int i = 1; i <= 4; ++i)
	{
		listOrig1.push_back(i);
		listMio1.push_back(i);
	}
	lPrint(listOrig1, listMio1);
	
	std::cout << CYAN"Set some initial values to listOrig2, listMio2 list" << RESET << std::endl;
	for (int i = 1; i <= 3; ++i)
	{
		listOrig2.push_back(i * 10);
		listMio2.push_back(i * 10);
	}
	lPrint(listOrig2, listMio2);
    
	it = listOrig1.begin();
	it++;
	myit = listMio1.begin();
	myit++;
    std::cout << CYAN"\nSetting two iterators that point to the second element on listOrig1 and listMio1.\n"
	<< "Splice and bringing the entire listOrig2 to listOrig1 inserting starting from the second element of listOrig1 and listMio1" << RESET << std::endl;
	listOrig1.splice(it, listOrig2);
	listMio1.splice(myit, listMio2);
	std::cout << CYAN"Print listOrig1 and listMio1 " << std::endl;
	lPrint(listOrig1, listMio1);
	std::cout << CYAN"\nPrint listOrig2 and listMio2 " << std::endl;
	lPrint(listOrig2, listMio2);

	std::cout << CYAN"\nTransferring element pointed by the iterators with value of 2 into listOrig2 and listMio2 that was empty(single element):\n" << RESET << std::endl;
	listOrig2.splice(listOrig2.begin(), listOrig1, it);
	listMio2.splice(listMio2.begin(), listMio1, myit);
	std::cout << CYAN"Print listOrig1 and listMio1" << std::endl;
	lPrint(listOrig1, listMio1);
	std::cout << CYAN"\nPrint listOrig2 and listMio2" << std::endl;
	lPrint(listOrig2, listMio2);
	
	pressAnyKey();
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING OPERATION ELEMENTS ******************" << RESET << std::endl;
	std::cout << CYAN"Printing listOrig1 and listMio1 previuos to move elements" << std::endl;
	lPrint(listOrig1, listMio1);
	std::cout << CYAN"\nMoving an element with splice, pointed by the iterator -> element value = 30. moving elements in the own list (range element):\n" << RESET << std::endl;
	it = listOrig1.begin();
	ft::advance(it, 3);
	myit = listMio1.begin();
	ft::advance(myit, 3);
	listOrig1.splice(listOrig1.begin(), listOrig1, it, listOrig1.end());
	
	listMio1.splice(listMio1.begin(), listMio1, myit, listMio1.end());
	
	std::cout << CYAN"Print listOrig1 and listMio1" << std::endl;
	lPrint(listOrig1, listMio1);

	std::cout << ORANGE"\n\nTesting the remove() function:" << RESET << std::endl;
	std::cout << CYAN"\nRemoving '20' and '1':\n" << RESET << std::endl;
	listOrig1.remove(20);
	listOrig1.remove(1);
	listMio1.remove(20);
	listMio1.remove(1);
	std::cout << CYAN"Print out listOrig1 and listMio1" << std::endl;
	lPrint(listOrig1, listMio1);
	
	pressAnyKey();
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING OPERATION ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the remove_if() function:" << RESET << std::endl;
	int myints[]= {12, 55, 49, 63, 8, 7, 32, 43, 89, 3, 99};
	std::cout << CYAN"\nAssign {12, 55, 49, 63, 8, 7, 32, 43, 89, 3, 99} to listOrig1:\n" << RESET << std::endl;
	listOrig1.assign(myints, myints + 11);
	listMio1.assign(myints, myints + 11);
	std::cout << CYAN"Print listOrig1 and listMio1" << std::endl;
	lPrint(listOrig1, listMio1);

	std::cout << CYAN"\nRemoving values less than 10:\n" << RESET << std::endl;
	listOrig1.remove_if(compByDigit);
	listMio1.remove_if(compByDigit);
	std::cout << CYAN"Print out listOrig1 and listMio1" << std::endl;
	lPrint(listOrig1, listMio1);

	std::cout << CYAN"\nRemoving odd values:\n" << RESET << std::endl;
	listOrig1.remove_if(oddNumber());
	listMio1.remove_if(oddNumber());
	std::cout << CYAN"Print out listOrig1 and listMio1" << std::endl;
	lPrint(listOrig1, listMio1);
	pressAnyKey("Press any key to continue with operation test part 2");
	lOperation_2();
}



template <class T>
void lModifier_3(std::list<T> &listOrig, ft::list<T> &listMio, std::list<T> &listOrig2, ft::list<T> &listMio2)
{
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the swap() function:" << RESET << std::endl;
	std::cout << CYAN"\nSwaping content from listOrig to listOrig2:\n" << RESET << std::endl;
	
	std::cout << CYAN"Print listOrig before swap: " << std::endl;
	lPrint(listOrig, listMio);
	std::cout << GREEN"\nlistOrig size: " << listOrig.size() << ". listMio size: " << listMio.size() << RESET << std::endl;
	std::cout << CYAN"\nPrint listOrig2 before swap: " << std::endl;
	lPrint(listOrig2, listMio2);
	std::cout << GREEN"\nlistOrig2 size: " << listOrig2.size() << ". listMio2 size: " << listMio2.size() << RESET << std::endl << std::endl;

	listOrig.swap(listOrig2);
	listMio.swap(listMio2);
	std::cout << CYAN"Print listOrig after swap: " << std::endl;
	lPrint(listOrig, listMio);
	std::cout << GREEN"\nlistOrig size: " << listOrig.size() << ". listMio size: " << listMio.size() << RESET << std::endl;
	std::cout << CYAN"\nPrint listOrig2 after swap: " << std::endl;
	lPrint(listOrig2, listMio2);
	std::cout << GREEN"\nlistOrig2 size: " << listOrig2.size() << ". listMio2 size: " << listMio2.size() << RESET << std::endl << std::endl;

	pressAnyKey();
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the resize() function:" << RESET << std::endl;
	std::cout << CYAN"\nResize listOrig to 7, with zero-initialized values:\n" << RESET << std::endl;
	listOrig.resize(7);
	listMio.resize(7);
	lPrint(listOrig, listMio);

	std::cout << CYAN"\nResize listOrig to 10, with val = 42:\n" << RESET << std::endl;
	listOrig.resize(10, 42);
	listMio.resize(10, 42);
	lPrint(listOrig, listMio);

	std::cout << CYAN"\nResize listOrig to 5::\n" << RESET << std::endl;
	listOrig.resize(5);
	listMio.resize(5);
	lPrint(listOrig, listMio);

	std::cout << ORANGE"\n\nTesting the clear() function:" << RESET << std::endl;
	listOrig.clear();
	listMio.clear();
	std::cout << CYAN"Print listOrig after clear: " << std::endl;
	lPrint(listOrig, listMio);
	std::cout << GREEN"\nlistOrig size: " << listOrig.size() << ". listMio size: " << listMio.size() << RESET << std::endl;
	
	pressAnyKey();
}

template <class T>
void	lModifier_2(std::list<T> &listOrig, ft::list<T> &listMio, std::list<T> &listOrig2, ft::list<T> &listMio2)
{
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the insert() function" << RESET << std::endl;
	std::cout << CYAN"\nPrinting listOrig and listMio previuos to insert elements" << std::endl;
	lPrint(listOrig, listMio);
	std::cout << CYAN"\nInserting '81' in the listOrig2 position (single element insert):\n" << RESET << std::endl;
	std::list<int>::iterator it = listOrig.begin();
	it++;
	ft::list<int>::iterator myit = listMio.begin();
	myit++;
	listOrig.insert(it, 81);
	listMio.insert(myit, 81);
	lPrint(listOrig, listMio);

	std::cout << CYAN"\nInserting two elements with the value '17' after '81' (fill insert):\n" << RESET << std::endl;
	listOrig.insert(it, 2, 17);
	listMio.insert(myit, 2, 17);
	lPrint(listOrig, listMio);

	int myints1[]={1,2,3,4,5};
	std::cout << CYAN"\nInserting a range [first, last] {1,2,3,4,5} at position before the last one using a range[first, last] insertion\n" << RESET << std::endl;
	it = listOrig.end();
	it--;
	myit = listMio.end();
	myit--;
	listOrig2.assign(myints1, myints1 + 5);
	listMio2.assign(myints1, myints1 + 5);
	listOrig.insert(it, listOrig2.begin(), listOrig2.end());
	listMio.insert(myit, listMio2.begin(), listMio2.end());
	lPrint(listOrig, listMio);

	pressAnyKey();
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the erase() function:" << RESET << std::endl;
	std::cout << std::endl << ORANGE"lists previous to erase elements\n" << std::endl;
	lPrint(listOrig, listMio);
	std::cout << CYAN"\nErase listOrig2 by position so we erase a single element:\n" << RESET << std::endl;
	it = listOrig.begin();
	it++;
	myit = listMio.begin();
	myit++; 
	listOrig.erase(it);
	listMio.erase(myit);
	lPrint(listOrig, listMio);

	std::cout << CYAN"\nErase from listOrig2 position from fifth to eight position (range erase):\n" << RESET << std::endl;
	it = listOrig.begin();
	ft::advance(it,4);
	std::list<int>::iterator it2 = listOrig.begin();
	ft::advance(it2, 8);
	myit = listMio.begin();
	ft::advance(myit, 4);
	ft::list<int>::iterator myit2 = listMio.begin();
	ft::advance(myit2, 8);
	listOrig.erase(it, it2);
	listMio.erase(myit, myit2);
	lPrint(listOrig, listMio);

	pressAnyKey("Press any key to continue with the modifier test part 3... ");
	lModifier_3(listOrig, listMio, listOrig2, listMio2);
}

void	lModifier()
{
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTest on assign() function:" << RESET << std::endl;
	int myints[]={2021,5,19};
	std::list<int> listOrig;
  	std::list<int> listOrig2;
	ft::list<int> listMio;
  	ft::list<int> listMio2;
	std::cout << CYAN"\nAssign() in listOrig and listMio, with 8 ints of value 42:\n" << RESET << std::endl;
	listOrig.assign(8, 42);
	listMio.assign(8, 42);
	lPrint(listOrig, listMio);
	std::cout << CYAN"\nTesting range values assign() in listOrig2 and listMio2, from array {2021, 5, 19}:\n" << RESET << std::endl;
	listOrig2.assign(myints, myints + 3);
	listMio2.assign(myints, myints + 3);
	lPrint(listOrig2, listMio2);
	std::cout << CYAN"\nReassign listOrig with listOrig2 and listMio with listMio2\n" << RESET << std::endl;
	std::cout << GREEN"Before reassign. listOrig size: " << listOrig.size() << ". listMio size: " << listMio.size() << RESET << std::endl;
	listOrig.assign(listOrig2.begin(), listOrig2.end());
	listMio.assign(listMio2.begin(), listMio2.end());
	std::cout << GREEN"After reassign. listOrig size: " << listOrig.size() << ". listMio size: " << listMio.size() << RESET << std::endl << std::endl;
	lPrint(listOrig, listMio);

	std::cout << ORANGE"\n\nTesting the push_front() function:" << RESET << std::endl;
	std::cout << CYAN"\nAdd {241, 874} to listOrig and listMio\n" << RESET << std::endl;
	listOrig.push_front(241);
	listOrig.push_front(874);
	listMio.push_front(241);
	listMio.push_front(874);
	lPrint(listOrig, listMio);
	pressAnyKey();
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the push_back() function:" << RESET << std::endl;
	std::cout << CYAN"\nPrinting listOrig and listMio previuos to pushing back elements" << std::endl;
	lPrint(listOrig, listMio);
	std::cout << CYAN"\nAdd {42, 24} to listOrig and listMio\n" << RESET << std::endl;
	listOrig.push_back(42);
	listOrig.push_back(24);
	listMio.push_back(42);
	listMio.push_back(24);
	lPrint(listOrig, listMio);

	std::cout << ORANGE"\n\nTesting the pop_front() function:" << RESET << std::endl;
	std::cout << CYAN"\nRemoving front to listOrig:\n" << RESET << std::endl;
	listOrig.pop_front();
	listMio.pop_front();
	lPrint(listOrig, listMio);

	std::cout << ORANGE"\n\nTesting the pop_back() function:" << RESET << std::endl;
	std::cout << CYAN"\nRemoving back to listOrig:\n" << RESET << std::endl;
	listOrig.pop_back();
	listMio.pop_back();
	lPrint(listOrig, listMio);

	pressAnyKey("Press any key to continue with the modifier test part 2... ");
	lModifier_2(listOrig, listMio, listOrig2, listMio2);
}

/* Checking the access elements*/
void	lAccess()
{
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING ELEMENT ACCESS ******************" << RESET << std::endl;
	std::list<int> listOrig;
	ft::list<int> listMio;

	std::cout << CYAN"\nEmpty listOrig and listMio:\n" << RESET << std::endl;
	lPrint(listOrig, listMio);

	listOrig.push_back(12);
	listOrig.push_back(17);
	listOrig.push_back(43);
	listOrig.push_back(66);

	listMio.push_back(12);
	listMio.push_back(17);
	listMio.push_back(43);
	listMio.push_back(66);
	
	std::cout << ORANGE"\nAdding values to listOrig and listMio with values 12, 17, 43, 66 unsing push_back():\n" << RESET << std::endl;
	lPrint(listOrig, listMio);
	std::cout << GREEN"listOrig front() points to: " << RESET << listOrig.front() << RESET << std::endl;
	std::cout << GREEN"listOrig back() points to: " << RESET << listOrig.back() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN"listMio front() points to: " << RESET << listMio.front() << RESET << std::endl;
	std::cout << CYAN"listMio back() points to: " << RESET << listMio.back() << RESET << std::endl;

	std::cout << ORANGE"\nUsing element access to change the front value by adding listOrig.front() + listMio.front() :\n" << RESET << std::endl;
	listOrig.front() += listOrig.back();
	listMio.front() += listMio.back();

	std::cout << GREEN"listOrig.front() is now " << RESET << listOrig.front() << '\n' << RESET;
	std::cout << GREEN"listMio.front() is now " << RESET << listMio.front() << '\n' << RESET;
	lPrint(listOrig, listMio);
	pressAnyKey();
}

/* Checking the capacity elements */
void	lCapacity()
{
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING CAPACITY ELEMENTS ******************" << RESET << std::endl;
	int arrayInts[] = {12,14,69,47,11,32,99};
	std::list<int> listOrig(arrayInts, arrayInts + 7);
	ft::list<int> listMio(arrayInts, arrayInts + 7);
	std::cout << CYAN"\nPasing an array of ints to create the lists with {12,14,69,47,11,32,99}:\n" << RESET << std::endl;

	std::list<int> listOrig2;
	ft::list<int> listMio2;
	lPrint(listOrig, listMio);

	std::cout << CYAN"\nEmpty listOrig2 and listMio2:\n" << RESET << std::endl;
	lPrint(listOrig2, listMio2);

	std::cout << CYAN"\nTesting the empty() function with listOrig:\n" << RESET << std::endl;
	std::string isTrue;
	
	isTrue = (listOrig.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << GREEN"listOrig " << isTrue << RESET << std::to_string(listOrig.size()) << std::endl;

	isTrue = (listMio.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << CYAN"listMio " << isTrue << RESET << std::to_string(listMio.size()) << std::endl;

	std::cout << CYAN"\nTesting the empty() function with list1:\n" << RESET << std::endl;
	isTrue = (listOrig2.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << GREEN"listOrig2 " << isTrue << RESET << std::to_string(listOrig2.size()) << std::endl;

	isTrue = (listMio2.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << CYAN"listMio2 " << isTrue << RESET << std::to_string(listMio2.size()) << std::endl;
	
	std::list<std::string> listOrig3;
	ft::list<std::string> listMio3;
	std::list<MyClass*> listOrig4;
	ft::list<MyClass*> listMio4;
	std::list<bool> listOrig5;
	ft::list<bool> listMio5;
	std::cout << CYAN"\nTesting the max_size() function\n" << RESET << std::endl;
	std::cout << ORANGE"Print out the max sizes with different types using max_size() function" << RESET << std::endl;
	std::cout << GREEN"listOrig<int> max_size: \t\t" << RESET << listOrig.max_size() << RESET << std::endl;
	std::cout << GREEN"listMio<int> max_size: \t\t\t" << RESET << listMio.max_size() << RESET << std::endl;
	std::cout << GREEN"listOrig3<std::string> max_size: \t" << RESET << listOrig3.max_size() << RESET << std::endl;
	std::cout << GREEN"listMio3<std::string> max_size: \t" << RESET << listMio3.max_size() << RESET << std::endl;

	std::cout << GREEN"listOrig4<MyClass*> max_size: \t\t" << RESET << listOrig4.max_size() << RESET << std::endl;
	std::cout << GREEN"listMio4<MyClass*> max_size: \t\t" << RESET << listMio4.max_size() << RESET << std::endl;
	std::cout << GREEN"listOrig5<bool> max_size: \t\t" << RESET << listOrig5.max_size() << RESET << std::endl;
	std::cout << GREEN"listMio5<bool> max_size: \t\t" << RESET << listMio5.max_size() << RESET << std::endl;
	std::cout << std::endl;
	pressAnyKey();
}

/* Const Iterator check: reverse iterators an iterators as constants */
void	lCitCheck(const std::list<int>& listOrig, const ft::list<int>& listMio)
{
	std::list<int>::const_iterator citOrig = listOrig.begin();
	ft::list<int>::const_iterator citMio = listMio.begin();
	std::list<int>::const_reverse_iterator rcitOrig = listOrig.rbegin();
	ft::list<int>::const_reverse_iterator rcitMio = listMio.rbegin();

	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING CONST ITERATORS ******************" << RESET << std::endl;
	std::cout << CYAN"\nIterating from begin() to end() with const iterators:\n" << RESET << std::endl;
	if (listOrig.size() != listMio.size())
	{
		std::cout << ORANGE << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		std::cout << GREEN"Original List"RESET << std::endl;
		for (citOrig = listOrig.begin(); citOrig != listOrig.end(); citOrig++)
			std::cout << *citOrig << " ";
		std::cout << std::endl;
		std::cout << GREEN"\tMy List"RESET << std::endl;
		for (citMio = listMio.begin(); citMio != listMio.end(); citMio++)
			std::cout << *citMio << " ";
		std::cout << std::endl;
		
		std::cout << CYAN"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
		std::cout << GREEN"Original Const Reverse IT List"RESET << std::endl;
		for (size_t i = 0; i < listOrig.size(); i++)
			std::cout << ORANGE"\t" << *(rcitOrig++) << RESET << std::endl;;
		
		std::cout << GREEN"My Const Reverse IT List"RESET << std::endl;
		for (size_t i = 0; i < listMio.size(); i++)
			std::cout << "\t"CYAN << *(rcitMio++) << RESET << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << GREEN"Original Const IT List\t\tMy const IT List"RESET << std::endl;
			for (size_t i = 0; i < listOrig.size(); i++)
				std::cout << ORANGE"\t" << *(citOrig++) << "\t\t\t\t"CYAN << *(citMio++) << RESET << std::endl;;
		std::cout << std::endl;
		std::cout << CYAN"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
		std::cout << GREEN"Original Const Reverse IT List\tMy Const Reverse IT List"RESET << std::endl;
			for (size_t i = 0; i < listOrig.size(); i++)
				std::cout << ORANGE"\t" << *(rcitOrig++) << "\t\t\t\t"CYAN << *(rcitMio++) << RESET << std::endl;;
		std::cout << std::endl;
	}
	
	pressAnyKey();
}

/* Iterators check: reverse iterators and iterators */
void	lItCheck()
{
	system("clear");
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING ITERATORS ******************" << RESET << std::endl;
	int arrayInts[] = {12,14,69,47,11,32,99};
	std::list<int> listOrig(arrayInts, arrayInts + 7);
	ft::list<int> listMio(arrayInts, arrayInts + 7);
	std::cout << CYAN"\nPassing an array of ints to create the lists with {12,14,69,47,11,32,99}:\n" << RESET << std::endl;
	std::list<int>::iterator itOrig = listOrig.begin();
	ft::list<int>::iterator	itMio = listMio.begin();
	std::cout << GREEN"listOrig begin() points to: " << RESET << *itOrig << std::endl;
	std::cout << GREEN"listMio begin() points to: " << RESET << *itMio << std::endl;
	std::cout << std::endl;

	std::list<int>::reverse_iterator ritOrig = listOrig.rbegin();
	ft::list<int>::reverse_iterator ritMio = listMio.rbegin();
	std::cout << GREEN"list rbegin() points to: " << RESET << *ritOrig << std::endl;
	std::cout << GREEN"listMio rbegin() points to: " << RESET << *ritMio << std::endl;
	std::cout << std::endl;

	std::cout << CYAN"\nIterating from begin() to end():\n" << RESET << std::endl;
	lPrint(listOrig, listMio);

	std::cout << CYAN"\nIterating from rbegin() to rend() with iterators:\n" << RESET << std::endl;
	if (listOrig.size() == listMio.size())
	{
		std::cout << GREEN"Original Reverse IT List\tMy Reverse IT List"RESET << std::endl;
			for (size_t i = 0; i < listOrig.size(); i++)
				std::cout << ORANGE"\t" << *(ritOrig++) << "\t\t\t\t"CYAN << *(ritMio++) << RESET << std::endl;;
		std::cout << std::endl;
	}
	else
		lPrint(listOrig, listMio);

	pressAnyKey("Next Test: Const Iterator. Press any key to continue");
	lCitCheck(listOrig, listMio);

}

/* Entry point of List Tests */
 void listExec()
 {
	size_t n = 6;
	int val = 42;
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl;
	std::cout << YELLOW"Empty Constructor. Constructs an empty container, with no elements" << RESET << std::endl << std::endl;
	std::cout << CYAN"Empty lists\n" << RESET << std::endl;
	std::list<int> list1;
	ft::list<int> milist1;
	lPrint(list1, milist1);


    std::cout << YELLOW"Constructs a container with n elements (n, val). Each element is a copy of val." << RESET << std::endl << std::endl;
	std::cout << CYAN"Fill constructor with ("<< n <<", " << val << "):\n" << RESET << std::endl;
	std::list<int>	ListOrig(n, val);
	ft::list<int>	ListMio(n, val);
	lPrint(ListOrig, ListMio);
	
	std::cout << YELLOW"Constructs a container with as many elements as the range [first,last)" << RESET << std::endl << std::endl;
	int arrayInts[] = {9,6,55,43,77,98,100,2,29};
	std::cout << CYAN"\nRange Constructor passing an array of ints {9,6,55,43,77,98,100,2,29}(iterator range(array, array + 6)):\n" << RESET << std::endl;
	std::list<int> listOrig2(arrayInts, arrayInts + 6);
	ft::list<int> listMio2(arrayInts, arrayInts + 6);
	lPrint(listOrig2, listMio2);

	pressAnyKey();
	printTestHeader("LIST");
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl;
	std::cout << YELLOW"Constructs a container with a copy of each of the elements in x, in the same orde" << RESET << std::endl << std::endl;
	std::cout << CYAN"\nCopy constructor using listOrig2 and listMio2 to create listOrig3 and listMio3:\n" << RESET << std::endl;
	std::list<int> listOrig3(listOrig2);
	ft::list<int> listMio3(listMio2);
	lPrint(listOrig3, listMio3);

	std::cout << CYAN"\n Fill Constructor by pasing n elements without any val, so it will inizialite whit Zero val\n" << RESET << std::endl;
	std::list<int> listOrig4(10);
	ft::list<int> listMio4(10);
	lPrint(listOrig4, listMio4);

	
	std::cout << CYAN"\nCopy construcot: operator = Copying from listOrig3 and listMio3 to listOrig4 and listMio4:\n" << RESET << std::endl;
	listOrig4 = listOrig3;
	listMio4 = listMio3;
	lPrint(listOrig4, listMio4);
	pressAnyKey();
    
	lItCheck();

	lCapacity();

	lAccess();

	lModifier();
	
	lOperation();

	lRelational();

    pressAnyKey("Finishing LIST test. Press any key to return to the main menu");
 }
 
