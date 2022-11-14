#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "Shtrassen.h"
using namespace std;

double** initializeMatrix(int n) {
	double** temp = new double* [n];
	for (int i = 0; i < n; i++)
		temp[i] = new double[n];
	return temp;
}

void input(int** M, int n) {
	std::cout << "Enter matrix: " << std::endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> M[i][j];
	std::cout << std::endl;
}

void printMatrix(int** M, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << M[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

double** add(double** M1, double** M2, int n) {
	double** temp = initializeMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = M1[i][j] + M2[i][j];
	return temp;
}

double** subtract(double** M1, double** M2, int n) {
	double** temp = initializeMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = M1[i][j] - M2[i][j];
	return temp;
}

double** strassenMultiply_Best(double** A, double** B, int n) {
    if (n <= 64) {
        double** C = initializeMatrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
            }
        }
        /*  double** C = initializeMatrix(1);
          C[0][0] = A[0][0] * B[0][0];*/
        return C;
    }

    /*if (n == 1) {

          double** C = initializeMatrix(1);
          C[0][0] = A[0][0] * B[0][0];
        return C;
    }*/
    double** C = initializeMatrix(n);
    int k = n / 2;

    double** A11 = initializeMatrix(k);
    double** A12 = initializeMatrix(k);
    double** A21 = initializeMatrix(k);
    double** A22 = initializeMatrix(k);
    double** B11 = initializeMatrix(k);
    double** B12 = initializeMatrix(k);
    double** B21 = initializeMatrix(k);
    double** B22 = initializeMatrix(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }

    //// double** P1 = strassenMultiply(A11, subtract(B12, B22, k), k);
    //// double** P2 = strassenMultiply(add(A11, A12, k), B22, k);
    //// double** P3 = strassenMultiply(add(A21, A22, k), B11, k);
    //// double** P4 = strassenMultiply(A22, subtract(B21, B11, k), k);
    //// double** P5 = strassenMultiply(add(A11, A22, k), add(B11, B22, k), k);
    //// double** P6 = strassenMultiply(subtract(A12, A22, k), add(B21, B22, k), k);
    //// double** P7 = strassenMultiply(subtract(A11, A21, k), add(B11, B12, k), k);

    //// double** C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
    //// double** C12 = add(P1, P2, k);
    //// double** C21 = add(P3, P4, k);
    //// double** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);


    double** sub_p1 = subtract(B12, B22, k);
    double** P1 = strassenMultiply_Best(A11, sub_p1, k);
    for (int i = 0; i < k; i++) {
        delete[] sub_p1[i];
    }
    delete[] sub_p1;

    double** add_p2 = add(A11, A12, k);
    double** P2 = strassenMultiply_Best(add_p2, B22, k);
    for (int i = 0; i < k; i++) {
        delete[] add_p2[i];
    }
    delete[] add_p2;


    double** add_p3 = add(A21, A22, k);
    double** P3 = strassenMultiply_Best(add_p3, B11, k);
    for (int i = 0; i < k; i++) {
        delete[] add_p3[i];
    }
    delete[] add_p3;


    double** sub_p4 = subtract(B21, B11, k);
    double** P4 = strassenMultiply_Best(A22, sub_p4, k);
    for (int i = 0; i < k; i++) {
        delete[] sub_p4[i];
    }
    delete[] sub_p4;

    double** add_p5_1 = add(A11, A22, k);
    double** add_p5_2 = add(B11, B22, k);
    double** P5 = strassenMultiply_Best(add_p5_1, add_p5_2, k);
    for (int i = 0; i < k; i++) {
        delete[] add_p5_1[i];
        delete[] add_p5_2[i];
    }
    delete[] add_p5_1;
    delete[] add_p5_2;


    double** sub_p6 = subtract(A12, A22, k);
    double** add_p6 = add(B21, B22, k);
    double** P6 = strassenMultiply_Best(sub_p6, add_p6, k);
    for (int i = 0; i < k; i++) {
        delete[] sub_p6[i];
        delete[] add_p6[i];
    }
    delete[] sub_p6;
    delete[] add_p6;


    double** sub_p7 = subtract(A11, A21, k);
    double** add_p7 = add(B11, B12, k);
    double** P7 = strassenMultiply_Best(sub_p7, add_p7, k);
    for (int i = 0; i < k; i++) {
        delete[] sub_p7[i];
        delete[] add_p7[i];
    }
    delete[] sub_p7;
    delete[] add_p7;

    double** C11_addadd = add(P5, P4, k);
    double** C11_add = add(C11_addadd, P6, k);
    for (int i = 0; i < k; i++) {
        delete[] C11_addadd[i];
    }
    delete[] C11_addadd;

    double** C11 = subtract(C11_add, P2, k);
    for (int i = 0; i < k; i++) {
        delete[] C11_add[i];
    }
    delete[] C11_add;



    double** C12 = add(P1, P2, k);
    double** C21 = add(P3, P4, k);

    double** C22_subadd = add(P5, P1, k);
    double** C22_sub = subtract(C22_subadd, P3, k);
    double** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);

    for (int i = 0; i < k; i++) {
        delete[] C22_subadd[i];
        delete[] C22_sub[i];
    }
    delete[] C22_subadd;
    delete[] C22_sub;

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }

    for (int i = 0; i < k; i++) {
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] P1[i];
        delete[] P2[i];
        delete[] P3[i];
        delete[] P4[i];
        delete[] P5[i];
        delete[] P6[i];
        delete[] P7[i];
        delete[] C11[i];
        delete[] C12[i];
        delete[] C21[i];
        delete[] C22[i];
    }

    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] P1;
    delete[] P2;
    delete[] P3;
    delete[] P4;
    delete[] P5;
    delete[] P6;
    delete[] P7;
    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;

    return C;
}


