#include "pch.h"
#include "List.h"

void List::Add(int item) {
	Node* newNode = new Node();
	newNode->data = item; //se guarda el item dentro de la data
	if (Count() == 0) {
		//Lista Vacia
		header = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

int List::Count() {
	return count;
}

int List::GetItem(int index) {
	int contador = 0;//se inicia un contador en 0
	Node* temporal = header;
	while ((temporal) && contador <= index) { //mientras exista un valor i, se continuará hasta que el indice sea igual al contador y se devuelte la data
		if (contador == index) return temporal->data;
		contador++;
		temporal = temporal->next;
	}
	return -1;
}