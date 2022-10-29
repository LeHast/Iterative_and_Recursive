/// Daniel Galarza

#pragma once
#include "project2.hpp"

/*
*	It accepts a verctor. If the first element is larger than the next
*	element, it adds plus 1 to the count. 
*	@return the total of invesion in the vector.
*/
int count_inversions_iterative(const std::vector<int>& numbers){
	int count = 0;

	for (int index = 0; index < numbers.size() - 1; index++) {
		if (numbers[index] > numbers[index + 1]) {
			count++;
		}
	}
	return count;
}

/*	
*	It accepts a verctor and an integer for the size of the vector.
*	This function is recursive.
*	If the first element is larger than the next
*	element, it adds plus 1 to the count.
*	@return the total of invesion in the vector.
*/
int count_inversions_recursive(const std::vector<int>& numbers, int n){
	int count = 0;

	if (n != 0) {
		count = count_inversions_recursive(numbers, n - 1);
	}
	if (n >= numbers.size() - 1)
		return count;
	
	if (numbers[n] > numbers[n + 1]) {
		return count + 1;
	}

	return count;
}

/*
*	It accepts two vecotrs of values, the first vector "numbers" has all the numbers
*	and the second vector "result" will contain the results.
*	It finds the closest value, if the next value is larger push 0 to result.
*	then push the largest element to result.
*/
void largest_left_iterative(const std::vector<int>& numbers, std::vector<int>& result){
	result.push_back(0);

	for (int index = 1; index < numbers.size() ; index++) {
		if (numbers[index - 1] > numbers[index]) {
			result.push_back(numbers[index - 1]);
		}
		else if (numbers[index - 1] < largest_left_Helper(numbers, index)) {
			result.push_back(largest_left_Helper(numbers, index));
		}
		else {
			result.push_back(0);
		}

	}

}
/*
*	It accepts a vecotrs of values and an integer, the first vector "numbers" has all the numbers
*	and the int for the index
*	@return the closest largarst number from index.
*/
int largest_left_Helper(const std::vector<int>& inNumbers, int inIndex){
	for (int index = inIndex - 1; index >= 0; index--) {
		if (inNumbers[index] > inNumbers[inIndex]) {
			return inNumbers[index];
		}
	}
	return 0;
}


/*
*	It accepts two vecotrs of values, the first vector "numbers" has all the numbers
*	and the second vector "result" will contain the results.
*	This function is recursive.
*	It finds the closest value, if the next value is larger push 0 to result.
*	then push the largest element to result.
*/
void largest_left_recursive(const std::vector<int>& numbers, std::vector<int>& result, int n){
	if (n == 0) {
		result.push_back(0);
		return;
	}

	largest_left_recursive(numbers, result, n - 1);
	// Base case.
	if (n == numbers.size()) {
		return;
	}
	if (numbers[n -1] > numbers[n]) {
		result.push_back(numbers[n - 1]);
	}
	else if (numbers[n] < helperlargest_left_recursive(numbers, n, n)) {
		result.push_back(helperlargest_left_recursive(numbers, n, n));
	}
	else {
		result.push_back(0);
	}
}

/*
*	It accepts a vertor of values and a number for the size of the vector.
*	This is a recursive function.
*	This is a helper function for largest_left_recursive().
*	@return the largest number from the vector.
*/
int helperlargest_left_recursive(const std::vector<int>& numbers, int n, int index) {

	if (n < 0) {
		return 0;
	}

	if (numbers[n] > numbers[index]) {
		return numbers[n];
	}
	else {
		return helperlargest_left_recursive(numbers, n - 1, index);
	}
}

/*
*	It accepts two vecotrs of values, the first vector "numbers" has all the numbers
*	and the second vector "result" will contain the result.
*	It check the closest largest number from left and right, and replace it.
*	If there is not lasrgest number, push 0 to result.
*/
void larger_left_right_iterative(const std::vector<int>& numbers, std::vector<int>& result){
	for (int index = 0; index < numbers.size(); index++) {
		result.push_back(std::max(leftRightHelperMax(numbers, index, true), leftRightHelperMax(numbers, index, false)));
	}
	
}

