#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 5e5 + 6;

string s[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			cin >> s[i];
		}
		for (int i=n-1;i>=1;i--) {
			int _=1,__=1;
			int sz_ = s[i].size(),sz__=s[i+1].size();
			while (1) {
				if (_==sz_ && sz__==__) break;
				else if (_ == sz_) break;
				else if (__ == sz__) {
					s[i].resize(__);
					break;
				}
				else if (s[i][_] < s[i+1][__]) break;
				else if (s[i][_] > s[i+1][__]) {
					s[i].resize(__);
					break;
				}
				else {
					_++;
					__++;
				}
			}
		}
		for (int i=1;n>=i;i++) {
			cout <<s[i]<<endl;
		}
	}
}