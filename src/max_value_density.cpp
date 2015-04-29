#include <iostream>
#include <vector>
#include "container.h"
#include "algorithms/max_value_density.cpp"

using namespace std;


int main(int argc, char **argv){
	
	if (argc < 3) {
		cerr << "Error" << endl;
		cerr << "Uso: ./" << argv[0] << " <containers-data-file> <max_weight>" << endl;
		return -1;
	}


	vector<Container> containers;
	int max_weight = atoi(argv[2]);
	ifstream containers_data_file(argv[1]);

	
	if (containers_data_file.good()) {
		containers_data_file >> containers;

		vector<Container> result = getMaxValueDensityContainersToLoad(containers, max_weight);

		for(Container container: result){
			cout << container << endl;
		}	
	} else {
		cerr << "Error: el archivo especificado no existe" << endl;
		return -1;
	}
	
}