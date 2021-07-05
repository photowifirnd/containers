#include <vector>
#include <iostream>

bool binPredTest(int val1, int val2)
{
	if (val1 == val2)
		return (true);
	return (false);
}

bool predTest(int val)
{
	return (val == 42);
}

bool compTest(int val1, int val2)
{
	return (val1 < val2);
}


int main(void)
{
	std::cout << "******* Constructors ********" << std::endl;
	{
		std::cout << "\tEmpty constructor miLista0" << std::endl;
		std::vector<int> miLista0;
		std::cout << "\tRange constructor miLista1(5, 200)" << std::endl;
		std::vector<int> miLista1(5, 200);
		std::cout << "\tCopy constructor miLista2(miLista1)" << std::endl;
		std::vector<int> miLista2(miLista1);
		std::cout << "\tAsignation constructor miLista0 = miLista1" << std::endl;
		miLista0 = miLista2;
		std::cout << "\t-------" << std::endl;
		std::cout << "\t* printing values of miLista0" << std::endl;
		std::vector<int>::iterator it = miLista0.begin();
		while (it != miLista0.end())
			std::cout << "\t\t- Values: " << *(it++) << std::endl;
	}

	std::cout << "\n******** Iterators ********" << std::endl;
	{
		std::vector<int>::iterator it;
		std::cout << "\t* begin() and end() iterator" << std::endl;
		std::vector<int> miLista1;
		miLista1.push_back(12);
		miLista1.push_back(7);
		miLista1.push_back(23);
		it = miLista1.begin();
		while (it != miLista1.end())
			std::cout << "\t\t- Values: " << *(it++) << std::endl;
		std::cout << "\t* rbegin() and rend() reverse iterator" << std::endl;
		std::vector<int>::reverse_iterator rit = miLista1.rbegin();
		while (rit != miLista1.rend())
			std::cout << "\t\t- Values: " << *(rit++) << std::endl;
	}

	std::cout << "\n******** Capacity ********" << std::endl;
	{
		std::vector<int> miLista0;
		std::vector<int>::iterator it;
		std::cout << "\t* max_size() of miLista0: " << miLista0.max_size() << std::endl;
		std::cout << "\n\t-------\n" << std::endl;
		std::cout << "\t* miLista0 inizialited but empty" << std::endl;
		if (miLista0.empty())
			std::cout << "\t\tList has no values" << std::endl;
		else
			std::cout << "\t\tNumber of elements: " << miLista0.size();
		std::cout << "\n\t-------\n" << std::endl;
		std::cout << "\t* miLista0 with 5 values added through push_front()" << std::endl;
		miLista0.push_back(8);
		miLista0.push_back(28);
		miLista0.push_back(33);
		miLista0.push_back(100);
		miLista0.push_back(209);
		it = miLista0.begin();
		if (!miLista0.empty())
		{
			std::cout << "\t\t# Number of elements: " << miLista0.size() << std::endl;
			while (it != miLista0.end())
				std::cout << "\t\t\t- Values: " << *(it++) << std::endl;
		}
		else
			std::cout << "\t\t# List has no values" << std::endl;
	}
	
	std::cout << "\n******** Element access ********" << std::endl;
	{
		std::vector<int> miLista0;
		std::vector<int>::iterator it;

		for (int i = 1; i <= 10; i++)
			miLista0.push_back(i * 7);
		std::cout << "\t* Showing first and last elements of miLista0" << std::endl;
		it = miLista0.begin();
		std::cout << "\t\t# First element of miLista0 using front(): " << miLista0.front() << std::endl;
		std::cout << "\t\t# Last element of miLista0 using back(): " << miLista0.back() << std::endl;
		std::cout << "\t* Content of miLista0: " << std::endl;
		while (it != miLista0.end())
			std::cout << "\t\t\t - Values: " << *(it++) << std::endl;
	}
	
	std::cout << "\n******** Modifiers ********" << std::endl;
	{
		std::vector<int> miLista0;
		std::vector<int> miLista1;
		std::vector<int> miLista2;
		std::vector<int>::iterator it0;
		std::vector<int>::iterator it1;

		std::cout << "\t* Using 3 lists: miLista0, miLista1 and miLista2" << std::endl;
		for (int i = 1; i <= 10; i++)
			miLista0.push_back(i * 9);
		std::cout << "\t\t# miLista0 added with push_back: " << std::endl;
		it0 = miLista0.begin();
		while (it0 != miLista0.end())
			std::cout << "\t\t\t- Values: " << *(it0++) << std::endl;
		std::cout << "\t\t# Assign modifier: " << std::endl;
		it0 = miLista0.begin();
		it1 = miLista0.end();
		std::cout << "\t\t\t>> Value of it0 as first: " << *++it0 << std::endl;
		std::cout << "\t\t\t>> Value of it1 as last: " << *--it1 << std::endl;

		miLista1.assign(it0, it1);
		it0 = miLista1.begin();
		std::cout << "\t\t\t\t> Assign values miLista1.assign(first, last)" << std::endl;
		while (it0 != miLista1.end())
			std::cout << "\t\t\t\t\t- Values: " << *(it0++) << std::endl;

		miLista2.assign(5, miLista0.back());
		it0 = miLista2.begin();
		std::cout << "\t\t\t\t> Assign last value of miLista0 to miLista2.assign(n, val)" << std::endl;
		while (it0 != miLista2.end())
			std::cout << "\t\t\t\t\t- Values: " << *(it0++) << std::endl;

		std::cout << "\t\t# pop_back() modifier: " << std::endl;
		while (!miLista1.empty())
		{
			std::cout << "\t\t\t- Poping value: " << miLista1.back() << std::endl;
			miLista1.pop_back();
		
		}
		std::cout << "\t\t# pop_back() modifier" << std::endl;
		it0 = miLista0.begin();
		it1 = miLista0.end();
		miLista1.assign(++it0, --it1);
		while (!miLista1.empty())
		{
			std::cout << "\t\t\t- Poping value: " << miLista1.back() << std::endl;
			miLista1.pop_back();
		}

		std::cout << "\t\t* Insert modifier" << std::endl;
		
		std::cout << "\t\t\t# miLista2.insert(position, valyy)" << std::endl;
		it0 = miLista2.begin();
		it0++;
		miLista2.insert(it0, 42);
		it0 = miLista2.begin();
		for (size_t i = 0; i < miLista2.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		
		std::cout << "\t\t\t# miLista2.insert(position, n, val)" << std::endl;
		it0 = miLista2.begin();
		it0++;
		miLista2.insert(it0, 5, 43);
		it0 = miLista2.begin();
		for (size_t i = 0; i < miLista2.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		
		std::cout << "\t\t\t# miLista2.insert(position, first, last)" << std::endl;
		it0 = miLista0.begin();
		it1 = miLista0.end();
	
		std::vector<int>::iterator it3 = miLista2.begin();
		it3++;	
		std::cout << miLista2.size()<< std::endl;
		miLista2.insert(it3, it0, it1);
		std::cout << miLista2.size()<< std::endl;
		it0 = miLista2.begin();
		for (size_t i = 0; i < miLista2.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
	
		std::cout << "\t\t* Erase modifier" << std::endl;
		std::cout << "\t\t\t# miLista2.erase(position)" << std::endl;
		miLista2.erase(miLista2.begin());
		it0 = miLista2.begin(); //erase vector see what is happening
		while (it0 != miLista2.end())
			std::cout << "\t\t\t\t- Value: " << *(it0++) << std::endl;

		std::cout << "\t\t\t# miLista2.erase(first, last)" << std::endl;
		it0 = miLista2.begin();
		it0 = miLista2.erase(it0);
		it0 = miLista2.begin();

		std::cout << "\t\t\t > Begin of miLista2: " << *it0 << std::endl;

		it1 = miLista2.end();
		it1 = miLista2.erase(--it1);
		//it1 = miLista2.end();
		
		if (it1 == miLista2.end())
			std::cout << "it1 == end" << std::endl;

		miLista2.erase(++it0, --it1); //Ver que pasa en los erase... fíjate en como hiciste list y map
		it0 = miLista2.begin();
		for (size_t i = 0; i < miLista2.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
/*
		std::cout << "\t\t# Swap modifier" << std::endl;
		miLista1.assign(miLista0.begin(), miLista0.end());	
		std::cout << "\t\t\t* miLista1" << std::endl;
		it0 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		
		std::cout << "\t\t\t* miLista2" << std::endl;
		it0 = miLista2.begin();
		for (size_t i = 0; i < miLista2.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;

		std::cout << "\t\t\t* Swapping miLista2 with miLista1" << std::endl;
		miLista2.swap(miLista1);
		std::cout << "\t\t\t* miLista1" << std::endl;
		it0 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		
		std::cout << "\t\t\t* miLista2" << std::endl;
		it0 = miLista2.begin();
		for (size_t i = 0; i < miLista2.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;

		std::cout << "\t\t# Resize modifier" << std::endl;
		miLista1.resize(10, 42);
		std::cout << "\t\t\t* miLista1 resized by 10 elements set to 42" << std::endl;
		it0 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;

		std::cout << "\t\t# Clear modifier" << std::endl;
		std::cout << "\t\t\t* miLista1 cleared" << std::endl;
		miLista1.clear();
		it0 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		*/
	}
/*	
	std::cout << "\n******** Operations ********" << std::endl;
	{
		std::list<int> miLista0;
		std::list<int> miLista1;
		std::list<int>::iterator it0;
		std::list<int>::iterator it1;

		for (size_t i = 1; i <= 10; i++)
			miLista0.push_back(i * 5);
		std::cout << "\t\t* Splice operation" << std::endl;
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;

		miLista1.push_front(19);
		it1 = miLista1.begin();
		miLista1.splice(it1, miLista0);
		it1 = miLista1.begin();
		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
		
		std::cout << "\t\t\t# Content of miLista0 after splice" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
	}
	
	{
		std::list<int> miLista0;
		std::list<int> miLista1;
		std::list<int>::iterator it0;
		std::list<int>::iterator it1;
		std::list<int>::iterator it3;

		for (int i = 1; i <= 10; i++)
			miLista0.push_front(i * 7);
		std::cout << "\t\t* Splice operation (position, list, first, last)" << std::endl;
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		it0 = miLista0.begin();
		it1 = miLista0.end();

		it3 = miLista1.begin();
		it0++;
		it1--;

		miLista1.splice(it3, miLista0, it0, it1);
		it1 = miLista1.begin();
		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
	}

	{
		std::list<int> miLista0;
		std::list<int>::iterator it0;

		for (size_t i = 1; i <= 10; i++)
			miLista0.push_back(i * 8);
		std::cout << "\t\t* Remove operation" << std::endl;
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		miLista0.remove(16);
		std::cout << "\t\t\t# Content of miLista0 after removing value 16" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
	}

	{
		std::list<int> miLista0;
		std::list<int>::iterator it0;

		for (size_t i = 1; i <= 10; i++)
			miLista0.push_back(i * 6);
		std::cout << "\t\t* Remove_if operation" << std::endl;
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		miLista0.remove_if(*predTest);
		std::cout << "\t\t\t# Content of miLista0 after removing value 42" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
	}
	
	{
		std::list<int> miLista0;
		std::list<int> miLista1;
		std::list<int>::iterator it0;

		miLista0.push_front(17);
		miLista0.push_front(17);
		miLista0.push_front(13);
		miLista0.push_front(12);
		miLista0.push_front(12);

		miLista1.push_front(16);
		miLista1.push_front(16);
		miLista1.push_front(13);
		miLista1.push_front(18);
		miLista1.push_front(19);
		
		std::cout << "\t\t* Unique operation" << std::endl;
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		miLista0.unique();
		std::cout << "\t\t\t# Content of miLista0 after apllying unique()" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		
		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		it0 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;

		miLista1.unique(*binPredTest);

		std::cout << "\t\t\t# Content of miLista1 after apllying unique(*binPredTest)" << std::endl;
		it0 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
	}

	{
		std::list<int> miLista0;
		std::list<int> miLista1;
		std::list<int>::iterator it0;
		std::list<int>::iterator it1;

		miLista0.push_front(17);
		miLista0.push_front(13);
		miLista0.push_front(12);

		miLista1.push_front(15);
		miLista1.push_front(42);
		miLista1.push_front(7);

		std::cout << "\t\t* Merge operation" << std::endl;
		
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		it1 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
		
		miLista0.merge(miLista1);
		
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		it1 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
	}

	{
		std::list<int> miLista0;
		std::list<int> miLista1;
		std::list<int>::iterator it0;
		std::list<int>::iterator it1;

		miLista0.push_front(17);
		miLista0.push_front(13);
		miLista0.push_front(12);

		miLista1.push_front(15);
		miLista1.push_front(42);
		miLista1.push_front(7);

		std::cout << "\t\t* Merge operation merge(list &x, Compare comp)" << std::endl;
		
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		it1 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
		
		miLista0.merge(miLista1, *compTest);
		
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		it1 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
	}

	{
		std::list<int> miLista0;
		std::list<int> miLista1;
		std::list<int>::iterator it0;
		std::list<int>::iterator it1;

		miLista0.push_back(23);
		miLista0.push_back(2);
		miLista0.push_back(6);
		miLista0.push_back(45);
		miLista0.push_back(12);
		
		miLista1.push_back(46);
		miLista1.push_back(4);
		miLista1.push_back(12);
		miLista1.push_back(90);
		miLista1.push_back(24);
		std::cout << "\t\t* Sort operation" << std::endl;
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		miLista0.sort();
		std::cout << "\t\t\t# Content of miLista0.sort()" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;

		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		it1 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
		miLista1.sort(*compTest);
		std::cout << "\t\t\t# Content of miLista1.sort(Compare comp)" << std::endl;
		it1 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
		miLista1.reverse();

		std::cout << "\t\t* reverse operation" << std::endl;
		std::cout << "\t\t\t# Content of miLista1.reverse()" << std::endl;
		it1 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
	}

	std::cout << "******** Relational Operators ********" << std::endl;
	{
		std::list<int> miLista0;
		std::list<int> miLista1;
		std::list<int> miLista2;
		std::list<int>::iterator it0;
		std::list<int>::iterator it1;
		std::list<int>::iterator it2;

		for (size_t i = 1; i <= 10; i++)
			miLista0.push_back(i * 4);
		
		for (size_t i = 1; i <= 10; i++)
			miLista1.push_back(i * 5);
		
		miLista2 = miLista0;

		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		it0 = miLista0.begin();
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		
		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		it1 = miLista1.begin();
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;

		std::cout << "\t\t\t# Content of miLista2" << std::endl;
		it2 = miLista2.begin();
		for (size_t i = 0; i < miLista2.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it2++) << std::endl;
*/
	/**********************************************************************************/
/*
		std::cout << "\t\t* (miLista0 != miLista1) operator" << std::endl;
		if (miLista0 != miLista1)
			std::cout << "\t\t\t #MiLista0 is not equal to miLista1" << std::endl;
		
		std::cout << "\t\t* (miLista0 == miLista2) operator" << std::endl;
		if (miLista0 == miLista2)
			std::cout << "\t\t\t# MiLista0 is equal to miLista2" << std::endl;

		std::cout << "\t\t* (miLista1 > miLista2) operator" << std::endl;
		if (miLista1 > miLista2)
			std::cout << "\t\t\t# MiLista1 is grater than to miLista2" << std::endl;
		
		std::cout << "\t\t* (miLista0 < miLista1) operator" << std::endl;
		if (miLista0 < miLista1)
			std::cout << "\t\t\t# MiLista0 is lower than to miLista1" << std::endl;
		
		std::cout << "\t\t* (miLista1 >= miLista2) operator" << std::endl;
		if (miLista1 >= miLista2)
			std::cout << "\t\t\t# MiLista1 is greater or equal than to miLista2" << std::endl;
		
		std::cout << "\t\t* (miLista0 <= miLista1) operator" << std::endl;
		if (miLista0 <= miLista1)
			std::cout << "\t\t\t# MiLista0 is lower or equal than to miLista1" << std::endl;
	}

	std::cout << "******** Swap non member ********" << std::endl;
	{
		std::list<int> miLista0;
		std::list<int> miLista1;
		std::list<int>::iterator it0;
		std::list<int>::iterator it1;

		for (size_t i = 1; i <= 10; i++)
			miLista0.push_back(i * 2);
		for (size_t i = 1; i <= 10; i++)
			miLista1.push_back(i * 3);
		it0 = miLista0.begin();
		it1 = miLista1.begin();
		
		std::cout << "\t\t\t# Content of miLista0" << std::endl;
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;

		std::cout << "\t\t\t# Content of miLista1" << std::endl;
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;

		swap(miLista0, miLista1);
		
		it0 = miLista0.begin();
		it1 = miLista1.begin();
		
		std::cout << "\t\t\t# Content of swapped miLista0: swap(miLista0, miLista1)" << std::endl;
		for (size_t i = 0; i < miLista0.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it0++) << std::endl;
		
		std::cout << "\t\t\t# Content of swapped miLista1: swap(miLista0, miLista1)" << std::endl;
		for (size_t i = 0; i < miLista1.size(); i++)
			std::cout << "\t\t\t\t- Values: " << *(it1++) << std::endl;
	}
*/
//	std::system("leaks a.out");
	return (0);
}
