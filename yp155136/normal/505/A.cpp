#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5 +6;

bool check(string s) {
	bool ret=true;
	int sz=s.size();
	int i=sz-1;
	for (int x=0;sz>x;x++,i--) {
		if (s[x] != s[i]) return false;
	}
	return true;
}

int main () {
	string s;
	while (cin >> s) {
		int sz=s.size();
		bool ans_get=false;
		string tmp=" " + s;
		for (int i=0;sz>=i;i++) {
			//insert at pos i
			if (i) swap(tmp[i],tmp[i-1]);
			for (int j='a';'z'>=j;j++) {
				tmp[i]=j;
//				cout<<"tmp = "<<tmp<<endl;
				if (check(tmp) && !ans_get) {
					cout<<tmp<<endl;
					ans_get=true;
				}
			}
		}
		if (!ans_get) cout<<"NA"<<endl;
	}
}