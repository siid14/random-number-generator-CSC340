/*
Psuedo code:
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
using namespace std;

// function to generate a histogram of randomly generated integers
void generateHistogram(int mean, int standard_deviation, int number_samples){


    //Creating a normal distribution object
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(mean, standard_deviation);
    // create vector to store the randomly generated samples
    std::map<int, int> histogram; 
    // generate the samples
    // number_samples generates till 20000
    for(int i =0 ;i < number_samples; i++){
        //rounds the random number to the nearest integer and increments the value in the map
        histogram[std::round(d(gen))]++;
    }
    // another for loop to count the occurence the each histogram value and print the histogram
    for(auto [x,y]:histogram){
        std::cout << std::setw(2) << x << " | " << std::string(y/100, '-') << std::endl;
    }


}
int main(){
    int mean, standard_deviation;

    cout << "Enter Mean:";
    cin >> mean;
    cout << "Enter Standard Deviation:";
    cin >> standard_deviation;
    // generateHistogram(50.0, 10.0, 20000);
    //generateHistogram(10,2,20000);
    generateHistogram(mean, standard_deviation, 20000);
    return 0;
}
