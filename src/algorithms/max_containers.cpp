#include "container.h"
#include <vector>
#include <algorithm>


bool weight_order(Container a, Container b){
	return a.weight < b.weight;
}

vector<Container> loadMaxNumberOfContainers(vector<Container> containers, int max_total_weight){

	std::sort(containers.begin(), containers.end(), weight_order);

	int total_weight = 0,
		current_container_index = 0;

	vector<Container> result;

	for(Container container : containers) {

		if(total_weight + container.weight <= max_total_weight) {
			result.push_back(container);
		} else {
			return result;
		}
	}

	return result;

}