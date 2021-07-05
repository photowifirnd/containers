#include "Queue.hpp"
#include <queue>

int main(void)
{
	std::cout << "******** MiQueue ********" << std::endl;
	std::queue<int> miQueue1;
	std::queue<int> miQueue2;
	if (miQueue1.empty() && miQueue2.empty())
		std::cout << "Both Queues 1 & 2 are empty." << std::endl;
	std::cout << "Size of miQueue1 at construction time: " << miQueue1.size() << std::endl;
	std::cout << "Size of miQueue2 at construction time: " << miQueue2.size() << std::endl;
	miQueue1.push(12);
	miQueue2.push(11);
	std::cout << "Size of miQueue1 after pushing: " << miQueue1.size() << std::endl;
	std::cout << "Size of miQueue2 after pushing: " << miQueue2.size() << std::endl;
	miQueue1.pop();
	std::cout << "Size of miQueue1 after popping: " << miQueue1.size() << std::endl;
	miQueue1.push(13);
	std::cout << "Size of miQueue1 after pushing: " << miQueue1.size() << std::endl;
	if (miQueue1 > miQueue2)
		std::cout << "mi1 es mayor que mi2" << std::endl;
	if (miQueue1 >= miQueue2)
		std::cout << "mi1 es mayor o igual que mi2" << std::endl;

	miQueue1.pop();
	miQueue1.push(10);

	if (miQueue1 < miQueue2)
		std::cout << "mi1 es menor que mi2" << std::endl;
	if (miQueue1 <= miQueue2)
		std::cout << "mi1 es menor o igual que mi2" << std::endl;

	std::cout << "Elemento frontal miQueue1: " << miQueue1.front() << std::endl;
	std::cout << "Elemento frontal miQueue2: " << miQueue2.front() << std::endl;
	
	if (miQueue1 == miQueue2)
		std::cout << "miQueues son iguales"<< std::endl;
	if (miQueue1 != miQueue2)
		std::cout << "miQueues son distintas"<< std::endl;
	if (miQueue1 < miQueue2)
		std::cout << "miQueue1 es menor que miQueue2" << std::endl;
	if (miQueue1 > miQueue2)
		std::cout << "miQueue1 es mayor que miQueue2" << std::endl;
	miQueue2.pop();
	miQueue2.push(13);
	if (miQueue1 >= miQueue2)
		std::cout << "miQueue1 es mayor o igual que miQueue2" << std::endl;
	if (miQueue1 <= miQueue2)
		std::cout << "miQueue1 es menor o igual que miQueue2" << std::endl;
	std::cout << "*************************" << std::endl;

	miQueue1.push(23);
	miQueue1.push(34);
	miQueue1.push(66);
	miQueue1.push(78);
	miQueue1.push(2);
	miQueue1.push(11);
	
	miQueue2.push(33);
	miQueue2.push(45);
	miQueue2.push(62);
	miQueue2.push(23);
	miQueue2.push(11);
	
	
	std::cout << "Size of miQueue1: " << miQueue1.size() << std::endl;
	std::cout << "Front element miQueue1: " << miQueue1.front() << std::endl;
	std::cout << "Back element miQueue1: " << miQueue1.back() << std::endl;

	std::cout << "Size of miQueue2: " << miQueue2.size() << std::endl;
	std::cout << "Front element miQueue2: " << miQueue2.front() << std::endl;
	std::cout << "Back element miQueue2: " << miQueue2.back() << std::endl;

	if (miQueue1.empty() && miQueue2.empty())
		std::cout << "Both Queues 1 & 2 are empty." << std::endl;
	else
		std::cout << "Both Queues have data. They're not empty" << std::endl;

	return (0);
}
