#include "percolation.h"

using namespace std;

// Sector method definitions ==========================

int Sector::get_id(){
	return ID;
}

vector<Sector*>& Sector::get_neighbours() {
	return neighbours;
}

void Sector::add_neighbour( Sector* n ) {
	assert( neighbours.size() < 5 );
	neighbours.push_back( n );
}

bool Sector::is_full() {
	return full;
}

void Sector::fill_up() {
	full = true;
}

bool Sector::is_open() {
	return open;
}

void Sector::open_up() {
	open = true;
}

// Percolation method definitions ====================

Percolation::Percolation( int n ) {
	vector<Sector*>temp;
	int id = 0;
	for ( int row = 0; row < n; row++ ) {
		for ( int col = 0; col < n; col++ ) {
			temp.push_back( new Sector( id ) );
			id++;
			//cout << "row:" << row << ',' << "col:" << col << "id:" << id << '\n';
		}
		grid.push_back( temp );
		// erase the temp vector each time in order to append new vals
		temp.erase( temp.begin(), temp.end() );
	}
	assert( grid.size()  == n);
}

void Percolation::open( int col, int row ) {
	// only concerned with opening the current sector and linking it to any adjacent 
	// open sectors
	grid[col][row]->open_up();
	if ( row > 0 )
		if ( isOpen( col, row - 1 ) )
			grid[col][row]->add_neighbour( grid[col][row - 1] );
}

bool Percolation::isOpen( int col, int row ) {
	return grid[row][col]->is_open();
}

bool Percolation::isFull( int col, int row ) {
	return grid[row][col]->is_full();
}

int Percolation::numberOfOpenSites() {
	int sum = 0;
	for ( unsigned int row = 0; row < grid.size(); row++ )
		for ( Sector* sect : grid[row] )
			if ( sect->is_open() ) sum += 1;

	return sum;
}

void Percolation::print_grid() {
	for ( unsigned int row = 0; row < grid.size(); row++ ){
		for ( unsigned int col = 0; col < grid.size(); col++ ){
			cout << ( grid[col][row]->is_open() ) ? 'o' : 'c';
		}
		cout << '\n';
		}
	cout << '\n';

	for ( unsigned int row = 0; row < grid.size(); row++ ){
		for ( unsigned int col = 0; col < grid.size(); col++ ){
			cout << grid[col][row]->get_id();
		}
		cout << '\n';
		}
	cout << '\n';
}

