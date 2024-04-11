#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 70006;

LL a[MAX_N];
LL _[MAX_N];

int main () {
	int n;
	scanf("%d",&n);
	map<pii,int> mp;
	for (int i=1;n>=i;i++) {
		LL x;
		scanf("%lld",&x);
		_[i] = x;
		int nn=9;
		for (int j=1;nn>=j;j++) {
			a[j] = x%10;
			x/=10;
		}
		vector<pii> v;
		v.clear();
		for (int j=1;nn>=j;j++) {
			LL now=0;
			LL ppow=1;
			for (int k=j;nn>=k;k++) {
				now += a[k]*ppow;
				ppow *= 10; 
				v.push_back(make_pair(now,k-j+1));
			}
		}
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end())-v.begin());
		for(pii p:v) {
			if (mp.find(p) == mp.end()) mp[p] = 1;
			else {
				int now=mp[p];
				mp.erase(mp.find(p));
				mp[p] = now+1;
			}
		}
	}
//	for (auto p:mp) {
//		cout<<"( ("<<p.first.first<<","<<p.first.second<<") , "<<p.second<<") "<<endl;
//	}
	for (int i=1;n>=i;i++) {
		int nn=9;
		LL x=_[i];
		for (int j=1;nn>=j;j++) {
			a[j] = x%10;
			x/=10;
		}
		int len_min=11,mn=-1;
		for (int j=1;nn>=j;j++) {
			LL now=0;
			LL ppow=1;
			for (int k=j;nn>=k;k++) {
				now += a[k]*ppow;
				ppow *= 10; 
				pii p=make_pair(now,k-j+1);
				if (mp[p] == 1LL) {
					if (k-j+1 < len_min) {
						len_min = k-j+1;
						mn = now;
					}
				}
			}
		}
		//cout<<"len_min = "<<len_min<<" , mn = "<<mn<<endl;
		x=mn;
		for (int j=1;nn>=j;j++) {
			a[j] = x%10;
			x/=10;
		}
		for (int j=len_min;j>=1;j--) {
			printf("%lld",a[j]);
		}
		puts("");
	}
}