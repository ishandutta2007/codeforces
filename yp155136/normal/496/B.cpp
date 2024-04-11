#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int n;
	while (cin >> n) {
		string s;
		cin >> s;
		vector<string> v;
		v.push_back(s);
		for (int i=0;10>=i;i++) {
			string tmp=s;
			for (int x=0;n>x;x++) {
				tmp[x] = (tmp[x]-'0'+i)%10 + '0';
			}
			v.push_back(tmp);
		}
		vector<string> __;
		for (string i:v) {
			string _=i;
			__.push_back(i);
			string ret=i;
			int tmp=n;
			while (tmp--) {
				char haha=ret[n-1];
				ret.resize(n-1);
				string y=" ";
				y[0]=haha;
				ret = y + ret;
				__.push_back(ret);
			}
		}
		sort(v.begin(),v.end());
		sort(__.begin(),__.end());
		cout<<__[0]<<endl;
	}
}