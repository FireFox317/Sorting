#include "BucketSort.h"

#include <cmath>

BucketSort::BucketSort(std::vector<int>& list) : arrayToBeSorted(list)
{
	for (int i = 0; i < 10; i++) {
		listOfBuckets[i] = new std::vector<int>;
	}

	size_t numberOfElements = arrayToBeSorted.size();
	for (auto bucket : listOfBuckets) {
		bucket->reserve(numberOfElements);
	}
}

void BucketSort::sort()
{
	for (int exponent = 0; exponent < 4; exponent++) { // magic number!!
		int value = (int)std::pow(10, exponent);

		for (auto element : arrayToBeSorted) {
			int ones = (element / value) % 10;
			listOfBuckets[ones]->push_back(element);
		}

		int i = 0;
		for (auto bucket : listOfBuckets) {
			for (int j = 0; j < (int)bucket->size(); j++) {
				arrayToBeSorted[i] = bucket->at(j);
				i++;
			}
		}

		for (auto bucket : listOfBuckets) {
			bucket->erase(bucket->begin(), bucket->end());
		}
	}
}

BucketSort::~BucketSort()
{
	for (int i = 0; i < 10; i++) {
		delete listOfBuckets[i];
	}

}
