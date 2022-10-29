#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main () {
	int n,m;
	while (cin >> n >> m) {
		map<string,string> mp;
		map<string,int> ala;
		for (int i=0;m>i;i++) {
			string a,b;
			cin >>a >>b;
			mp[a] = b;
			mp[b] = a;
			ala[a] = 1;
			ala[b] = 2;
		}
		for (int i=0;n>i;i++) {
			if (i) cout<<' ';
			string s;
			cin >> s;
			string ret=mp[s];
			if (ret.size() > s.size()) cout<< s;
			else if (ret.size() < s.size()) cout<< ret;
			else if (ala[s] == 1) cout<<s;
			else cout<<ret;
		}
	}
}