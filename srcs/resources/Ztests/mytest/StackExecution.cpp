#include "testing.hpp"

//Template of generic function to print out the underliying container of my own stack implementation
template <class T, template <class U, class = std::allocator<U> > class Container>
void sPrintUnderMio(ft::stack<T, Container<T> > sMio)
{
    std::cout << GREEN"My Implementation stack"RESET << std::endl;
    while (!sMio.empty())
    {
        std::cout << CYAN"\t" << sMio.top() << RESET << std::endl;
        sMio.pop();
    }
	std::cout << std::endl;
}

//Template of generic function to print out the underliying container of the original stack
template <class T, template <class U, class = std::allocator<U> > class Container>
void sPrintUnderOrig(std::stack<T, Container<T> > sOrig)
{
    std::cout << GREEN"Original stack"RESET << std::endl;
    while (!sOrig.empty())
    {
        std::cout << ORANGE"\t" << sOrig.top() << RESET << std::endl;
        sOrig.pop();
    }
	std::cout << std::endl;
}

//Generic template function that prints the underliying List<T> container of both mio and original
template <class T>
void sPrintUnderL(std::stack<T, std::list<T> > sOrig, ft::stack<T, ft::list<T> > sMio)
{
	if (sOrig.size() != sMio.size())
	{
		std::cout << RED << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		while (!sOrig.empty())
        {
            std::cout << ORANGE << sOrig.top() << ", " << RESET;
            sOrig.pop();
        }
		std::cout << std::endl;
		
	    while (!sMio.empty())
        {
            std::cout << CYAN << sMio.top() << ", " << RESET;
            sMio.pop();
        }
        std::cout << std::endl;
	}
	else
	{
        std::cout << GREEN"Original stack\t\tMy stack"RESET << std::endl;
		while (!sOrig.empty())
        {
            std::cout << ORANGE"\t" << sOrig.top()  << "\t\t"CYAN  << sMio.top() << RESET << std::endl;
            sOrig.pop();
            sMio.pop();
        }
		std::cout << std::endl;
	}

    std::cout << std::endl;
    
}

template <class T>
void sPrint(std::stack<T> sOrig, ft::stack<T> sMio)
{
	if (sOrig.size() != sMio.size())
	{
		std::cout << RED << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		while (!sOrig.empty())
        {
            std::cout << ORANGE << sOrig.top() << ", " << RESET << std::endl;
            sOrig.pop();
        }
		std::cout << std::endl;
		
	    while (!sMio.empty())
        {
            std::cout << CYAN << sMio.top() << ", " << RESET << std::endl;
            sMio.pop();
        }
        std::cout << std::endl;
	}
	else
	{
        std::cout << GREEN"Original stack\t\tMy stack"RESET << std::endl;
		while (!sOrig.empty())
        {
            std::cout << ORANGE"\t" << sOrig.top()  << "\t\t"CYAN  << sMio.top() << RESET << std::endl;
            sOrig.pop();
            sMio.pop();
        }
		std::cout << std::endl;
	}

    std::cout << std::endl;
    
}


template <class T>
void sClear(std::stack<T> *sOrig, ft::stack<T> *sMio)
{
    system("clear");
    printTestHeader("STACK");
	std::cout << RED"****************** TESTING MODIFIER & ACCESS ELEMENTS ******************" << RESET << std::endl;
    std::cout << YELLOW << "\nCleaning sOrig and sMio using pop() function and top() to show the value\n" << RESET << std::endl;
    while (!sOrig->empty())
    {
        std::cout << ORANGE"Popped Value from sOrig:\t" << sOrig->top() << RESET << std::endl;
        sOrig->pop();
    }
    std::cout << std::endl;
    while (!sMio->empty())
    {
        std::cout << CYAN"Popped Value from sMio3:\t" << sMio->top() << RESET << std::endl;
        sMio->pop();
    }
    std::cout << std::endl;
    pressAnyKey("Original and implamentation of stack was clean and emptied");
}

/***
 * 
 * */

