#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.4_/Matrix.h"
#include "../Lab_2.4_/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest24
{
	TEST_CLASS(UnitTest24)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matr A(3,4);
			Assert::AreEqual(A.GetC(), 4);
		}
	};
}
