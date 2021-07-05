#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::pair<std::map<char,int>::iterator,bool> ret;
  std::map<char,int>::iterator it;

  //max_size a map can hold
  size_t maxSize = mymap.max_size();
  std::cout << "Max size mymap can hold: " << maxSize << std::endl;

  // first insert function version (single parameter):

  
  std::cout << "********************** B *********************" << std::endl;
	ret = mymap.insert ( std::pair<char,int>('b',300) );
  	std::cout << "#b => " << mymap['b'] <<  std::endl;
  std::cout << "********************** A *********************" << std::endl;
	ret = mymap.insert ( std::pair<char,int>('a',100) );
  	std::cout << "#a => " << mymap['a'] <<  std::endl;
  std::cout << "********************** M *********************" << std::endl;
	ret = mymap.insert ( std::pair<char,int>('m',300) );
  	std::cout << "#m => " << mymap['m'] <<  std::endl;
  std::cout << "********************** Y *********************" << std::endl;
	ret = mymap.insert ( std::pair<char,int>('y',200) );
  	std::cout << "#z => " << mymap['y'] <<  std::endl;
  std::cout << "********************** X *********************" << std::endl;
	ret = mymap.insert ( std::pair<char,int>('x',500) );
  	std::cout << "#x => " << mymap['x'] << std::endl;


	if (ret.second==false)
	{
		std::cout << "element 'y' already exists";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

  // second insert function version (with hint position):
 it = mymap.begin();
  while (it != mymap.end())
  {
	  std::cout << "Key: " << it->first << " -> Value: " << it->second << std::endl;
	  ++it;
  }

  //std::pair<std::map<char,int>::iterator,bool> ret;
  ret.first = mymap.insert (it, std::pair<char,int>('b',301));  // max efficiency inserting
  std::cout << "Returned value: " << ret.first->first << " => " << ret.first->second << std::endl;
  std::cout << "After trying to insert an existing key=>value pair" << std::endl;
  it = mymap.begin();
  while (it != mymap.end())
  {
	  std::cout << "Key: " << it->first << " -> Value: " << it->second << std::endl;
	  ++it;
  }
  it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
  std::cout << "printing from the begining of the map" << std::endl;
  while (it != mymap.end())
  {
	  std::cout << "Key: " << it->first << " -> Value: " << it->second << std::endl;
	  ++it;
  }

//Checkin Bounds: lower_bound and upper_bound
  std::cout << "lower_bound" << std::endl;
  it = mymap.lower_bound('m');
  if (it != mymap.end())
    std::cout << "Showing lower bound of \'m\' if key value existing in the map is lower or equal: [" << it->first << "]" << std::endl;
  else
    std::cout << "iterator it is mymap.end() since there's no key considered to go before." << std::endl;
  it = mymap.lower_bound('z');
  if (it != mymap.end())
   std::cout << "Showing lower bound of \'z\' if key value existing in the map is lower or equal: [" << it->first << "]" << std::endl;
  else
    std::cout << "iterator it is mymap.end() since there's no key considered to go before." << std::endl;

  std::cout << "upper_bound" << std::endl;
  it = mymap.upper_bound('m');
  if (it != mymap.end())
    std::cout << "Showing upper bound of \'m\' if key value existing in the map is upper or equal: [" << it->first << "]" << std::endl;
  else
    std::cout << "iterator it is mymap.end() since there's no key considered to go after." << std::endl;
  it = mymap.upper_bound('z');
  if (it != mymap.end())
   std::cout << "Showing upper bound of \'z\' if key value existing in the map is upper or equal: [" << it->first << "]" << std::endl;
  else
    std::cout << "iterator it is mymap.end() since there's no key considered to go after." << std::endl;


  //checking Key compare
  std::map<char,int>::key_compare mycomp = mymap.key_comp();
  std::cout << "mymap contains:\n";
  {
    char highest = mymap.rbegin()->first;     // key value of last element you can try 'm' key value to test it. Warning: if key doesn't exist has an unexpected behivor;
    std::cout << "Comparison value: " << highest << std::endl;
    it = mymap.begin();
    do {
      std::cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, highest) );
  }
  std::cout << "*******************" << std::endl;
  
  {
    std::pair<char,int> highest = *mymap.rbegin();
    it = mymap.begin();
    do {
      std::cout << it->first << " => " << it->second << '\n';
    } while ( mymap.value_comp()(*it++, highest) );
  }

  std::cout << '\n';

//Checking equal range
  {
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
  }

  //checking iterator
  std::cout << "Checking iterator-- operation" << std::endl;
  it = mymap.end();
  //it--;
  size_t i = 0;
  while (i < mymap.size())
  {
    it--;
    std::cout << it->first << " => " << it->second << " Pos[" << i << "]"<< '\n';
    i++;
  }
  
  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(), mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
  std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
  std::cout << it->first << " => " << it->second << '\n';

  // Checking reverse iterators with rbegin and rend
  std::map<char,int>::reverse_iterator rit;
  std::cout << "Checking rbegin and rend" << std::endl;
  rit = mymap.rbegin();
  /* 
  --rit;  
  --rit;
  --rit; */
  //std::cout << rit->first << " => " << rit->second << std::endl;
  
  i = 0;
  while (i < mymap.size())
  {
    std::cout << rit->first << " => " << rit->second << '\n';
    i++;
    rit++;
  } 
  //for (rit = mymap.rend(); rit != mymap.rbegin(); rit--)

  //checking count function, it must return 1 if key matches or zero otherwise
  i = 0;
  i = mymap.count('c');
  std::cout << "key value c searched, result: " << i << std::endl;
  i = mymap.count('w');
  std::cout << "key value w searched, result: " << i << std::endl;

  //checking find function: it must return an iterator at the position of the key equivalent or map end if no match

  it = mymap.find('c');
  std::cout << "Key => " << it->first << "\tvalue => " << it->second << std::endl;

  it = mymap.find('w');
  if (it == mymap.end())
    std::cout << "Not found key = w" << std::endl;
  else
    std::cout << "Key => " << it->first << "\tvalue => " << it->second << std::endl;

  //Checking erase single element from de map by key
  it = mymap.begin();
  while (it != mymap.end())
  {
    std::cout << "key => " << it->first << "\tvalue => " << it->second << std::endl;
    it++;
  }
  i = mymap.erase('y');
  i = mymap.erase('m');
  std::cout << "returned value: " << i << std::endl;
  
  //Checking erase single element by iterator
  it = mymap.begin();
  mymap.erase(it);
  it = mymap.begin();
  while (it != mymap.end())
  {
    std::cout << "key => " << it->first << "\tvalue => " << it->second << std::endl;
    it++;
  }

  //Checking erase a range of elements from the map by [iterator first, iterator last)
  std::map<char, int>::iterator first = mymap.begin();
  std::map<char, int>::iterator last = mymap.end();

  //first++;
  mymap.erase(first, last);
  //mymap.insert(std::pair<char, int>('g', 42));
  std::cout << "########################" << std::endl;
  it = mymap.begin();

  std::cout << "Size of mymap " << mymap.size() << std::endl;
  while (it != mymap.end())
  {
    std::cout << "key => " << it->first << "\tvalue => " << it->second << std::endl;
    it++;
  }
  //checking empty function: return bool true if empty false otherwise
  mymap.clear();
  if (mymap.empty())
    std::cout << "mymap is empty" << std::endl;
  else
    std::cout << "mymap is not empty" << std::endl;

std::cout << "Size of mymap: " << mymap.size() << std::endl;
  /* std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  // second insert function version (with hint position):
  std::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n'; */

  return 0;
}
