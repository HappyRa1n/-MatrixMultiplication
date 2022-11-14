#include <iostream>
#include <vector>
#include <random>
#include "Standart.h"
#include <string>
#include <fstream>
using namespace std;

void show_matrix(vector <vector <double>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

vector<vector <double>> mul_matrix(const vector <vector <double>>& first_matrix, const vector <vector <double>>& second_matrix) {
	int n = first_matrix.size();
	vector <vector <double>> result_matrix;
	for (int i = 0; i < n; i++) {
		result_matrix.push_back(vector <double>());
		for (int j = 0; j < n; j++) {
			double sum = 0;
			for (int k = 0; k < n; k++) {
				sum += first_matrix[i][k] * second_matrix[k][j];
			}
			result_matrix[i].push_back(sum);
		}
	}
	return result_matrix;
}

void Start_Standart(string in, string out) {

	ifstream fin(in);
	ofstream fout(out);
	int n;
	fin >> n;
	vector<vector <double>> a;
	vector<vector <double>> b;

	for (int i = 0; i < n; i++) {
		a.push_back(vector <double>());
		for (int j = 0; j < n; j++) {
			double var;
			fin >> var;
			a[i].push_back(var);
		}
	}
	for (int i = 0; i < n; i++) {
		b.push_back(vector <double>());
		for (int j = 0; j < n; j++) {
			double var;
			fin >> var;
			b[i].push_back(var);
		}
	}
	vector<vector <double>> c = mul_matrix(a, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fout << c[i][j] << " ";
		}
		fout <<endl;
	}
	fin.close();
	fout.close();
};
