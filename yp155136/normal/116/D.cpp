#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long LL;
const int MAX_N = 156;

char s[MAX_N];
bool mp[MAX_N][MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		getchar();
		memset(mp,0,sizeof(mp));
		for (int i=1;n>=i;i++) {
			scanf("%s",s);
			for (int j=1;m>=j;j++) {
				mp[i][j] = (s[j-1]=='W');
			}
		}
		LL ans=0;
		LL now=1;
		int last=1;
		for (int i=1;n>=i;i++) {
			int st=-1,ed=-1;
			for (int j=1;m>=j;j++) {
				if (mp[i][j]) {
					if (st==-1) st=j;
					ed=j;
				}
			}
//			cout<<"i = "<<i<<" , j = "<<st<<" , ed = "<<ed<<endl;
			if (st==-1) continue;
			if (i%2==0) swap(st,ed);
			last=i;
			if(i&1) {
				//possitive
				if (now>st) {
					ans += abs(now-st);
					now = st;
				}
				ans += abs(now-ed);
				now=ed;
			}
			else {
				//negative
				if (now<st) {
					ans += abs(now-st);
					now=st;
				}
				ans += abs(now-ed);
				now=ed;
			}
//			cout<<"i = "<<i<<" , ans = "<<ans<<endl;
		}
		printf("%I64d\n",ans+(last-1));
	}
}