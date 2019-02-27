#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>

using std::cin;
using std::cout;
using std::list;

list<int>::iterator find_gt(list<int>::iterator, list<int>::iterator, int );
void printAdjList(std::vector <list<int>>);
bool merge2(std::list<int> &, std::list<int> &);


int main() {
	std::vector <list<int>> adjList;
	std::string fileName;

	cout << "Please enter the graph filename to process: ";
	cin >> fileName;

	//opening the entererd file
	std::ifstream read;
	read.open(fileName);

   list<int> x;
   adjList.push_back(x);

   int i1, i2, value;
   std::string line;
   list<int>::iterator begin, end;

   //Creaiting the graph
   int i = 0;
   while (getline(read, line)) {
   	std::istringstream lineStream(line);
   	list<int> newList;

	   while(lineStream >> value) {
	   	newList.insert(find_gt(adjList[i].begin(), adjList[i].end(), value), value);
	   }
	   adjList.push_back(newList);
	   ++i;
	}

	//MAIN LOOP
	while(i1 != -1) {
		cout << "The adjacency list for your graph is: " << "\n";
		printAdjList(adjList);

		cout << "\nEnter two list ids to potentially merge together or -1 to quit: ";
		cin >> i1 >> i2;

		if(merge2(adjList[i1], adjList[i2]))
			cout << "The lists are merged.";
		else
			cout << "The lists are not merged.";
	}

	read.close();
	return 0;
}

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x ) {
	//checks for empty list
	if (start == stop)
		return start;

	while(start != stop) {
		if (*start > x)
			return start;
		++start;
	}
	//safety from running off the end
	return stop;
}

void printAdjList(std::vector <list<int>> adjList) {
	list<int>::iterator begin;
	for(size_t i = 0; i < adjList.size(); ++i) {
		begin = adjList[i].begin();
		while(begin != adjList[i].end()) {
			cout << *begin << " ";
			++begin;
		}
		cout << "\n";
	}
}

bool connComponent(const std::list<int> &L1, const std::list<int> &L2) {
	std::list<int>::const_iterator L1parse = L1.begin(), L2parse = L2.begin();
	while (L1parse != L1.end() && L2parse != L2.end()) {
		if (*L1parse == *L2parse)
			return true;
		else if (*L1parse > *L2parse)
			++L2parse;
		else
			++L1parse;
	}
	return false;
}

bool merge2(std::list<int> &L1, std::list<int> &L2) {
	if (connComponent(L1, L2)) {
		if (L1.size() > L2.size()) {
			L1.merge(L2);
			L1.unique();
			return true;
		}
		else {
			L2.merge(L1);
			L2.unique();
			return true;
		}
	}
	return false;
}