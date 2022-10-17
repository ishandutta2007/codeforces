#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

string s;
map<char, int> gr;

void go(int v, char t) {
	for (int i = 0; i < s.size(); i++) {
		if (i % 4 == v % 4 && s[i] == '!') {
			gr[t]++;
			s[i] = t;
		}
	}
}

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '!')	go(i, s[i]);
	}
	cout << gr['R'] << " " << gr['B'] << " " << gr['Y'] << " " << gr['G'] << endl;
	return 0;
}