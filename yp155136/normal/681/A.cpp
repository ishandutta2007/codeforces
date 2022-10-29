#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		string a[n];
		int b[n];
		int c[n];
		string ans="NO";
		for (int x=0;n>x;x++) {
			cin >> a[x]>>b[x]>>c[x];
			if (b[x]>=2400 && c[x]-b[x]>0) ans="YES";
		}
		cout<<ans<<endl;
	}
}