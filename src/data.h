#include "headers.h"

class Vertex
{
	public:
	int pos_x;
	int pos_y;
	int capacity;
	int demand;

	Vertex(int, int, int, int);
	int get_x();
	int get_y();
	int get_capacity();
	int get_demand();
};

class Data
{
	public:
	int n_vertex;
	int p_medians;
	vector<Vertex> points;
	vector<vector<double>> distances;

	Data(char*);
	int get_p();
	int get_vertex_number();
	Vertex& get_point(int);
	double get_distance(int, int);
};
