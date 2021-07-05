#include "../../containers/Vector.hpp"
#include <vector>

int main(void)
{
	ft::vector<int> miVector(1, 9);
	std::cout << "Capacity (virtual sz): " << miVector.capacity() << std::endl;
	std::cout << "Size: " << miVector.size() << std::endl;
	
	ft::vector<int>::iterator it;
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "Valor del vector: " << *(it++) << std::endl;

	std::cout << "************ pushing value 2 ****************" << std::endl;
	miVector.push_back(2);
	std::cout << "************ pushing value 4 ****************" << std::endl;
	miVector.push_back(4);
	std::cout << "New Capacity (virtual sz): " << miVector.capacity() << std::endl;
	std::cout << "New Size: " << miVector.size() << std::endl;
	it = miVector.begin();
	std::cout << "IT vale ahora mismo: " << *(it) << std::endl;
	while (it != miVector.end())
		std::cout << "Valor del vector: " << *(it++) << std::endl;

	/* Como invocar a los metoods const como begin y retornar un const iterator...
	 * acuerdate que solo const puede invocar a const
	 * */
	std::cout << "Creando un contenedor const para poder demostrar que devuelve un const_iterator llamando a un begin() const" << std::endl;
	ft::vector<int> const miConst(2, 5);
	const ft::vector<int>::const_iterator cit = miConst.begin();
	std::cout << "Valor del const_iterator: " << *cit << std::endl;

	/********************************/

	ft::vector<int>::reverse_iterator rit = miVector.rbegin();
	std::cout << "rbegin value: " << *rit << std::endl;

	const ft::vector<int>::const_reverse_iterator crit = miConst.rbegin();
	std::cout << "const rbegin value: " << *crit << std::endl;

	rit = miVector.rend();
	std::cout << "Valor de rit con rend(): " << *(--rit) << std::endl;

	const ft::vector<int>::const_reverse_iterator crit2 = miConst.rend();
	std::cout << "Valor de crit2 con rend() const: " << *(crit) << std::endl;

	if (!miVector.empty())
		std::cout << "Is not empty" << std::endl;
	else
		std::cout << "Is empty" << std::endl;

	std::cout << "trying to reserv 5 elements for the vector myVector" << std::endl;
	miVector.reserve(5);
	std::cout << "New capacity after reserving: " << miVector.capacity() << std::endl;
	std::cout << "size of myVector: " << miVector.size() << std::endl;
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "Stored values: " << *(it++) << std::endl;


	std::vector<int> tuVector(1,9);
	tuVector.push_back(2);
	tuVector.push_back(4);
	std::vector<int>::iterator tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "Valores de tuVector: " << *(tuIt++) << std::endl;
	tuVector.reserve(5);
	std::cout << "New capacity after reserving: " << tuVector.capacity() << std::endl;
	std::cout << "size of myVector: " << tuVector.size() << std::endl;
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "Valores de tuVector: " << *(tuIt++) << std::endl;

	std::cout << "Posicion [0] de miVector: " << miVector[0] << std::endl;
	std::cout << "Posicion [0] de tuVector: " << tuVector[0] << std::endl;

	std::cout << "Posicion const [0] de miConst: " << miConst[0] << std::endl;

	/*Posiciones con el metodo at*/
	std::cout << "posicion miVector.at(2): " << miVector.at(2) << std::endl;
	std::cout << "posicion tuVector.at(2): " << tuVector.at(2) << std::endl;

	std::cout << "Posicion miConst.at(1): " << miConst.at(1) << std::endl;

	std::cout << "Front from miVector: " << miVector.front() << std::endl;
	std::cout << "Front from tuVector: " << tuVector.front() << std::endl;

	std::cout << "Front fom miConst: " << miConst.front() << std::endl;

	std::cout << "Back from miVector: " << miVector.back() << std::endl;
	std::cout << "Back from tuVector: " << tuVector.back() << std::endl;

	std::cout << "Back fom miConst: " << miConst.back() << std::endl;

	std::vector<int> addTuVector;
	addTuVector.push_back(12);
	addTuVector.push_back(19);

	ft::vector<int> addRange;
	addRange.push_back(12);
	addRange.push_back(19);
	it = addRange.begin();
	while (it != addRange.end())
		std::cout << "Values to add: " << *(it++) << std::endl;
	tuVector.assign(addTuVector.begin(), addTuVector.end());
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "New values addtuVector with assign(first, last): " << *(tuIt++) << std::endl;

	tuVector.assign(2, 3);
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "New values addtuVector with assign(2, 3): " << *(tuIt++) << std::endl;
	miVector.assign(addRange.begin(), addRange.end());
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "New values addRange with assign(first, last): " << *(it++) << std::endl;

	miVector.assign(2, 3);
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "New values added with assign(2, 3): " << *(it++) << std::endl;

	std::cout << "****************** Inserting *********************" << std::endl;

	it = miVector.begin();
	miVector.insert(it, 8);
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "Values from miVector inserted: " << *(it++) << std::endl;

	it -= 2;
	miVector.insert(it, 17);
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "Values from miVector inserted: " << *(it++) << std::endl;
	std::cout << "Size: " << miVector.size() << std::endl;

	std::cout << "***************** Inserting original ****************" << std::endl;
	tuIt = tuVector.begin();
	tuVector.insert(tuIt, 8);
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "Values from tuVector inserted: " << *(tuIt++) << std::endl;

	tuIt -= 2;
	tuVector.insert(tuIt, 17);
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "Values from tuVector inserted: " << *(tuIt++) << std::endl;
	std::cout << "Size: " << tuVector.size() << std::endl;


	std::cout << "******* Inserting values to miVector using insert(it, n, val) *******" << std::endl;
	it = miVector.begin();
	it++;
	miVector.insert(it, 4, 12);
	
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "Values inserted miVector.insert(it, 4, 12): " << *(it++) << std::endl;
	
	std::cout << "******* Inserting values to tuVector using insert(it, n, val) *******" << std::endl;
	tuIt = tuVector.begin();
	tuIt++;
	tuVector.insert(tuIt, 4, 12);
	
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "Values inserted tuVector.insert(it, 4, 12): " << *(tuIt++) << std::endl;

	std::cout << "**************** values inserted miVector using insert(position, first, last)*********" << std::endl;
	ft::vector<int> unVector;
	unVector.push_back(99);
	unVector.push_back(73);
	it = miVector.begin();
	miVector.insert(it, unVector.begin(), unVector.end());
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "New values inserted using a range: " << *(it++) << std::endl;
	
	std::cout << "**************** values inserted tuVector using insert(position, first, last)*********" << std::endl;
	std::vector<int> otroVector;
	otroVector.push_back(99);
	otroVector.push_back(73);
	tuIt = tuVector.begin();
	tuVector.insert(tuIt, otroVector.begin(), otroVector.end());
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "New values inserted using a range: " << *(tuIt++) << std::endl;

	std::cout << "*************** erasing values from miVector using erase(position) *************" << std::endl;
	it = miVector.begin();
	miVector.erase(it);
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "Values after erasing: " << *(it++) << std::endl;

	std::cout << "*************** erasing values from tuVector using erase(position) *************" << std::endl;
	tuIt = tuVector.begin();
	tuVector.erase(tuIt);
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "Values after erasing: " << *(tuIt++) << std::endl;

	std::cout << "*********** Erasing miVector using erase(first, last) ************" << std::endl;
	it = miVector.begin();
	it++;
	std::cout << "Return value: " << *(miVector.erase(it, miVector.end()) - 1) << std::endl;
	it = miVector.begin();
	while (it != miVector.end())
		std::cout << "Values remaining after erase a range on mivector: " << *(it++) << std::endl;
	
	std::cout << "*********** Erasing tuVector using erase(first, last) ************" << std::endl;
	tuIt = tuVector.begin();
	tuIt++;
	std::cout << "Return value: " << *(tuVector.erase(tuIt, tuVector.end()) - 1) << std::endl;
	tuIt = tuVector.begin();
	while (tuIt != tuVector.end())
		std::cout << "Values remaining after erase a range on mivector: " << *(tuIt++) << std::endl;
//	std::system("leaks a.out");

	return (0);
}
