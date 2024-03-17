#include "SumRandArray.h"

SumRandArray::SumRandArray(int count)
{
	numCount = count;
	numArr = new unsigned long int[numCount];
	fillArray();
}

SumRandArray::SumRandArray(int count, int parts)
{
	numCount = count;
	numArr = new unsigned long int[numCount];
	parted.resize(parts);
	fillArray();
	splitArray(parts);
	multiSum(parts);
}

SumRandArray::~SumRandArray()
{
	delete[] numArr;
}

void SumRandArray::printArray()
{
	for (unsigned int i = 0; i < numCount; i++)
	{
		cout << "Элемент " << i+1 << ": " << numArr[i] << "; ";
	}
}

void SumRandArray::multiSum(unsigned int parts)
{
	splitArray(parts);
	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long int result = 0;
	std::vector<std::thread> threads;
	for (unsigned int i = 0; i < parts; i++)
	{
		threads.push_back(threadMaker(i, result));
	}
	for (unsigned int i = 0; i < parts; i++)
	{
		threads[i].join();
	}

	auto finish = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = finish - start;
	printf("%-*llu | %*f секунд\n", 20, result, 7, elapsed.count());
}

void SumRandArray::fillArray()
{
	srand(static_cast<unsigned int>(time(0)));
	for (unsigned long int i = 0; i < numCount; i++)
	{
		numArr[i] = rand();
	}
}

void SumRandArray::splitArray(unsigned int parts)
{
	parted.clear();
	parted.resize(parts);
	unsigned int x = numCount / parts;
	unsigned int j = 0;

	for (unsigned int i = 1; i <= parts; i++)
	{
		for (; j < x * i && j < numCount; j++)
		{
			parted[i - 1].push_back(numArr[j]);
		}
	}

	if (numCount % parts != 0 && j < numCount)
	{
		parted[parts - 1].push_back(numArr[j]);
	}
}

std::thread SumRandArray::threadMaker(unsigned int id, unsigned long long int &result)
{
	return std::thread(&SumRandArray::sumClass, this, id, std::ref(result));
}

void SumRandArray::sumClass(unsigned int id, unsigned long long int &result)
{
	unsigned long long int sum = 0;
	for (int i = 0; i < parted[id].size(); i++)
	{
		sum += parted[id][i];
	}
	result += sum;
}