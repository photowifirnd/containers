# include <iostream>
# include <iomanip>
# include <string>
# include "testing.hpp"

int		check_list(void);
int		check_vector(void);
int		check_map(void);
int		check_queue(void);
int		check_stack(void);

void	sigHandler(int sig)
{
	write(1, "\033[2D\033[J", 7);
	if (sig == SIGFPE || sig == SIGINT)
	{
		std::cout << ORANGE"Exiting from tester. Press any key to finish and exit" << std::endl;
		sleep(1);
		system("clear");
		std::cout <<BLUE"See you soon" << RESET << std::endl;
		exit(0);
	}
}

void	main_menu()
{
	signal(SIGPIPE, sigHandler);
	signal(SIGINT, sigHandler);
	std::cout << std::endl;
	std::cout << GREEN"============================= Main Menu =============================" << std::endl;
	std::cout << GREEN"*"<< std::setw(68)<< "*" << std::endl;
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(10) << GREEN << "Option [1]" << std::setfill('.') << std::setw(50) << std::right << "Test List Container" << std::setfill(' ') << std::setw(11) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(74) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(10) << GREEN << "Option [2]" << std::setfill('.') << std::setw(50) << "Test Vector Container" << std::setfill(' ') << std::setw(11) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(74) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(10) << GREEN << "Option [3]" << std::setfill('.') << std::setw(50) << "Test Map Container" << std::setfill(' ') << std::setw(11) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(74) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(10) << GREEN << "Option [4]" << std::setfill('.') << std::setw(50) << "Test Queue Container" << std::setfill(' ') << std::setw(11) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(74) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(10) << GREEN << "Option [5]" << std::setfill('.') << std::setw(50) << "Test Stack Container" << std::setfill(' ') << std::setw(11) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(74) << GREEN << "*\n";
	std::cout << GREEN"*" << std::setfill(' ') << std::setw(10) << GREEN << "Option [0]" << std::setfill('.') << std::setw(50) << "Exit" << std::setfill(' ') << std::setw(11) << GREEN << "*\n";
	std::cout << GREEN"*"<< std::setw(68)<< "*" << std::endl;
	std::cout << GREEN"=====================================================================" << std::endl;
}

int main()
{
	system("clear");
	std::cout << std::flush;
	std::cout << std::endl;
	std::string input;
	std::string  powered = ("\033[48;5;208m\033[38;5;16m\033[3m\033[1m\t\t\tpowered by jheras-f   \033[m");

	while (1)
	{
		printContainerHeader();
		main_menu();
		std::cout << powered << std::endl;
		std::cout << std::right << ORANGE"Type your option: " << RESET;
		std::getline(std::cin, input);
		
		if (input == "1")
		{
			check_list();
			system("clear");
		}
		else if (input == "2")
		{
			check_vector();
			system("clear");
		}
		else if (input == "3")
		{
			check_map();
			system("clear");
		}
		else if (input == "4")
		{
			check_queue();
			system("clear");
		}
		else if (input == "5")
		{
			check_stack();
			system("clear");
		}
		else if(input == "0")
			break ;
		else
		{
			std::cout << RED;
			std::cout << "Not a valid option. Pleas make another selection" << std::endl;
			sleep(1/2);
			system("clear");
			std::cout << RESET;
		}
	}
	
	return 0;
}
