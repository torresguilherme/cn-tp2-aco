#include "headers.h"
#include "data.h"
#include "ant.h"

int main(int argc, char**argv)
{
	if(argc < 4)
	{
		cout<<"Erro na leitura dos parametros"<<endl;
		exit(1);
	}
	srand(time(NULL));

	// parametros
	char* DataFileName = argv[1];
	int PENALTY_MODIFIER = atoi(argv[2]);
	double DECAY_RATE = atof(argv[3]);

	Data train_data(DataFileName, DECAY_RATE);

	// treinamento
	int ant_number = train_data.get_vertex_number() - train_data.get_p();
	int ITERATIONS = ant_number * 5;
	double bestofall = DBL_MAX;
	vector<double> best_averages;
	vector<double> average_averages;

	for(int i = 0; i < ITERATIONS; i++)
	{
		best_averages.push_back(0);
		average_averages.push_back(0);
	}

	for(int k = 0; k < 30; k++)
	{
		Ant ants[ant_number];
		double best_solution = DBL_MAX;
		double average = 0;
		for(int i = 0; i < ITERATIONS; i++)
		{
			for(int j = 0; j < ant_number; j++)
			{
				ants[j].make_path(train_data);
			}

			double local_fitness = get_fitness(train_data, ants, ant_number, PENALTY_MODIFIER, best_solution);
			average = (double)(average * (i) + local_fitness)/(i+1);
			if(local_fitness < best_solution)
			{
				best_solution = local_fitness;
			}

			train_data.reset_medians();

			for(int j = 0; j < ant_number; j++)
			{
				ants[j].reset();
			}

			best_averages[i] = (double)(best_averages[i] * (k) + best_solution)/(k+1);
			average_averages[i] = (double)(average_averages[i] * (k) + average)/(k+1);
		}	
		
		train_data.full_reset();
		if(best_solution < bestofall)
			bestofall = best_solution;
	}

	for(int i = 0; i < ITERATIONS; i++)
	{
		cout<<i<<' '<<average_averages[i]<<' '<<best_averages[i]<<endl;
	}

	cout<<bestofall<<endl;

	return 0;
}
