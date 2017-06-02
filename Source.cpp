#include <iostream>
#include <vector>
#include "percolation.h"
#include "tests.h"

using namespace std;



int main() {
	run_all_tests();
	Percolation *p = new Percolation( 5 );
	//	cout << "Equal? " << ( p == p );
	p->print_grid();
	return 0;
}