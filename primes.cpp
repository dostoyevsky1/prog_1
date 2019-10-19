#include <iostream>
#include <vector>
#include <math.h>

std::vector<int> range(int x_lower, int x_upper, int step = 1)
{
    std::vector<int> v;
    while(1) {
            if(x_lower > x_upper){
                break;
            }
            v.push_back(x_lower);
            x_lower += step;
        }
    return v;
}

int main() 
{
    int x_lower, x_upper, check_lim, endline_check;
    char yes_no_var;

    std::cout << std::endl <<
    "Michael Drozdov" << std::endl <<
    "CIS 9310 Programming Assignment 1" <<
    std::endl;

    do {

        std::cout << std::endl <<
                "Enter starting value for prime list: ";
        std::cin >> x_lower;

        std::cout << std::endl <<
                "Enter ending value for prime list: ";
        std::cin >> x_upper;

        std::vector<int> num_list;
        num_list = range(x_lower,x_upper);
        
        
        std::vector<int> primes_list;

        for (auto num : num_list)
        {
            std::vector<int> check_list;
            check_lim = pow(num,0.5);
            
            std::vector<int> check_range;
            check_range = range(2,check_lim);

            for (auto i : check_range)
            {
                check_list.push_back(num % i == 0);
            }
            
            if(std::any_of(check_list.begin(),check_list.end(), [](bool k){return k == true;}))
            {continue;}
            else if(num != 1)
            {
                primes_list.push_back(num);
            }
        }

        endline_check = 0;
        for(auto prime : primes_list)
        {   
            if (endline_check == 5)
            {
                std::cout << std::endl;
                endline_check = 0;
            }
            else
            {
                std::cout << prime << " ";
                endline_check++;
            }
        }

        std::cout << std::endl << 
        "Would you like to generate another sequence of primes? (y/n)";
        std::cin >> yes_no_var;

    }
    while(yes_no_var == 'y');

    return 0;
}
