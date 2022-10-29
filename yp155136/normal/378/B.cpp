#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;

int a[MAX_N],b[MAX_N];
int can[2][MAX_N];
pii _[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int __=0;
		for (int i=1;n>=i;i++) {
			scanf("%d %d",&a[i],&b[i]);
			_[__++] = make_pair(a[i],i);
			_[__++] = make_pair(b[i],i+n);
		}
		sort(_,_+__);
		memset(can,0,sizeof(can));
		for (int i=0;n>i;i++) {
			int val=_[i].second;
			if (val > n) can[1][val - n] = 1;
			else can[0][val] = 1;
		}
		for (int i=0;2>i;i++) {
			for (int j=1;n>=j;j++) {
				if (j <= n/2) cout<<1;
				else cout<<can[i][j];
			}
			cout<<endl;
		}
	}
}