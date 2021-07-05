#include <stack>
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
		std::cout << "\tEmpty constructor" << std::endl;
		std::stack<int> miLista0;
		miLista0.push(32);
		miLista0.push(42);
		std::cout << "\tCopy constructor" << std::endl;
		std::stack<int> miLista1(miLista0);
		std::cout << "\tAsignation constructor" << std::endl;
		miLista0 = miLista1;
		std::cout << "\t* printing values miLista1" << std::endl;
		while (!miLista1.empty())
		{
			std::cout << "\t\t- Values: " << miLista1.top() << std::endl;
			miLista1.pop();
		}
		std::cout << "\t-------" << std::endl;
		std::cout << "\t* printing values miLista0" << std::endl;
		while (!miLista0.empty())
		{
			std::cout << "\t\t- Values: " << miLista0.top() << std::endl;
			miLista0.pop();
		}

	}

/*	std::cout << "\n******** Iterators ********" << std::endl;
	{
		std::stack<int>::iterator it;
		std::cout << "\t* begin() and end() iterator" << std::endl;
		std::stack<int> miLista1;
		miLista1.push_back(12);
		miLista1.push_back(7);
		miLista1.push_back(23);
		it = miLista1.begin();
		while (it != miLista1.end())
			std::cout << "\t\t- Values: " << *(it++) << std::endl;
		std::cout << "\t* rbegin() and rend() reverse iterator" << std::endl;
		std::stack<int>::reverse_iterator rit = miLista1.rbegin();
		while (rit != miLista1.rend())
			std::cout << "\t\t- Values: " << *(rit++) << std::endl;
	}
*/	
	std::cout << "\n******** Capacity ********" << std::endl;
	std::cout << "Int type added to miLista0" << std::endl;
	{
		std::stack<int> miLista0;
		std::cout << "\t* miLista0 inizialited but empty" << std::endl;
		if (miLista0.empty())
			std::cout << "\t\tList has no values" << std::endl;
		else
			std::cout << "\t\tNumber of elements: " << miLista0.size();
		std::cout << "\n\t-------\n" << std::endl;
		std::cout << "\t* miLista0 with 5 values added through push()" << std::endl;
		miLista0.push(8);
		miLista0.push(28);
		miLista0.push(33);
		miLista0.push(100);
		miLista0.push(209);
		if (!miLista0.empty())
		{
			std::cout << "\t\t# Number of elements: " << miLista0.size() << std::endl;
			int i = 0;
			while (!miLista0.empty())
			{
				std::cout << "\t\t\t- Value at top[" << i++ << "]: " << miLista0.top() << std::endl;
				miLista0.pop();
			}
		}
		else
			std::cout << "\t\t# List has no values" << std::endl;
		if (miLista0.empty())
			std::cout << "Now the Stact miLista0 is empty" << std::endl;
	}
	std::cout << "Char type added to miLista0" << std::endl;
	{
		std::stack<char> miLista0;
		std::cout << "\t* miLista0 inizialited but empty" << std::endl;
		if (miLista0.empty())
			std::cout << "\t\tList has no values" << std::endl;
		else
			std::cout << "\t\tNumber of elements: " << miLista0.size();
		std::cout << "\n\t-------\n" << std::endl;
		std::cout << "\t* miLista0 with 5 values added through push()" << std::endl;
		miLista0.push('a');
		miLista0.push('g');
		miLista0.push('h');
		miLista0.push('j');
		miLista0.push('e');
		if (!miLista0.empty())
		{
			std::cout << "\t\t# Number of elements: " << miLista0.size() << std::endl;
			int i = 0;
			while (!miLista0.empty())
			{
				std::cout << "\t\t\t- Value at top[" << i++ << "]: " << miLista0.top() << std::endl;
				miLista0.pop();
			}
		}
		else
			std::cout << "\t\t# List has no values" << std::endl;
		if (miLista0.empty())
			std::cout << "Now the Stact miLista0 is empty" << std::endl;
	}
	std::cout << "String type added to miLista0" << std::endl;
	{
		std::stack<std::string> miLista0;
		std::cout << "\t* miLista0 inizialited but empty" << std::endl;
		if (miLista0.empty())
			std::cout << "\t\tList has no values" << std::endl;
		else
			std::cout << "\t\tNumber of elements: " << miLista0.size();
		std::cout << "\n\t-------\n" << std::endl;
		std::cout << "\t* miLista0 with 5 values added through push()" << std::endl;
		miLista0.push("Juan");
		miLista0.push("Marta");
		miLista0.push("Lidia");
		miLista0.push("Mario");
		miLista0.push("Luigi");
		if (!miLista0.empty())
		{
			std::cout << "\t\t# Number of elements: " << miLista0.size() << std::endl;
			int i = 0;
			while (!miLista0.empty())
			{
				std::cout << "\t\t\t- Value at top[" << i++ << "]: " << miLista0.top() << std::endl;
				miLista0.pop();
			}
		}
		else
			std::cout << "\t\t# List has no values" << std::endl;
		if (miLista0.empty())
			std::cout << "Now the Stact miLista0 is empty" << std::endl;
	}
	
	std::cout << "******** Relational Operators ********" << std::endl;
	{
		std::stack<int> miLista0;
		std::stack<int> miLista1;
		std::stack<int> miLista2;

		for (size_t i = 1; i <= 10; i++)
			miLista0.push(i * 4);
		
		for (size_t i = 1; i <= 10; i++)
			miLista1.push(i * 5);
		
		miLista2 = miLista0;

	/**********************************************************************************/

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
		std::stack<int> miLista0;
		std::stack<int> miLista1;
		
		for (size_t i = 1; i <= 12; i++)
			miLista0.push(i * 2);
		for (size_t i = 1; i <= 10; i++)
			miLista1.push(i * 3);
		
		std::cout << "\t\t\t# Before swap the size of miLista0: " << miLista0.size() << std::endl;
		std::cout << "\t\t\t# Before swap the size of miLista1: " << miLista1.size() << std::endl;
		swap(miLista0, miLista1);
		std::cout << "\t\t\t# After swap the size of miLista0: " << miLista0.size() << std::endl;
		std::cout << "\t\t\t# After swap the size of miLista1: " << miLista1.size() << std::endl;
		
		
		std::cout << "\t\t\t# Content of swapped miLista0: swap(miLista0, miLista1)" << std::endl;
		for (size_t i = 0; i < miLista0.size(); i++)
		{
			std::cout << "\t\t\t\t- Values: " << miLista0.top() << std::endl;
			miLista0.pop();
		}
		
		std::cout << "\t\t\t# Content of swapped miLista1: swap(miLista0, miLista1)" << std::endl;
		for (size_t i = 0; i < miLista1.size(); i++)
		{
			std::cout << "\t\t\t\t- Values: " << miLista1.top() << std::endl;
			miLista1.pop();
		}
	
	}

//	std::system("leaks a.out");
	return (0);
}
