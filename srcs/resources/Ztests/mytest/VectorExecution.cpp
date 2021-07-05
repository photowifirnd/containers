#include "testing.hpp"

/* Prints out the vector passed as argument: it sizes are equals it prints out in columns */
template <class T>
void	vPrint(std::vector<T> vectorOrig, ft::vector<T> vectorMio)
{
	typename std::vector<T>::iterator itOrig = vectorOrig.begin();
	typename ft::vector<T>::iterator itMio = vectorMio.begin();

	if (vectorOrig.size() != vectorMio.size())
	{
		std::cout << ORANGE << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		for (itOrig = vectorOrig.begin(); itOrig != vectorOrig.end(); itOrig++)
			std::cout << *itOrig << " ";
		std::cout << std::endl;
		
		for (itMio = vectorMio.begin(); itMio != vectorMio.end(); itMio++)
			std::cout << *itMio << " ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << GREEN"Original vector\t\t" << BLUE"My vector"RESET << std::endl;
			for (size_t i = 0; i < vectorOrig.size(); i++)
				std::cout << ORANGE"\t" << *(itOrig++) << "\t\t"CYAN << *(itMio++) << RESET << std::endl;;
		std::cout << std::endl;
	}
}

/***
 * *
 * */

/* Relational operations */
void	vRelational()
{
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING RELATIONAL OPERATORS ******************" << RESET << std::endl;
	std::cout << CYAN"\nCreating vectors with some data:\n" << RESET << std::endl;
	
	int	intsa[] = {9, 11, 22, 33};
	int	intsb[] = {33, 22, 11, 9};	
	
	std::vector<int> vector_a(intsa, intsa + 4);
	std::vector<int> vector_b(intsa, intsa + 4);
	std::vector<int> vector_c(intsb, intsb + 4);
	ft::vector<int> myVector_a(intsa, intsa + 4);
	ft::vector<int> myVector_b(intsa, intsa + 4);
	ft::vector<int> myVector_c(intsb, intsb + 4);

	std::cout << CYAN"Print vectors vector_a and myVector_a" << std::endl;
	vPrint(vector_a, myVector_a);
	std::cout << CYAN"Print vectors vector_b and myVector_b" << std::endl;
	vPrint(vector_b, myVector_b);
	std::cout << CYAN"Print vectors vector_c and myVector_c" << std::endl;
	vPrint(vector_c, myVector_c);

	std::cout << GREEN"\n\nTesting the relational operators:" << RESET << std::endl;
	std::cout << GREEN"\n\nvector output:\t\t\t\t\tMy vector output:" << RESET << std::endl;
	
	/* Checking the equality comparison */
	if (vector_a == vector_b) std::cout << ORANGE"vector_a and vector_b are equal\t\t\t";
	if (myVector_a == myVector_b) std::cout << CYAN"myVector_a and myVector_b are equal"RESET << std::endl;
	/* Checking Not-Equal comparison */
	if (vector_b != vector_c) std::cout << ORANGE << "vector_b and vector_c are not equal\t\t";
	if (myVector_b != myVector_c) std::cout << CYAN << "myVector_b and myVector_c are not equal"RESET << std::endl;;
	/* Checking less than comparison */
	if (vector_b < vector_c) std::cout << ORANGE << "vector_b is less than vector_c\t\t\t";
	if (myVector_b < myVector_c) std::cout << CYAN << "myVector_b is less than myVector_c"RESET << std::endl;;
	/* Checking greater than comparison */
	if (vector_c > vector_b) std::cout << ORANGE << "vector_c is greater than vector_b\t\t";
	if (myVector_c > myVector_b) std::cout << CYAN << "myVector_c is greater than myVector_b"RESET << std::endl;;
	/* Checking less than or equal comparison */
	if (vector_a <= vector_b) std::cout << ORANGE << "vector_a is less than or equal to vector_b\t";
	if (myVector_a <= myVector_b) std::cout << CYAN << "myVector_a is less than or equal to myVector_b"RESET << std::endl;;
	/* Checking greater than or equal comparison */
	if (vector_a >= vector_b) std::cout << ORANGE << "vector_a is greater than or equal to myVector_b\t";
	if (myVector_a >= myVector_b) std::cout << CYAN << "myVector_a is greater than or equal to myVector_b"RESET << std::endl;;

	pressAnyKey();
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING NON MEMBER SWAP FUNCTION ******************" << RESET << std::endl;
	std::cout << CYAN"\nConstructing vector whith some data on them\n" << RESET << std::endl;

	std::vector<int> dummy (2, 77);
	std::vector<int> otherDummy (8, 212);
	ft::vector<int> onevector (2, 77);
	ft::vector<int> anothervector (8, 212);

	std::cout << CYAN"Print dummy and oneVector before swap" << std::endl;
	vPrint(dummy, onevector);
	std::cout << CYAN"\nPrint otherDummy and anotherVector before swap them" << std::endl;
	vPrint(otherDummy, anothervector);

	std::cout << CYAN"\nUsing Swap() function to interchange vectors\n" << RESET << std::endl;
	std::swap(dummy,otherDummy);
	ft::swap(onevector, anothervector);
	std::cout << CYAN"Print dummy and oneVector after swap them" << std::endl;
	vPrint(dummy, onevector);
	std::cout << CYAN"\nPrint otherDummy and anotherVector after swap them" << std::endl;
	vPrint(otherDummy, anothervector);
	pressAnyKey();
}

