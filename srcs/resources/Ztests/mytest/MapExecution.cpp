#include "testing.hpp"

template <class T, class X>
void	mPrint(std::map<T, X> mapOrig, ft::map<T, X> mapMio)
{
	typename std::map<T, X>::iterator itOrig = mapOrig.begin();
	typename ft::map<T, X>::iterator itMio = mapMio.begin();

	if (mapOrig.size() != mapMio.size())
	{
        std::cout << "Sizes after: " << mapOrig.size() << " - " << mapMio.size() << std::endl;
		std::cout << RED << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		for (itOrig = mapOrig.begin(); itOrig != mapOrig.end(); itOrig++)
			std::cout << itOrig->first << " -> " << itOrig->second << ", ";
		std::cout << std::endl;
		
		for (itMio = mapMio.begin(); itMio != mapMio.end(); itMio++)
            std::cout << itMio->first << " -> " << itMio->second << ", ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << GREEN"Original map\t\tMy map"RESET << std::endl;
			for (size_t i = 0; i < mapOrig.size(); i++, itOrig++, itMio++)
				std::cout << ORANGE"\t" << itOrig->first  << " -> " << itOrig->second << "\t\t"CYAN  << itMio->first  << " -> " << itMio->second << RESET << std::endl;;
		std::cout << std::endl;
	}
}

template <class T, class X>
void	mPrintReverse(std::map<T, X> mapOrig, ft::map<T, X> mapMio)
{
	typename std::map<T, X>::reverse_iterator itOrig = mapOrig.rbegin();
	typename ft::map<T, X>::reverse_iterator itMio = mapMio.rbegin();

	if (mapOrig.size() != mapMio.size())
	{
		std::cout << ORANGE << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		for (itOrig = mapOrig.rbegin(); itOrig != mapOrig.rend(); itOrig++)
			std::cout << itOrig->first << " -> " << itOrig->second << ", ";
		std::cout << std::endl;
		
		for (itMio = mapMio.rbegin(); itMio != mapMio.rend(); itMio++)
            std::cout << itMio->first << " -> " << itMio->second << ", ";
		std::cout << std::endl;
	}
	else
	{
		std::cout << GREEN"Original map\t\tMy map"RESET << std::endl;
			for (size_t i = 0; i < mapOrig.size(); i++, itOrig++, itMio++)
				std::cout << ORANGE"\t" << itOrig->first  << " -> " << itOrig->second << "\t\t"CYAN  << itMio->first  << " -> " << itMio->second << RESET << std::endl;;
		std::cout << std::endl;
	}
}

/***
 * 
 * */

/* Relational Operator tests */
template <class T, class X>
void	mRelational(std::map<T, X> mapOrig, ft::map<T, X> mapMio)
{
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING RELATIONAL OPERATORS ******************" << RESET << std::endl;
	
    std::map<char,int> foo(mapOrig);
	ft::map<char,int> fooMio(mapMio);
	
	std::cout << ORANGE"\nPrinting mapOrig and mapMio:\n" << RESET << std::endl;
	mPrint(mapOrig, mapMio);
    std::cout << ORANGE"\nPrinting foo and fooMio:\n" << RESET << std::endl;
	mPrint(foo, fooMio);
    
    /* Checking the equality comparison */
	if (mapOrig == foo) std::cout << ORANGE << "mapOrig and foo are equal\t";
	if (mapMio == fooMio) std::cout << CYAN << "mapMio and fooMio are equal\n";
    
    /* Checking Not-Equal comparison */
    if (mapOrig != foo) std::cout << ORANGE << "mapOrig and foo are not equal\t\t\t" << RESET;
    if (mapMio != fooMio) std::cout << CYAN << "mapMio and fooMio are not equal\n" << RESET;

    /* Checking less than comparison */
	if (mapOrig < foo) std::cout << ORANGE << "mapOrig is less than foo\t\t" << RESET;
    if (mapMio < fooMio) std::cout << CYAN << "mapMio is less than fooMio\n" << RESET;
	
    /* Checking greater than comparison */
    if (mapOrig > foo) std::cout << ORANGE << "mapOrig is greater than foo\t\t" << RESET;
	if (mapMio > fooMio) std::cout << CYAN << "mapMio is greater than fooMio\n" << RESET;
    
    /* Checking less than or equal comparison */
    if (mapOrig <= foo) std::cout << ORANGE << "mapOrig is less than or equal to foo\t\t" << RESET;
	if (mapMio <= fooMio) std::cout << CYAN << "mapMio is less than or equal to fooMio\n" << RESET;
    
    /* Checking greater than or equal comparison */
    if (mapOrig >= foo) std::cout << ORANGE << "mapOrig is greater than or equal to foo\t\t" << RESET;
    if (mapMio >= fooMio) std::cout << CYAN << "mapMio is greater than or equal to fooMio\n" << RESET;

    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING RELATIONAL OPERATORS ******************" << RESET << std::endl;

    std::map<char,int> toSwapOrig;
    ft::map<char,int> toSwapMio;
	std::cout << ORANGE"\nTesting non-Member swap function with (MapOrig -> toSwapOrig) and (mapMio -> toSwapMio):" << RESET << std::endl;
    
    toSwapOrig['X'] = 1500;
    toSwapMio['X'] = 1500;
    std::cout << ORANGE"\nPrinting mapOrig and mapMio before swapping:\n" << RESET << std::endl;
	mPrint(mapOrig, mapMio);
    std::cout << ORANGE"\nPrinting toSwapOrig and toSwapMio before swapping:\n" << RESET << std::endl;
	mPrint(toSwapOrig, toSwapMio);

	std::swap(mapOrig, toSwapOrig);
	ft::swap(mapMio, toSwapMio);
	
	std::cout << ORANGE"\nPrinting mapOrig and mapMio after swapping:\n" << RESET << std::endl;
	mPrint(mapOrig, mapMio);
    std::cout << ORANGE"\nPrinting toSwapOrig and toSwapMio after swapping:\n" << RESET << std::endl;
	mPrint(toSwapOrig, toSwapMio);
	pressAnyKey();
}

