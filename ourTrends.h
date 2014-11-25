#include "Trends.h"

#include <unordered_map>
#include <vector>

class ourTrends : public Trends {
public:
	ourTrends() {isSorted = true;}
	virtual void increaseCount(std::string s, unsigned int amount);
	virtual unsigned int getCount(std::string s);
	virtual std::string getNthPopular(unsigned int n);
	virtual unsigned int numEntries();

protected:
	std::unordered_map<std::string, std::vector<std::pair<std::string, int>>::iterator> wordStoreTable;
	std::vector<std::pair<std::string, int>> sortedVector;
	bool isSorted;
};