#include "ant.h"

Ant::Ant()
{
	distance = 0;
}

void Ant::make_path(Data& train_data)
{
	path.push_back(choose_median(train_data));
	train_data.is_visited[path[0]] = true;
	train_data.is_median[path[0]] = true;
	path.push_back(choose_client(train_data, path[0]));
	train_data.is_visited[path[1]] = true;
	train_data.points[path[0]].capacity_left -= train_data.points[path[1]].get_demand();
	distance = train_data.distances[path[0]][path[1]];
}

int Ant::choose_median(Data& train_data)
{
	double sum = 0;
	for(int i = 0; i < train_data.median_pheromones.size(); i++)
	{
		if(train_data.medians == train_data.get_p())
		{
			if(train_data.is_visited[i])
				sum += train_data.median_pheromones[i];
		}
		else
		{
			if(!train_data.is_visited[i])
				sum += train_data.median_pheromones[i];
		}
	}

	double choice = frand(0, sum);
	for(int i = 0; i < train_data.median_pheromones.size(); i++)
	{
		if(train_data.medians == train_data.get_p())
		{
			if(train_data.is_visited[i])
				choice -= train_data.median_pheromones[i];
		}
		else
		{
			if(!train_data.is_visited[i])
				choice -= train_data.median_pheromones[i];
		}

		if(choice <= 0)
		{
			if(train_data.medians != train_data.get_p())
				train_data.medians++;
			return i;
		}
	}

	cout<<"erro ao escolher a mediana"<<endl;
	exit(4);
}

/*int Ant::choose_client(Data& train_data, int median)
{
	double min_distance = DBL_MAX;
	int ret = -1;

	for(int i = 0; i < train_data.pheromones[median].size(); i++)
	{
		if(!train_data.is_visited[i])
		{
			if(train_data.distances[median][i] < min_distance)
			{
				min_distance = train_data.distances[median][i];
				ret = i;
			}
		}
	}

	return ret;
}*/

int Ant::choose_client(Data& train_data, int median)
{
	double sum = 0;
	for(int i = 0; i < train_data.pheromones[median].size(); i++)
	{
		if(!train_data.is_visited[i])
		{	
			sum += train_data.pheromones[median][i] * (1.0/train_data.distances[median][i]);
		}
	}

	double choice = frand(0, sum);
	for(int i = 0; i < train_data.pheromones[median].size(); i++)
	{
		if(!train_data.is_visited[i])
		{	
			choice -= train_data.pheromones[median][i] * (1.0/train_data.distances[median][i]);
			if(choice <= 0)
			{
				return i;
			}
		}
	}

	cout<<"erro ao escolher o no cliente"<<endl;
	exit(4);
}

void Ant::reset()
{
	distance = 0;
	path.clear();
}

double get_fitness(Data& train_data, Ant* ants, int ant_number, int PENALTY_MODIFIER, double best_global)
{
	double local_fitness = 0;
	int exceeding_demand = 0;
	for(int i = 0; i < ant_number; i++)
	{
		local_fitness += ants[i].distance;
		if(train_data.points[ants[i].path[0]].capacity_left < 0)
		{
			exceeding_demand -= train_data.points[ants[i].path[0]].capacity_left;
		}
	}
	local_fitness += exceeding_demand * PENALTY_MODIFIER;

	//update pheromone levels
	if(best_global < DBL_MAX)
	{
		for(int i = 0; i < ant_number; i++)
		{
			train_data.pheromones[ants[i].path[0]][ants[i].path[1]] *= (local_fitness / best_global);
		}
	}

	return local_fitness;
}

double frand(double min, double max)
{
	double d = (double)rand() / RAND_MAX;
	return min + d * (max-min);
}
