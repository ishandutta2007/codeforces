#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <set>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
const int MAX_N = 1e5 + 6;
const int INF = 1e9+7;

int a[MAX_N];
int b[MAX_N];
int c[MAX_N];

int main () {
	int n,l,r;
	while (scanf("%d %d %d",&n,&l,&r) != EOF) {
		set<pii> st;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&c[i]);
			st.insert(make_pair(c[i],i));
		}
		int mn=-INF;
		for (auto iter=st.begin();iter!=st.end();iter++) {
			pii tmp=*iter;
			int g=tmp.first;
			int h=tmp.second;
			int _a=-a[h];
			int _b=max(mn+a[h],l);
			if (_b>r) {
				puts("-1");
				return 0;
			}
			b[h] = _b;
			mn = _b+_a+1;
		}
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			printf("%d",b[i]);
		}
		puts("");
	}
}