template <class T>
void	sRelational(std::stack<T> sOrig, ft::stack<T> sMio)
{
    system("clear");
	printTestHeader("STACK");
	std::cout << RED"****************** TESTING RELATIONAL OPERATORS ******************" << RESET << std::endl;
	std::cout << BLUE"\nCreating stacks to test: foo, myfoo, bar and mybar\n" << RESET << std::endl;
	std::stack<int>	foo(sOrig);
	ft::stack<int>	myfoo(sMio);
	std::stack<int>	bar(sOrig);
	ft::stack<int>	mybar(sMio);

    std::cout << ORANGE"\nPrinting foo and myfoon \n" << RESET << std::endl;
    sPrint(foo, myfoo);
    std::cout << ORANGE"\nPrinting bar and mybar \n" << RESET << std::endl;
    sPrint(bar, mybar);

	std::cout << ORANGE"\n\nChecking relational operators:" << RESET << std::endl;
	std::cout << ORANGE"--- sOrig --- \t\t\t\t\t\t" << CYAN"--- sMio ---" << RESET << std::endl;
	if (foo == bar) std::cout << ORANGE"Testing (==): foo and bar are equal\t\t\t";
	if (myfoo == mybar) std::cout << CYAN"Testing (==): myfoo and mybar are equal\n"RESET;

	if (foo != bar) std::cout << ORANGE"Testing (!=): foo and bar are not equal\t\t";
	if (myfoo!=mybar) std::cout << CYAN"Testing (!=): myfoo and mybar are not equal\n"RESET;

	if (foo < bar) std::cout << ORANGE"Testing (<): foo is less than bar\t\t";
	if (myfoo < mybar) std::cout << ORANGE"Testing (<): myfoo is less than mybar\n"RESET;

	if (foo > bar) std::cout << ORANGE"Testing (>): foo is greater than bar\t\t";
	if (myfoo> mybar) std::cout << CYAN"Testing (>): myfoo is greater than mybar\n"RESET;

	if (foo <= bar) std::cout << ORANGE"Testing (<=): foo is less than or equal to bar\t\t";
	if (myfoo<=mybar) std::cout << CYAN"Testing (<=): myfoo is less than or equal to mybar\n"RESET;

	if (foo >= bar) std::cout << ORANGE"Testing (>=): foo is greater than or equal to bar\t";
	if (myfoo>=mybar) std::cout << ORANGE"Testing (>=): myfoo is greater than or equal to mybar\n"RESET;
    std::cout << std::endl;
	
	pressAnyKey();
}

template <class T>
void	sModifier(std::stack<T> *sOrig, ft::stack<T> *sMio)
{
    system("clear");
    printTestHeader("STACK");
    std::cout << RED"****************** TESTING ELEMENT ACCESS ******************" << RESET << std::endl;

	std::cout << ORANGE"\n\nTesting push() function on sOrig and sMio:" << RESET << std::endl;
	std::cout << ORANGE"Pushing {69, 73, 93} values:\n" << RESET << std::endl;
    
    std::cout << ORANGE"\nPrinting sOrig and sMio before pushing\n" << RESET << std::endl;
    sPrint(*(sOrig), *(sMio));
	
    sOrig->push(69);
	sOrig->push(73);
	sOrig->push(93);

	sMio->push(69);
	sMio->push(73);
	sMio->push(93);

    std::cout << ORANGE"\nPrinting sOrig and sMio after pushing\n" << RESET << std::endl;
    sPrint(*(sOrig), *(sMio));

	std::cout << ORANGE"\nTesting pop() function on sOrig and sMio. Popping to the next element of stack:\n" << RESET << std::endl;
	sOrig->pop();
	sMio->pop();
    std::cout << ORANGE"\nPrinting sOrig and sMio after Popping\n" << RESET << std::endl;
    sPrint(*(sOrig), *(sMio));

	std::cout << ORANGE"Now the top of the container is (sOrig.top()): \t" << RESET << sOrig->top() << RESET << std::endl;
	std::cout << CYAN"Now the top of the container is (sMio.top()): \t" << RESET << sMio->top() << RESET << std::endl;
    std::cout << std::endl;
	pressAnyKey();
}

template <class T>
void	sAccess(std::stack<T> sOrig, ft::stack<T> sMio)
{
    system("clear");
    printTestHeader("STACK");
	std::cout << RED"****************** TESTING ELEMENT ACCESS ******************" << RESET << std::endl;
    std::cout << ORANGE"\nPrinting sOrig and sMio \n" << RESET << std::endl;
    sPrint(sOrig, sMio);

	std::cout << ORANGE"\n\nTesting top() function:" << RESET << std::endl;
	std::cout << GREEN"Container sOrig top() points to: " << RESET << sOrig.top() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << GREEN"Container sMio top() points to: " << RESET << sMio.top() << RESET << std::endl;
    std::cout << std::endl;
	
    pressAnyKey();
}

