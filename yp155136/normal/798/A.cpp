#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5 +6;

bool okay(string s) {
	bool okay =true;
	int j=s.size()-1;
	for (int i=0;s.size()>i;i++) {
		okay &= (s[i]==s[j]);
		j--;
	}
	return okay;
}

int main () {
	string s;
	while (cin >> s) {
		bool okayy=false;
		for (int i=0;s.size()>i;i++) {
			string tmp;
			tmp=s;
			for (int j='a';'z'>=j;j++) {
				if (j==s[i]) continue;
				tmp[i] = j;
				okayy |= okay(tmp);
			}
		}
		if (okayy) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}