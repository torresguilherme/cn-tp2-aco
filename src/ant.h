#ifndef ANT_T_
#define ANT_T_

#include "headers.h"
#include "data.h"

class Ant
{
	public:
	double distance;
	vector<int> path;

	Ant();
	void make_path(Data&);
	int choose_median(Data&);
	int choose_client(Data&, int);
};

void put_pheromone(Data&, Ant*, int, double);
double frand(double, double);
#endif
