#include "data.h"

Vertex::Vertex(int new_x, int new_y, int new_c, int new_d)
{
	pos_x = new_x;
	pos_y = new_y;
	capacity = new_c;
	demand = new_d;
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

	fclose(f);
}