/* Modifier functions test 3/3 */
template <class T>
void vModifier_3(std::vector<T> &vectorOrig, ft::vector<T> &vectorMio, std::vector<T> &vectorOrig2, ft::vector<T> &vectorMio2)
{
	system("clear");
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the swap() function:" << RESET << std::endl;
	std::cout << CYAN"\nSwaping content from vectorOrig to vectorOrig2:\n" << RESET << std::endl;
	
	std::cout << CYAN"Print vectorOrig and vectorMio before swap: " << std::endl;
	vPrint(vectorOrig, vectorMio);
	std::cout << GREEN"\nvectorOrig size: " << vectorOrig.size() << ". vectorMio size: " << vectorMio.size() << RESET << std::endl;
	std::cout << CYAN"\nPrint vectorOrig2 and vectorMio2 before swap: " << std::endl;
	vPrint(vectorOrig2, vectorMio2);
	std::cout << GREEN"\nvectorOrig2 size: " << vectorOrig2.size() << ". vectorMio2 size: " << vectorMio2.size() << RESET << std::endl << std::endl;

	vectorOrig.swap(vectorOrig2);
	vectorMio.swap(vectorMio2);
	std::cout << CYAN"Print vectorOrig and vectorMio after swap: " << std::endl;
	vPrint(vectorOrig, vectorMio);
	std::cout << GREEN"\nvectorOrig size: " << vectorOrig.size() << ". vectorMio size: " << vectorMio.size() << RESET << std::endl;
	std::cout << CYAN"\nPrint vectorOrig2 and vectorMio2 after swap: " << std::endl;
	vPrint(vectorOrig2, vectorMio2);
	std::cout << GREEN"\nvectorOrig2 size: " << YELLOW << vectorOrig2.size() << WHITE" - " << CYAN"vectorMio2 size: " << YELLOW << vectorMio2.size() << RESET << std::endl << std::endl;

	pressAnyKey();
	system("clear");
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the resize() function:" << RESET << std::endl;
	std::cout << CYAN"\nResize vectorOrig to 7, with zero-initialized values:\n" << RESET << std::endl;
	vectorOrig.resize(7);
	vectorMio.resize(7);
	vPrint(vectorOrig, vectorMio);

	std::cout << CYAN"\nResize vectorOrig to 10, with val = 42:\n" << RESET << std::endl;
	vectorOrig.resize(10, 42);
	vectorMio.resize(10, 42);
	vPrint(vectorOrig, vectorMio);

	std::cout << CYAN"\nResize vectorOrig to 5:\n" << RESET << std::endl;
	vectorOrig.resize(5);
	vectorMio.resize(5);
	vPrint(vectorOrig, vectorMio);

	std::cout << ORANGE"\n\nTesting the clear() function:" << RESET << std::endl;
	vectorOrig.clear();
	vectorMio.clear();
	std::cout << CYAN"Print vectorOrig after clear\n" << std::endl;
	vPrint(vectorOrig, vectorMio);
	std::cout << std::endl << GREEN"\nvectorOrig size: " << YELLOW << vectorOrig.size() << WHITE" - " << CYAN"vectorMio size: " << YELLOW << vectorMio.size() << RESET << std::endl;
	
	pressAnyKey();
}

