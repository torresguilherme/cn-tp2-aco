#include "headers.h"
#include "data.h"

int main(int argc, char**argv)
{
	if(argc < 6)
	{
		cout<<"Erro na leitura dos parametros"<<endl;
		exit(1);
	}

	// parametros
	char* DataFileName = argv[1];
	int PLUS_ANTS = atoi(argv[2]);
	double UPDATE_MODIFIER = atof(argv[3]);
	int PENALTY_MODIFIER = atoi(argv[4]);
	double DECAY_RATE = atof(argv[5]);

	Data train_data(DataFileName, DECAY_RATE);
	cout<<"boop"<<endl;

	return 0;
}
