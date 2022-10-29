#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main () {
	int T;
	cin >> T;
	map<string,int> mp;
	while (T--) {
		string s;
		cin >> s;
		if (mp[s]) puts("YES");
		else puts("NO");
		mp[s]=1;
	}
}