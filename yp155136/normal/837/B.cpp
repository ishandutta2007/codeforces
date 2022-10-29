#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

string mp[123];

int main () {
	int n,m;
	cin >> n >> m;
	for (int i=1;n>=i;i++) {
		cin >> mp[i];
		mp[i] = " "+mp[i];
	}
	string ans="NO";
	if (n%3==0) {
		set<char> s[4];
		int id=1;
		for (int i=1;n>=i;i++) {
			if (i==n/3 + 1) id=2;
			if (i==2*(n/3) + 1) id=3;
			for (int j=1;m>=j;j++) {
				s[id].insert(mp[i][j]);
			}
		}
		if (s[1].size()==1 && s[2].size()==1&&s[3].size()==1) {
			s[0].insert(*s[1].begin());
			s[0].insert(*s[2].begin());
			s[0].insert(*s[3].begin());
			if (s[0].size() == 3) ans="YES";
		}
	}
	if (m%3==0) {
		set<char> s[4];
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				int id=0;
				if (j <= m/3) id=1;
				else if (j<= 2*(m/3)) id=2;
				else id=3;
				s[id].insert(mp[i][j]);
			}
		}
		if (s[1].size()==1 && s[2].size()==1&&s[3].size()==1) {
			s[0].insert(*s[1].begin());
			s[0].insert(*s[2].begin());
			s[0].insert(*s[3].begin());
			if (s[0].size() == 3) ans="YES";
		}
	}
	cout<<ans<<endl;
}