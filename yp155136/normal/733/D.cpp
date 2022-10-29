#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e5 + 6;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		LL mx=-1;
		pii mx_id=make_pair(-1,-1);
		map<pii,pii> mp;
		for (int i=1;n>=i;i++) {
			LL _[3];
			scanf("%I64d %I64d %I64d",&_[0],&_[1],&_[2]);
			sort(_,_+3);
			LL a=_[0],b=_[1],c=_[2];
			if (a > mx) {
				mx = a;
				mx_id = make_pair(i,0);
			}
			pii tmp=make_pair(a,b);
			if (mp.find(tmp) != mp.end()) {
				pii ret=mp[tmp];
				if (min(a,ret.first+c) > mx) {
					mx = min(a,ret.first+c);
					mx_id=make_pair(i,ret.second);
				}
			}
			tmp = make_pair(b,c);
			if (mp.find(tmp) != mp.end()) {
				pii ret=mp[tmp];
				if (min(b,ret.first+a) > mx) {
					mx = min(b,ret.first+a);
					mx_id=make_pair(i,ret.second);
				}
			}
			tmp = make_pair(a,c);
			if (mp.find(tmp) != mp.end()) {
				pii ret=mp[tmp];
				if (min(a,ret.first+b) > mx) {
					mx = min(a,ret.first+b);
					mx_id=make_pair(i,ret.second);
				}
			}
			tmp=make_pair(a,b);
			if (mp.find(tmp) != mp.end()) {
				pii ret=mp[tmp];
				pii can=make_pair(c,i);
				if (can > ret) mp[tmp] = can;
			}
			else {
				pii can=make_pair(c,i);
				mp[tmp] = can;
			}
			tmp = make_pair(b,c);
			if (mp.find(tmp) != mp.end()) {
				pii ret=mp[tmp];
				pii can=make_pair(a,i);
				if (can > ret) mp[tmp] = can;
			}
			else {
				pii can=make_pair(a,i);
				mp[tmp] = can;
			}
			tmp = make_pair(a,c);
			if (mp.find(tmp) != mp.end()) {
				pii ret=mp[tmp];
				pii can=make_pair(b,i);
				if (can > ret) mp[tmp] = can;
			}
			else {
				pii can=make_pair(b,i);
				mp[tmp] = can;
			}
		}
		if (mx_id.second == 0) {
			puts("1");
			printf("%I64d\n",mx_id.first);
		}
		else {
			puts("2");
			printf("%I64d %I64d\n",mx_id.first,mx_id.second);
		}
	}
}