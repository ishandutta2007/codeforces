#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	string a,b;
	while (cin >> a >> b) {
		if (a.size()!=b.size()) puts("NO");
		else {
			int sz=a.size();
			string ans="YES";
			for (int x=0;sz>x;x++) {
				if (a[x]!=b[sz-x-1]) ans="NO";
			}
			cout<<ans<<endl;
		}
	}
}