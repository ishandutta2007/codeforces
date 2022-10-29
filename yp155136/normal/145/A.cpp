#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	string a,b;
	while (cin >> a >> b) {
		int _4=0,_44=0;
		int __=0;
		for(int i=0;a.size()>i;i++) {
			if (a[i]=='4') _4++;
			if (b[i]=='4') _44++;
			if (a[i]!=b[i]) __++;
		}
		int ans = abs(_4-_44);
		__ -= abs(_4-_44);
		printf("%d\n",ans+(__+1)/2);
	}
}