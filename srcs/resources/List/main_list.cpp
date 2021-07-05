#include "List.hpp"
#include <list>

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
	{
	ft::list<int> miLista;
	ft::list<int> otraLista;
	ft::list<int>::iterator it;
	ft::list<int>::iterator otroIt;
	
	miLista.push_back(42);
	miLista.push_back(56);
	miLista.push_back(102);

	otraLista.push_back(200);
	otraLista.push_back(14);
	otraLista.push_back(7);
	
	it = miLista.begin();
	std::cout << std::endl << "********** miLista ********" << std::endl;
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;

	it = miLista.begin();
	otroIt = otraLista.begin();
	it++; // que es 56
	otroIt++; // qie es 14;
	miLista.splice(it, otraLista, otroIt); // vamos a poner 14 delante de 56

	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;

	it = miLista.begin();
	otroIt = otraLista.begin();

	miLista.splice(it, otraLista, otroIt, otraLista.end());
	
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;

	miLista.remove(7);
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	
	miLista.remove_if(*predTest);
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;

	miLista.push_back(42);
	miLista.push_back(42);
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	miLista.unique(*binPredTest);
	std::cout << std::endl << "********** miLista ********" << std::endl;
	otraLista.push_back(39);
	otraLista.push_back(201);
	otraLista.push_back(300);
	otraLista.push_back(9);
	otraLista.sort();
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;
	
	std::cout << std::endl << "********** miLista ********" << std::endl;
	miLista.sort();
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	
	std::cout << std::endl << "********** miLista ********" << std::endl;
	miLista.merge(otraLista);
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << "Nunero de elementos de miLista: " << miLista.size() << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;
	
	std::cout << "Nunero de elementos de otraLista: " << otraLista.size() << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otraLista.push_back(2036);
	otraLista.push_back(2);
	otraLista.push_back(3);
	//otraLista.sort();
	otraLista.sort(*compTest);
	miLista.merge(otraLista, compTest);
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	miLista.reverse();
	otraLista.push_back(754);
	miLista.swap(otraLista);
	std::cout << std::endl << "********** otraLista revertida ********" << std::endl;
	it = otraLista.begin();
	while (it != otraLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;

	if (otraLista != miLista)
		std::cout << "OtraLista y MiLista son distintas" << std::endl;
	else
		std::cout << "Las dos son iguales" << std::endl;
	}
	/*************************** Original ****************************/
	{
	std::list<int> miLista;
	std::list<int> otraLista;
	std::list<int>::iterator it;
	std::list<int>::iterator otroIt;

	miLista.push_back(42);
	miLista.push_back(56);
	miLista.push_back(102);

	otraLista.push_back(200);
	otraLista.push_back(14);
	otraLista.push_back(7);

	it = miLista.begin();
	std::cout << std::endl << "********** miLista ********" << std::endl;
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;

	it = miLista.begin();
	otroIt = otraLista.begin();
	it++; // que es 56
	otroIt++; // qie es 14;
	miLista.splice(it, otraLista, otroIt); // vamos a poner 14 delante de 56

	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;

	it = miLista.begin();
	otroIt = otraLista.begin();

	miLista.splice(it, otraLista, otroIt, otraLista.end());

	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;

	miLista.remove(7);
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;

	miLista.remove_if(*predTest);
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;

	miLista.push_back(42);
	miLista.push_back(42);
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	miLista.unique(*binPredTest);
	std::cout << std::endl << "********** miLista ********" << std::endl;
	otraLista.push_back(39);
	otraLista.push_back(201);
	otraLista.push_back(300);
	otraLista.push_back(9);
	otraLista.sort();
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;

	std::cout << std::endl << "********** miLista ********" << std::endl;
	miLista.sort();
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;

	std::cout << std::endl << "********** miLista ********" << std::endl;
	miLista.merge(otraLista);
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << "Nunero de elementos de miLista: " << miLista.size() << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otroIt = otraLista.begin();
	while (otroIt != otraLista.end())
		std::cout << *(otroIt++) << std::endl;

	std::cout << "Nunero de elementos de otraLista: " << otraLista.size() << std::endl;
	std::cout << std::endl << "********** otraLista ********" << std::endl;
	otraLista.push_back(2036);
	otraLista.push_back(2);
	otraLista.push_back(3);
	//otraLista.sort();
	otraLista.sort(*compTest);
	miLista.merge(otraLista, compTest);
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;
	miLista.reverse();
	otraLista.push_back(754);
	miLista.swap(otraLista);
	std::cout << std::endl << "********** otraLista revertida ********" << std::endl;
	it = otraLista.begin();
	while (it != otraLista.end())
		std::cout << *(it++) << std::endl;
	std::cout << std::endl << "********** miLista ********" << std::endl;
	it = miLista.begin();
	while (it != miLista.end())
		std::cout << *(it++) << std::endl;

	if (otraLista != miLista)
		std::cout << "OtraLista y MiLista son distintas" << std::endl;
	else
		std::cout << "Las dos son iguales" << std::endl;
	}
//	std::system("leaks a.out");
	return (0);
}
