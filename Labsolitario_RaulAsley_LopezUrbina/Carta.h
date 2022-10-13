#pragma once
class Cartas
{
private:
	int numero = 0;
	char color = 'R';
	char simbolo = 'A';
public:
	int getNumero();
	void setNumero(int num);

	char getColor();
	void setColor(char clor);

	char getSimbolo();
	void setSimbolo(char Simb);
};

