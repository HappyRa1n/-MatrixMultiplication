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
int DATA_MAX = 2000000, DATA_MIN = -2000000;
double GenDouble() {
    return (double)rand() / RAND_MAX * (DATA_MAX - DATA_MIN) + DATA_MIN;
}
void f(int n, ofstream& fout)
{
    //int n;
    //cin >> n;

    vector<vector<double>> a(n, (vector<double>(n)));
    vector<vector<double>> b(n, (vector<double>(n)));
    

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[i].size(); ++j)
        {
            a[i][j] = (double)rand() / RAND_MAX * (DATA_MAX - DATA_MIN) + DATA_MIN;
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


}
void OutGen() {
    for (int i = 1; i <= 61; i++) {
        string inp="test/input"+to_string(i)+".txt";
        string out="test/output" + to_string(i) + ".txt";
        Start_Standart(inp, out);
    }
}
void CorrectTests() {
    string inp = "strassen64.txt";
    string out = "correct_" + inp;
    int n = 100;
    ifstream fin(inp);
    ofstream fout(out);
    std::vector<std::pair<int, double>> vec;
    for (int i = 0; i < n;i++) {
        int num;
        double time;
        if (!(fin >> num)) {
            break;
        }
        fin >> time;
        vec.push_back(std::make_pair(num, time));
    }
    // Сортировка массива пузырьком
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j].first > vec[j+1].first) {
                int tmp_n = vec[j+1].first;
                double tmp_time = vec[j+1].second;
                vec[j+1].first = vec[j].first;
                vec[j+1].second = vec[j].second;
                vec[j].first = tmp_n;
                vec[j].second = tmp_time;
            }
        }
    }

    std::vector<std::pair<int, double>> ans;
    for (int i = 0; i < vec.size(); i++) {
        int k = 1;
        int num = vec[i].first;
        double sum = vec[i].second;
        while (i + 1 != vec.size() && vec[i + 1].first == vec[i].first) {
            k++;
            i++;
            sum+= vec[i].second;
        }
        double finaly = sum / k;
        ans.push_back(make_pair(num, finaly));
    }
    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i].first << " " << ans[i].second<<endl;
    }
}