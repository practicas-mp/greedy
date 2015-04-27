#include "container.h"
#include <vector>
#include <algorithm>

using namespace std;

bool weight_order(Container a, Container b){
	return a.weight < b.weight;
}

vector<Container> getContainersToLoad(vector<Container> containers, int max_total_weight){
	std::sort(containers.begin(), containers.end(), weight_order);

	int total_current_weight = 0;
	vector<Container> result;

	for(Container container : containers) {

		if(total_current_weight + container.weight <= max_total_weight) {
			total_current_weight += container.weight;
			result.push_back(container);
		} else {
			break;
		}
	}

	return result;

}