/* Modifier functions test 2/3 */
template <class T>
void	vModifier_2(std::vector<T> &vectorOrig, ft::vector<T> &vectorMio, std::vector<T> &vectorOrig2, ft::vector<T> &vectorMio2)
{
	system("clear");
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the insert() function" << RESET << std::endl;
	std::cout << std::endl << ORANGE"Vectors previoues to insert elements\n" << std::endl;
	vPrint(vectorOrig, vectorMio);
	std::cout << CYAN"\nInserting '81' in the vectorOrig2 by position so we simple insert a single element\n" << RESET << std::endl;
	std::vector<int>::iterator it = vectorOrig.begin();
	it++;
	ft::vector<int>::iterator myit = vectorMio.begin();
	myit++;
	vectorOrig.insert(it, 81);
	vectorMio.insert(myit, 81);
	vPrint(vectorOrig, vectorMio);

	std::cout << CYAN"\nInserting two elements with the value '17' before '81' fill insertion\n" << RESET << std::endl;
	vectorOrig.insert(it, 2, 17);
	vectorMio.insert(myit, 2, 17);
	vPrint(vectorOrig, vectorMio);

	int myints1[]={1,2,3,4,5};
	std::cout << CYAN"\nInserting a range [first, last] {1,2,3,4,5} at position before the last one using a range[first, last] insertion\n" << RESET << std::endl;
	it = vectorOrig.end();
	it--;
	myit = vectorMio.end();
	myit--;
	vectorOrig2.assign(myints1, myints1 + 5);
	vectorMio2.assign(myints1, myints1 + 5);
	vectorOrig.insert(it, vectorOrig2.begin(), vectorOrig2.end());
	vectorMio.insert(myit, vectorMio2.begin(), vectorMio2.end());
	vPrint(vectorOrig, vectorMio);

	pressAnyKey();
	system("clear");
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nTesting the erase() function:" << RESET << std::endl;
	std::cout << std::endl << ORANGE"Vectors previous to erase elements\n" << std::endl;
	vPrint(vectorOrig, vectorMio);
	std::cout << CYAN"\nErase vectorOrig2 by position so we erase a single element:\n" << RESET << std::endl;
	it = vectorOrig.begin();
	it++;
	myit = vectorMio.begin();
	myit++; 
	vectorOrig.erase(it);
	vectorMio.erase(myit);
	vPrint(vectorOrig, vectorMio);

	std::cout << CYAN"\nErase from fourth position to eight position (range erase):\n" << RESET << std::endl;
	it = vectorOrig.begin();
	ft::advance(it,4);
	std::vector<int>::iterator it2 = vectorOrig.begin();
	ft::advance(it2, 8);
	myit = vectorMio.begin();
	ft::advance(myit, 4);
	ft::vector<int>::iterator myit2 = vectorMio.begin();
	ft::advance(myit2, 8);
	vectorOrig.erase(it, it2);
	vectorMio.erase(myit, myit2);
	vPrint(vectorOrig, vectorMio);

	pressAnyKey("Press any key to continue with the modifier test part 3... ");
	vModifier_3(vectorOrig, vectorMio, vectorOrig2, vectorMio2);
}

