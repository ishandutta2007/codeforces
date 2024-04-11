#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int n,L;
	while (cin >> n >> L) {
		vector<int> a,b;
		for (int x=0;n>x;x++) {
			int i;
			cin >>i;
			a.push_back(i);
		}
		for (int x=0;n>x;x++) {
			int i;
			cin>>i;
			b.push_back(i);
		}
		for (int x=0;L+3>x;x++) {
			if (a==b) {
				puts("YES");
				return 0;
			}
			for (int y=0;n>y;y++) {
				a[y]++;
				if (a[y]>=L) a[y]-=L;
			}
			sort(a.begin(),a.end());
		}
		puts("NO");
	}
}