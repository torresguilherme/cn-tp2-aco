#include "ant.h"

Ant::Ant()
{
	distance = 0;
}

void Ant::make_path(Data& train_data)
{
	path.push_back(choose_median(train_data));
	train_data.is_median[path[0]] = true;
	path.push_back(choose_client(train_data, path[0]));
	distance = train_data.distances[path[0]][path[1]];
}

int Ant::choose_median(Data& train_data)
{
	double sum = 0;
	for(int i = 0; i < train_data.median_pheromones.size(); i++)
	{
		sum += train_data.median_pheromones[i];
	}

	double choice = frand(0, sum);
	for(int i = 0; i < train_data.median_pheromones.size(); i++)
	{
		choice -= train_data.median_pheromones[i];
		if(choice <= 0)
		{
			return i;
		}
	}

	cout<<"erro na execução"<<endl;
	exit(4);
}

int Ant::choose_client(Data& train_data, int median)
{
	double sum = 0;
	for(int i = 0; i < train_data.pheromones[median].size(); i++)
	{
		if(!train_data.is_median[i])
		{	
			sum += train_data.pheromones[median][i];
		}
	}

	double choice = frand(0, sum);
	for(int i = 0; i < train_data.pheromones[median].size(); i++)
	{
		if(!train_data.is_median[i])
		{	
			choice -= train_data.pheromones[median][i];
			if(choice <= 0)
			{
				return i;
			}
		}
	}

	cout<<"erro na execução"<<endl;
	exit(4);
}

void put_pheromone(Data& train_data, Ant* ants, int PENALTY_MODIFIER, double UPDATE_MODIFIER)
{
}

double frand(double min, double max)
{
	double d = (double)rand() / RAND_MAX;
	return min + d * (max-min);
}
