#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main () {
	int n;
	cin >> n;
	string s[n];
	set<string> st;
	for (int i=0;n>i;i++) {
		string ss;
		cin >> ss;
		#define SZ(x) ((int)(x).size())
		while (1) {
			string tmp="";
			for (int i=0;SZ(ss)>i;i++) {
				if (ss[i] == 'u') {
					tmp.push_back('o');
					tmp.push_back('o');
				}
				else if (i==SZ(ss)-1) tmp.push_back(ss[i]);
				else if (ss[i]=='k' && ss[i+1]=='h') {
					tmp.push_back('h');
					i++;
				} 
				else {
					tmp.push_back(ss[i]);
				}
			}
//			cout<<"tmp = "<<tmp<<endl;
			if (tmp == ss) break;
			else ss=tmp;
		}
//		cout<<"ss = "<<ss<<endl;
		st.insert(ss);
	}
	cout<<SZ(st)<<endl;;;
}