#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

const int MAX_N = 1e5 +6;

int main() {
	string s;
	while (cin >> s) {
		set<string> st;
		st.insert(s);
		int t=s.size();
		while (t--) {
			char tmp=s[s.size()-1];
			string ala=" ";
			ala[0]=tmp;
			s.resize(s.size()-1);
			s = ala + s;
			st.insert(s);
//			cout<<s<<endl;
		}
		printf("%d\n",st.size());
	}
}