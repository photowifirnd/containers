#include "testing.hpp"


//Template of generic function to print out the underliying container of my own stack implementation
template <class T, template <class U, class = std::allocator<U> > class Container>
void qPrintUnderMio(ft::queue<T, Container<T> > sMio)
{
    std::cout << GREEN"My Implementation queue"RESET << std::endl;
    while (!sMio.empty())
    {
        std::cout << CYAN"\t" << sMio.front() << RESET << std::endl;
        sMio.pop();
    }
	std::cout << std::endl;
}

//Template of generic function to print out the underliying container of the original queue
template <class T, template <class U, class = std::allocator<U> > class Container>
void qPrintUnderOrig(std::queue<T, Container<T> > sOrig)
{
    std::cout << GREEN"Original queue"RESET << std::endl;
    while (!sOrig.empty())
    {
        std::cout << ORANGE"\t" << sOrig.front() << RESET << std::endl;
        sOrig.pop();
    }
	std::cout << std::endl;
}

//Generic template function that prints the underliying List<T> container of both mio and original
template <class T>
void qPrintUnderL(std::queue<T, std::list<T> > sOrig, ft::queue<T, ft::list<T> > sMio)
{
	if (sOrig.size() != sMio.size())
	{
		std::cout << RED << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		while (!sOrig.empty())
        {
            std::cout << ORANGE << sOrig.front() << ", " << RESET << std::endl;
            sOrig.pop();
        }
		std::cout << std::endl;
		
	    while (!sMio.empty())
        {
            std::cout << CYAN << sMio.front() << ", " << RESET << std::endl;
            sMio.pop();
        }
        std::cout << std::endl;
	}
	else
	{
        std::cout << GREEN"Original queue\t\tMy queue"RESET << std::endl;
		while (!sOrig.empty())
        {
            std::cout << ORANGE"\t" << sOrig.front()  << "\t\t"CYAN  << sMio.front() << RESET << std::endl;
            sOrig.pop();
            sMio.pop();
        }
		std::cout << std::endl;
	}

    std::cout << std::endl;
    
}


template <class T>
void qPrint(std::queue<T> qOrig, ft::queue<T> qMio)
{
	if (qOrig.size() != qMio.size())
	{
		std::cout << RED << "Sizes are not the same. Printing as separete blocks" << RESET << std::endl;
		while (!qOrig.empty())
        {
            std::cout << ORANGE << qOrig.front() << ", " << RESET << std::endl;
            qOrig.pop();
        }
		std::cout << std::endl;
		
	    while (!qMio.empty())
        {
            std::cout << CYAN << qMio.front() << ", " << RESET << std::endl;
            qMio.pop();
        }
        std::cout << std::endl;
	}
	else
	{
        std::cout << GREEN"Original queue\t\tMy queue"RESET << std::endl;
		while (!qOrig.empty())
        {
            std::cout << ORANGE"\t" << qOrig.front()  << "\t\t"CYAN  << qMio.front() << RESET << std::endl;
            qOrig.pop();
            qMio.pop();
        }
		std::cout << std::endl;
	}

    std::cout << std::endl;
    
}


template <class T>
void qClear(std::queue<T> *qOrig, ft::queue<T> *qMio)
{
    system("clear");
    printTestHeader("QUEUE");
	std::cout << RED"****************** TESTING MODIFIER & ACCESS ELEMENTS ******************" << RESET << std::endl;
    std::cout << YELLOW << "\nCleaning qOrig and qMio using pop() function and front() to show the value\n" << RESET << std::endl;
    while (!qOrig->empty())
    {
        std::cout << ORANGE"Popped Value from qOrig:\t" << qOrig->front() << RESET << std::endl;
        qOrig->pop();
    }
    std::cout << std::endl;
    while (!qMio->empty())
    {
        std::cout << CYAN"Popped Value from qMio3:\t" << qMio->front() << RESET << std::endl;
        qMio->pop();
    }
    std::cout << std::endl;
    pressAnyKey("Original and implamentation of Queue was clean and emptied");
}

/***
 * 
 * */

