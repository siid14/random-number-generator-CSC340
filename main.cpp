/*
Pseudo code:
1. Create a mean and standard deviation
2. Create a normal distribution object with the mean and standard deviation
3. Create a map to store the randomly generated samples
4. Generate the samples
5. Count the occurence the each histogram value and print the histogram
-We decided to use a map because we thought it would be more efficent and made the most sense
because we are storing the values and the number of times they occur.
-Our function prototype is generateHistogram(mean, standard deviation, number of samples)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <cassert>
using namespace std;

// generate a histogram of randomly generated integers
std::map<int, int> generateHistogram(int mean, int standard_deviation, int number_samples)
{
    // * FOR TESTING PURPOSE : create a normal distribution object with a fixed random seed of 1
    std::mt19937 gen(1); // get the same sequence of random numbers every time you run the program with the same input values
    std::normal_distribution<> d(mean, standard_deviation);

    // create a normal distribution object
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::normal_distribution<> d(mean, standard_deviation);

    // create vector to store the randomly generated samples
    std::map<int, int> histogram; // key : possible value of sample -- value : number of times it occurs

    // * generate the sample number and store it in histogram
    for (int i = 0; i < number_samples; i++)
    {
        // rounds the random number to the nearest integer and increments the value in the map
        histogram[std::round(d(gen))]++;
    }

    cout << "PRINTING ACTUAL HISTOGRAM REPRESENTATION"
         << "\n";

    // ! Structured bindings method, compiler need to be set with C++17 for use (warning)
    // for (auto [x, y] : histogram)
    // {

    //     cout << std::setw(2) << x << " | " << std::string(y / 100, '-') << "\n";
    // }

    // count the occurence the each histogram value and print the histogram represention
    for (const auto &pair : histogram)
    {
        const int x = pair.first;
        const int y = pair.second;
        cout << std::setw(2) << x << " | " << std::string(y / 100, '-') << "\n";
    }

    cout << "END PRINTING ACTUAL HISTOGRAM REPRESENTATION"
         << "\n";

    cout << "PRINTING ACTUAL HISTOGRAM KEY - VALUE"
         << "\n";
    // print key-value pair of historgram
    for (const auto &pair : histogram)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
    cout << "END PRINTING ACTUAL HISTOGRAM KEY - VALUE"
         << "\n";

    return histogram;
    cout << "\n";
}

int main()
{
    // * PART 1
    int mean, standard_deviation;

    // * get mean and standard deviation
    cout << "Enter Mean: ";
    cin >> mean;
    cout << "Enter Standard Deviation: ";
    cin >> standard_deviation;

    //  print an histogram of numbers
    // generateHistogram(50.0, 10.0, 20000);
    // generateHistogram(10, 2, 20000);
    // generateHistogram(mean, standard_deviation, 20000);

    // * Unit Test - PART 1

    // * TEST WITH INPUT Median : 10 - Standard Deviation : 2
    std::map<int, int> expectedOutput = {
        {2, 2},
        {3, 10},
        {4, 46},
        {5, 167},
        {6, 564},
        {7, 1371},
        {8, 2335},
        {9, 3499},
        {10, 4027},
        {11, 3426},
        {12, 2408},
        {13, 1350},
        {14, 564},
        {15, 172},
        {16, 46},
        {17, 11},
        {18, 2}};

    std::map<int, int> actualOutput = generateHistogram(mean, standard_deviation, 20000); /* return a histogram of Key-Value pair
                                                                                            Key-Value --> Number - Number of time the same number appear*/

    cout << "PRINTING EXPECTED HISTOGRAM"
         << "\n";
    for (const auto &pair : expectedOutput)
    {
        const int x = pair.first;
        const int y = pair.second;
        cout << std::setw(2) << x << " | " << std::string(y / 100, '-') << "\n";
    }
    cout << "END PRINTING EXPECTED HISTOGRAM"
         << "\n";

    cout << "PRINTING EXPECTED HISTOGRAM KEY - VALUE"
         << "\n";
    for (const auto &pair : expectedOutput)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
    cout << "END PRINTING EXPECTED HISTOGRAM KEY - VALUE"
         << "\n";

    // * compare actual and expected outputs
    if (actualOutput == expectedOutput)
    {
        std::cout << "Test passed!" << std::endl;
    }
    else
    {
        std::cout << "Test failed!" << std::endl;
    }

    // cout << "PRINTING ACTUAL HISTOGRAM KEY - VALUE"
    //      << "\n";
    // for (const auto &pair : actualOutput)
    // {
    //     std::cout << pair.first << " : " << pair.second << std::endl;
    // }
    // cout << "END PRINTING ACTUAL HISTOGRAM KEY - VALUE"
    //      << "\n";

    // * compare actual and expected outputs
    assert(actualOutput == expectedOutput);
    cout << "Test passed via assert method"
         << "\n";

    // TODO: Unit Test: Part 2

    return 0;
}
