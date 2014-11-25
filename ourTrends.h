#include "Trends.h"

#include <unordered_map>
#include <array>

class ourTrends : public Trends {
public:
	ourTrends() {isSorted = true; count = 0;}
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();

protected:
	std::unordered_map<std::string, int> wordStoreTable;
	std::array<std::pair<std::string, int>, 50> sortedArray;
	bool isSorted;
	int count;
};