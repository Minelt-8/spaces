#include <array>
#include <iostream>
#include <vector>

int userLength(){

        std::cout << "Enter Vector length: ";
        int number;
        std::cin >> number;
        if(!number){
            if(static_cast<char>(number) == 'q'){
                std::cout << "EXITED";
                return 0;
            }
            std::cout << "Please enter valid number!";
        }

        return number;
}

std::vector<int> initializeVectorLength(){
    int user{userLength()};

    std::vector<int> vector(user);

    return vector;
}

std::vector<int> userVector(std::vector<int> vector){
    int j{0};
    for (int i{0}; i < vector.size(); i++)
    {
        std::cout << "Enter number (Please enter an intiger): ";
        int num;
        std::cin >> num;

        if(!num){
             std::cout << "INVALID NUMBER" << '\n';
             break;
        }

        vector[i] = num;

        j++;
    }
    return vector;
}

void bubbleSort(std::vector<int> vector)
{

    for (int i{0}; i < vector.size(); i++)
    {
        for (int j{0}; j < vector.size() - 1; j++)
        {
                if (vector[j + 1] < vector[j])
                {
                    std::swap(vector[j], vector[j + 1]);
                }
        }
    }

    for (const auto &elements : vector)
    {
        std::cout << elements << ' ';
    }
}

void sum(std::vector<int> vector)
{
    int sum{0};
    for (int i{0}; i < vector.size(); i++)
    {
        sum += vector[i];
    }

    std::cout << "The sum of those elements is " << sum;
}

void max(std::vector<int> vector)
{
    int max{0};
    for (int i{0}; i < vector.size(); i++)
    {

        if (vector[i] > max)
        {
                max = vector[i];
        }
    }

    std::cout << "The max of those elements is " << max;
}

bool isOdd(std::vector<int> vector){

    int count{0};

    bool isOdd = false;

    for (int i{1}; i < vector.size(); i++){
        count++;
    }

    if((count % 2) == 0){

        isOdd = true;
    }

    return isOdd;
}

void median(std::vector<int> vector){
    bool odd{isOdd(vector)};

    if(odd == false){
        double a{(vector.size() - 1) / 2};

        int m{a + 1 / 2};

        double total{vector[m] + 0.5};

        std::cout << "The median of these numbers is: " << total;
    }
    if (odd == true)
    {
        int a{(vector.size() - 1) / 2};

        int m{((a / 2) + (a / 2 + 1))};

        std::cout << "The median of these numbers is: " << vector[m];
    }
}

void askUserForFunction(){
    std::cout << "What do you want to do with the vector(Sort it (S), find the sum (U), find the max (M), find median (E) Enter q to exit: ";
    char input;

    std::cin >> input;

    switch (input)
    {
    case 'S':
        bubbleSort(userVector(initializeVectorLength()));
        break;
    case 'U':
        sum(userVector(initializeVectorLength()));
        break;
    case 'M':
        max(userVector(initializeVectorLength()));
        break;
    case 'E':
        median(userVector(initializeVectorLength()));
        break;
    }

    if(!input){
        std::cout << "Enter valid functionality!";
        return;
    }
}

int main()
{

    askUserForFunction();

    return 0;
}