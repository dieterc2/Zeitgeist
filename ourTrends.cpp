#include "ourTrends.h"

void ourTrends::increaseCount(std::string s, unsigned int amount){
	// check to see if key is already in
	if(wordStoreTable->find(s) == wordStoreTable->end()){
		// add the element into the hash table
		std::pair<std::string, int> word (s, amount);
		wordStoreTable->insert(word);
	} else{
		// just update the count
		wordStoreTable->find(s)->second++;
	}
}

unsigned int ourTrends::getCount(std::string s){
	unsigned int x = wordStoreTable->find(s)->second;
	return x;
}

std::string ourTrends::getNthPopular(unsigned int n){
	std::string x = NULL;
	return x;
}

unsigned int ourTrends::numEntries() {
	return wordStoreTable->size();
}
