#include "maze.h"

maze::maze(int r, int c) : row(r), col(c){
   std::vector<mazeCell> newMaze (r * c);
   theMaze = newMaze;
}

// returns true if neigh is cell's neighbor
//(i.e. in position left, right, top or bot
// with respect to cell)
bool maze::neighbors(int cell, int neigh) const {
	if((cell + row == neigh) || (cell - row == neigh))
		return true;
	else if((cell % row != 0) && (cell - 1 == neigh))
		return true;
	else if((cell % row != row - 1) && (cell + 1 == neigh))
		return true;
	else
		return false;
}

// get rid of cell's wall between cell and neighbor
// Note: this method should be invoked twice from the driver
// code to smashWall(a,b) and to smashWall(b,a)
void maze::smashWall (int cell, int neigh) {
	if(neighbors(cell, neigh)) {
		if(d.isConnected(cell, neigh))
			cout << "These cells are already connected!\n";
		else {
			d.unionSets(d.find(cell), d.find(neigh));
			cout << "Smashing wall between " << cell << " and " << neigh << "\n";
		}
	}
	else
		cout << cell << " and " << neigh << " are not neighbors. No wall smashed.\n";
}

//print the maze
void maze::printMaze() {
	int pos = 0;

	for(int i = 0; i < col; ++i) {
		if(i > 0)
			cout << " _";
		else
			cout << "  ";
	}
	cout << "\n";

	for(int i = 0; i < row; ++i) {
		if (i > 0)
			cout << "|";
		else
			cout << " ";
		for(int j = 0; j < col; ++j) {
			if(i == row - 1 && j == col - 1)
				break;
			if(!d.isConnected(pos, pos + row) || i == row - 1)
				cout << "_";
			else 
				cout << " ";	
			if(!d.isConnected(pos, pos + 1) || j == col - 1)
				cout << "|";
			else 
				cout << " ";

			++pos;
		}
		cout << "\n";
	}
}

bool maze::isComplete() {
	return d.isConnected(((row * col) - 1), 0);
}