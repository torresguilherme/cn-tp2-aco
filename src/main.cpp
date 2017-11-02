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

	return 0;
}
