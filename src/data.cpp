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

Data::Data(char* filename)
{
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

	for(int i = 0; i < n_vertex; i++)
	{
		vector<double> next;
		for(int j = 0; j < n_vertex; j++)
		{
			next.push_back(get_distance(points[i], points[j]));
		}

		distances.push_back(next);
	}


	fclose(f);
}

double get_distance(Vertex a, Vertex b)
{
	return sqrt(pow(a.get_x() - b.get_x(), 2) + pow(a.get_y() - b.get_y(), 2));
}
