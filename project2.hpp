#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

int count_inversions_iterative(const std::vector<int>& numbers);
int count_inversions_recursive(const std::vector<int>& numbers, int n);
void largest_left_iterative(const std::vector<int>& numbers, std::vector<int>& result);
void largest_left_recursive(const std::vector<int>& numbers, std::vector<int>& result, int n);
void larger_left_right_iterative(const std::vector<int>& numbers, std::vector<int>& result);
void larger_left_right_recursive(const std::vector<int>& numbers, std::vector<int>& result, int n);
int increasing_sequences_iterative(std::vector<int>& numbers);
int increasing_sequences_recursive(std::vector<int>& numbers, int startIdx);

void read_numbers(std::string fileName, std::vector<int>& v);

int helperlargest_left_recursive(const std::vector<int>& result, int n, int index);
int helper_increasing_sequences_recursive(std::vector<int>& numbers, int startIdx, int count, int larger);
int leftRightHelperMax(const std::vector<int>& inNumbers, int index, bool bLeft);
int leftRightHelperMaxRec(const std::vector<int>& inNumbers, int index, bool bLeft, int saveIndex);
int largest_left_Helper(const std::vector<int>& inNumbers, int current);

void PrintResult(std::vector<int>& v);

// exit 3 - no file 