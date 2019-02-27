#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>

using std::cin;
using std::cout;
using std::list;

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x );

int main() {
	std::vector <list<int>> adjList;
	std::string fileName;

	cout << "Please enter the graph filename to process: ";
	cin >> fileName;

	std::ifstream read;
	read.open(fileName);

   list<int> x;
   adjList.push_back(x);

   int input, value;
   std::string line;

   int i = 0;
   while (getline(read, line)) {
   	std::istringstream lineStream(line);
   	list<int> newList;
	   //adjList.push_back(mtLst);
	   while(lineStream >> value) {
	   	
	   	newList.insert(find_gt(adjList[i].begin(), adjList[i].end(), value), value);
	   }
	   adjList.push_back(newList);
	   ++i;
	}


	read.close();
	return 0;
}

list<int>::iterator find_gt(list<int>::iterator start, list<int>::iterator stop, int x ) {
	for(list<int>::iterator i = start; i != stop; ++i) {
		if (*i > x)
			return i;
	}
}