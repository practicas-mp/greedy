#include <iostream>
#include "container.h"
#include "algorithms/max_value_density.cpp"
#include "algorithms/max_value.cpp"
#include <vector>

using namespace std;

int getTotalValue(vector<Container> containers){
	int total_value = 0;
	for(auto container : containers) {
		total_value += container.value;
	}

	return total_value;
}

vector<Container> randomContainerCollection(){
	vector<Container> result;

	return result;
}

int main(){
	vector<Container> containers = randomContainerCollection();
	int max_weight = atoi(argv[2]);
	

	
	if (containers_data_file.good()) {
		containers_data_file >> containers;

		vector<Container> result = getContainersToLoad(containers, max_weight);

	} else {
		cerr << "Error: el archivo especificado no existe" << endl;
		return -1;
	}
}