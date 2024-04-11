#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAX_N = 106;

int a[MAX_N];
int _[MAX_N];
int mx[MAX_N];
bool visit[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(_,0,sizeof(_));
		int cnt=0;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			if (!_[a[i]]) {
				cnt++;
			}
			_[a[i]]=1;
		}
		if (cnt != n) {
			puts("-1");
			continue;
		}
		vector<int> v;
		memset(visit,0,sizeof(visit));
		int gcd=-1;
		for (int i=1;n>=i;i++) {
			if (!visit[i]) {
				int sz=0;
				int tmp=i;
				while (!visit[tmp]) {
					visit[tmp]=1;
					tmp = a[tmp];
					sz++;
				}
				v.push_back(sz);
				if (gcd==-1) gcd=sz;
				else gcd = __gcd(sz,gcd);
			}
		}
		memset(mx,0,sizeof(mx));
		LL ans=1;
		for (auto i:v) {
			for (int j=2;MAX_N>j;j++) {
				int cnt=0;
				while (i%j==0) {
					cnt++;
					i/=j;
				}
				mx[j] = max(mx[j],cnt);
			}
		}
		LL _=1;
		for (int j=2;MAX_N>j;j++) {
			if (j==2 && mx[j]!=0) _=2;
			while (mx[j]--) ans*=j;
		}
		printf("%I64d\n",ans/_);
	}
}