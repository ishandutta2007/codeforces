#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 2e5 + 6;
const int MAX_K = 2e5 + 6;
const LL INF = 1e17+6;

pii a[MAX_N];
LL g[MAX_N];

bool check(LL id,int n,LL t) {
	int s=0;
	LL cnt=0;
	for (int x=1;n>=x;x++) {
		int delta=g[x]-s;
//		cout<<"x = "<<x<<" id = "<<id<<" , delata =  "<<delta<<" , cnt = "<<cnt<<endl;
		if (delta<=id/2) cnt += delta;
		else if (delta>id) return false;
		else {
			cnt += 2*(id - 2*(id-delta)) + (id-delta);
		}
		s=g[x];
	}
	return cnt<=t;
}

int main () {
	LL n,k,s,t;
	while (scanf("%I64d %I64d %I64d %I64d",&n,&k,&s,&t) != EOF) {
		LL mn=INF;
		LL mx=-INF;
		for (int x=1;n>=x;x++) {
			LL i,j;
			scanf("%I64d %I64d",&i,&j); //money, gas val
			a[x] = make_pair(i,j); 
			mn = min(mn,j);
			mx = max(mx,j);
		}
		sort(a+1,a+n+1);
		for (int x=1;k>=x;x++) {
			int i;
			scanf("%d",&i);
			g[x] = i;
			mx = max(mx,g[x]);
			mn = min(mn,g[x]);
		}
		sort(g+1,g+k+1);
		g[++k] = s;
		//find the lowest value
		LL L=mn-1,R=mx+1;  //R is okay, L is not okay
		while (R-L!=1) {
			LL mid=(L+R)>>1;
			if (check(mid,k,t)) R=mid;
			else L=mid;
		}
//		cout<<"R = "<<R<<endl;
		bool ans=false;
		for (int x=1;n>=x;x++) {
			if (a[x].second >= R) {
				ans=true;
				printf("%I64d\n",a[x].first);
				break;
			}
		}
		if (!ans) puts("-1");
	}
}