/* Operation tests */
template <class T, class X>
void	mOperations(std::map<T, X> mapOrig, ft::map<T, X> mapMio)
{
	system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING OPERATIONS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\nFind(): Searches the container for an element with a key equivalent" << std::endl
              << "to k and returns an iterator to it if found, otherwise it returns an iterator to map::end" << RESET << std::endl;
	
	std::map<char,int>::iterator it;
	ft::map<char,int>::iterator myit;

	mPrint(mapOrig, mapMio);

	std::cout << ORANGE"\nFind 'B' with function and erase it:\n" << RESET << std::endl;

	it = mapOrig.find('B');
	if (it != mapOrig.end())
		mapOrig.erase (it);
	myit = mapMio.find('B');
	if (myit != mapMio.end())
		mapMio.erase (myit);
	mPrint(mapOrig, mapMio);

	std::cout << ORANGE"\nCount(): Searches the container for elements with a key equivalent to k and returns" << std::endl
              << "the number of matches." << std::endl 
              << "Because all elements in a map container are unique, the function can only return 1 " << std::endl
              << "(if the element is found) or zero (otherwise)." << RESET << std::endl;
	
    std::string is_present = "";

	is_present = mapOrig.count('F') ? "" : "not";
	std::cout << GREEN"The element 'F' is " << is_present << " presnet in mapOrig" << std::endl;

    is_present = mapMio.count('F') ? "" : "not";
	std::cout << GREEN"The element 'F' is " << is_present << " present in mapMio" << std::endl;
    
    is_present = mapOrig.count('C') ? "" : "not";
	std::cout << GREEN"The element 'C' is " << is_present << " presnet in mapOrig" << std::endl;
	
    is_present = mapMio.count('C') ? "" : "not";
	std::cout << GREEN"The element 'C' is " << is_present << " present in mapMio" << std::endl;

	std::cout << ORANGE"\nChecking upper_bound() and lowe_bound functions:" << RESET << std::endl;
	
	mPrint(mapOrig, mapMio);

	std::cout << ORANGE"\nUse functions to erase from 'B' to 'D':\n" << RESET << std::endl;
	std::map<char, int>::iterator itlow, itup;
	ft::map<char, int>::iterator myitlow, myitup;

	itlow = mapOrig.lower_bound('B');
	itup = mapOrig.upper_bound('D');
	mapOrig.erase(itlow, itup);
	myitlow = mapMio.lower_bound('B');
	myitup = mapMio.upper_bound('D');
	mapMio.erase(myitlow, myitup);
	mPrint(mapOrig, mapMio);

    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING OPERATIONS ELEMENTS ******************" << RESET << std::endl;

	std::cout << RED"\nLower_bound():" << ORANGE" Returns an iterator pointing to the first element in the container" << std::endl
              << "whose key is not considered to go before k (i.e., either it is equivalent or goes after)." << std::endl
              << "The function uses its internal comparison object (key_comp) to determine this, returning an" << std::endl
              << "iterator to the first element for which key_comp(element_key,k) would return false." << std::endl
              << "If the map class is instantiated with the default comparison type (less), the function" << std::endl
              << "returns an iterator to the first element whose key is not less than k." << RESET << std::endl;

    std::cout << RED"\nUpper_bound():" << ORANGE" Returns an iterator pointing to the first element in the container" << std::endl
              << "whose key is considered to go after k." << std::endl
              << "The function uses its internal comparison object (key_comp) to determine this, returning" << std::endl
              << "an iterator to the first element for which key_comp(k,element_key) would return true." << std::endl
              << "If the map class is instantiated with the default comparison type (less), the function" << std::endl
              << "returns an iterator to the first element whose key is greater than k" << RESET << std::endl;

    std::cout << RED"\nEqual_Range():" << ORANGE" Returns the bounds of a range that includes all the elements" << std::endl
              << "in the container which have a key equivalent to k." << std::endl
              << "Because the elements in a map container have unique keys, the range returned will" << std::endl
              << "contain a single element at most."RESET << std::endl;
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> myret;
	std::cout << BLUE"\nWith all of this in mind, let's go ahead with upper_bound, lower_bound and equal_range with the key 'E':\n" << RESET << std::endl;
	ret = mapOrig.equal_range('E');
	myret = mapMio.equal_range('E');

	std::cout << GREEN"In mapOrig lower bound points to: \t" << RESET;
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << GREEN"In mapOrig upper bound points to: \t" << RESET;
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	std::cout << GREEN"In mapMio lower bound points to: \t" << RESET;
	std::cout << myret.first->first << " => " << myret.first->second << '\n';

	std::cout << GREEN"In mapMio upper bound points to: \t" << RESET;
	std::cout << myret.second->first << " => " << myret.second->second << '\n';
    std::cout << std::endl;
	pressAnyKey();
}

