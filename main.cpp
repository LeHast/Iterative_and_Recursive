
#include <iostream>
#include <string>
#include <vector>
#include "project2.hpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "usage:" << argv[0] << " nameOfInputFile\n";
        exit(2);
    }
    std::vector<int> numbers, result;

    read_numbers(std::string(argv[1]), numbers);

    std::cout << "______________________________________________" << std::endl;
    std::cout << "largest_left_iterative" << std::endl;
    largest_left_iterative(numbers, result);
    PrintResult(result);

    std::cout << "______________________________________________" << std::endl;
    std::cout << "largest_left_recursive" << std::endl;
    largest_left_recursive(numbers, result, numbers.size());
    PrintResult(result);
    
    
    std::cout << "______________________________________________" << std::endl;
    std::cout << "larger_left_right_iterative" << std::endl;
    larger_left_right_iterative(numbers, result);
    PrintResult(result);

    std::cout << "______________________________________________" << std::endl;
    std::cout << "larger_left_right_recursive" << std::endl;
    larger_left_right_recursive(numbers, result, numbers.size());
    PrintResult(result);

    
    std::cout << "Iterative Count: " << count_inversions_iterative(numbers) << std::endl;
    std::cout << "Recursive Count: " << count_inversions_recursive(numbers, numbers.size()) << std::endl;

    
    std::cout << "______________________________________________" << std::endl;
    std::cout << "Iterative longest Count: " << increasing_sequences_iterative(numbers) << std::endl;
    std::cout << "Recursive longest Count: " << increasing_sequences_recursive(numbers, 0) << std::endl;
    std::cout << "______________________________________________" << std::endl;

 

    return 0;
}