#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void parseParams(string query, char delim, unordered_map<string, string> &params) {
	int curStart = 0;
	do {
		int delimIndex = query.find(delim, curStart);
		int equalIndex = query.find('=', curStart);
		string newParam = query.substr(curStart, equalIndex - curStart);
		string newValue = query.substr(equalIndex + 1, delimIndex - equalIndex - 1);
		
		params[newParam] = newValue;
		curStart = delimIndex + 1;
	} while (curStart != 0);
}

int main() {
	unordered_map<string, string> params;
	parseParams("hey=supp&money=100&wigley=stupor", '&', params);
	
	for (auto const &cur: params)
		cout << cur.first << " " << cur.second << endl;
		
	return 0;
}
