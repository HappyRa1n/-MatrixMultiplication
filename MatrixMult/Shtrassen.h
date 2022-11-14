#pragma once
#include <string>
#include <vector>
using namespace std;

void Start_Shtrassen(string inp, string out);
void Start_ShtrassenBest(string inp, string out);


vector <vector <double>> Start_Shtrassen(const vector <vector <double>>& first_matrix, const vector <vector <double>>& second_matrix);
vector <vector <double>> Start_ShtrassenBest(const vector <vector <double>>& first_matrix, const vector <vector <double>>& second_matrix);