void Start_ShtrassenBest(string inp, string out)
{

	ifstream fin(inp);
	ofstream fout(out);
	int n;
	int n_old;
	fin >> n;
	n_old = n;
	n = pow(2, ceil(log2(n)));
	double** A = initializeMatrix(n);
	double** B = initializeMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = 0;
		}
	}
	for (int i = 0; i < n_old; i++) {
		for (int j = 0; j < n_old; j++) {
			double var;
			fin >> var;
			A[i][j] = var;
		}
	}
	for (int i = 0; i < n_old; i++) {
		for (int j = 0; j < n_old; j++) {
			double var;
			fin >> var;
			B[i][j] = var;
		}
	}


	double** C = initializeMatrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}
	C = strassenMultiply_Best(A, B, n);
	double** ANSWER = initializeMatrix(n_old);
	for (int i = 0; i < n_old; i++) {
		for (int j = 0; j < n_old; j++) {
			ANSWER[i][j] = C[i][j];
		}
	}

	for (int i = 0; i < n_old; i++) {
		for (int j = 0; j < n_old; j++) {
			fout << ANSWER[i][j] << " ";
		}
		fout << endl;
	}
	fin.close();
	fout.close();
	for (int i = 0; i < n_old; i++)
		delete[] ANSWER[i];
	delete[] ANSWER;

	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;

	for (int i = 0; i < n; i++)
		delete[] B[i];
	delete[] B;

	for (int i = 0; i < n; i++)
		delete[] C[i];
	delete[] C;
}
double** strassenMultiply(double** A, double** B, int n) {
    //if (n <= 64) {
    //    double** C = initializeMatrix(n);
    //    for (int i = 0; i < n; i++) {
    //        for (int j = 0; j < n; j++) {
    //            double sum = 0;
    //            for (int k = 0; k < n; k++) {
    //                sum += A[i][k] * B[k][j];
    //            }
    //            C[i][j] = sum;
    //        }
    //    }
    //    /*  double** C = initializeMatrix(1);
    //      C[0][0] = A[0][0] * B[0][0];*/
    //    return C;
    //}

    if (n == 1) {

          double** C = initializeMatrix(1);
          C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    double** C = initializeMatrix(n);
    int k = n / 2;

    double** A11 = initializeMatrix(k);
    double** A12 = initializeMatrix(k);
    double** A21 = initializeMatrix(k);
    double** A22 = initializeMatrix(k);
    double** B11 = initializeMatrix(k);
    double** B12 = initializeMatrix(k);
    double** B21 = initializeMatrix(k);
    double** B22 = initializeMatrix(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }

    //// double** P1 = strassenMultiply(A11, subtract(B12, B22, k), k);
    //// double** P2 = strassenMultiply(add(A11, A12, k), B22, k);
    //// double** P3 = strassenMultiply(add(A21, A22, k), B11, k);
    //// double** P4 = strassenMultiply(A22, subtract(B21, B11, k), k);
    //// double** P5 = strassenMultiply(add(A11, A22, k), add(B11, B22, k), k);
    //// double** P6 = strassenMultiply(subtract(A12, A22, k), add(B21, B22, k), k);
    //// double** P7 = strassenMultiply(subtract(A11, A21, k), add(B11, B12, k), k);

    //// double** C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
    //// double** C12 = add(P1, P2, k);
    //// double** C21 = add(P3, P4, k);
    //// double** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);


    double** sub_p1 = subtract(B12, B22, k);
    double** P1 = strassenMultiply(A11, sub_p1, k);
    for (int i = 0; i < k; i++) {
        delete[] sub_p1[i];
    }
    delete[] sub_p1;

    double** add_p2 = add(A11, A12, k);
    double** P2 = strassenMultiply(add_p2, B22, k);
    for (int i = 0; i < k; i++) {
        delete[] add_p2[i];
    }
    delete[] add_p2;


    double** add_p3 = add(A21, A22, k);
    double** P3 = strassenMultiply(add_p3, B11, k);
    for (int i = 0; i < k; i++) {
        delete[] add_p3[i];
    }
    delete[] add_p3;


    double** sub_p4 = subtract(B21, B11, k);
    double** P4 = strassenMultiply(A22, sub_p4, k);
    for (int i = 0; i < k; i++) {
        delete[] sub_p4[i];
    }
    delete[] sub_p4;

    double** add_p5_1 = add(A11, A22, k);
    double** add_p5_2 = add(B11, B22, k);
    double** P5 = strassenMultiply(add_p5_1, add_p5_2, k);
    for (int i = 0; i < k; i++) {
        delete[] add_p5_1[i];
        delete[] add_p5_2[i];
    }
    delete[] add_p5_1;
    delete[] add_p5_2;


    double** sub_p6 = subtract(A12, A22, k);
    double** add_p6 = add(B21, B22, k);
    double** P6 = strassenMultiply(sub_p6, add_p6, k);
    for (int i = 0; i < k; i++) {
        delete[] sub_p6[i];
        delete[] add_p6[i];
    }
    delete[] sub_p6;
    delete[] add_p6;


    double** sub_p7 = subtract(A11, A21, k);
    double** add_p7 = add(B11, B12, k);
    double** P7 = strassenMultiply(sub_p7, add_p7, k);
    for (int i = 0; i < k; i++) {
        delete[] sub_p7[i];
        delete[] add_p7[i];
    }
    delete[] sub_p7;
    delete[] add_p7;

    double** C11_addadd = add(P5, P4, k);
    double** C11_add = add(C11_addadd, P6, k);
    for (int i = 0; i < k; i++) {
        delete[] C11_addadd[i];
    }
    delete[] C11_addadd;

    double** C11 = subtract(C11_add, P2, k);
    for (int i = 0; i < k; i++) {
        delete[] C11_add[i];
    }
    delete[] C11_add;



    double** C12 = add(P1, P2, k);
    double** C21 = add(P3, P4, k);

    double** C22_subadd = add(P5, P1, k);
    double** C22_sub = subtract(C22_subadd, P3, k);
    double** C22 = subtract(C22_sub, P7, k);

    for (int i = 0; i < k; i++) {
        delete[] C22_subadd[i];
        delete[] C22_sub[i];
    }
    delete[] C22_subadd;
    delete[] C22_sub;

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }

    for (int i = 0; i < k; i++) {
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] P1[i];
        delete[] P2[i];
        delete[] P3[i];
        delete[] P4[i];
        delete[] P5[i];
        delete[] P6[i];
        delete[] P7[i];
        delete[] C11[i];
        delete[] C12[i];
        delete[] C21[i];
        delete[] C22[i];
    }

    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] P1;
    delete[] P2;
    delete[] P3;
    delete[] P4;
    delete[] P5;
    delete[] P6;
    delete[] P7;
    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;

    return C;
}

