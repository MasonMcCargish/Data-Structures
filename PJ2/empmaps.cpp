#include "empmaps.h"

#include <iostream>
#include <string>
#include <fstream>

using std::map;

vector<Employee> employees()
{
	std::cout << "Enter the input file: ";
	std::string file;
	std::cin >> file;

	std::ifstream readFile;
	readFile.open(file);

	if(readFile.fail()) {
		std::cout << "That file does not exist.\n";
	}

	vector<Employee> emp;

	int identifier;
   std::string lastname;
   int salary;
   int count = 0;
   while(readFile >> identifier >> lastname >> salary ) {
   	Employee nextEmp {identifier, lastname, salary};
   	emp.push_back(nextEmp);
   	++count;
   }

	readFile.close();

	std::cout << "Number of employees are: " << count << "\n";
	return emp;
}

map<int,vector<Employee>> mapEmpDept(vector<Employee> & emp) 
{
	clock_t start, stop;
	start = clock ();

	// Actual function code
	int count = 0;
	map<int, vector<Employee>> empMap;

	for(int i = 0; i < emp.size(); ++i) {
		empMap[emp[i].id()/100].push_back(emp[i]);
		++count;
	}
	//end

	stop = clock ();
	std::cout << "ORDERED Map creation with department as key clock ticks: " << double(stop-start) << "\n";
	std::cout << "ORDERED Map number of salary departments: " << count << "\n";

	return empMap;
}

map<int,vector<Employee>> mapSalRange(vector<Employee> & emp) 
{
	clock_t start, stop;
	start = clock ();

	map<int, vector<Employee>> empMap;

	int count = 0;
	for(int i = 0; i < emp.size(); ++i) {
		empMap[(emp[i].sal()/10000) * 10000].push_back(emp[i]);
		++count;
	}

	stop = clock ();
	std::cout << "ORDERED Map creation with salary as key clock ticks: " << double(stop-start) << "\n";
	std::cout << "ORDERED Map number of salary ranges: " << count << "\n";

	return empMap;
}

void printSalRange(map<int,vector<Employee>> & salRange)
{
	int largestR = 0;
	int RSize = 0;
	for(auto i: salRange) {
		std::cout << "ORDERED Map In Range " << i.first << ": " << i.second.size() << "\n";
		if(i.second.size() > RSize) {
			largestR = i.first;
			RSize = i.second.size();
		}
	}
	std::cout << "ORDERED Map Salary Range with the most employees: " << largestR
				 << " containing " << RSize << " employees.\n\n";
}

unordered_map<int,vector<Employee>> umapEmpDept(vector<Employee> & emp) 
{
	clock_t start, stop;
	start = clock ();

	unordered_map<int, vector<Employee>> empMap;

	int count = 0;
	for(int i = 0; i < emp.size(); ++i) {
		empMap[emp[i].id()/100].push_back(emp[i]);
		++count;
	}

	std::cout << "UNORDERED Map creation with department as key clock ticks: " << double(stop-start) << "\n";
	std::cout << "UNORDERED Map number of salary departments: " << count << "\n";


	return empMap;
}

unordered_map<int,vector<Employee>> umapSalRange(vector<Employee> & emp) 
{
	clock_t start, stop;
	start = clock ();

	int count = 0;
	unordered_map<int, vector<Employee>> empMap;

	for(int i = 0; i < emp.size(); ++i) {
		empMap[(emp[i].sal()/10000) * 10000].push_back(emp[i]);
		++count;
	}

	stop = clock ();
	std::cout << "UNORDERED Map creation with salary as key clock ticks: " << double(stop-start) << "\n";
	std::cout << "UNORDERED Map number of salary ranges: " << count << "\n";

	return empMap;
}

void uprintSalRange(unordered_map<int,vector<Employee>> & salRange)
{
	int largestR = 0;
	int RSize = 0;
	for(auto i: salRange) {
		std::cout << "UNORDERED Map In Range " << i.first << ": " << i.second.size() << "\n";
		if(i.second.size() > RSize) {
			largestR = i.first;
			RSize = i.second.size();
		}
	}
	std::cout << "UNORDERED Map Salary Range with the most employees: " << largestR
				 << " containing " << RSize << " employees.\n\n";
}