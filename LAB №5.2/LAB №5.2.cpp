#include <iostream>
#include <iomanip>
#include <cmath>

void S(double xp, double xk, double dx, double eps);
void A(const double x, const double eps, int& n, double& s);
void B(const double x, const int n, double& a);

int main()
{
    double xp, xk, dx, eps;

    std::cout << "xp = "; std::cin >> xp;
    std::cout << "xk = "; std::cin >> xk;
    std::cout << "dx = "; std::cin >> dx;
    std::cout << "eps = "; std::cin >> eps;

    std::cout << std::fixed;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "x" << " |"
        << std::setw(20) << "ln(1 - x)" << " |"
        << std::setw(15) << "S" << " |"
        << std::setw(10) << "n" << " |"
        << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    S(xp, xk, dx, eps);

    std::cout << "-------------------------------------------------" << std::endl;
    return 0;
}

void S(double xp, double xk, double dx, double eps)
{
    double x = xp;
    int n;
    double s = 0;

    while (x <= xk)
    {
        A(x, eps, n, s);
        std::cout << "|" << std::setw(10) << std::setprecision(2) << x << " |"
            << std::setw(20) << std::setprecision(10) << -log(1 - x) << " |"
            << std::setw(15) << std::setprecision(10) << s << " |"
            << std::setw(10) << n << " |"
            << std::endl;
        x += dx;
    }
}

void A(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = x;
    s = a;

    do
    {
        n++;
        B(x, n, a);
        s += a;
    } while (std::abs(a) >= eps);
}

void B(const double x, const int n, double& a)
{
    double R = -(x * n) / (n + 1);
    a *= -R;
}
