#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "container.h"
#include "algorithms/max_value_density.cpp"
#include "algorithms/max_value.cpp"

using namespace std;


int getTotalValue(vector <Container> containers){
	int total_value = 0;
	for(auto container : containers) {
		total_value += container.value;
	}

	return total_value;
}


vector <Container> randomContainerCollection(int containers){
	vector <Container> result;
	Container curr;

	for(int i = 0; i < containers; ++i){
		curr.weight = rand() % 50;
		curr.value = rand() % 50;

		result.push_back(curr);
	}

	return result;
}


int computeContainersValue(vector <Container> containers){
	int total = 0;
	
	for(auto container: containers){
		total += container.value;
	}
}


int main(int argc, char **argv){
	srand(time(NULL));

	const int CONTAINERS = 10, MAX_WEIGHT = 100;
	int executions = atoi(argv[1]), max_value_density_wins = 0, max_value_wins = 0;
	vector <Container> containers, max_value, max_value_density;
	int total_max_value, total_max_value_density;

	for(int i = 0; i < executions; ++i){
		containers = randomContainerCollection(CONTAINERS);
		max_value = getMaxValueContainersToLoad(containers, MAX_WEIGHT);
		max_value_density = getMaxValueDensityContainersToLoad(containers, MAX_WEIGHT);

		total_max_value = computeContainersValue(max_value);
		total_max_value_density = computeContainersValue(max_value_density);

		if(total_max_value > total_max_value_density){
			++max_value_wins;
		} else if(total_max_value < total_max_value_density){
			++max_value_density_wins;
		}
	}

	int total_cases = max_value_wins + max_value_density_wins;
	
	printf("Total cases with winner: %d\n", total_cases);
	printf("Max value wins: %12d\t%s\n", 
	       max_value_wins, string(max_value_wins * 100 / total_cases, '+').c_str());
	printf("Max value density wins: %4d\t%s\n",
	       max_value_density_wins, string(max_value_density_wins * 100 / total_cases, '+').c_str());
}