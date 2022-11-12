
#include <iostream>
#include "MatrixMult.h"
#include "Generator.h"
#include <string>
#include <fstream>
#include "Standart.h"
#include "Shtrassen.h"

using namespace std;
int ver_alg = 2;//1- стандарт, 2- штрасcен, 3 - совместный
void create_answer(string in, string out) {
	
	if (ver_alg == 1) {
		Start_Standart(in, out);
	}
	else if (ver_alg == 2) {
		Start_Shtrassen(in, out);
	}
	else {
		Start_ShtrassenBest(in, out);
	}
};
int main()
{
	create_answer("input1.txt", "output.txt");
}
