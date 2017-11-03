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
	cout<<"boop"<<endl;

	// treinamento
	int ant_number = train_data.get_vertex_number() - train_data.get_p();
	int ITERATIONS = ant_number * 5;
	Ant ants[ant_number];
	double best_solution = DBL_MAX;
	for(int i = 0; i < ITERATIONS; i++)
	{
		for(int j = 0; j < ant_number; j++)
		{
			ants[j].make_path(train_data);
		}

		train_data.decay();
		double local_fitness = get_fitness(train_data, ants, ant_number, PENALTY_MODIFIER, best_solution);
		if(local_fitness < best_solution)
		{
			best_solution = local_fitness;
		}

		train_data.reset_medians();

		for(int j = 0; j < ant_number; j++)
		{
			ants[j].reset();
		}

		cout<<best_solution<<endl;
	}

	return 0;
}
