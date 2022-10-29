#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	string n;
	int k;
	while (cin >> n >> k) {
		int ans=0;
		int _=0;
		if (n=="0") {
			puts("0");
			continue;
		}
		else if (n.size() <= k) {
			printf("%d\n",n.size()-1);
		}
		else {
			string s=n;
			int _=0;
			int ans=0;
			int i;
			for (i=n.size()-1;i>=0;i--) {
				if (s[i]=='0') ans++;
				else _++;
				if (ans==k) break;
			}
			if (ans != k) printf("%d\n",n.size()-1);
			else {
				int __=-1;
				for (;i>=0;i--) {
					if (s[i] != '0') __=1;
				}
				if (__ == 1) printf("%d\n",_);
				else printf("%d\n",n.size()-1);
			}
		}
	}
}