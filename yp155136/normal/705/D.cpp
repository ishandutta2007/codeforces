#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

typedef long long LL;
const int MAX_N = 5002;
const LL INF = 1e15+9;

LL x[MAX_N];
LL a[MAX_N];
LL b[MAX_N];
LL c[MAX_N];
LL d[MAX_N];

/*
|xi-xj|+ci+bj seconds if j?<?i.
|xi-xj|+di+aj seconds otherwise (j?>?i).
*/
LL f(int i,int j) {
	if(j<i) return abs(x[i] - x[j]) + c[i] + b[j];
	else return abs(x[i] - x[j]) + d[i] + a[j];
}

int Next[MAX_N];

int main () {
	int n,s,e;
	while (scanf("%d %d %d",&n,&s,&e) != EOF) {
		for (int i=1;n>=i;i++) scanf("%d",&x[i]);
		for (int i=1;n>=i;i++) scanf("%d",&a[i]);
		for (int i=1;n>=i;i++) scanf("%d",&b[i]);
		for (int i=1;n>=i;i++) scanf("%d",&c[i]);
		for (int i=1;n>=i;i++) scanf("%d",&d[i]);
		Next[s] = e;
		LL sum=f(s,e);
		for (int i=1;n>=i;i++) {
			if (i!=s && i!=e) {
				int id=-1;
				LL mn=INF;
				for (int j=s;j!=e;j=Next[j]) {
					//add vertex i in the hamilton circuit
					LL tmp=f(j,i) + f(i,Next[j]) - f(j,Next[j]);
					if (tmp<mn) {
						mn=tmp;
						id=j;
					}
				}
				sum += mn;
				Next[i] = Next[id];
				Next[id] = i;
			}
		}
		printf("%I64d\n",sum);
	}
}