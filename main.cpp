#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

typedef map<string, int> Dict;

struct Pair {
	string word;
	int n;
};

bool mySort(Pair a, Pair b) { return (a.n > b.n); }

int main(int argc, char** argv) {
	int nWordsPrint = atoi(argv[1]);

	string word;
	ifstream file(argv[2]);
	Dict dict;

	while (file >> word)
		dict[word]++;

	vector<Pair> sortableDict;

	for (auto&& it : dict)
		sortableDict.push_back({ it.first, it.second });
	
	sort(sortableDict.begin(), sortableDict.end(), mySort);

	for (auto it = sortableDict.begin(); it < sortableDict.begin() + nWordsPrint; ++it)
		cout << it->word << " " << it->n << endl;

	return 0;
}