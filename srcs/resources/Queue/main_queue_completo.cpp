#include "Queue.hpp"
#include <queue>
#include <iostream>

#ifndef MODE
#define MODE ft
#endif

int main()
{
	{
		MODE::queue<int> MyQueue;
		std::cout << MyQueue.empty() << std::endl;
		std::cout << MyQueue.size() << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::queue<int> MyQueue;
		std::cout << MyQueue.empty() << std::endl;
		MyQueue.push(88);
		std::cout << MyQueue.back() << std::endl;
		MyQueue.push(44);
		std::cout << MyQueue.back() << std::endl;
		std::cout << MyQueue.size() << std::endl;
		MyQueue.pop();
		std::cout << MyQueue.size() << std::endl;
		std::cout << MyQueue.back() << std::endl;
		MyQueue.pop();
		std::cout << MyQueue.size() << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::queue<int> MyQueue;
		std::cout << MyQueue.empty() << std::endl;
		MyQueue.push(88);
		std::cout << MyQueue.front() << std::endl;
		MyQueue.push(44);
		std::cout << MyQueue.front() << std::endl;
		std::cout << MyQueue.size() << std::endl;
		MyQueue.pop();
		std::cout << MyQueue.size() << std::endl;
		std::cout << MyQueue.front() << std::endl;
		MyQueue.pop();
		std::cout << MyQueue.size() << std::endl;
	}
	{
		MODE::queue<int> MyQueue1;
		MODE::queue<int> MyQueue2;
		MyQueue1.push(101);
		MyQueue2.push(102);

		if (MyQueue1 > MyQueue2)
			std::cout << "es mayor" << std::endl;
		
	}
	{
		MODE::queue<int> MyQueue1;
		MODE::queue<int> MyQueue2;

		MyQueue1.push(100);
		MyQueue1.push(44);

		MyQueue2.push(100);
		MyQueue2.push(44);

		if (MyQueue1 == MyQueue2)
			std::cout << "MyQueue1 is equal to MyQueue2" << std::endl;
		if (MyQueue1 != MyQueue2)
			std::cout << "MyQueue1 is distinct to MyQueue2" << std::endl;
		else
			std::cout << "MyQueue1 is is not distinct to MyQueue2" << std::endl;
		MyQueue1.pop();
		MyQueue1.pop();
		if (MyQueue1 < MyQueue2)
			std::cout << "MyQueue1 is smaller than MyQueue2" << std::endl;

		if (MyQueue1 <= MyQueue2)
			std::cout << "MyQueue1 is smaller than or equal to MyQueue2" << std::endl;

		std::cout << "Tamaño tuq1: " << MyQueue1.size() << std::endl;
		MyQueue1.push(101);
		std::cout << "Tamaño tuq1: " << MyQueue1.size() << std::endl;
		std::cout << "Tamaño tuq2: " << MyQueue2.size() << std::endl;
		if (MyQueue1 > MyQueue2)
			std::cout << "MyQueue1 is larger than MyQueue2" << std::endl;
		if (MyQueue1 >= MyQueue2)
			std::cout << "MyQueue1 is larger than or equal to MyQueue2" << std::endl;


		std::cout << "************" << std::endl;

		std::queue<int> tuQueue1;
		std::queue<int> tuQueue2;
//		std::queue<int> tuQueue3(3, 100); // no hay constructor para esto. Así que el mío está bien
		tuQueue1.push(100);
		tuQueue1.push(44);
		
		tuQueue2.push(100);
		tuQueue2.push(44);
		if (tuQueue1 == tuQueue2)
			std::cout << "tuQueue1 is equal to tuQueue2" << std::endl;
		if (tuQueue1 != tuQueue2)
			std::cout << "tuQueue1 is distinct to tuQueue2" << std::endl;
		else
			std::cout << "tuQueue1 is is not distinct to tuQueue2" << std::endl;
		tuQueue1.pop();
		tuQueue1.pop();
		if (tuQueue1 < tuQueue2)
			std::cout << "tuQueue1 is smaller than tuQueue2" << std::endl;
		if (tuQueue1 <= tuQueue2)
			std::cout << "tuQueue1 is smaller than or equal to tuQueue2" << std::endl;

		std::cout << "Tamaño tuq1: " << tuQueue1.size() << std::endl;
		tuQueue1.push(101);
		std::cout << "Tamaño tuq1: " << tuQueue1.size() << std::endl;
		std::cout << "Tamaño tuq2: " << tuQueue2.size() << std::endl;
		if (tuQueue1 > tuQueue2)
			std::cout << "tuQueue1 is larger than tuQueue2" << std::endl;
		if (tuQueue1 >= tuQueue2)
			std::cout << "tuQueue1 is larger than or equal to tuQueue2" << std::endl;

	}
}