void Start_Shtrassen(string inp, string out)
{

    ifstream fin(inp);
    ofstream fout(out);
    int n;
    int n_old;
    fin >> n;
    n_old = n;
    n = pow(2, ceil(log2(n)));
    double** A = initializeMatrix(n);
    double** B = initializeMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = 0;
        }
    }
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            double var;
            fin >> var;
            A[i][j] = var;
        }
    }
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            double var;
            fin >> var;
            B[i][j] = var;
        }
    }


    double** C = initializeMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
    C = strassenMultiply(A, B, n);
    double** ANSWER = initializeMatrix(n_old);
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            ANSWER[i][j] = C[i][j];
        }
    }

    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            fout << ANSWER[i][j] << " ";
        }
        fout << endl;
    }
    fin.close();
    fout.close();
    for (int i = 0; i < n_old; i++)
        delete[] ANSWER[i];
    delete[] ANSWER;

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < n; i++)
        delete[] B[i];
    delete[] B;

    for (int i = 0; i < n; i++)
        delete[] C[i];
    delete[] C;
}

vector <vector <double>> Start_Shtrassen(const vector <vector <double>>& first_matrix, const vector <vector <double>>& second_matrix)
{

    int n=first_matrix.size();
    int n_old;
    n_old = n;
    n = pow(2, ceil(log2(n)));
    double** A = initializeMatrix(n);
    double** B = initializeMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = 0;
        }
    }
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            double var;
            A[i][j] = first_matrix[i][j];
        }
    }
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            double var;
            B[i][j] = second_matrix[i][j];
        }
    }


    double** C = initializeMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
    C = strassenMultiply(A, B, n);
    double** ANSWER = initializeMatrix(n_old);
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            ANSWER[i][j] = C[i][j];
        }
    }
    std::vector<vector<double>> ans;
    for (int i = 0; i < n_old; i++) {
        ans.push_back(std::vector<double>());
        for (int j = 0; j < n_old; j++) {
            ans[i].push_back(ANSWER[i][j]);
        }
    }
    for (int i = 0; i < n_old; i++)
        delete[] ANSWER[i];
    delete[] ANSWER;

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < n; i++)
        delete[] B[i];
    delete[] B;

    for (int i = 0; i < n; i++)
        delete[] C[i];
    delete[] C;
    return ans;
}

