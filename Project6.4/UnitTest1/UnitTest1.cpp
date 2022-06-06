#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Study\ООП\Project6.4\Project6.4\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Vector<int> a(4);
			a[0] = 4, a[1] = 2, a[2] = 3, a[3] = 1;
			int b = 1;
			b = a.min();
			Assert::AreEqual(b, 1);
		}
	};
}
