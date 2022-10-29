#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main () {
	map<string,int> mp;
	string ans;
	cin >>ans;
	int n;
	cin >> n;
	map<char,int> mp1,mp2;
	while (n--) {
		string x;
		cin >> x;
		mp[x]++;
		mp1[x[0]]++;
		mp2[x[1]]++;
	}
	if (mp[ans] || mp2[ans[0]] && mp1[ans[1]]) puts("YES");
	else puts("NO");
}