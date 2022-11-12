#include <iostream>
#include <vector>
#include <random>
#include "Standart.h"
using namespace std;

void show_matrix(vector <vector <float>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

vector <vector <double>> mul_matrix(vector <vector <double>> first_matrix, vector <vector <double>> second_matrix) {
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