void stackExec()
{
    system("clear");
    printTestHeader("STACK");
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl;
	std::cout << YELLOW"\nEmpty Constructor. Constructs an empty container, with no elements" << RESET << std::endl << std::endl;
	std::cout << YELLOW"stack constructor sOrig and sMio stack<int>\n" << RESET << std::endl;
	std::stack<int> sOrig;
	ft::stack<int> sMio;
    
    std::cout << ORANGE"\nPrinting empty sOrig and sMio \n" << RESET << std::endl;
    sPrint(sOrig, sMio);
	std::cout << YELLOW"Checking sOrig size at empty stack container:\t" << RESET << sOrig.size() << std::endl;
	std::cout << YELLOW"Checking sMio size at empty stack container:\t" << RESET << sMio.size() << std::endl;

    std::cout << YELLOW"\nTesting empty function on both containers sOrig and sMio\n" << RESET << std::endl;
	if (sOrig.empty())
		std::cout << ORANGE"Container sOrig is empty" << std::endl;
	else
		std::cout << ORANGE"Container sOrig is not empty" << std::endl;
	if (sMio.empty())
		std::cout << CYAN"Container sMio is empty" << std::endl;
	else
		std::cout << CYAN"Container sMio is not empty" << std::endl;

	std::list<int>	listOrig(4, 42);
	ft::list<int>	listMio(4, 42);
	std::vector<int> vectorOrig(5, 24);
	ft::vector<int>	vectorMio(5, 24);
    

    std::cout << YELLOW"\nCreating sOrig2 stack as copy of list (4, 42) passing list as second argument of container class stack:\n" << RESET << std::endl;
	std::stack<int, std::list<int> > sOrig2(listOrig);
	ft::stack<int, ft::list<int> > sMio2(listMio);
    
    sPrintUnderL(sOrig2, sMio2);
	
    std::cout << YELLOW"Checking sOrig2 size after creating as copy of listOrig:\t" << RESET << sOrig2.size() << std::endl;
	std::cout << YELLOW"Checking sMio2 size after creating as copy of listMio:\t\t" << RESET << sMio2.size() << std::endl;
	
    std::cout << YELLOW"\nTesting empty function on both containers sOrig and sMio\n" << RESET << std::endl;
    if (sOrig2.empty())
		std::cout << ORANGE"Container sOrig2 is empty" << std::endl;
	else
		std::cout << ORANGE"Container sOrig2 is not empty" << std::endl;
	
    if (sMio2.empty())
		std::cout << CYAN"Container sMio2 is empty" << std::endl;
	else
		std::cout << CYAN"Container sMio2 is not empty" <<  RESET << std::endl;

	std::cout << YELLOW"\nCreating third stack with vector as underlying container:\n" << RESET << std::endl;
	std::stack<int, std::vector<int> > sOrig3(vectorOrig);
	ft::stack<int, ft::vector<int> > sMio3(vectorMio);

    sPrintUnderOrig(sOrig3);
    sPrintUnderMio(sMio3);

	std::cout << ORANGE"Container sOrig3 size:\t" << RESET << sOrig3.size() << std::endl;
	std::cout << CYAN"Container sMio3 size:\t" << RESET << sMio3.size() << std::endl;
    std::cout << std::endl;

    pressAnyKey();

    system("clear");
    printTestHeader("STACK");
	std::cout << RED"****************** TESTING MODIFIER ELEMENTS PUSH ******************" << RESET << std::endl;
    std::cout << ORANGE"\nPrinting sOrig and sMio before pushing {12, 13} \n" << RESET << std::endl;
    sPrint(sOrig, sMio);
    sOrig.push(12);
    sOrig.push(13);
    sMio.push(12);
    sMio.push(13);
    std::cout << ORANGE"\nPrinting sOrig and sMio After pushing\n" << RESET << std::endl;
    sPrint(sOrig, sMio);
    
    pressAnyKey();
    system("clear");
    printTestHeader("STACK");
	std::cout << RED"****************** TESTING MODIFIER ELEMENTS POP ******************" << RESET << std::endl;
    std::cout << ORANGE"\nPrinting sOrig and sMio before popping {12, 13} \n" << RESET << std::endl;
    sPrint(sOrig, sMio);

    sClear(&sOrig, &sMio);

    std::cout << ORANGE"\nPrinting sOrig and sMio after poping {12, 13} \n" << RESET << std::endl;
    sPrint(sOrig, sMio);

    std::cout << ORANGE"\nAdding some values to sOrig and sMio" << RESET << std::endl;
    sOrig.push(4);
	sOrig.push(8);
	sOrig.push(15);
    sOrig.push(16);
    sOrig.push(23);
    sOrig.push(42);
	sMio.push(4);
	sMio.push(8);
	sMio.push(15);
    sMio.push(16);
    sMio.push(23);
    sMio.push(42);
    
    std::cout << ORANGE"\nPrinting sOrig and sMio \n" << RESET << std::endl;
    sPrint(sOrig, sMio);
    
    pressAnyKey();

    sAccess(sOrig, sMio);

    sModifier(&sOrig, &sMio);

    sRelational(sOrig, sMio);

    pressAnyKey("Finishing stack test. Press any key to return to the main menu");
}