/* Map Pbservers functions */

void	mObservers()
{
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING OBSERVER ELEMENTS ******************" << RESET << std::endl;
    std::cout << ORANGE"Key_comp(): Returns a copy of the comparison object used by the container to compare keys." << std::endl
              << "The comparison object of a map object is set on construction. Its type (member key_compare)" << std::endl
              << "is the third template parameter of the map template. By default, this is a less object, which returns the same as operator<." << std::endl
              << "This object determines the order of the elements in the container: it is a function pointer " << std::endl
              << "or a function object that takes two arguments of the same type as the element keys," << std::endl
              << "and returns true if the first argument is considered to go before the second in the strict" << std::endl
              << "weak ordering it defines, and false otherwise.\n"RESET << std::endl;
	
	std::cout << ORANGE"\nChecking key_comp() function:" << RESET << std::endl << std::endl;

	std::map<char,int> mapOrig;
	std::map<char,int>::key_compare comp = mapOrig.key_comp();

	ft::map<char,int> mapMio;
	ft::map<char,int>::key_compare mycomp = mapMio.key_comp();

	mapOrig['a']=100;
	mapOrig['b']=200;
	mapOrig['c']=300;

	mapMio['a']=100;
	mapMio['b']=200;
	mapMio['c']=300;

	char highest = mapOrig.rbegin()->first;
	std::cout << GREEN"mapOrig contains:\n" << RESET;
	std::map<char,int>::iterator it = mapOrig.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( comp((*it++).first, highest) );

	std::cout << '\n';

	highest = mapMio.rbegin()->first;
    std::cout << GREEN"mapMio contains:\n" << RESET;
	ft::map<char,int>::iterator myit = mapMio.begin();
	do {
		std::cout << myit->first << " => " << myit->second << '\n';
	} while ( mycomp((*myit++).first, highest) );

	std::cout << '\n';
    
    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING OBSERVER ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\nValue_comp(): Returns a comparison object that can be used to compare" << std::endl
              << "two elements to get whether the key of the first one goes before the second." << std::endl
              << "The arguments taken by this function object are of member type value_type" << std::endl
              << "(defined in map as an alias of pair<const key_type,mapped_type>), but the mapped_type" << std::endl
              << "of the value is not taken into consideration in this comparison." << std::endl
              << "The comparison object returned is an object of the member type map::value_compare," << std::endl
              << "which is a nested class that uses the internal comparison object to generate the" << std::endl
              << "appropriate comparison functional class." << RESET << std::endl << std::endl;

	std::map<char,int> mapOrig2;
    ft::map<char,int> mapMio2;

	mapOrig2['x']=1001;
	mapOrig2['y']=2002;
	mapOrig2['z']=3003;

	mapMio2['x']=1001;
	mapMio2['y']=2002;
	mapMio2['z']=3003;

	std::pair<char,int> highest1 = *mapOrig2.rbegin();
	std::map<char,int>::iterator it1 = mapOrig2.begin();
	std::cout << GREEN"mapOrig2 contains:\n" << RESET;
	do {
		std::cout << it1->first << " => " << it1->second << '\n';
	} while ( mapOrig2.value_comp()(*it1++, highest1) );

	highest1 = *mapMio2.rbegin();
	ft::map<char,int>::iterator myit1 = mapMio2.begin();
	std::cout << GREEN"\nmapMio2 contains:\n" << RESET;
	do {
		std::cout << myit1->first << " => " << myit1->second << '\n';
	} while ( mapMio2.value_comp()(*myit1++, highest1) );
    std::cout << std::endl;
	pressAnyKey();
}

/* Checking modifier elements */

