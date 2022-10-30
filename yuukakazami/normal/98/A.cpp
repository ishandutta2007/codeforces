/*
 * a.cpp
 *
 *  Created on: 2011-7-22
 *      Author: mac
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
#include <set>
#include <vector>
using namespace std;

struct Dice {
	//top, front, left, right, back, bottom
	string is;
	Dice(string _is) {
		is = _is;
	}
	void rollX() {
		roll(0, 1, 5, 4);
	}
	void rollY() {
		roll(0, 3, 5, 2);
	}
	void rollZ() {
		roll(1, 3, 4, 2);
	}
	void roll(int a, int b, int c, int d) {
		int t = is[d];
		is[d] = is[c];
		is[c] = is[b];
		is[b] = is[a];
		is[a] = t;
	}
	vector<string> rollAll() {
		vector<string> dices(24);
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				dices[i * 4 + j] = is;
				rollZ();
			}
			if ((i & 1) > 0)
				rollX();
			else
				rollY();
		}
		return dices;
	}
};

int main() {
	string s;
	cin >> s;
	set<string> Set;
	sort(s.begin(), s.end());
	do {
		vector<string> tmp = Dice(s).rollAll();
		string rep = *min_element(tmp.begin(), tmp.end());
		Set.insert(rep);
	} while (next_permutation(s.begin(), s.end()));
	cout << Set.size() << endl;
	return 0;
}