/* Modifier fuctions 1/3 */
void	vModifier()
{
	system("clear");
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;

	std::cout << ORANGE"\n\nTest on assign() function:" << RESET << std::endl;
	int myints[]={2021,5,19};
	std::vector<int> vectorOrig;
  	std::vector<int> vectorOrig2;
	ft::vector<int> vectorMio;
  	ft::vector<int> vectorMio2;
	std::cout << CYAN"\nAssign() in vectorOrig and vectorMio, with 8 ints of value 42:\n" << RESET << std::endl;
	vectorOrig.assign(8, 42);
	vectorMio.assign(8, 42);
	vPrint(vectorOrig, vectorMio);
	std::cout << CYAN"\nTesting range values assign() in vectorOrig2 and vectorMio2, from array {2021, 5, 19}:\n" << RESET << std::endl;
	vectorOrig2.assign(myints, myints + 3);
	vectorMio2.assign(myints, myints + 3);
	vPrint(vectorOrig2, vectorMio2);
	std::cout << CYAN"\nReassign vectorOrig with vectorOrig2 and vectorMio with vectorMio2\n" << RESET << std::endl;
	std::cout << GREEN"Before reassign. vectorOrig size: " << vectorOrig.size() << ". vectorMio size: " << vectorMio.size() << RESET << std::endl;
	vectorOrig.assign(vectorOrig2.begin(), vectorOrig2.end());
	vectorMio.assign(vectorMio2.begin(), vectorMio2.end());
	std::cout << GREEN"After reassign. vectorOrig size: " << vectorOrig.size() << ". vectorMio size: " << vectorMio.size() << RESET << std::endl << std::endl;
	vPrint(vectorOrig, vectorMio);

	std::cout << ORANGE"\n\nTesting the push_back() function:" << RESET << std::endl;
	std::cout << CYAN"\nAdd {42, 24} to vectorOrig and vectorMio\n" << RESET << std::endl;
	vectorOrig.push_back(42);
	vectorOrig.push_back(24);
	vectorMio.push_back(42);
	vectorMio.push_back(24);
	vPrint(vectorOrig, vectorMio);
	
	pressAnyKey();

	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << std::endl << ORANGE"Vectors before poping back an element\n" << std::endl;
	vPrint(vectorOrig, vectorMio);
	std::cout << ORANGE"\n\nTesting the pop_back() function:" << RESET << std::endl;
	std::cout << CYAN"\nRemoving back to vectorOrig:\n" << RESET << std::endl;
	vectorOrig.pop_back();
	vectorMio.pop_back();
	vPrint(vectorOrig, vectorMio);

	pressAnyKey("Press any key to continue with the modifier test part 2... ");
	vModifier_2(vectorOrig, vectorMio, vectorOrig2, vectorMio2);
}

/* Checking the access elements*/
void	vAccess()
{
	system("clear");
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING ELEMENT ACCESS ******************" << RESET << std::endl;
	std::vector<int> vectorOrig;
	ft::vector<int> vectorMio;

	std::cout << CYAN"\nEmpty vectorOrig and vectorMio:\n" << RESET << std::endl;
	vPrint(vectorOrig, vectorMio);

	vectorOrig.push_back(12);
	vectorOrig.push_back(17);
	vectorOrig.push_back(43);
	vectorOrig.push_back(66);

	vectorMio.push_back(12);
	vectorMio.push_back(17);
	vectorMio.push_back(43);
	vectorMio.push_back(66);
	
	std::cout << GREEN"vectorOrig front() points to: \t" << RESET << vectorOrig.front() << RESET << std::endl;
	std::cout << GREEN"vectorOrig back() points to: \t" << RESET << vectorOrig.back() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN"vectorMio front() points to: \t" << RESET << vectorMio.front() << RESET << std::endl;
	std::cout << CYAN"vectorMio back() points to: \t" << RESET << vectorMio.back() << RESET << std::endl;


	std::cout << std::endl << ORANGE"Adding values to vectorOrig and vectorMio with values 12, 17, 43, 66 unsing push_back():\n" << RESET << std::endl;
	vPrint(vectorOrig, vectorMio);
	std::cout << std::endl << ORANGE"Modifying values of myVector ussing [] operator"
						   << "Actual value of element[1] = 17 -> changing it to element[1] = 9 \n" << std::endl;
	vectorOrig[1] = 9;
	vectorMio[1] = 9;
	vPrint(vectorOrig, vectorMio);
	std::cout << GREEN"vectorOrig front() still points to \t" << RESET << vectorOrig.front() << RESET << std::endl;
	std::cout << GREEN"vectorOrig back() still points to \t" << RESET << vectorOrig.back() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << CYAN"vectorMio front() still points to \t" << RESET << vectorMio.front() << RESET << std::endl;
	std::cout << CYAN"vectorMio back() still points to \t" << RESET << vectorMio.back() << RESET << std::endl;

	std::cout << ORANGE"\nUsing element access to change the front value by adding vectorOrig.front() + vectorMio.front() :\n" << RESET << std::endl;
	vectorOrig.front() += vectorOrig.back();
	vectorMio.front() += vectorMio.back();

	std::cout << GREEN"vectorOrig.front() now points to\t" << RESET << vectorOrig.front() << std::endl << RESET;
	std::cout << GREEN"vectorMio.front() now points to\t\t" << RESET << vectorMio.front() << std::endl << RESET;
	vPrint(vectorOrig, vectorMio);
	std::cout << std::endl << ORANGE"changing all values of vectorOrig and vectorMio through a for loop using [] operator\n" << std::endl;
	for (size_t i = 0; i < vectorOrig.size(); i++)
		vectorOrig[i] = i * 5;
	for (size_t i = 0; i < vectorMio.size(); i++)
		vectorMio[i] = i * 5;
	vPrint(vectorOrig, vectorMio);
	pressAnyKey();
}

