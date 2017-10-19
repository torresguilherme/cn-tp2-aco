#include "headers.h"

class Vertex
{
	public:
	int pos_x;
	int pos_y;
	int capacity;
	int demand;

	Vertex(int, int, int, int);
};

class Data
{
	public:
	int n_vertex;
	int p_medians;
	vector<Vertex> points;

	Data(char*);
};
