#ifndef DATA_H_
#define DATA_H_

#include "headers.h"

class Vertex
{
	int pos_x;
	int pos_y;
	int capacity;
	int demand;

	public:
	int capacity_left;

	Vertex(int, int, int, int);
	int get_x();
	int get_y();
	int get_capacity();
	int get_demand();
};

class Data
{
	int n_vertex;
	int p_medians;
	double decay_rate;

	public:
	vector<Vertex> points;
	vector<vector<double>> distances;
	vector<vector<double>> pheromones;
	vector<double> median_pheromones;
	vector<bool> is_median;
	vector<bool> is_visited;
	int medians;

	Data(char*, double);
	int get_p();
	int get_vertex_number();
	void decay();
	void reset_medians();
	void full_reset();
};

#endif
