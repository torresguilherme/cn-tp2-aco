#ifndef DATA_H_
#define DATA_H_

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
	int decay_rate;
	vector<Vertex> points;
	vector<vector<double>> distances;
	vector<vector<double>> pheromones;

	Data(char*, double);
	int get_p();
	int get_vertex_number();
	Vertex& get_point(int);
	double get_distance(int, int);
	double get_pheromone(int, int);
	void decay();
};

#endif
