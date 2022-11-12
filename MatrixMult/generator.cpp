#include "Generator.h"
#include <random>
#include <fstream>
#include <iostream>
#include <iomanip> 

using namespace std;
int sign()
{
    int rnd = rand() % 2;
    if (rnd == 1)  return 1;
    else return -1;
}
void f()
{
    int n;
    cin >> n;
    ofstream fout("output.txt");
    vector<vector<double>> a(n, (vector<double>(n)));
    vector<vector<double>> b(n, (vector<double>(n)));


    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[i].size(); ++j)
        {
            a[i][j] = rand() % 2000000 * sign();
            b[i][j] = rand() % 2000000 * sign();
        }

    fout << n << '\n';

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
            fout << fixed << setprecision(3) << a[i][j] << ' ';
        fout << endl;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b[i].size(); ++j)
            fout << fixed << setprecision(3) << b[i][j] << ' ';
        fout << endl;
    }

    fout.close();
}