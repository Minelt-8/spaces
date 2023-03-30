#include <iostream>
#include <string>
#include <limits>

void userArrayLengthAndSortPrint()
{
    std::cout << "How many names would you like to enter: ";
    int length{};
    std::cin >> length;

    if (!std::cin)
    {
        std::cerr << "ENTER AN INTIGER";
        return;
    }

    std::string *ptr{new std::string[length]};

    for (int start{0}; start < length; start++)
    {
        std::cout << "Enter name " << start + 1 << "# ";

        std::string name;

        std::getline(std::cin >> std::ws, name);

        ptr[start] = name;
    }

    std::cout << '\n';

    // Bubble sort algorithm

    for (int start{0}; start < length - 1; start++)
    {

        for (int current{0}; current < length - 1; current++)
        {

            if (ptr[current + 1] < ptr[current])
            {

                std::swap(ptr[current], ptr[current + 1]);
            }
        }
    }

    std::cout << "Sorting the array with bubble sort algorithm we get: " << '\n';

    // print array :)

    for (int i = 0; i < length + 1; i++)
    {
        std::cout << '\n';
        std::cout << ptr[i] << '\n';
     
    }

    // delete the array

    delete[] ptr;
}

int main()
{

    userArrayLengthAndSortPrint();

    return 0;
}