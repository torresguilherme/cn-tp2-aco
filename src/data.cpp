#include "data.h"

Vertex::Vertex(int new_x, int new_y, int new_c, int new_d)
{
	pos_x = new_x;
	pos_y = new_y;
	capacity = new_c;
	demand = new_d;
}

int Vertex::get_x()
{
	return pos_x;
}

int Vertex::get_y()
{
	return pos_y;
}

int Vertex::get_capacity()
{
	return capacity;
}

int Vertex::get_demand()
{
	return demand;
}

Data::Data(char* filename, double new_decay)
{
	decay_rate = new_decay;
	FILE* f = fopen(filename, "r");
	if(f == NULL)
	{
		cout<<"Error opening file ;< aborting"<<endl;
		exit(1);
	}

	if(!fscanf(f, "%i %i", &n_vertex, &p_medians))
	{
		cout<<"Error reading file ;< aborting"<<endl;
		exit(2);
	}

	int x, y, c, d;
	for(int i = 0; i < n_vertex; i++)
	{
		if(!fscanf(f, "%i %i %i %i", &x, &y, &c, &d))
		{
			cout<<"Error reading file ;< aborting"<<endl;
			exit(2);
		}

		Vertex new_vertex(x, y, c, d);
		points.push_back(new_vertex);
	}

	double min_x = DBL_MAX;
	double min_y = DBL_MAX;
	double max_x = 0;
	double max_y = 0;
	for(int i = 0; i < n_vertex; i++)
	{
		if(points[i].get_x() < min_x)
		{
			min_x = points[i].get_x();
		}

		if(points[i].get_y() < min_y)
		{
			min_y = points[i].get_y();
		}

		if(points[i].get_x() > max_x)
		{
			max_x = points[i].get_x();
		}

		if(points[i].get_y() > max_y)
		{
			max_y = points[i].get_y();
		}

		vector<double> next;
		vector<double> next2;
		for(int j = 0; j < n_vertex; j++)
		{
			next.push_back(sqrt(pow(points[i].get_x() - points[j].get_x(), 2) + pow(points[i].get_y() - points[j].get_y(), 2)));
			next2.push_back(0.5);
		}

		distances.push_back(next);
		pheromones.push_back(next2);
		median_pheromones.push_back(0.5);
		is_median.push_back(false);
	}

	fclose(f);
}

int Data::get_p()
{
	return p_medians;
}

int Data::get_vertex_number()
{
	return n_vertex;
}

void Data::decay()
{
	for(int i = 0; i < n_vertex; i++)
	{
		for(int j = 0; j < n_vertex; j++)
		{
			pheromones[i][j] *= decay_rate;
		}
		median_pheromones[i] *= decay_rate;
	}
}

void Data::reset_medians()
{
	for(int i = 0; i < n_vertex; i++)
	{
		is_median[i] = false;
	}
}
