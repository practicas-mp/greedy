#ifndef __CONTAINER_H__
#define __CONTAINER_H__

struct Container {
	int weight;
	int value;

	Container(int weight, int value){
		this->weight = weight;
		this->value = value;
	}
};

#endif