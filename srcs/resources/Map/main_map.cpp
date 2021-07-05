#include <iostream>
#include "Map.hpp"
#include <map>
#include <utility>

int main(void)
{
	
	ft::map<int, int> miMap;
	std::map<int, int> tuMap;


	miMap.insert(std::make_pair(1, 42));
	miMap.insert(std::make_pair(2, 5));
	miMap.insert(std::make_pair(3, 7));
	miMap.insert(std::make_pair(6, 73));


	tuMap.insert(std::make_pair(1, 42));
	tuMap.insert(std::make_pair(2, 5));
	tuMap.insert(std::make_pair(3, 7));
	tuMap.insert(std::make_pair(6, 73));


	ft::map<int, int>::iterator it = miMap.begin();
	std::map<int, int>::iterator tuit = tuMap.begin();

	std::cout << "******** Map mio ********" << std::endl;
	while (it != miMap.end())
	{
		std::cout << it->first << " -> " << it->second << std::endl;
		it++;
	}
	it = miMap.find(3);
	if (it != miMap.end())
		std::cout << "value of " << it->first << " is " << it->second << std::endl;
	else
		std::cout << "Value not found by key" << std::endl;
	
	it = miMap.lower_bound(2);
	std::cout << "lower_bound " << it->first << " is " << it->second << std::endl;
	it = miMap.upper_bound(2);
	std::cout << "upper_bound " << it->first << " is " << it->second << std::endl;
	
	if (miMap == miMap)
		std::cout << "Son iguales" << std::endl;
	else
		std::cout << "No son el mismo" << std::endl;
	
	/********************************************************************************/
	std::cout << "******** Map Original ********" << std::endl;
	while (tuit != tuMap.end())
	{
		std::cout << tuit->first << " -> " << tuit->second << std::endl;
		tuit++;
	}

	tuit = tuMap.find(3);
	if (tuit != tuMap.end())
		std::cout << "value of " << tuit->first << " is " << tuit->second << std::endl;
	else
		std::cout << "Value not found by key" << std::endl;

	tuit = tuMap.lower_bound(2);
	std::cout << "lower_bound " << tuit->first << " is " << tuit->second << std::endl;
	tuit = tuMap.upper_bound(2);
	std::cout << "upper_bound " << tuit->first << " is " << tuit->second << std::endl;

	if (tuMap == tuMap)
		std::cout << "Son iguales" << std::endl;
	else
		std::cout << "No son el mismo" << std::endl;
	
	std::cout << "******** End Original ********" << std::endl;
	
//	std::system("leaks a.out");
	return (0);
}
