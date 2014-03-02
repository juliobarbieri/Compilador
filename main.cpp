/*Compilador BX*/
#include <iostream>
#include<string.h>
#include<stdio.h>


int escopo_0_funcao(int temp_0) ;



int escopo_1_funcao(int temp_3, int temp_2, int temp_1) {



}



int main(void)
{

	int temp_10;
	int temp_4;
	int temp_5;
	int temp_8;

	temp_4 = 3;
	temp_5 = temp_4;

	std::cout << temp_5 << std::endl;
{
	char temp_6[5];
	char temp_7[5];

	strcpy(temp_6, "teste");
	strcpy(temp_7, temp_6);

	std::cout << temp_7 << std::endl;

}
	

	temp_8 = escopo_0_funcao(temp_5);
	temp_10 = temp_8;

	std::cout << temp_10 << std::endl;

}


int escopo_0_funcao(int temp_11) {

	int temp_12;
	int temp_13;
	int temp_14;

	temp_12 = 1;
	temp_13 = temp_12;

	std::cout << temp_13 << std::endl;
	temp_14 = temp_13 + temp_11;

	return temp_14;

}




