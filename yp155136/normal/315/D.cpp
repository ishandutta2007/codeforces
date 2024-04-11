#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_M = 106;

int pos[MAX_M];
int add[MAX_M];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int b,d;
	while (cin >> b >> d) {
		string a,c;
		cin >> a >>c;
		for (int i=0;c.size()>i;i++) {
			pos[i]=0;
			add[i]=0;
			//start 
			int p=0;
			int q=i;
			while (p<a.size()) {
				if (a[p] == c[q]) {
					q++;
					if (q==c.size()) {
						add[i]++;
						q=0;
					}
				}
				p++;
			}
			pos[i] = q;
		}
		long long cnt=0;
		int q=0;
		for (int i=0;b>i;i++) {
			cnt += add[q];
			q = pos[q];
		}
		cout<<cnt/d<<endl;
	}
}