/* Checking the capacity elements */
void	vCapacity()
{
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING CAPACITY ELEMENTS ******************" << RESET << std::endl;
	int arrayInts[] = {12,14,69,47,11,32,99};
	std::vector<int> vectorOrig(arrayInts, arrayInts + 7);
	ft::vector<int> vectorMio(arrayInts, arrayInts + 7);
	std::cout << CYAN"\nPasing an array of ints to create the vectors with {12,14,69,47,11,32,99}:\n" << RESET << std::endl;

	std::vector<int> vectorOrig2;
	ft::vector<int> vectorMio2;
	vPrint(vectorOrig, vectorMio);

	std::cout << CYAN"\nEmpty vectorOrig2 and vectorMio2:\n" << RESET << std::endl;
	vPrint(vectorOrig2, vectorMio2);

	std::cout << CYAN"\nTesting the empty() function with vectorOrig and vectorMio:\n" << RESET << std::endl;
	std::string isTrue;
	
	isTrue = (vectorOrig.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << GREEN"vectorOrig " << isTrue << RESET << std::to_string(vectorOrig.size()) << std::endl;

	isTrue = (vectorMio.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << CYAN"vectorMio " << isTrue << RESET << std::to_string(vectorMio.size()) << std::endl;

	std::cout << CYAN"\nTesting the empty() function with vectorOrig1 and vectorMio1:\n" << RESET << std::endl;
	isTrue = (vectorOrig2.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << GREEN"vectorOrig2 " << isTrue << RESET << std::to_string(vectorOrig2.size()) << std::endl;

	isTrue = (vectorMio2.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << CYAN"vectorMio2 " << isTrue << RESET << std::to_string(vectorMio2.size()) << std::endl;
	
	std::vector<std::string> vectorOrig3;
	ft::vector<std::string> vectorMio3;
	std::vector<MyClass*> vectorOrig4;
	ft::vector<MyClass*> vectorMio4;
	std::vector<bool> vectorOrig5;
	ft::vector<bool> vectorMio5;
	std::cout << CYAN"\nTesting the max_size() function\n" << RESET << std::endl;
	std::cout << ORANGE"Print out the max sizes with different types using max_size() function" << RESET << std::endl;
	std::cout << GREEN"vectorOrig<int> max_size: \t\t" << RESET << vectorOrig.max_size() << RESET << std::endl;
	std::cout << GREEN"vectorMio<int> max_size: \t\t" << RESET << vectorMio.max_size() << RESET << std::endl;
	std::cout << GREEN"vectorOrig3<std::string> max_size: \t" << RESET << vectorOrig3.max_size() << RESET << std::endl;
	std::cout << GREEN"vectorMio3<std::string> max_size: \t" << RESET << vectorMio3.max_size() << RESET << std::endl;

	std::cout << GREEN"vectorOrig4<MyClass*> max_size: \t" << RESET << vectorOrig4.max_size() << RESET << std::endl;
	std::cout << GREEN"vectorMio4<MyClass*> max_size: \t\t" << RESET << vectorMio4.max_size() << RESET << std::endl;
	std::cout << GREEN"vectorOrig5<bool> max_size: \t\t" << RESET << vectorOrig5.max_size() << RESET << std::endl;
	std::cout << GREEN"vectorMio5<bool> max_size: \t\t" << RESET << vectorMio5.max_size() << RESET << std::endl;
	std::cout << std::endl;
	pressAnyKey();
}

/* Const Iterator check: reverse iterators an iterators as constants */
void	vCitCheck(const std::vector<int>& vectorOrig, const ft::vector<int>& vectorMio)
{
	std::vector<int>::const_iterator citOrig = vectorOrig.begin();
	ft::vector<int>::const_iterator citMio = vectorMio.begin();
	std::vector<int>::const_reverse_iterator rcitOrig = vectorOrig.rbegin();
	ft::vector<int>::const_reverse_iterator rcitMio = vectorMio.rbegin();

	system("clear");
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING CONST ITERATORS ******************" << RESET << std::endl << std::endl;
	std::cout << CYAN"\nIterating from begin() to end() with const iterators:\n" << RESET << std::endl;
	if (vectorOrig.size() != vectorMio.size())
	{
		std::cout << ORANGE << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		std::cout << GREEN"Original vector"RESET << std::endl;
		for (citOrig = vectorOrig.begin(); citOrig != vectorOrig.end(); citOrig++)
			std::cout << *citOrig << " ";
		std::cout << std::endl;
		std::cout << GREEN"\tMy vector"RESET << std::endl;
		for (citMio = vectorMio.begin(); citMio != vectorMio.end(); citMio++)
			std::cout << *citMio << " ";
		std::cout << std::endl;
		
		std::cout << CYAN"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
		std::cout << GREEN"Original Const Reverse IT vector"RESET << std::endl;
		for (size_t i = 0; i < vectorOrig.size(); i++)
			std::cout << ORANGE"\t" << *(rcitOrig++) << RESET << std::endl;;
		
		std::cout << GREEN"My Const Reverse IT vector"RESET << std::endl;
		for (size_t i = 0; i < vectorMio.size(); i++)
			std::cout << "\t"CYAN << *(rcitMio++) << RESET << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << GREEN"Original Const IT vector\t\tMy const IT vector"RESET << std::endl;
			for (size_t i = 0; i < vectorOrig.size(); i++)
				std::cout << ORANGE"\t" << *(citOrig++) << "\t\t\t\t"CYAN << *(citMio++) << RESET << std::endl;;
		std::cout << std::endl;
		std::cout << CYAN"\nIterating from rbegin() to rend() with const iterators:\n" << RESET << std::endl;
		std::cout << GREEN"Original Const Reverse IT vector\tMy Const Reverse IT vector"RESET << std::endl;
			for (size_t i = 0; i < vectorOrig.size(); i++)
				std::cout << ORANGE"\t" << *(rcitOrig++) << "\t\t\t\t"CYAN << *(rcitMio++) << RESET << std::endl;;
		std::cout << std::endl;
	}
	
	pressAnyKey();
}

/* Iterators check: reverse iterators and iterators */
void	vItCheck()
{
	system("clear");
	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING ITERATORS ******************" << RESET << std::endl << std::endl;
	int arrayInts[] = {12,14,69,47,11,32,99};
	std::vector<int> vectorOrig(arrayInts, arrayInts + 7);
	ft::vector<int> vectorMio(arrayInts, arrayInts + 7);
	std::cout << CYAN"Passing an array of ints to create the vectors with {12,14,69,47,11,32,99}:\n" << RESET << std::endl;
	std::vector<int>::iterator itOrig = vectorOrig.begin();
	ft::vector<int>::iterator	itMio = vectorMio.begin();
	std::cout << GREEN"vectorOrig begin() points to: " << RESET << *itOrig << std::endl;
	std::cout << GREEN"vectorMio begin() points to: " << RESET << *itMio << std::endl;
	std::cout << std::endl;

	std::vector<int>::reverse_iterator ritOrig = vectorOrig.rbegin();
	ft::vector<int>::reverse_iterator ritMio = vectorMio.rbegin();
	std::cout << GREEN"vector rbegin() points to: " << RESET << *ritOrig << std::endl;
	std::cout << GREEN"vectorMio rbegin() points to: " << RESET << *ritMio << std::endl;
	std::cout << std::endl;

	std::cout << CYAN"\nIterating from begin() to end():\n" << RESET << std::endl;
	vPrint(vectorOrig, vectorMio);

	std::cout << CYAN"\nIterating from rbegin() to rend() with iterators:\n" << RESET << std::endl;
	if (vectorOrig.size() == vectorMio.size())
	{
		std::cout << GREEN"Original Reverse IT vector\tMy Reverse IT vector"RESET << std::endl;
			for (size_t i = 0; i < vectorOrig.size(); i++)
				std::cout << ORANGE"\t" << *(ritOrig++) << "\t\t\t\t"CYAN << *(ritMio++) << RESET << std::endl;;
		std::cout << std::endl;
	}
	else
		vPrint(vectorOrig, vectorMio);

	pressAnyKey("Next Test: Const Iterator. Press any key to continue");
	vCitCheck(vectorOrig, vectorMio);

}

/* Entry point of Vector Tests */
 void vectorExec()
 {
	size_t n = 6;
	int val = 42;
	printTestHeader("VECTOR");
    
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl << std::endl;
	std::cout << YELLOW"Empty Constructor. Constructs an empty container, with no elements" << RESET << std::endl << std::endl;
	std::cout << CYAN"Empty vector: emptyVector original and miEmptyVector my implementation\n" << RESET << std::endl;
	std::vector<int> emptyVector;
	ft::vector<int> miEmptyVector;
	vPrint(emptyVector, miEmptyVector);


    std::cout << YELLOW"Constructs a container with n elements (n, val). Each element is a copy of val." << RESET << std::endl << std::endl;
	std::cout << CYAN"Fill constructor with ("<< n <<", " << val << "):\n" << RESET << std::endl;
	std::vector<int>	vectorOrig(n, val);
	ft::vector<int> vectorMio(n, val);
	vPrint(vectorOrig, vectorMio);
	
	std::cout << YELLOW"Constructs a container with as many elements as the range [first,last)" << RESET << std::endl;
	int arrayInts[] = {9,6,55,43,77,98,100,2,29};
	std::cout << CYAN"\nRange Constructor passing an array of ints {9,6,55,43,77,98,100,2,29} (iterator range(array, array + 6)):\n" << RESET << std::endl;
	std::vector<int> vectorOrig2(arrayInts, arrayInts + 6);
	ft::vector<int> vectorMio2(arrayInts, arrayInts + 6);
	vPrint(vectorOrig2, vectorMio2);

	pressAnyKey();

	printTestHeader("VECTOR");
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl << std::endl;
	std::cout << YELLOW"Constructs a container with a copy of each of the elements in x, in the same orde" << RESET << std::endl;
	std::cout << CYAN"\nCopy constructor using vectorOrig2 and vectorMio2 to create vectorOrig3 and vectorMio3:\n" << RESET << std::endl;
	std::vector<int> vectorOrig3(vectorOrig2);
	ft::vector<int> vectorMio3(vectorMio2);
	vPrint(vectorOrig3, vectorMio3);

	std::cout << CYAN"\nFill Constructor by pasing n (in this case n = 8) elements without any val, so it will inizialite whit Zero val\n" << RESET << std::endl;
	std::vector<int> vectorOrig4(8);
	ft::vector<int> vectorMio4(8);
	vPrint(vectorOrig4, vectorMio4);
	
	std::cout << CYAN"\nCopy construcot: operator = Copying from vectorOrig3 and vectorMio3 to vectorOrig4 and vectorMio4:\n" << RESET << std::endl;
	vectorOrig4 = vectorOrig3;
	vectorMio4 = vectorMio3;
	vPrint(vectorOrig4, vectorMio4);
	
	pressAnyKey();
    
	vItCheck();

	vCapacity();

	vAccess();

	vModifier();

	vRelational();

    pressAnyKey("Finishing VECTOR test. Press any key to return to the main menu");
 }