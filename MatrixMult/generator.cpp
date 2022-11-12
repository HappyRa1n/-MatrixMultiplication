#include "Generator.h"
#include "Standart.h"
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
void Test_generator()
{
    int n;
    cin >> n;
    ofstream fout("input15.txt");
    vector<vector<double>> a(n, (vector<double>(n)));
    vector<vector<double>> b(n, (vector<double>(n)));
    int DATA_MAX = 2000000, DATA_MIN = -2000000;

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[i].size(); ++j)
        {
            a[i][j] = (double)rand() / RAND_MAX * (DATA_MAX - DATA_MIN) + DATA_MIN;
            Sleep(2);
            b[i][j] = (double)rand() / RAND_MAX * (DATA_MAX - DATA_MIN) + DATA_MIN;
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
