#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

int main()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_int_distribution<int> distr(0,20);
		int ct = 0;
    for (int i = 0; i < 10; i++)
    {
        int a = distr(e);
        int b = distr(e);

        std::cout << " " << std::setfill('0') << std::setw(2) << i+1 
						      << ": " << std::setfill(' ') << std::setw(2) << a << " + "
                         << std::setfill(' ') << std::setw(2) << b << " = ";
        int c = 0;
        std::cin >> c;
        if ((a + b) == c)
        {
						cout << "\e[A \t\t\t\t [" << "\033[1;32mPASS\033[0m" <<"]\n";
						ct++;
        }
        else
        {
            cout << "\e[A \t\t\t\t [" << "\033[1;31mFAIL\033[0m" <<"]\n";
        }
    }
		cout << "---------------------------------------\n";
		cout << ct << "/10 PASSED\n";

    return 0;
}
