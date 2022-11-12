
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
	double f=0,s=0;
	while (f1 >> f && s1 >> s); {
		if (f != s)
			return false;
	}
	if (f1 >> f)
		return false;
	if (s1 >> s)
		return false;
	return true;
}
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(T1)
		{
			//string kek = filesystem::current_path().string();
			string inp = "../../test/input1.txt";
			string ans = "../../test/output1.txt";
			string out = "../../test/answer/output.txt";

			create_answer(inp, out);
			
			Assert::IsTrue(check_t(ans, out));
		}
		TEST_METHOD(T2)
		{
			Assert::IsTrue(true);
		}
	};
}
