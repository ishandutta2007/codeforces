#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool okay(int x) {
	string s="";
	while (x) {
		s.push_back(x%10);
		x/=10;
	}
	string t=s;
	reverse(t.begin(),t.end());
	return t==s;
}

int main () {
	int x;
	cin >> x;
	while (x%10==0) x/=10;
	if (okay(x)) puts("YES");
	else puts("NO");
}