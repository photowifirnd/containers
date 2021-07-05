#include "Stack.hpp"
#include <stack>

int main(void)
{
	ft::stack<int> miStack1;
	miStack1.push(12);
	std::cout << "Top value: " << miStack1.top() << std::endl;
	std::cout << "Back value: " << miStack1.top() << std::endl;
	return (0);
}
