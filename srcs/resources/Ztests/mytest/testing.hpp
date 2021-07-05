#ifndef TESTING_HPP
# define TESTING_HPP
# include <iomanip>
# include <cmath>
# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <map>
# include <queue>
# include <stack>
# include <iterator>
# include <signal.h>
# include <unistd.h>

# include "List.hpp"
# include "Map.hpp"
# include "Queue.hpp"
# include "Stack.hpp"
# include "Vector.hpp"
# include "MyClass.hpp"

/* Ansi escape code*/
# define POWERED    "\033[48;5;208m\033[38;5;16m\033[3m\033[1m\t\t\tpowered by jheras-f   \033[m\n"
# define YELLOW     "\033[33m"
# define WHITE      "\033[37m"
# define RED		"\033[1;31m"
# define GREEN		"\033[9;32m"
# define BGREEN     "\033[1;92m"
# define ORANGE		"\033[1;33m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[1;36m"
# define BLUE       "\033[1;34m"
# define MAGNETA    "\033[35m"
# define GREY		"\033[1;30m"
# define UNDER		"\033[4m"
# define LINE_UP    "\033[F"
# define LINE_BEGIN "\033[100000D"
# define CLEAN_LINE "\033[F\033[99D\033[J"
# define RESET		"\033[0m"

void    listExec();
void    vectorExec();
void    mapExec();
void    queueExec();
void    stackExec();
void    printTestHeader(const std::string &str);
void    printContainerHeader();
bool    c_insensitive (const std::string& first, const std::string& second);
bool    same_integral_part (double first, double second);
bool    compLess (double first, double second);
bool    compByDigit (const int& value);
void    pressAnyKey(const std::string &test = "Continue testing...");
int		check_list(void);
int		check_vector(void);
int		check_map(void);
int		check_queue(void);
int		check_stack(void);

struct is_near {
    bool operator() (double first, double second)
    {
      return (fabs(first-second)<5.0);
    }
};

struct lessThanCmp {
    bool operator() (int first, int second) const
    {
      return (first < second);
    }
};

struct greatThanCmp {
    bool operator() (int first, int second) const
    {
      return (first > second);
    }
};

struct moduleCmp {
    bool operator() (int first, int second) const
    {
      return (first % second);
    }
};

struct divisionCmp {
    bool operator() (int first, int second) const
    {
      return (first / second);
    }
};

struct oddNumber {
    bool operator() (const int& value)
    {
        return (value % 2) == 1;
    }
};

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};


#endif