#include "testing.hpp"

void nothing()
{

    std::cout << std::flush << std::flush;
    system("clear");

    std::cout << std::flush << std::flush;
    system("clear");
    std::cout << std::setw(57) << GREEN"*********************************" << std::endl;
	std::cout << std::setw(40) << "* QUEUE TESTER *" << std::endl;
	std::cout << std::setw(50) << "*********************************" << std::endl << RESET << std::endl;
    
    std::map<int, int, moduleCmp>  m;
    std::map<int, int>::iterator it;
    m.insert(std::pair<int, int>(4,4));
    m.insert(std::pair<int, int>(6,4));
    m.insert(std::pair<int, int>(8,4));
    m.insert(std::pair<int, int>(3,4));
    m.insert(std::pair<int, int>(1,4));
    m.insert(std::pair<int, int>(7,4));
    ft::map<int, int, moduleCmp>  m2;
    ft::map<int, int>::iterator it2;
    m2.insert(std::pair<int, int>(4,4));
    m2.insert(std::pair<int, int>(6,4));
    m2.insert(std::pair<int, int>(8,4));
    m2.insert(std::pair<int, int>(3,4));
    m2.insert(std::pair<int, int>(1,4));
    m2.insert(std::pair<int, int>(7,4));
    //m.draw(m.getRoot());
    it = m.begin();
    it2 = m2.begin();
    /* std::cout << " begin: " << it->first << " | " << it2->first << std::endl;
    it++; it2++;
    std::cout << " begin: " << it->first << " | " << it2->first << std::endl;
    it++; it2++;
    std::cout << " begin: " << it->first << " | " << it2->first << std::endl; */
    
    while (it != m.end())
    {
        std::cout << " or: " << it->first  << std::endl;
        it++;
    }
    std::cout << "*****\n";
    while (it2 != m2.end())
    {
        std::cout << " ft: "  << it2->first << std::endl;
        it2++;
    }
	
    std::cout << std::setw(57) << GREEN"*********************************" << std::endl;
	std::cout << std::setw(40) << "* STACK TESTER *" << std::endl;
	std::cout << std::setw(50) << "*********************************" << std::endl << RESET << std::endl;
    std::cout << "Stack test is Running" << std::endl;
    
    std::cout << std::endl;
	std::string input;
	
    std::cout << RED"Press any key to continue..." << RESET << std::endl;
    std::cin.get();
}

void printTestHeader(const std::string &str)
{
    std::cout << std::setw(57) << GREEN"*********************************" << std::endl;
	std::cout << std::setw(30) << "* " << str << " TEST *" << std::endl;
	std::cout << std::setw(50) << "*********************************" << std::endl << RESET << std::endl;
}

void printContainerHeader()
{
		std::cout << std::setw(57) << GREEN"*********************************" << std::endl;
		std::cout << std::setw(45) << "* FT_CONTAINERS TESTER *" << std::endl;
		std::cout << std::setw(50) << "*********************************" << std::endl << RESET << std::endl;
}

bool c_insensitive (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

bool same_integral_part (double first, double second)
{
    return (int(first) == int(second));
}

bool compLess (double first, double second)
{
    return ( int(first)<int(second) );
}
bool compByDigit (const int& value)
{
    return (value < 10);
}
void pressAnyKey(const std::string &test)
{
    std::cout << POWERED << std::endl;
    if (test.size())
	    std::cout << std::endl << ORANGE << test << std::endl;
    else
        std::cout << ORANGE"Press any key to continue..." << RESET << std::endl;
    std::cin.get();
    std::cout << std::flush << std::flush;
    system("clear");

}

int		check_list(void)
{
    std::cout << std::flush << std::flush;
    system("clear");
  
    listExec();
	
    return (0);
}
int		check_vector(void)
{
    
    std::cout << std::flush << std::flush;
    system("clear");
    
    vectorExec();
    return (0);
}
int		check_map(void)
{
    std::cout << std::flush << std::flush;
    system("clear");
    
    mapExec();
    
    return (0);
}
int		check_queue(void)
{
    
    std::cout << std::flush << std::flush;
    system("clear");
  
    queueExec();
    
    return (0);
}
int		check_stack(void)
{

    std::cout << std::flush << std::flush;
    system("clear");
  
    stackExec();
    
    return (0);
}