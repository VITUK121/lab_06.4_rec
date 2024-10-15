#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06.4_rec/lab_06.4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest064rec
{
	TEST_CLASS(UnitTest064rec)
	{
	public:
		template <typename T>
		bool AreSame(T* a, T* b, int size) {
			for (int i = 0; i != size; i++) {
				if (a[i] != b[i]) { return false; }
			}
			return true;
		}

		TEST_METHOD(TestMethod1)
		{
			double* a = new double[8];
			for (int i = -4; i != 4; i++) {
				a[i + 4] = (i * i) / 2.5;
			}

			double b[] = {0.4,0,0.4,6.4,3.6,1.6,1.6,3.6};

			change_arr(a, 8);

			Assert::IsTrue(AreSame(a, b, 8));
		}
	};
}
