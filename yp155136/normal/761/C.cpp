#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int main () {
	int n,m;
	while (cin >>n >> m) {
		int _0[n],_1[n],_2[n];
		for (int x=0;n>x;x++) {
			_0[x]=_1[x]=_2[x]=123456789;
			string s;
			cin >> s;
			for (int y=0;m>y;y++) {
				if ('0'<=s[y]&&s[y]<='9') {
					_0[x] = min(min(y,m-y),_0[x] );
				}
				else if ('a'<=s[y]&&s[y]<='z') {
					_1[x] = min(min(y,m-y),_1[x] ) ;
				}
				else {
					_2[x] = min(min(y,m-y),_2[x] );
				}
			}
			//cout<<"x = "<<x<<" , _0 = "<<_0[x]<<" , _1 = "<<_1[x]<<" , _2 = "<<_2[x]<<endl;
		}
		int mn=123456789;
		for (int i=0;n>i;i++) {
			for (int j=0;n>j;j++) {
				for (int k=0;n>k;k++) {
					if (i==j||j==k||k==i) continue;
					if (_0[i]+_1[j]+_2[k]<mn) mn=_0[i]+_1[j]+_2[k];
				}
			}
		}
		cout<<mn<<endl;
	}
}