vector <vector <double>> Start_ShtrassenBest(const vector <vector <double>>& first_matrix, const vector <vector <double>>& second_matrix)
{

    int n = first_matrix.size();
    int n_old;
    n_old = n;
    n = pow(2, ceil(log2(n)));
    double** A = initializeMatrix(n);
    double** B = initializeMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = 0;
        }
    }
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            double var;
            A[i][j] = first_matrix[i][j];
        }
    }
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            double var;
            B[i][j] = second_matrix[i][j];
        }
    }


    double** C = initializeMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
    C = strassenMultiply_Best(A, B, n);
    double** ANSWER = initializeMatrix(n_old);
    for (int i = 0; i < n_old; i++) {
        for (int j = 0; j < n_old; j++) {
            ANSWER[i][j] = C[i][j];
        }
    }
    std::vector<vector<double>> ans;
    for (int i = 0; i < n_old; i++) {
        ans.push_back(std::vector<double>());
        for (int j = 0; j < n_old; j++) {
            ans[i].push_back(ANSWER[i][j]);
        }
    }
    for (int i = 0; i < n_old; i++)
        delete[] ANSWER[i];
    delete[] ANSWER;

    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    for (int i = 0; i < n; i++)
        delete[] B[i];
    delete[] B;

    for (int i = 0; i < n; i++)
        delete[] C[i];
    delete[] C;
    return ans;
}