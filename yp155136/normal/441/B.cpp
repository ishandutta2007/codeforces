#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N =3006;

pii a[MAX_N];
int ala[MAX_N];

int main () {
	int n,v;
	while (cin >> n >> v) {
		memset(ala,0,sizeof(ala));
		for (int i=0;n>i;i++) {
			int x,y;
			cin >> x >> y;
			a[i] = make_pair(x,y);
			ala[x] += y;
		}
		sort(a,a+n);
		int ans=0;
		int _=v;
		for (int i=1;MAX_N-2>i;i++) {
			v=_;
			ans += min(v,ala[i-1]);
			v-=ala[i-1];
			if (v>0) {
				ans += min(v,ala[i]);
				ala[i] = max(0,ala[i]-v);
			}
		}
		cout<<ans<<endl;
	}
}