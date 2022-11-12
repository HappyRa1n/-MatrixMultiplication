#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "Shtrassen.h"
using namespace std;

void show_matrix(vector <vector <double>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

vector <vector<double>> extend_matrix(vector <vector<double>> matrix) {
	int n = matrix.size();
	int size = n;
	while ((size & (size - 1)) != 0) {
		size += 1;
	}

	for (int i = 0; i < size; i++) {
		if (i >= n) {
			matrix.push_back(vector <double>());
			for (int j = 0; j < size; j++) {
				matrix[i].push_back(0);
			}
		}
		else {
			for (int j = 0; j < size - n; j++) {
				matrix[i].push_back(0);
			}
		}
	}

	return matrix;
}

void split_matrix(vector<vector <double>> matrix, vector<vector <double>>& m1, vector<vector <double>>& m2, vector<vector <double>>& m3, vector<vector <double>>& m4) {
	int n = matrix.size();
	int middle = n >> 1;
	for (int i = 0; i < n; i++) {
		if (i < middle) {
			m1.push_back(vector <double>());
			m2.push_back(vector <double>());
			m3.push_back(vector <double>());
			m4.push_back(vector <double>());
		}
		for (int j = 0; j < n; j++) {
			if ((i < middle) && (j < middle)) {
				m1[i].push_back(matrix[i][j]);
			}
			else if ((i < middle) && (j >= middle)) {
				m2[i].push_back(matrix[i][j]);
			}
			else if ((i >= middle) && (j < middle)) {
				m3[i % middle].push_back(matrix[i][j]);
			}
			else {
				m4[i % middle].push_back(matrix[i][j]);
			}
		}
	}
}

vector <vector <double>> merge_matrix(vector <vector <double>> m1, vector <vector <double>> m2, vector <vector <double>> m3, vector <vector <double>> m4) {
	vector <vector <double>> matrix;
	int n = m1.size();

	for (int i = 0; i < n; i++) {
		matrix.push_back(vector<double>());
		for (int j = 0; j < n; j++) {
			matrix[i].push_back(m1[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i].push_back(m2[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		matrix.push_back(vector<double>());
		for (int j = 0; j < n; j++) {
			matrix[i + n].push_back(m3[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i + n].push_back(m4[i][j]);
		}
	}

	return matrix;
}

vector <vector <double>> sum_matrix(vector<vector <double>> first_matrix, vector<vector <double>> second_matrix) {
	int n = first_matrix.size();
	vector <vector <double>> result_matrix;
	for (int i = 0; i < n; i++) {
		result_matrix.push_back(vector <double>());
		for (int j = 0; j < n; j++) {
			result_matrix[i].push_back(first_matrix[i][j] + second_matrix[i][j]);
		}
	}
	return result_matrix;
}

vector <vector <double>> diff_matrix(vector<vector <double>> first_matrix, vector<vector <double>> second_matrix) {
	int n = first_matrix.size();
	vector <vector <double>> result_matrix;
	for (int i = 0; i < n; i++) {
		result_matrix.push_back(vector <double>());
		for (int j = 0; j < n; j++) {
			result_matrix[i].push_back(first_matrix[i][j] - second_matrix[i][j]);
		}
	}
	return result_matrix;
}


vector <vector <double>> strassen_best(vector<vector <double>> first_matrix, vector<vector <double>> second_matrix, int n) {
	if (n <= 64) {
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

	n = n >> 1;

	vector<vector <double>> fm1;
	vector<vector <double>> fm2;
	vector<vector <double>> fm3;
	vector<vector <double>> fm4;

	vector<vector <double>> sm1;
	vector<vector <double>> sm2;
	vector<vector <double>> sm3;
	vector<vector <double>> sm4;

	split_matrix(first_matrix, fm1, fm2, fm3, fm4);
	split_matrix(second_matrix, sm1, sm2, sm3, sm4);

	vector<vector <double>> p1 = strassen_best(sum_matrix(fm1, fm4), sum_matrix(sm1, sm4), n);
	vector<vector <double>> p2 = strassen_best(sum_matrix(fm3, fm4), sm1, n);
	vector<vector <double>> p3 = strassen_best(fm1, diff_matrix(sm2, sm4), n);
	vector<vector <double>> p4 = strassen_best(fm4, diff_matrix(sm3, sm1), n);
	vector<vector <double>> p5 = strassen_best(sum_matrix(fm1, fm2), sm4, n);
	vector<vector <double>> p6 = strassen_best(diff_matrix(fm3, fm1), sum_matrix(sm1, sm2), n);
	vector<vector <double>> p7 = strassen_best(diff_matrix(fm2, fm4), sum_matrix(sm3, sm4), n);

	vector<vector <double>> r1 = sum_matrix(sum_matrix(p1, p4), diff_matrix(p7, p5));
	vector<vector <double>> r2 = sum_matrix(p3, p5);
	vector<vector <double>> r3 = sum_matrix(p2, p4);
	vector<vector <double>> r4 = sum_matrix(diff_matrix(p1, p2), sum_matrix(p3, p6));

	return merge_matrix(r1, r2, r3, r4);
}

vector <vector <double>> strassen(vector<vector <double>> first_matrix, vector<vector <double>> second_matrix, int n) {
     if (n == 2) {
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

	n = n >> 1;

	vector<vector <double>> fm1;
	vector<vector <double>> fm2;
	vector<vector <double>> fm3;
	vector<vector <double>> fm4;

	vector<vector <double>> sm1;
	vector<vector <double>> sm2;
	vector<vector <double>> sm3;
	vector<vector <double>> sm4;

	split_matrix(first_matrix, fm1, fm2, fm3, fm4);
	split_matrix(second_matrix, sm1, sm2, sm3, sm4);

	vector<vector <double>> p1 = strassen(sum_matrix(fm1, fm4), sum_matrix(sm1, sm4), n);
	vector<vector <double>> p2 = strassen(sum_matrix(fm3, fm4), sm1, n);
	vector<vector <double>> p3 = strassen(fm1, diff_matrix(sm2, sm4), n);
	vector<vector <double>> p4 = strassen(fm4, diff_matrix(sm3, sm1), n);
	vector<vector <double>> p5 = strassen(sum_matrix(fm1, fm2), sm4, n);
	vector<vector <double>> p6 = strassen(diff_matrix(fm3, fm1), sum_matrix(sm1, sm2), n);
	vector<vector <double>> p7 = strassen(diff_matrix(fm2, fm4), sum_matrix(sm3, sm4), n);

	vector<vector <double>> r1 = sum_matrix(sum_matrix(p1, p4), diff_matrix(p7, p5));
	vector<vector <double>> r2 = sum_matrix(p3, p5);
	vector<vector <double>> r3 = sum_matrix(p2, p4);
	vector<vector <double>> r4 = sum_matrix(diff_matrix(p1, p2), sum_matrix(p3, p6));

	return merge_matrix(r1, r2, r3, r4);
}

vector<vector <double>> remove_zeros(vector<vector <double>> matrix, int n) {
	vector<vector <double>> result_matrix;

	for (int i = 0; i < n; i++) {
		result_matrix.push_back(vector <double>());
		for (int j = 0; j < n; j++) {
			result_matrix[i].push_back(matrix[i][j]);
		}
	}

	return result_matrix;
}

vector<vector <double>> Start_Shtrassen(vector<vector <double>> A, vector<vector <double>> B) {
	int old_size = A.size();

	A = extend_matrix(A);
	B = extend_matrix(B);

	vector<vector <double>> C = strassen(A, B, A.size());

	return remove_zeros(C, old_size);
}
void Start_Shtrassen(string inp, string out )
{	    
		ifstream fin(inp);
		int n;
		fin >> n;
		ofstream fout(out);

		vector <vector <double>> A;
		vector <vector <double>> B;

		for (int i = 0; i < n; i++) {
			A.push_back(vector <double>());
			for (int j = 0; j < n; j++) {
				double x;
				fin >> x;
				A[i].push_back(x);
			}
		}

		for (int i = 0; i < n; i++) {
			B.push_back(vector <double>());
			for (int j = 0; j < n; j++) {
				double x;
				fin >> x;
				B[i].push_back(x);
			}
		}

		vector <vector <double>> C = Start_Shtrassen(A, B);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				fout << C[i][j] << " ";
			}
			fout << endl;
		}
		fin.close();
		fout.close();
}
vector<vector <double>> Start_ShtrassenBest(vector<vector <double>> A, vector<vector <double>> B) {
	int old_size = A.size();

	A = extend_matrix(A);
	B = extend_matrix(B);

	vector<vector <double>> C = strassen_best(A, B, A.size());

	return remove_zeros(C, old_size);
}
void Start_ShtrassenBest(string inp, string out)
{
	ifstream fin(inp);
	int n;
	fin >> n;
	ofstream fout(out);

	vector <vector <double>> A;
	vector <vector <double>> B;

	for (int i = 0; i < n; i++) {
		A.push_back(vector <double>());
		for (int j = 0; j < n; j++) {
			double x;
			fin >> x;
			A[i].push_back(x);
		}
	}

	for (int i = 0; i < n; i++) {
		B.push_back(vector <double>());
		for (int j = 0; j < n; j++) {
			double x;
			fin >> x;
			B[i].push_back(x);
		}
	}

	vector <vector <double>> C = Start_ShtrassenBest(A, B);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fout << C[i][j] << " ";
		}
		fout << endl;
	}
	fin.close();
	fout.close();
}