
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
	assert( s->is_full() == false );
	s->fill_up();
	assert( s->is_full() == true );
}

void open_test() {
	Sector *s = new Sector( 1 );
	assert( s->is_open() == false );
	s->open_up();
	assert( s->is_open() == true );
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

void is_open_test() {
	Percolation p = Percolation( 5 );
	assert( p.isOpen( 0, 0 ) == false );
	assert( p.isOpen( 4, 4 ) == false );
	p.grid[0][0]->open_up();
	p.grid[4][4]->open_up();
	assert( p.isOpen( 0, 0 ) == true );
	assert( p.isOpen( 4, 4 ) == true );
	assert( p.isOpen( 0, 3 ) == false );
	assert( p.isOpen( 3, 4 ) == false );

}

void is_full_test() {
	Percolation p = Percolation( 5 );
	assert( p.isFull( 0, 0 ) == false );
	assert( p.isFull( 4, 4 ) == false );
	p.grid[0][0]->fill_up();
	p.grid[4][4]->fill_up();
	assert( p.isFull( 0, 0 ) == true );
	assert( p.isFull( 4, 4 ) == true );
	assert( p.isFull( 0, 1 ) == false );
	assert( p.isFull( 3, 4 ) == false );

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
	//fill_test();
	//open_test();
	//is_open_test();
	//is_full_test();
	number_of_open_sectors_test();
}
