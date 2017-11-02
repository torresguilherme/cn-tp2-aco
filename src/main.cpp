#include "headers.h"
#include "data.h"
#include "ant.h"

int main(int argc, char**argv)
{
	if(argc < 7)
	{
		cout<<"Erro na leitura dos parametros"<<endl;
		exit(1);
	}
	srand(time(NULL));

	// parametros
	char* DataFileName = argv[1];
	int PLUS_ANTS = atoi(argv[2]);
	double UPDATE_MODIFIER = atof(argv[3]);
	int PENALTY_MODIFIER = atoi(argv[4]);
	double DECAY_RATE = atof(argv[5]);
	int ITERATIONS = atoi(argv[6]);

	Data train_data(DataFileName, DECAY_RATE);
	cout<<"boop"<<endl;

	// treinamento
	int ant_number = train_data.get_vertex_number() - train_data.get_p() + PLUS_ANTS;
	Ant ants[ant_number];
	for(int i = 0; i < ITERATIONS; i++)
	{
		for(int j = 0; j < ant_number; j++)
		{
			ants[j].make_path(train_data);
		}
		train_data.decay();
		put_pheromone(train_data, ants, PENALTY_MODIFIER, UPDATE_MODIFIER);
		train_data.reset_medians();
	}

	return 0;
}
