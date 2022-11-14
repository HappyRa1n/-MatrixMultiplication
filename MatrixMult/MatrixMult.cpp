
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
	cout << "hand - 0, auto-1, file -2" << endl;;
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
		cout << "input n" << endl;;
		int n;
		cin >> n;

		std::vector<vector<double>> A;
		std::vector<vector<double>> B;
		std::vector<vector<double>> C;
		cout << "Input A" << endl;
		for (int i = 0; i < n; i++) {
			A.push_back(std::vector<double>());
			for (int j = 0; j < n; j++) {
				double tmp_d;
				cin >> tmp_d;
				A[i].push_back(tmp_d);
			}
		}
		cout << "Input B" << endl;
		for (int i = 0; i < n; i++) {
			B.push_back(std::vector<double>());
			for (int j = 0; j < n; j++) {
				double tmp_d;
				cin >> tmp_d;
				B[i].push_back(tmp_d);
			}
		}

		switch (alg)
		{
		case 1: {
			C = mul_matrix(A, B);
			show_matrix(C);
			break;
		}
		case 2:
		{
			C = Start_Shtrassen(A, B);
			show_matrix(C);
			break;
		}
		case 3: {
			C = Start_ShtrassenBest(A, B);
			show_matrix(C);
			break;
		}
		default:
			break;
		}
		break;
	}
	case 1:
	{
		cout << "input n"<<endl;
		int n;
		cin >> n;
		std::vector<vector<double>> A;
		std::vector<vector<double>> B;
		std::vector<vector<double>> C;
		for (int i = 0; i < n; i++) {
			A.push_back(std::vector<double>());
			B.push_back(std::vector<double>());
			for (int j = 0; j < n; j++) {
				A[i].push_back(GenDouble());
				B[i].push_back(GenDouble());
			}
		}
	   
		switch (alg)
		{
		case 1: {
			C= mul_matrix(A,B);
			show_matrix(C);
			break;
		}
		case 2:
		{
			C = Start_Shtrassen(A, B);
			show_matrix(C);
			break;
		}
		case 3: {
			C = Start_ShtrassenBest(A, B);
			show_matrix(C);
			break;
		}
		default:
			break;
		}
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
	//CorrectTests();
	use_my();
}
