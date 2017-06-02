
using namespace std;

// Sector tests =====================
void add_sector_test() {
	Sector *s = new Sector( 4 );
	Sector *e = new Sector( 3 );
	Sector *f = new Sector( 2 );
	Sector *y = new Sector( 1 );
	s->add_neighbour( e );
	s->add_neighbour( f );
	s->add_neighbour( y );
	//for ( Sector* sect : s->get_neighbours() )
	//	cout << sect->get_id() << '\n';
	assert( s->get_neighbours()[0]->get_id() == 3 );
	assert( s->get_neighbours()[1]->get_id() == 2 );
	assert( s->get_neighbours()[2]->get_id() == 1 );
	assert( s->get_neighbours().size() == 3 );
}

void fill_test() {
	Sector *s = new Sector( 1 );
	assert( ! s->is_full() );
	s->fill_up();
	assert( s->is_full() );
}

void open_test() {
	Sector *s = new Sector( 1 );
	assert( ! s->is_open() );
	s->open_up();
	assert( s->is_open() );

}

// Percolation tests ================

void percolation_constructor_test() {
	Percolation p = Percolation( 5 );
	//p.print_grid();
	assert( p.grid[0][0]->get_id() != p.grid[0][1]->get_id() );
	p.open( 0, 0 );
	assert( p.grid[0][0]->get_id() != p.grid[0][1]->get_id() );
	//p.print_grid();
}

void Percolation_open_test() {
	// Tests the open function of Percolation class.
	Percolation *p = new Percolation( 5 );
	p->open( 2, 2 );
	p->open( 2, 3 );
	p->open( 2, 1 );
	p->open( 1, 2 );
	p->open( 3, 2 );
	assert( p->grid[2][2]->get_neighbours().size() == 4 );

	vector<Sector*> s = p->grid[2][2]->get_neighbours();
	assert( find( s.begin(), s.end(), p->grid[2][3] ) != s.end() );
	assert( find( s.begin(), s.end(), p->grid[2][1] ) != s.end() );
	assert( find( s.begin(), s.end(), p->grid[1][2] ) != s.end() );
	assert( find( s.begin(), s.end(), p->grid[3][2] ) != s.end() );

	// edge cases:
	p->open( 0, 0 );
	p->open( 0, 4 );
	p->open( 4, 0 );
	p->open( 4, 4 );
	assert( p->isOpen( 0, 0 ) );
	assert( p->isOpen( 0, 4 ) );
	assert( p->isOpen( 4, 0 ) );
	assert( p->isOpen( 4, 4 ) );
	}


void is_open_test() {
	Percolation p = Percolation( 5 );
	assert( ! p.isOpen( 0, 0 ) );
	assert( ! p.isOpen( 4, 4 ) );
	p.grid[0][0]->open_up();
	p.grid[4][4]->open_up();
	assert( p.isOpen( 0, 0 ) );
	assert( p.isOpen( 4, 4 ) );
	assert( ! p.isOpen( 0, 3 ) );
	assert( ! p.isOpen( 3, 4 ) );

}

void is_full_test() {
	Percolation p = Percolation( 5 );
	assert( ! p.isFull( 0, 0 ) );
	assert( ! p.isFull( 4, 4 ) );
	p.grid[0][0]->fill_up();
	p.grid[4][4]->fill_up();
	assert( p.isFull( 0, 0 ) );
	assert( p.isFull( 4, 4 ) );
	assert( ! p.isFull( 0, 1 ) );
	assert( ! p.isFull( 3, 4 ) );

}

void number_of_open_sectors_test() {
	Percolation p = Percolation( 5 );
	assert( p.numberOfOpenSites() == 0 );
	p.open( 0, 0 );
	assert( p.numberOfOpenSites() == 1 );
}

void run_all_tests() {
	add_sector_test();
	percolation_constructor_test();
	Percolation_open_test();
	//fill_test();
	//open_test();
	//is_open_test();
	//is_full_test();
	number_of_open_sectors_test();
}
