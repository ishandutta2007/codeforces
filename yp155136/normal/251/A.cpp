#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;
const LL INF = 1e15 + 6;

LL a[MAX_N];

int main () {
	int n,d;
	while (scanf("%d %d",&n,&d) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
		}
		a[0] = INF;
		LL ans=0;
		for (int i=3;n>=i;i++) {
			LL L=0,R=i;  //R is the answer
			while (R-L!=1) {
				LL mid=(L+R)>>1;
				if (a[i]-a[mid] <= d) R=mid;
				else L=mid;
			}
			LL dis=i-R;
			if (dis)ans += (dis-1)*(dis)/2;
		}
		printf("%I64d\n",ans);
	}
}