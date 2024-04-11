#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int n,m;
	while (cin >> n >> m) {
		string s[n+1];
		for (int i=0;n>=i;i++) {
			s[i].resize(m+1);
		}
		for (int i=1;n>=i;i++) {
			cin >> s[i];
			s[i] = " "+s[i];
		}
		int ans=0;
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				vector<int> v;
				v.push_back(s[i][j]);
				v.push_back(s[i-1][j]);
				v.push_back(s[i][j-1]);
				v.push_back(s[i-1][j-1]);
				sort(v.begin(),v.end());
				if (v[0]=='a' && v[1]=='c' && v[2]=='e' && v[3]=='f') ans++;
			}
		}
		cout<<ans<<endl;
	}
}