void	mModifier()
{
	system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	
	std::map<int, std::string>	mapOrig;
	ft::map<int, std::string>	mapMio;
    std::map<int, std::string>::iterator itOrig; 
    ft::map<int, std::string>::iterator itMio; 

    std::cout << ORANGE"\n\nChecking insert() function:" << RESET << std::endl;
    std::cout << ORANGE"Because element keys in a map are unique, the insertion operation checks" << std::endl
              << "whether each inserted element has a key equivalent to the one of an element already " << std::endl
              << "in the container, and if so, the element is not inserted, returning an iterator " << std::endl
              << "to this existing element (if the function returns a value)."RESET << std::endl;

	std::cout << ORANGE"\nSetting some values in a of <int, string> using insert single pair values values:\n" << RESET << std::endl;
	std::cout << std::boolalpha;
	mapOrig.insert(std::pair<int, std::string>(5, "Pepe"));
	mapOrig.insert(std::pair<int, std::string>(7, "Marta"));
	mapOrig.insert(std::pair<int, std::string>(3, "Lidia"));
	mapOrig.insert(std::pair<int, std::string>(1, "Fran"));
    mapOrig.insert(std::pair<int, std::string>(13, "Silvia"));
    mapOrig.insert(std::pair<int, std::string>(23, "Andres"));

	mapMio.insert(std::pair<int, std::string>(5, "Pepe"));
	mapMio.insert(std::pair<int, std::string>(7, "Marta"));
	mapMio.insert(std::pair<int, std::string>(3, "Lidia"));
	mapMio.insert(std::pair<int, std::string>(1, "Fran"));
    mapMio.insert(std::pair<int, std::string>(13, "Silvia"));
    mapMio.insert(std::pair<int, std::string>(23, "Andres"));

    std::cout << ORANGE"Content after insert some values to both maps\n"RESET << std::endl;
    mPrint(mapOrig, mapMio);
    std::cout << std::endl;

	std::cout << GREEN"Inserting a new pair value into the map mapOrig: key = 9, value = Laura" << RESET << std::endl
              << CYAN"Retult of the insertion: " << (mapOrig.insert(std::pair<int, std::string>(9, "Laura"))).second << std::endl;

	std::cout << GREEN"Inserting a new pair value into the map MapMio: key = 9, value = Laura" << RESET << std::endl
              << CYAN"Retult of the insertion: " << (mapMio.insert(std::pair<int, std::string>(9, "Laura"))).second << std::endl;

	std::cout << GREEN"\nInserting an element with a key equivalent to the one of an element already key = 3, value = Alberto" << std::endl
              << "in the container mapOrig: " << RESET << (mapOrig.insert(std::pair<int, std::string>(3, "Alberto"))).second << std::endl;

	std::cout << GREEN"\nInserting an element with a key equivalent to the one of an element already key = 3, value = Alberto" << std::endl
              << "in the container mapMio: " << RESET << (mapOrig.insert(std::pair<int, std::string>(3, "Alberto"))).second << std::endl;
	
    std::cout << ORANGE"Printing both maps after the prevoius operations\n"RESET << std::endl;
    mPrint(mapOrig, mapMio);
    std::cout << std::endl;

	std::cout << ORANGE"\nInserting with a hint. Find an iterator pointing to either the newly inserted element or" << std::endl
              << "to the element that already had an equivalent key in the map (max efficiency) find(9), inserting <15, Susana>:\n" << RESET << std::endl;
	
	mapOrig.insert(mapOrig.find(9), std::pair<int, std::string>(15, "Susana"));
	mapMio.insert(mapMio.find(9), std::pair<int, std::string>(15, "Susana"));
	mPrint(mapOrig, mapMio);

    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;
	std::cout << ORANGE"\nInserting with a hint. Find an iterator not pointin to the newly nor " << std::endl
              << "the element with an equivalent key in map (no max efficiency) find(7), inserting <17, Juan>:\n" << RESET << std::endl;
	
	mapOrig.insert(mapOrig.find(7), std::pair<int, std::string>(17, "Juan"));
	mapMio.insert(mapMio.find(7), std::pair<int, std::string>(17, "Juan"));
	mPrint(mapOrig, mapMio);

	std::cout << ORANGE"\nRange insertion from begin to an element, defining its position by an iterator using find(9)\n" << std::endl
              << "Creating a couple of maps to copy in the elements from MapOrig and Mapmio" RESET << std::endl;
	std::map<int, std::string>	mapOrig2;
	ft::map<int, std::string>	mapMio2;
	mapOrig2.insert(mapOrig.begin(), mapOrig.find(9));
	mapMio2.insert(mapMio.begin(), mapMio.find(9));
	mPrint(mapOrig2, mapMio2);
    
    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;

	std::cout << ORANGE"\n\nRemoves from the maps container (MapOrig and MaoMio)" << std::endl
              << "either a single element or a range of elements ([first,last)).\n" << RESET << std::endl;
	std::cout << ORANGE"\nIterator pointing to a single element to be removed from the map." << std::endl
              << "This shall point to a valid and dereferenceable element.\n\n" << RESET << std::endl;
	
    std::cout << ORANGE"Maps before erasing by iterator"RESET << std::endl;
    mPrint(mapOrig, mapMio);

    std::cout << ORANGE"\nErase key = 5, value = Pepe, an element from the container maps MapOrig and MapMio using an iterator:\n" << RESET << std::endl;
    itOrig = mapOrig.find(5);
	itMio = mapMio.find(5);
	mapOrig.erase(itOrig);
	mapMio.erase(itMio);
	mPrint(mapOrig, mapMio);

	std::cout << ORANGE"\nErase key = 1, value = Fran, another element from the container maps MapOrig and MapMio using an iterator:\n" << RESET << std::endl;
	itOrig = mapOrig.find(1);
	itMio = mapMio.find(1);
	mapOrig.erase(itOrig);
	mapMio.erase(itMio);
	mPrint(mapOrig, mapMio);

    std::cout << ORANGE"\nErase key = 23, value = Andres, another element from the container maps MapOrig and MapMio using an iterator:\n" << RESET << std::endl;
	itOrig = mapOrig.find(23);
	itMio = mapMio.find(23);
	mapOrig.erase(itOrig);
	mapMio.erase(itMio);
	mPrint(mapOrig, mapMio);

    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;


	std::cout << ORANGE"\nErase by Key of the element to be removed from the map." << std::endl
              <<"Member type key_type is the type of the elements in the container," << std::endl
              <<"defined in map as an alias of its first template parameter (Key).\n" << RESET << std::endl;
    
    std::cout << ORANGE"Maps before erasing by Key-value"RESET << std::endl;
	std::cout << ORANGE"mapOrig.size(): " << mapOrig.size() << RESET" - "CYAN << "mapMio.size(): " << mapMio.size() << RESET << std::endl;
    mPrint(mapOrig, mapMio);
    
    std::cout << ORANGE"\nErasing element key = 13, value = Silvia"RESET << std::endl;
    std::cout << GREEN"\nNumber of elements erased in mapOrig: " << RESET << mapOrig.erase(13) << std::endl;
    std::cout << GREEN"\nNumber of elements erased in mapMio: " << RESET << mapMio.erase(13) << std::endl << std::endl;
	std::cout << ORANGE"mapOrig.size(): " << mapOrig.size() << RESET" - "CYAN << "mapMio.size(): " << mapMio.size() << RESET << std::endl;
    std::cout << std::endl;
    mPrint(mapOrig, mapMio);

	std::cout << ORANGE"\nErasing element key = 17, value = Juan"RESET << std::endl;
    std::cout << GREEN"\nNumber of elements erased in mapOrig: " << RESET << mapOrig.erase(17) << std::endl;
    std::cout << GREEN"\nNumber of elements erased in mapMio: " << RESET << mapMio.erase(17) << std::endl << std::endl;
    std::cout << ORANGE"mapOrig.size(): " << mapOrig.size() << RESET" - "CYAN << "mapMio.size(): " << mapMio.size() << RESET << std::endl;
    mPrint(mapOrig, mapMio);
	std::cout << ORANGE"\nErasing element key = 20, Non-Existing value"RESET << std::endl;
    std::cout << GREEN"\nNumber of elements erased in mapOrig: " << RESET << mapOrig.erase(20) << std::endl;
    std::cout << GREEN"\nNumber of elements erased in mapMio: " << RESET << mapMio.erase(20) << std::endl << std::endl;
	std::cout << ORANGE"mapOrig.size(): " << mapOrig.size() << RESET" - "CYAN << "mapMio.size(): " << mapMio.size() << RESET << std::endl;
   
    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;


	std::cout << ORANGE"\nErase by range [first, last) mapOrig2 and mapMio2:\n" << RESET << std::endl;
	std::map<int, std::string>::iterator itOrig2 = mapOrig2.begin();
	ft::map<int, std::string>::iterator itMio2 = mapMio2.begin();
	
    std::cout << ORANGE"Maps before erasing by range[first, last)"RESET << std::endl;
    mPrint(mapOrig, mapMio);
	
    mapOrig2.erase(itOrig2, mapOrig2.end());
	mapMio2.erase(itMio2, mapMio2.end());
    std::cout << ORANGE"Maps After erasing by range[first, last)"RESET << std::endl;
	mPrint(mapOrig2, mapMio2);
    
    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;

	std::cout << ORANGE"\n\nExchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ" << RESET << std::endl;
	std::cout << ORANGE"\nSetting some values for mapOrig2 and mapMio2:\n" << RESET << std::endl;
	
    mapOrig2.insert(std::pair<int, std::string>(42, "Sandra"));
	mapOrig2.insert(std::pair<int, std::string>(43, "Pedro"));
	mapMio2.insert(std::pair<int, std::string>(42, "Sandra"));
	mapMio2.insert(std::pair<int, std::string>(43, "Pedro"));
	
    std::cout << ORANGE"\nPrinting mapOrig and mapMio before swapping them\n" << RESET << std::endl;
	mPrint(mapOrig, mapMio);
	std::cout << ORANGE"\nPrinting mapOrig2 and mapMio before swapping them\n" << RESET << std::endl;
	mPrint(mapOrig2, mapMio2);
	
    mapOrig.swap(mapOrig2);
	mapMio.swap(mapMio2);

	std::cout << ORANGE"\nrinting mapOrig and mapMio after swapping them\n" << RESET << std::endl;
	mPrint(mapOrig, mapMio);
	std::cout << ORANGE"\nPrinting mapOrig2 and mapMio after swapping them\n" << RESET << std::endl;
	mPrint(mapOrig2, mapMio2);

    pressAnyKey();
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING MODIFIERS ELEMENTS ******************" << RESET << std::endl;

	std::cout << ORANGE"\n\nclear() function: Removes all elements from the map container (which are destroyed), leaving the container with a size of 0" << RESET << std::endl;
	std::cout << ORANGE"\nClear mapOrig and mapMio:\n" << RESET << std::endl;
	
    mapOrig.clear();
	mapMio.clear();
	
    mPrint(mapOrig, mapMio);
	pressAnyKey();
}

