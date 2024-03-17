#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <chrono>

using std::cout;
using std::endl;

class SumRandArray
{
public:
	SumRandArray(int count);
	SumRandArray(int count, int parts);
	~SumRandArray();
	void printArray();
	void multiSum(unsigned int parts);
private:
	unsigned long int* numArr;
	unsigned int numCount;
	std::vector<std::vector<unsigned long int>> parted;
	void fillArray();
	void splitArray(unsigned int parts);
	std::thread threadMaker(unsigned int id, unsigned long long int &result);
	void sumClass(unsigned int id, unsigned long long int &result);
};