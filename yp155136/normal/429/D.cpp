#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e5 + 6;
const LL INF = 1e17+6;

pii p[MAX_N];
pii _[MAX_N];

LL get_dis(int x,int y) {
	return ((p[x].first-p[y].first)*(p[x].first-p[y].first) + (p[x].second-p[y].second)*(p[x].second-p[y].second));
}

LL solve(int L,int R) {
	if (L >= R) return INF;
	int mid=(L+R)>>1;
	LL d=min(solve(L,mid),solve(mid+1,R));
	int sz=0;
	for (int x=mid;x>=L && (p[mid].first - p[x].first)*(p[mid].first-p[x].first) <d;x-- ) {
		_[sz++] = p[x];
	}
	for (int x=mid+1;R>=x && (p[x].first - p[mid+1].first)*(p[x].first-p[mid+1].first)<d;x++) {
		_[sz++] = p[x];
	}
	sort(_,_+sz,[](const pii &p1,const pii &p2) {
		return p1.second < p2.second || p1.second ==p2.second && p1.first < p2.first;
	});
	for (int i=0;sz>i;i++) {
		for (int j=1;3>=j && i+j<sz;j++) {
			d = min(d,(_[i].first-_[i+j].first)*(_[i].first-_[i+j].first) + 
			          (_[i].second-_[i+j].second) * (_[i].second-_[i+j].second));
		}
	}
	return d;
}

int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		a[0]=0;
		for (int i=1;n>=i;i++) {
			int x;
			scanf("%d",&x);
			a[i] = a[i-1] + x;
			p[i] = make_pair(i,a[i]);
		}
		sort(p+1,p+n+1,[](const pii &p1,const pii &p2) {
			return p1.first<p2.first || p1.first == p2.first && p1.second<p2.second;
		});
		LL ret=solve(1,n);
//		cout<<"ret = "<<ret<<endl;
		printf("%I64d\n",(ret));
	}
}