template <class T>
void	qRelational(std::queue<T> qOrig, ft::queue<T> qMio)
{
    system("clear");
	printTestHeader("QUEUE");
	std::cout << RED"****************** TESTING RELATIONAL OPERATORS ******************" << RESET << std::endl;
	std::cout << BLUE"\nCreating queues to test: foo, myfoo, bar and mybar\n" << RESET << std::endl;
	std::queue<int>	foo(qOrig);
	ft::queue<int>	myfoo(qMio);
	std::queue<int>	bar(qOrig);
	ft::queue<int>	mybar(qMio);

    std::cout << ORANGE"\nPrinting foo and myfoon \n" << RESET << std::endl;
    qPrint(foo, myfoo);
    std::cout << ORANGE"\nPrinting bar and mybar \n" << RESET << std::endl;
    qPrint(bar, mybar);

	std::cout << ORANGE"\n\nChecking relational operators:" << RESET << std::endl;
	std::cout << ORANGE"--- qOrig --- \t\t\t\t\t\t" << CYAN"--- qMio ---" << RESET << std::endl;
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
void	qModifier(std::queue<T> *qOrig, ft::queue<T> *qMio)
{
    system("clear");
    printTestHeader("QUEUE");
    std::cout << RED"****************** TESTING ELEMENT ACCESS ******************" << RESET << std::endl;

	std::cout << ORANGE"\n\nTesting push() function on qOrig and qMio:" << RESET << std::endl;
	std::cout << ORANGE"Pushing {69, 73, 93} values:\n" << RESET << std::endl;
    
    std::cout << ORANGE"\nPrinting qOrig and qMio before pushing\n" << RESET << std::endl;
    qPrint(*(qOrig), *(qMio));
	
    qOrig->push(69);
	qOrig->push(73);
	qOrig->push(93);

	qMio->push(69);
	qMio->push(73);
	qMio->push(93);

    std::cout << ORANGE"\nPrinting qOrig and qMio after pushing\n" << RESET << std::endl;
    qPrint(*(qOrig), *(qMio));

	std::cout << ORANGE"\nTesting pop() function on qOrig and qMio. Popping to the next element of queue:\n" << RESET << std::endl;
	qOrig->pop();
	qMio->pop();
    std::cout << ORANGE"\nPrinting qOrig and qMio after Popping\n" << RESET << std::endl;
    qPrint(*(qOrig), *(qMio));

	std::cout << ORANGE"Now the front of the container is (qOrig.front()): \t" << RESET << qOrig->front() << RESET << std::endl;
	std::cout << CYAN"Now the front of the container is (qMio.front()): \t" << RESET << qMio->front() << RESET << std::endl;
    std::cout << std::endl;
	pressAnyKey();
}

template <class T>
void	qAccess(std::queue<T> qOrig, ft::queue<T> qMio)
{
    system("clear");
    printTestHeader("QUEUE");
	std::cout << RED"****************** TESTING ELEMENT ACCESS ******************" << RESET << std::endl;
    std::cout << ORANGE"\nPrinting qOrig and qMio \n" << RESET << std::endl;
    qPrint(qOrig, qMio);

	std::cout << ORANGE"\n\nTesting front() and back() functions:" << RESET << std::endl;
	std::cout << GREEN"Container qOrig front() points to: " << RESET << qOrig.front() << RESET << std::endl;
	std::cout << GREEN"Container qOrig back() points to: " << RESET << qOrig.back() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << GREEN"Container qMio front() points to: " << RESET << qMio.front() << RESET << std::endl;
	std::cout << GREEN"Container qMio back() points to: " << RESET << qMio.back() << RESET << std::endl;
    std::cout << std::endl;
	
    pressAnyKey();
}

void queueExec()
{
    system("clear");
    printTestHeader("QUEUE");
	std::cout << RED"****************** TESTING CONSTRUCTORS ******************" << RESET << std::endl;
	std::cout << YELLOW"\nEmpty Constructor. Constructs an empty container, with no elements" << RESET << std::endl << std::endl;
	std::cout << YELLOW"Queue constructor qOrig and qMio Queue<int>\n" << RESET << std::endl;
	std::queue<int> qOrig;
	ft::queue<int> qMio;
    
    std::cout << ORANGE"\nPrinting empty qOrig and qMio \n" << RESET << std::endl;
    qPrint(qOrig, qMio);
	std::cout << YELLOW"Checking qOrig size at empty queue container:\t" << RESET << qOrig.size() << std::endl;
	std::cout << YELLOW"Checking qMio size at empty queue container:\t" << RESET << qMio.size() << std::endl;

    std::cout << YELLOW"\nTesting empty function on both containers qOrig and qMio\n" << RESET << std::endl;
	if (qOrig.empty())
		std::cout << ORANGE"Container qOrig is empty" << std::endl;
	else
		std::cout << ORANGE"Container qOrig is not empty" << std::endl;
	if (qMio.empty())
		std::cout << CYAN"Container qMio is empty" << std::endl;
	else
		std::cout << CYAN"Container qMio is not empty" << std::endl;

	std::list<int>	listOrig(4, 42);
	ft::list<int>	listMio(4, 42);
	
    
    
    std::cout << YELLOW"\nCreating qOrig2 queue as copy of list (4, 42) passing list as second argument of container class Queue:\n" << RESET << std::endl;
	std::queue<int, std::list<int> > qOrig2(listOrig);
	ft::queue<int, ft::list<int> > qMio2(listMio);
    qPrintUnderL(qOrig2, qMio2);
	
    std::cout << YELLOW"Checking qOrig2 size after creating as copy of listOrig:\t" << RESET << qOrig2.size() << std::endl;
	std::cout << YELLOW"Checking qMio2 size after creating as copy of listMio:\t\t" << RESET << qMio2.size() << std::endl;
	
    std::cout << YELLOW"\nTesting empty function on both containers qOrig and qMio\n" << RESET << std::endl;
    if (qOrig2.empty())
		std::cout << ORANGE"Container qOrig2 is empty" << std::endl;
	else
		std::cout << ORANGE"Container qOrig2 is not empty" << std::endl;
	
    if (qMio2.empty())
		std::cout << CYAN"Container qMio2 is empty" << std::endl;
	else
		std::cout << CYAN"Container qMio2 is not empty" <<  RESET << std::endl;
    
    std::cout << std::endl;

    pressAnyKey();

    system("clear");
    printTestHeader("QUEUE");
	std::cout << RED"****************** TESTING MODIFIER ELEMENTS PUSH ******************" << RESET << std::endl;
    std::cout << ORANGE"\nPrinting qOrig and qMio before pushing {12, 13} \n" << RESET << std::endl;
    qPrint(qOrig, qMio);
    qOrig.push(12);
    qOrig.push(13);
    qMio.push(12);
    qMio.push(13);
    std::cout << ORANGE"\nPrinting qOrig and qMio After pushing\n" << RESET << std::endl;
    qPrint(qOrig, qMio);
    
    pressAnyKey();
    system("clear");
    printTestHeader("QUEUE");
	std::cout << RED"****************** TESTING MODIFIER ELEMENTS POP ******************" << RESET << std::endl;
    std::cout << ORANGE"\nPrinting qOrig and qMio before popping {12, 13} \n" << RESET << std::endl;
    qPrint(qOrig, qMio);
    qClear(&qOrig, &qMio);
    std::cout << ORANGE"\nPrinting qOrig and qMio after poping {12, 13} \n" << RESET << std::endl;
    qPrint(qOrig, qMio);

    std::cout << ORANGE"\nAdding some values to qOrig and qMio" << RESET << std::endl;
    qOrig.push(4);
	qOrig.push(8);
	qOrig.push(15);
    qOrig.push(16);
    qOrig.push(23);
    qOrig.push(42);
	qMio.push(4);
	qMio.push(8);
	qMio.push(15);
    qMio.push(16);
    qMio.push(23);
    qMio.push(42);
    
    std::cout << ORANGE"\nPrinting qOrig and qMio \n" << RESET << std::endl;
    qPrint(qOrig, qMio);
    
    pressAnyKey();

    qAccess(qOrig, qMio);

    qModifier(&qOrig, &qMio);

    qRelational(qOrig, qMio);

    pressAnyKey("Finishing QUEUE test. Press any key to return to the main menu");
}