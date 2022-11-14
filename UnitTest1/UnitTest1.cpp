
#include <string>
#include "pch.h"
#include "CppUnitTest.h"

#include "..\MatrixMult\Standart.h"
#include "..\MatrixMult\Standart.cpp"
#include "..\MatrixMult\Generator.h"
#include "..\MatrixMult\generator.cpp"
#include "..\MatrixMult\Shtrassen.h"
#include "..\MatrixMult\Shtrassen.cpp"
#include "..\MatrixMult\MatrixMult.h"
#include "..\MatrixMult\MatrixMult.cpp"

#include <filesystem>
#include <time.h> 

//ofstream out("..\\input.")
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

bool check_t(string first, string second) {
	ifstream f1(first);
	ifstream s1(second);

	double f=0,s=1;
	while (f1 >> f && s1 >> s); {
		if (f != s) {
			f1.close();
			s1.close();
			return false;
		}
	}
	if (f1 >> f)
	{
		f1.close();
		s1.close();
		return false;
	}
	if (s1 >> s)
	{
		f1.close();
		s1.close();
		return false;
	}
	f1.close();
	s1.close();
	return true;
}

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(T1)
		{
			string num_t = "1";

			string inp = "../../test/input"+num_t+".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл
			
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T2)
		{
			string num_t = "2";

			string inp = "../../test/input"+num_t+".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл
			
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T3)
		{

			string num_t = "3";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T4)
		{

			string num_t = "4";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T5)
		{

			string num_t = "5";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T6)
		{

			string num_t = "6";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T7)
		{

			string num_t = "7";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T8)
		{

			string num_t = "8";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T9)
		{

			string num_t = "9";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T10)
		{

			string num_t = "10";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T11)
		{

			string num_t = "11";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T12)
		{

			string num_t = "12";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T13)
		{

			string num_t = "13";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T14)
		{

			string num_t = "14";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T15)
		{

			string num_t = "15";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T16)
		{

			string num_t = "16";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T17)
		{

			string num_t = "17";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T18)
		{

			string num_t = "18";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T19)
		{

			string num_t = "19";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T20)
		{

			string num_t = "20";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T21)
		{

			string num_t = "21";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T22)
		{

			string num_t = "22";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T23)
		{

			string num_t = "23";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T24)
		{

			string num_t = "24";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T25)
		{

			string num_t = "25";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T26)
		{

			string num_t = "26";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T27)
		{

			string num_t = "27";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T28)
		{

			string num_t = "28";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T29)
		{

			string num_t = "29";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T30)
		{

			string num_t = "30";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T31)
		{

			string num_t = "31";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T32)
		{

			string num_t = "32";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T33)
		{

			string num_t = "33";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T34)
		{

			string num_t = "34";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T35)
		{

			string num_t = "35";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T36)
		{

			string num_t = "36";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T37)
		{

			string num_t = "37";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T38)
		{

			string num_t = "38";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T39)
		{

			string num_t = "39";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T40)
		{

			string num_t = "40";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T41)
		{

			string num_t = "41";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T42)
		{

			string num_t = "42";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T43)
		{

			string num_t = "43";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T44)
		{

			string num_t = "44";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T45)
		{

			string num_t = "45";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T46)
		{

			string num_t = "46";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T47)
		{

			string num_t = "47";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T48)
		{

			string num_t = "48";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T49)
		{

			string num_t = "49";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T50)
		{

			string num_t = "50";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T51)
		{

			string num_t = "51";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T52)
		{

			string num_t = "52";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T53)
		{

			string num_t = "53";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T54)
		{

			string num_t = "54";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T55)
		{

			string num_t = "55";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T56)
		{

			string num_t = "56";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T57)
		{

			string num_t = "57";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T58)
		{

			string num_t = "58";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T59)
		{

			string num_t = "59";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T60)
		{

			string num_t = "60";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T61)
		{

			string num_t = "61";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T62)
		{

			string num_t = "62";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T63)
		{

			string num_t = "63";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T64)
		{

			string num_t = "64";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";
			clock_t start = clock();
			create_answer(inp, out);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			std::ifstream fin(inp);
			int n;
			fin >> n;
			std::ofstream fout;                    //создаем поток 
			fout.open("../../../tests.txt", std::ios::app);  // открываем файл для записи в конец
			fout << n << " " << seconds << endl;;
			fout.close();                          // закрываем файл

			Assert::IsTrue(check_t(ans, out));
		}
	};
}
