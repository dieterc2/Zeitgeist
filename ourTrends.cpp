#include "ourTrends.h"
#include <algorithm>
#include <iostream>

bool compareFunc(std::pair<std::string, unsigned int> i, std::pair<std::string, unsigned int> j);

void ourTrends::increaseCount(std::string s, unsigned int amount){
	// check to see if key is already in
	if(wordStoreTable.find(s) == wordStoreTable.end()){
		// add the element into the hash table
		
		std::pair<std::string, int> word (s, count);
		wordStoreTable.insert(word);

		// add element to back of vector
		std::pair<std::string, int> p1 (s, amount);
		sortedArray[count] = p1;

		// set the iterator of the hash pair to the end of the current vector size
		isSorted = false;
		count++;
		
	} else{
		int y = wordStoreTable.find(s)->second;
		sortedArray[y].second++;
	}
}

unsigned int ourTrends::getCount(std::string s){
	return 0;
	
}

std::string ourTrends::getNthPopular(unsigned int n){
	/*if (!isSorted){
		std::sort(sortedVector.begin(), sortedVector.end(), compareFunc);
		isSorted = true;
	}

	if (n <= numEntries()){
		return sortedVector.at(n).first;
	}

	//If they give bad input, return empty string.
	return "";*/
	return "end";
}

unsigned int ourTrends::numEntries() {
	return wordStoreTable.size();
}