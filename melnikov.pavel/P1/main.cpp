#include <cstdlib>
#include <iostream>
#include <stdexcept>

namespace
{
    constexpr int kMinPositiveValue = 0;
    constexpr int kTripleSize = 3;
    constexpr int kInvalidInputExitCode = 1;
    constexpr int kRangeErrorExitCode = 2;
}

bool isTriple(int a, int b, int c)
{
    if (a <= kMinPositiveValue || b <= kMinPositiveValue || c <= kMinPositiveValue)
    {
        return false;
    }

    return (a * a + b * b == c * c) ||
           (b * b + c * c == a * a) ||
           (a * a + c * c == b * b);
}

int main()
{
    int num = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int count = 0;
    int size = 0;

    try
    {
        while (std::cin >> num && num != 0)
        {
            size++;

            a = b;
            b = c;
            c = num;

            if (size >= kTripleSize)
            {
                if (isTriple(a, b, c))
                {
                    count++;
                    a = 0;
                    b = 0;
                    c = 0;
                    size = 0;
                }
            }
        }

        if (std::cin.fail() && !std::cin.eof())
        {
            throw std::invalid_argument("Invalid data format.");
        }

        if (count == 0)
        {
            throw std::range_error("No triples found in the sequence.");
        }

        std::cout << count << '\n';
        return 0;
    }
    catch (const std::invalid_argument &ex)
    {
        std::cerr << "Invalid_argument: " << ex.what() << '\n';
        std::exit(kInvalidInputExitCode);
    }
    catch (const std::range_error &ex)
    {
        std::cerr << "Range_error: " << ex.what() << '\n';
        std::exit(kRangeErrorExitCode);
    }
}