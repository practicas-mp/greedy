#include "container.h"
#include <vector>
#include <algorithm>

using namespace std;

// The first option to take will be the one with bigger 'value density'
bool value_density_order(Container a, Container b){ 
    double a_ratio = (1.0 * a.value) / a.weight,  // Cast to float
            b_ratio = (1.0 * b.value) / b.weight;

    if(a_ratio == b_ratio){  // In case of same ratio, pick the heavier one
        return a.weight >= b.weight;
    } else {
        return a_ratio > b_ratio;
    }
}

vector<Container> getMaxValueDensityContainersToLoad(vector<Container> containers, int max_total_weight){
    std::sort(containers.begin(), containers.end(), value_density_order);

    int total_current_weight = 0;
    vector<Container> result;

    for(Container container : containers) {

        if(total_current_weight + container.weight <= max_total_weight) {
            total_current_weight += container.weight;
            result.push_back(container);
        } else {
            // Puede que aun queden containers pequeños que quepan (aunque tengan poco valor)
        }
    }

    return result;

}