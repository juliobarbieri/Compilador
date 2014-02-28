/*Compilador BX*/
#include <iostream>
#include<string.h>
#include<stdio.h>


int main(void)
{

	int temp_0;
	int temp_1;
	int temp_10;
	int temp_11;
	int temp_12;
	int temp_13;
	int temp_14;
	int temp_15;
	int temp_16;
	int temp_17;
	bool temp_18;
	int temp_3;
	int temp_4;
	int temp_5;
	int temp_6;
	int temp_7;
	int temp_8;
	int temp_9;

	temp_0 = 2;
	temp_1 = 2;
	int temp_2[temp_0 * temp_1 + temp_1];

	temp_3 = 0;
	temp_4 = 0;
	temp_5 = 3;
	temp_2[temp_3 * 2 + temp_4] = temp_5;

	temp_6 = 1;
	temp_7 = 0;
	temp_8 = 4;
	temp_2[temp_6 * 2 + temp_7] = temp_8;

	temp_9 = 0;
	temp_10 = 1;
	temp_11 = 7;
	temp_2[temp_9 * 2 + temp_10] = temp_11;

	temp_12 = 1;
	temp_13 = 1;
	temp_14 = 9;
	temp_2[temp_12 * 2 + temp_13] = temp_14;

	temp_15 = 0;
	temp_16 = temp_15;

	temp_17 = 2;

	temp_18 = temp_16 < temp_17;

	if(temp_18) goto escopo_1_inicio; 
	else goto escopo_1_fim;
	escopo_1_inicio:{

	int temp_19;
	int temp_20;
	int temp_21;
	bool temp_22;

	temp_19 = 0;
	temp_20 = temp_19;

	temp_21 = 2;

	temp_22 = temp_20 < temp_21;

	if(temp_22) goto escopo_0_inicio; 
	else goto escopo_0_fim;
	escopo_0_inicio:{



	std::cout << temp_2[temp_16 * 2 + temp_20] << std::endl;

}
	escopo_0_verificacao:;
	temp_20++;
 
 	temp_21 = 2;

	temp_22 = temp_20 < temp_21;

	if(temp_22) goto escopo_0_inicio; 
	else goto escopo_0_fim;
	escopo_0_fim:;


}
	escopo_1_verificacao:;
	temp_16++;
 
 	temp_17 = 2;

	temp_18 = temp_16 < temp_17;

	if(temp_18) goto escopo_1_inicio; 
	else goto escopo_1_fim;
	escopo_1_fim:;


}




