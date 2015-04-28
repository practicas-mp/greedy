#include "container.h"
#include <vector>
#include <algorithm>

using namespace std;


bool value_order(Container a, Container b){ 
    return a.value > b.value;
}

vector<Container> getContainersToLoad(vector<Container> containers, int max_total_weight){
    std::sort(containers.begin(), containers.end(), value_order);

    int total_current_weight = 0;
    vector<Container> result;

    for(Container container : containers) {

        if(total_current_weight + container.weight <= max_total_weight) {
            total_current_weight += container.weight;
            result.push_back(container);
        } else {
            // Puede que aun queden containers pequeños que quepan (aunque tengan menos valor)
        }
    }

    return result;

}