/*
*	It accepts a vector of values, an integer for the index and bool to get left or rigth.
*	This is a helper function for increasing_sequences_iterative().
*	@returns the largest number from the left or rigth.
*/
int leftRightHelperMax(const std::vector<int>& inNumbers, int index, bool bLeft){
	int count = index;
	// Left.
	if (bLeft) {
		while (count >= 0) {
			if (inNumbers[index] < inNumbers[count]) {
				return inNumbers[count];
			}
			count--;
		}
	}
	// Right.
	else {
		while (count < inNumbers.size()) {
			if (inNumbers[index] < inNumbers[count]) {
				return inNumbers[count];
			}
			count++;
		}
	}
	return 0;
}


/*
*	It accepts two vecotrs of values, the first vector "numbers" has all the numbers
*	and the second vector "result" will contain the result.
*	This function is recursive.
*	It check the closest largest number from left and right, and replace it.
*	If there is not lasrgest number, push 0 to result.
*/
void larger_left_right_recursive(const std::vector<int>& numbers, std::vector<int>& result, int n){
	if (n != 0)
		larger_left_right_recursive(numbers, result, n - 1);
	if (n < numbers.size())
		result.push_back(std::max(leftRightHelperMaxRec(numbers, n, true, numbers[n]), leftRightHelperMaxRec(numbers, n, false, numbers[n])));

}



/*
*	It accepts a vector of values.
*	@return the largest consecutive secuence.
*/
int increasing_sequences_iterative(std::vector<int>& numbers){
	int count = 1;
	int large = 1;

	for (int index = 0; index < numbers.size() - 1; index++) {

		if (numbers[index] <= numbers[index + 1]) {
			count++;
		}
		else {
			count = 1;
		}	
		if (count > large)
			large = count;
	}
	return large;
}

/*
*	It accepts a vector of values.
*	This function is recursive.
*	@return the largest consecutive secuence.
*/
int increasing_sequences_recursive(std::vector<int>& numbers, int startIdx) {
	int count = 1, larger = 1;	
	return helper_increasing_sequences_recursive(numbers, startIdx, count, larger);
}

/*
*	It accepts a vector of values, 3 intiger; 'startIdx' for the start of the index,
*	'count' for the current increasing sequence and 'larger' for the largest count.
*	This function is recursive.
*	@return the largest conseutive count
*/
int helper_increasing_sequences_recursive(std::vector<int>& numbers, int startIdx, int count, int larger)
{
	//Base case
	if (numbers.size() - 1 == startIdx) {
		return larger;
	}

	if (numbers[startIdx] <= numbers[startIdx + 1]) {
		count += 1;
	}
	else {
		if (count > larger) {
			larger = count;
		}
		count = 1;
	}

	return helper_increasing_sequences_recursive(numbers, startIdx + 1, count, larger);
}

/*
* 	It accepts a vector of values, an integer for the index and bool to get left or rigth.
*	This is a helper function for increasing_sequences_recursive().
*	@returns the largest number from the left or rigth.
*
*/
int leftRightHelperMaxRec(const std::vector<int>& inNumbers, int index, bool bLeft, int saveIndex) {
	int larger;
	// For left.
	if (bLeft) {
		if (index == 0) {
			return 0;
		}

		if (saveIndex < inNumbers[index - 1]) {
			return inNumbers[index - 1];
		}

		larger = leftRightHelperMaxRec(inNumbers, index - 1, bLeft, saveIndex);

		return larger;
	}
	// For right.
	else {
		if (index >= inNumbers.size() - 1) {
			return 0;
		}
		if (saveIndex < inNumbers[index + 1]) {
			return inNumbers[index + 1];
		}

		larger = leftRightHelperMaxRec(inNumbers, index + 1, bLeft, saveIndex);

		return larger;
	}
}

/*
*	It accepts a string for the file name and a vector of values to storage 
*	from the file.
*/
void read_numbers(std::string fileName, std::vector<int>& v){
	int inNumber;
	std::ifstream file;

	file.open(fileName);
	
	if (!file.is_open()) {
		std::cout << "No File "<< std::endl;
		exit(3);
	}

	while (file >> inNumber) {
		v.push_back(inNumber);
	}
	//std::cout << v.size() << std::endl;

	file.close();
}

/*
*	Print Result from a vector then clear the vector.
*/
void PrintResult(std::vector<int>& result) {
	for (int x : result) {
		std::cout << x << ", ";
	}
	std::cout << std::endl;
	std::cout << "Results: " << result.size() << std::endl;
	std::cout << "______________________________________________" << std::endl;

	result.clear();

}