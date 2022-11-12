
#include <string>
#include "pch.h"
#include "CppUnitTest.h"

#include "..\MatrixMult\Standart.h"
#include "..\MatrixMult\Standart.cpp"
#include "..\MatrixMult\MatrixMult.h"
#include "..\MatrixMult\MatrixMult.cpp"
#include <filesystem>


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

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T2)
		{
			string num_t = "2";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T3)
		{

			string num_t = "3";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T4)
		{

			string num_t = "4";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T5)
		{

			string num_t = "5";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T6)
		{

			string num_t = "6";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T7)
		{

			string num_t = "7";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T8)
		{

			string num_t = "8";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T9)
		{

			string num_t = "9";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T10)
		{

			string num_t = "10";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T11)
		{

			string num_t = "11";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T12)
		{

			string num_t = "12";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T13)
		{

			string num_t = "13";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T14)
		{

			string num_t = "14";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T15)
		{

			string num_t = "15";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T16)
		{

			string num_t = "16";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T17)
		{

			string num_t = "17";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T18)
		{

			string num_t = "18";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T19)
		{

			string num_t = "19";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T20)
		{

			string num_t = "20";

			string inp = "../../test/input" + num_t + ".txt";
			string ans = "../../test/output" + num_t + ".txt";

			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			Assert::IsTrue(check_t(ans, out));
		}
	};
}
