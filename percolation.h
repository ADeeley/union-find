#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Sector {
public:
	Sector( int id ) :
		ID{ id } {};
	int get_id();
	vector<Sector*>& get_neighbours();
	void add_neighbour( Sector* n );
	bool is_full();
	void fill_up();
	bool is_open();
	void open_up();
private:
	int ID;
	vector<Sector*>neighbours;
	bool full = false;
	bool open = false;
};

class Percolation {
public:
	Percolation( int n );                // create n-by-n grid, with all sites blocked
	void open( int row, int col );    // open site (row, col) if it is not open already
	bool isOpen( int row, int col );  // is site (row, col) open?
	bool isFull( int row, int col );  // is site (row, col) full?
	int numberOfOpenSites();       // number of open sites
	bool percolates();              // does the system percolate?
	vector<vector<Sector*>> grid;   // to remove?
	void print_grid();				// test function

};