/* Checking the access elements */
template <class K, class T>
void	mAccess(std::map<K, T> mapOrig, ft::map<K, T> mapMio)
{
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING ELEMENT ACCESS ******************" << RESET << std::endl;
	std::cout << ORANGE"\n\nChecking operator[]:" << RESET << std::endl;

    std::cout << GREEN"mapOrig[]\t\t\t" << BLUE"mapMio[]"RESET << std::endl;
    for (char c = 'A'; c <= 'F'; c++)
        std::cout << ORANGE"mapOrig[" << c << "] -> " << mapOrig[c] << "\t\t" << CYAN"mapMio[" << c << "] -> " << mapMio[c] << RESET << std::endl; 
    
    std::cout << std::endl;
    std::cout << ORANGE"mapOrig size is: " << RESET << mapOrig.size() << RESET << CYAN"\t\tmapMio size is: " << RESET << mapMio.size() << RESET << std::endl;

    std::cout << std::endl << GREEN"Adding some values to mapOrig and mapMio using the element access operator []\n"RESET << std::endl;
    mapOrig['Z'] = 'Z';
	mapOrig['Y'] = 'Y';
	mapOrig['X'] = mapOrig['F'];

    mapMio['Z'] = 'Z';
	mapMio['Y'] = 'Y';
	mapMio['X'] = mapOrig['F'];
    
    for (char c = 'X'; c <= 'Z'; c++)
        std::cout << ORANGE"mapOrig[" << c << "] -> " << mapOrig[c] << "\t\t" << CYAN"mapMio[" << c << "] -> " << mapMio[c] << RESET << std::endl; 

	std::cout << std::endl;
	std::cout << ORANGE"mapOrig size is " << RESET << mapOrig.size() << RESET << CYAN"\t\tmapMio size is " << RESET << mapMio.size() << RESET;
	std::cout << std::endl;
}

