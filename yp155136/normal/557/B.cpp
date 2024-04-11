#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 6;
const int INF = 1e9 + 7;

int a[MAX_N];

int main () {
	int n,w;
	while (scanf("%d %d",&n,&w) != EOF) {
		int mn=INF;
		for (int i=1;2*n>=i;i++) {
			scanf("%d",&a[i]);
			mn = min(mn,a[i]);
		}
		sort(a+1,a+2*n+1);
		double L=0.0,R=min(double(mn),(w/double(3*n)) );
		int cnt=200;
		while (cnt--) {
			double mid=(L+R)/2.0;
			bool flag=0;
			for (int i=1;n>=i;i++) {
				if (mid*2 > a[i+n]) {
					flag=1;
					break;
				}
			}
			if (!flag) L=mid;
			else R=mid;
		}
		printf("%.10f\n",L*(3*n));
	}
}