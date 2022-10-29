#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 106;

int a[MAX_N];

int calc(int L,int R) {
	if (L>=R) return 0;
	int ret=0;
	for (int i=L;R>=i;i+=2) {
		ret += (a[i+1] - a[i]);
	}
	return ret;
}

int main () {
	int n;
	cin >> n;
	int nn=n*2;
	for(int i=1;nn>=i;i++) {
		int x;
		cin >> x;
		a[i] = x;
	}
	sort(a+1,a+nn+1);
	int ans = calc(1,nn);
	for (int i=1;nn>=i;i+=2) {
		for (int j=i+1;nn>=j;j+=2) {
			ans = min(ans,calc(1,i-1) + calc(i+1,j-1) + calc(j+1,nn));
		}
	}
	printf("%d\n",ans);
}