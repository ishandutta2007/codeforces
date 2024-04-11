#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
typedef long double ld;
const int MAX_N = 1e5 + 6;

LL aa[MAX_N];

LL a,b,c,d;

typedef pair<LL,LL> pii;

LL prime[MAX_N];

void build() {
	memset(prime,0,sizeof(prime));
	prime[0]=prime[1]=1;
	for (LL i=2;MAX_N>i;i++) {
		if (prime[i]==0) {
			for (LL j=i;MAX_N>j;j+=i) {
				prime[j]=i;
			}
		}
	}
}

vector<pii> f(LL x) {
	vector<pii> ret;
	ret.push_back(make_pair(x,1));
	return ret;
	while (x>1) {
		LL tmp=prime[x];
		LL cnt=0;
		while (x%tmp==0) {
			x/=tmp;
			cnt++;
		}
		ret.push_back(make_pair(tmp,cnt));
	}
	sort(ret.begin(),ret.end());
//	cout<<"x = "<<x<<endl;
	return ret;
}

vector<pii> g(vector<pii> a,vector<pii> b) {
	vector<pii> ret;
	int id1=0,id2=0;
	int sza=a.size(),szb=b.size();
	while (id1<sza || id2<szb) {
		if (id1==sza) {
			ret.push_back(b[id2++]);
		}
		else if (id2==szb) {
			ret.push_back(a[id1++]);
		}
		else if (a[id1].first == b[id2].first) {
			ret.push_back(make_pair(a[id1].first,a[id1].second + b[id2].second));
			id1++;
			id2++;
		}
		else if (a[id1].first > b[id2].first) {
			ret.push_back(b[id2++]);
		}
		else if (a[id1].first < b[id2].first) {
			ret.push_back(a[id1++]);
		}
	}
	return ret;
}

bool check(int id) {
	LL num=1;
	ld lg=0;
	vector<pii> v=f(aa[1]);
	for (int i=1;id>=i;i++) {
		if (log10(aa[i]) + lg >= 18.1) return true;
		else {
			num *= aa[i];
			lg += log10(aa[i]);
			if (i!=1) v = g(v,f(aa[i]));
		}
	}
	vector<pii> e=v;
	queue<pii> que;
	que.push(make_pair(1,-1));
	int sze=e.size();
	bool check_1=0;
	while (!que.empty()) {
		pii t=que.front();
		if (t.second == sze-1) break;
		que.pop();
		if (t.second+1>=sze) continue;
		LL id=t.second+1;
		LL _1=e[id].first;
		LL val=t.first;
		for (int i=0;e[id].second>=i;i++) {
			que.push(make_pair(val,id));
			val*=_1;
		}
	}
	while (!que.empty()) {
		pii t=que.front();
		que.pop();
		LL i=t.first;
		if (num%i==0) {
			LL cc,dd;
			if (log10(c) + log10(i) <= 18) cc=c*i;
			else cc=MAX_N;
			if (log10(d) + log10(num/i) <= 18)dd=d*(num/i);
			else dd=MAX_N;
			if (min(cc,dd) >= min(a,b) && max(cc,dd) >= max(a,b)) return true;
			if (log10(c) + log10(num/i) <= 18) cc=c*i;
			else cc=MAX_N;
			if (log10(d) + log10(i) <= 18)dd=d*(num/i);
			else dd=MAX_N;
			if (min(cc,dd) >= min(a,b) && max(cc,dd) >= max(a,b)) return true;
		}
	}
	return false;
}

int main () {
	build();
	int n;
	while (scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%lld",&aa[i]);
		}
		sort(aa+1,aa+n+1);
		reverse(aa+1,aa+n+1);
		if (min(c,d) >= min(a,b) && max(c,d) >= max(a,b)) {
			puts("0");
			continue;
		}
		int L=0,R=n+1;
		while (R-L!=1) {
			int mid=(L+R)>>1;
			if (check(mid)) R=mid;
			else L=mid;
		}
		if (R==n+1) puts("-1");
		else printf("%d\n",R);
	}
}