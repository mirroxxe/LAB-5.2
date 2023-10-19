#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB №5.2/LAB №5.2.cpp"

extern void S(double xp, double xk, double dx, double eps);
extern void A(const double x, const double eps, int& n, double& s);
extern void B(const double x, const int n, double& a);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            double xp = 0.1;
            double xk = 0.8;
            double dx = 0.1;
            double eps = 0.00001;
            int n;
            double s;

            S(xp, xk, dx, eps);
            A(xp, eps, n, s);

            Assert::AreEqual(-log(1 - xp), s, eps);
        }
    };

