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
	int path_choice(Data&);
	void put_pheromone(Data&);
};

#endif
