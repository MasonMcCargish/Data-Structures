#include "DisjSets.h"
#include "mazeCell.h"
#include "maze.h"

#include <iostream>

using std::cout;
using std::cin;

int main()
{
	int rows, cols, neig1, neig2;

	cout << "How many rows in your maze (greater than 1)? ";
	cin << rows;

	cout << "How many columns in your maze (greater than 1)? ";
	cin << cols;

	while(true) {
		// 
		// PRINT THE MAZE HERE
		// 

		cout << "Enter the first neighbor: ";
		cin >> neig1;

		cout << "Enter the second neighbor: "
		cin >> neig2;

	}

	return 0;
}