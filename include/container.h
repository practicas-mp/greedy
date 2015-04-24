#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Container {
	int weight;
	int value;

	Container() {	
		// Se inicializa a un valor determinado para que no haya basura dificil de depurar
		this->weight = 0;
		this->value = 0;
	}

	Container(int weight, int value){
		this->weight = weight;
		this->value = value;
	}
};

istream& operator>>(istream &is, Container &container) {
	is >> container.weight;
	is >> container.value;

	return is;
}

istream& operator>>(istream &is, vector<Container> &containers) {
	while( !is.eof() ) {
		Container new_container;
		is >> new_container;
		containers.push_back(new_container);
	}

	return is;
}

ostream& operator<<(ostream &os, const Container &container){
	os << "W: " << container.weight << ", V: " << container.value;

	return os;
}

#endif