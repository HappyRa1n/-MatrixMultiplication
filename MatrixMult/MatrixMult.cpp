
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
void use_my(){
	cout << "hand - 0, auto-1, file -2";
	int type_inp;
	cin >> type_inp;
	cout << "choose the algorithm" << endl;
	int alg;
	cout <<"1 Standart" << endl;
	cout << "2 shtrassen" << endl;
	cout << "3 shtrassen fast" << endl;

	cin >> alg;
	
	
	switch (type_inp) {
	case 0: {
		cout << "input n";
		int n;
		cin >> n;
		break;
	}
	case 1:
	{
		cout << "input n";
		int n;
		cin >> n;
		break;
	}
	case 2:
	{

		clock_t start = clock();
	
		switch (alg)
		{
		case 1: {
			Start_Standart("input.txt", "output.txt");
			break;
		}
		case 2:
		{
			Start_Shtrassen("input.txt", "output.txt");
			break;
		}
		case 3: {
			Start_ShtrassenBest("input.txt", "output.txt");
			break;
		}
		default:
			break;
		}
		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "ALL " << seconds;
	}
    }
};
int main()
{
	//OutGen();
	CorrectTests();
	//use_my();
}
