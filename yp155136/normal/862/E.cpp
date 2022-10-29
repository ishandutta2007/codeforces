#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL INF = 1e17 + 6;
const int MAX_N = 1e5 + 6;

LL a[MAX_N],b[MAX_N],pre[MAX_N];

vector<LL> v;

void query(LL now) {
	auto iter=lower_bound(v.begin(),v.end(),now);
	auto iter2 = iter;
	--iter2;
	LL ans= min((*iter)-now,now-(*iter2));
	printf("%lld\n",ans);
}

int main () {
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	LL now=0;
	int val=1;
	for (int i=1;n>=i;i++) {
		scanf("%lld",&a[i]);
		now += a[i]*val;
		val *= (-1);
	}
	val = 1;
	for (int i=1;m>=i;i++) {
		scanf("%lld",&b[i]);
		pre[i] = pre[i-1] + b[i]*val;
		val *= (-1);
	}
	v.push_back(-INF);
	v.push_back(INF);
	val = 1;
	for (int i=n;m>=i;i++) {
		v.push_back(val*(pre[i] - pre[i-n]));
		val *= -1;
	}
//	for (int i:v)
	sort(v.begin(),v.end());
	query(now);
	for (int i=1;q>=i;i++) {
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		if ((r-l+1)&1) {
			if (l&1) now+= x;
			else now-=x;
		}
		query(now);
	}
}