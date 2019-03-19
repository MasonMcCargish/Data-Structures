#include "empmaps.h"
#include "Employee.h"

#include <ctime>


int main()
{
	std::vector<Employee> v;

	// Ordered

	map<int, vector<Employee>> empMap;

	v = employees();

	empMap = mapEmpDept(v);
	empMap = mapSalRange(v);

	printSalRange(empMap);

	// Unordered

	unordered_map<int, vector<Employee>> uempMap;

	uempMap = umapEmpDept(v);
	uempMap = umapSalRange(v);

	uprintSalRange(uempMap);

	return 0;
}