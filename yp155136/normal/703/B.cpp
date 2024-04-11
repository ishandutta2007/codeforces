#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5+6;
long long a[MAX_N];
long long b[MAX_N];
bool cap[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int x=0;n>=x;x++) cap[x]=false;
		long long sum=0;
		long long num=0;
		for (int x=1;n>=x;x++) {
			scanf("%I64d",&a[x]);
			num+=a[x];
		}
		long long v1=0,v2=0;
		for (int x=0;k>x;x++) {
			scanf("%I64d",&b[x]);
			cap[b[x]]=true;
			sum += a[b[x]] * (num-a[b[x]]);
			v1+=a[b[x]],v2+=a[b[x]]*a[b[x]];
		}
		sum -= (v1*v1-v2)/2;
//		cout<<sum<<"ttt\n";
		for (int x=1;n>=x;x++) {
			if (x==n) {
				if (!cap[n] && !cap[1]) sum+=a[n]*a[1];
			}
			else if (!cap[x] && !cap[x+1]) sum+= a[x]*a[x+1];
		}
		printf("%I64d\n",sum);
	}
}