#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX_N = 1e2 + 6;

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int cnt=0,ans=0;
		int t=10;
		for (int i=1;n>=i;i++) {
			if (t+a[i]>720) break;
			else if (t+a[i]<=360) cnt++;
			else {
				cnt++;
				ans += t+a[i]-360;
			}
			t += a[i];
		}
		printf("%d %d\n",cnt,ans);
	}
}