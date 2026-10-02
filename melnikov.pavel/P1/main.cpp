#include <iostream>
#include <stdexcept>
#include <cstdlib>

bool is_triple(int a = 0, int b = 0, int c = 0);

int main()
{
    int num = 0;
    int a = 0, b = 0, c = 0;
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

            if (size >= 3)
            {
                if (is_triple(a, b, c))
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

        std::cout << count << "\n";
        return 0;
    }
    catch (const std::invalid_argument &ex)
    {
        std::cerr << "Invalid_argument: " << ex.what() << "\n";
        std::exit(1);
    }
}

bool is_triple(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }

    return (a * a + b * b == c * c) ||
           (b * b + c * c == a * a) ||
           (a * a + c * c == b * b);
}