/* Checking the capacity elements */
template <class K, class T>
void	mCapacity(std::map<K, T> mapOrig, ft::map<K, T> mapMio)
{
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING CAPACITY ELEMENTS ******************" << RESET << std::endl;
	

	std::map<char, int> mapOrig2;
	ft::map<char, int> mapMio2;

	std::cout << CYAN"\nPrinting out 'origMap' Map and 'mapMio' Map with the same data on them\n" << RESET << std::endl;
	mPrint(mapOrig, mapMio);

	std::cout << CYAN"\nPrinting two empty maps: mapOrig2 and mapMio2\n" << RESET << std::endl;
	mPrint(mapOrig2, mapMio2);

	std::cout << CYAN"\nTesting the empty() function with mapOrig and mapMio:\n" << RESET << std::endl;
	std::string isTrue;
	
	isTrue = (mapOrig.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << GREEN"mapOrig " << isTrue << RESET << std::to_string(mapOrig.size()) << std::endl;

	isTrue = (mapMio.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << CYAN"mapMio " << isTrue << RESET << std::to_string(mapMio.size()) << std::endl;

	std::cout << CYAN"\nTesting the empty() function with mapOrig2 and mapMio2:\n" << RESET << std::endl;
	isTrue = (mapOrig2.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << GREEN"mapOrig2 " << isTrue << RESET << std::to_string(mapOrig2.size()) << std::endl;

	isTrue = (mapMio2.empty()) ? "is empty with size of: " : "is not empty with size of: ";
	std::cout << CYAN"mapMio2 " << isTrue << RESET << std::to_string(mapMio2.size()) << std::endl;
	
	std::map<std::string, int> mapOrig3;
	ft::map<std::string, int> mapMio3;
	std::map<MyClass*, int> mapOrig4;
	ft::map<MyClass*, int> mapMio4;
    std::map<std::string, std::string> mapOrig5;
	ft::map<std::string, std::string> mapMio5;
    std::map<bool, bool> mapOrig6;
    ft::map<bool, bool> mapMio6;
	std::cout << CYAN"\nTesting the max_size() function\n" << RESET << std::endl;
	std::cout << ORANGE"Print out the max sizes with different types using max_size() function" << RESET << std::endl;
	std::cout << GREEN"mapOrig<char, int> max_size: \t\t\t" << RESET << mapOrig.max_size() << RESET << std::endl;
	std::cout << GREEN"mapMio<char, int> max_size: \t\t\t" << RESET << mapMio.max_size() << RESET << std::endl;
	std::cout << GREEN"mapOrig3<std::string, int> max_size: \t\t" << RESET << mapOrig3.max_size() << RESET << std::endl;
	std::cout << GREEN"mapMio3<std::string, int> max_size: \t\t" << RESET << mapMio3.max_size() << RESET << std::endl;
	std::cout << GREEN"mapOrig4<MyClass*, int> max_size: \t\t" << RESET << mapOrig4.max_size() << RESET << std::endl;
	std::cout << GREEN"mapMio4<MyClass*, int> max_size: \t\t" << RESET << mapMio4.max_size() << RESET << std::endl;
    std::cout << GREEN"mapOrig5<std::string, std::string> max_size: \t" << RESET << mapOrig5.max_size() << RESET << std::endl;
	std::cout << GREEN"mapMio5<std::string, std::string> max_size: \t" << RESET << mapMio5.max_size() << RESET << std::endl;
    std::cout << GREEN"mapMio6<bool, bool> max_size: \t\t\t" << RESET << mapMio6.max_size() << RESET << std::endl;
    std::cout << GREEN"mapOrig6<bool, bool> max_size: \t\t\t" << RESET << mapOrig6.max_size() << RESET << std::endl;
	std::cout << std::endl;
	pressAnyKey();
}

/* Const Iterator test*/
void	mCitCheck(const std::map<char, int>& orig, const ft::map<char, int>& mio)
{
    system("clear");
	printTestHeader("MAP");
	std::map<char,int>::const_iterator cit = orig.begin();
	ft::map<char, int>::const_iterator citMio = mio.begin();
	std::map<char, int>::const_reverse_iterator rcit = orig.rbegin();
	ft::map<char, int>::const_reverse_iterator rcitMio = mio.rbegin();
	
	std::cout << RED"****************** TESTING CONST ITERATORS ******************" << RESET << std::endl << std::endl;
	std::cout << CYAN"\nIterating from the begining to the end using const iterators:\n" << RESET << std::endl;

	std::cout << GREEN"Printing out the Original Map\n" << RESET;
	while (cit != orig.end())
    {
        std::cout << ORANGE<< cit->first << " -> " << cit->second << RESET << std::endl;
        cit++;
    }

	std::cout << GREEN"Printing out the my(mio) Map\n" << RESET;
    while (citMio != mio.end())
    {
        std::cout << CYAN << citMio->first << " -> " << citMio->second << RESET << std::endl;
        citMio++;
    }
	
    std::cout << GREEN"Printing out the Original Map using const reverse iterator\n" << RESET;
    while (rcit != orig.rend())
    {
        std::cout << ORANGE<< rcit->first << " -> " << rcit->second << RESET << std::endl;
        rcit++;
    }
    
    std::cout << GREEN"Printing out the Original my(mio) Map using const reverse iterator\n" << RESET;
     while (rcitMio != mio.rend())
    {
        std::cout << CYAN<< rcitMio->first << " -> " << rcitMio->second << RESET << std::endl;
        rcitMio++;
    }
    std::cout << std::endl;
}

/* Iterator tester*/
template <class K, class T>
void	mItcheck(std::map<K, T> orig, ft::map<K, T> mio)
{
    system("clear");
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING ITERATORS ******************" << RESET << std::endl << std::endl;

	std::map<char, int>::iterator it = orig.begin();
	ft::map<char, int>::iterator itMio = mio.begin();
	std::map<char, int>::reverse_iterator rit = orig.rbegin();
	ft::map<char, int>::reverse_iterator ritMio = mio.rbegin();

	std::cout << ORANGE"Iterator it points to the begining: " << RESET << it->first << " -> " << it->second << std::endl;
	std::cout << CYAN"Iterator itMio points to the begining: " << RESET << itMio->first << " -> " << itMio->second << std::endl;
	std::cout << std::endl;

    std::cout << YELLOW"\nPrinting the Maps iterating from the beginin to the end:\n" << RESET << std::endl;
    mPrint(orig, mio);

	std::cout << ORANGE"Reverse iterator rit points to the reverse begin: " << RESET << rit->first << " -> " << rit->second << std::endl;
	std::cout << CYAN"Reverse iterator ritMio points to de reverse begin: " << RESET << ritMio->first << " -> " << ritMio->second << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW"\nIterating from rbegin() to rend():\n" << RESET << std::endl;
	std::cout << GREEN"In vector: \n" << RESET;
    
    mPrintReverse(orig, mio);

	pressAnyKey("Next Test: Const Iterator. Press any key to continue");

	mCitCheck(orig, mio);
}

void mapExec()
{
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl;
	std::cout << YELLOW"Empty Constructor. Constructs an empty container, with no elements" << RESET << std::endl << std::endl;
	std::cout << YELLOW"Map constructor mapOrig and mapMio map<string, int>\n" << RESET << std::endl;
	std::cout << CYAN"Empty Maps mapOrig and mapMio\n" << RESET << std::endl;
	std::map<std::string, int> mapOrig;
	ft::map<std::string, int> mapMio;
    mPrint(mapOrig, mapMio);
    
    std::cout << BLUE" \nSetting some values\n" << RESET << std::endl;
	mapOrig["edad"] = 10;
	mapOrig["altura"] = 30;
	mapOrig["peso"] = 50;
	mapOrig["ci"] = 100;

	mapMio["edad"] = 10;
	mapMio["altura"] = 30;
	mapMio["peso"] = 50;
	mapMio["ci"] = 100;
	mPrint(mapOrig, mapMio);

	std::cout << YELLOW"Constructs a container with as many elements as the range [first,last),"
              << " with each element constructed from its corresponding element in that range."
              << RESET << std::endl << std::endl;
	
	std::map<std::string, int> mapOrig2(mapOrig.begin(), mapOrig.end());
	ft::map<std::string, int> mapMio2(mapMio.begin(), mapMio.end());
	mPrint(mapOrig2, mapMio2);

	pressAnyKey();
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl;
	std::cout << YELLOW"Constructs a container with a copy of each of the elements in x, in the same order" << RESET << std::endl << std::endl;
	std::cout << CYAN"\nCopy constructor using mapOrig2 and mapMio2 to create mapOrig3 and mapMio3:\n" << RESET << std::endl;
	std::map<std::string, int> mapOrig3(mapOrig2);
	ft::map<std::string, int> mapMio3(mapMio2);
	mPrint(mapOrig3, mapMio3);

	std::cout << BLUE"\nUsing the third parameter of the constructor, Class Compare\n" << RESET << std::endl;
	std::map<std::string, int, cmpByStringLength> mapOrigComp;
	ft::map<std::string, int, cmpByStringLength> mapMioComp;
    std::map<std::string, int> mapOrigLessDefaultcmp;
    ft::map<std::string, int> mapMioLessDefaultcmp;
	std::map<std::string, int>::iterator it;
	ft::map<std::string, int>::iterator itMio;
	
    /* Adding to map with default calss compare less */
    mapOrigLessDefaultcmp["electric"] = 54;
	mapOrigLessDefaultcmp["house"] = 52;
	mapOrigLessDefaultcmp["CAT"] = 55;
	mapOrigLessDefaultcmp["Heritance"] = 78;
    mapOrigLessDefaultcmp["genious"] = 78;
    mapOrigLessDefaultcmp["fourth"] = 78;

    /* Adding to map with default calss compare less */
    mapMioLessDefaultcmp["electric"] = 54;
	mapMioLessDefaultcmp["house"] = 52;
	mapMioLessDefaultcmp["CAT"] = 55;
	mapMioLessDefaultcmp["Heritance"] = 78;
    mapMioLessDefaultcmp["genious"] = 78;
    mapMioLessDefaultcmp["fourth"] = 78;

    /* Adding to map passing comparison function to the constructor calss */
    mapOrigComp["electric"] = 54;
	mapOrigComp["house"] = 52;
	mapOrigComp["CAT"] = 55;
	mapOrigComp["Heritance"] = 78;
    mapOrigComp["genious"] = 78;
    mapOrigComp["fourth"] = 78;
    
    /* Adding to map passing comparison function to the constructor calss */
	mapMioComp["electric"] = 54;
	mapMioComp["house"] = 52;
	mapMioComp["CAT"] = 55;
	mapMioComp["Heritance"] = 78;
    mapMioComp["genious"] = 78;
    mapMioComp["fourth"] = 78;

    std::cout << BLUE"\nPrinting mapOrigLessDefaultcmp and mapMioLessDefaultcmp. Using third parameter by default in maps\n" << RESET << std::endl;
    mPrint(mapOrigLessDefaultcmp, mapMioLessDefaultcmp);

    std::cout << BLUE"\nCreate mapOrigComp map<string, int> with string lenght as comparason function:\n" << RESET << std::endl;
	std::cout << GREEN"Printing out mapOrigComp\n" << RESET << std::endl;
	it = mapOrigComp.begin();
	for ( ; it != mapOrigComp.end(); it++)
			std::cout << ORANGE << it->first << ' ' << it->second << RESET << std::endl;
   
	std::cout << GREEN"\nPrinting out mapMioComp:\n" << RESET << std::endl;
	itMio = mapMioComp.begin();
	for ( ; itMio != mapMioComp.end(); itMio++)
			std::cout << CYAN << itMio->first << ' ' << itMio->second << RESET << std::endl;
    std::cout << "\n\nChecking orig.begin() = " << (mapOrigComp.begin()->first) << " - "<< mapOrigComp.begin()->second << std::endl;
	std::cout << "\nChecking mio.begin() = " << (mapMioComp.begin()->first) << " - "<< mapMioComp.begin()->second << std::endl;
    pressAnyKey();
	printTestHeader("MAP");
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl;
	
	std::cout << BLUE"\nTrying operator =. Create mapOrig4 map equal to mapOrig, and mapOrig equal to new map:\n" << RESET << std::endl;
	std::map<std::string, int>	mapOrig4;
	ft::map<std::string, int>	mapMio4;

	mapOrig4 = mapOrig;
	mapOrig = std::map<std::string, int>();
	mapMio4 = mapMio;
	mapMio = ft::map<std::string, int>();
	std::cout << BLUE"\nPrint mapOrig:\n" << RESET << std::endl;
	mPrint(mapOrig, mapMio);
	std::cout << BLUE"\nPrint mapOrig4:\n" << RESET << std::endl;
	mPrint(mapOrig4, mapMio4);

    std::map<char, int>	mapTestOrig;
	ft::map<char, int>	mapTestMio;
	std::cout << BLUE"\nCreating map<char, int> with some values:\n" << RESET << std::endl;
    int c = 'A';
    while (c <= 'F')
	{
        mapTestOrig[c] = c;
	    mapTestMio[c] = c;
        c++;
    }

    mItcheck(mapTestOrig, mapTestMio);

    mCapacity(mapTestOrig, mapTestMio);

    mAccess(mapTestOrig, mapTestMio);

    mModifier();

    mObservers();

    mOperations(mapTestOrig, mapTestMio);

    mRelational(mapTestOrig, mapTestMio);

	pressAnyKey("Finishing MAP test. Press any key to return to the main menu");
}