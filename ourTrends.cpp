#include "ourTrends.h"
#include <algorithm>
#include <iostream>

bool compareFunc(std::pair<std::string, unsigned int> i, std::pair<std::string, unsigned int> j);

void ourTrends::increaseCount(std::string s, unsigned int amount){
	// check to see if key is already in
	if(wordStoreTable.find(s) == wordStoreTable.end()){
		// add the element into the hash table
		std::vector<std::pair<std::string, int>>::iterator it;
		std::pair<std::string, std::vector<std::pair<std::string, int>>::iterator> word (s, it);
		wordStoreTable.insert(word);

		// add element to back of vector
		std::pair<std::string, int> p1 (s, amount);
		sortedVector.push_back(p1);
		std::swap(sortedVector.front(), sortedVector.back());
		// set the iterator of the hash pair to the end of the current vector size
		it = sortedVector.begin();
		wordStoreTable.find(s)->second = it;
		isSorted = false;
		
	} else{
		int x = wordStoreTable.find(s)->second->second;
		std::pair<std::string, int> p1 (s, x + amount);
		sortedVector.erase(wordStoreTable.find(s)->second);
		sortedVector.push_back(p1);
		
		std::vector<std::pair<std::string, int>>::iterator it = sortedVector.begin();

		wordStoreTable.find(s)->second = it;
		

	}
}

unsigned int ourTrends::getCount(std::string s){
	std::vector<std::pair<std::string, int>>::iterator it = wordStoreTable.find(s)->second;
	return it->second;
	
}

std::string ourTrends::getNthPopular(unsigned int n){
	if (!isSorted){
		std::sort(sortedVector.begin(), sortedVector.end(), compareFunc);
		isSorted = true;
	}

	if (n <= numEntries()){
		return sortedVector.at(n).first;
	}

	//If they give bad input, return empty string.
	return "";
}

unsigned int ourTrends::numEntries() {
	int x = sortedVector.size();
	return wordStoreTable.size();
}
