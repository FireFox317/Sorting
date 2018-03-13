#pragma once

#include <array>
#include <vector>

class BucketSort
{
private:
	std::array<std::vector<int>*, 10> listOfBuckets;
	std::vector<int> &arrayToBeSorted;
public:
	BucketSort(std::vector<int> &arrayToBeSorted);
	void sort();
	~BucketSort();
};

