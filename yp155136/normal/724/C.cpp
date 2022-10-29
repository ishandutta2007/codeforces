#include <iostream>
#include <stdio.h>
#include <utility>
#include <map>
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
const int MAX_N = 1e5 + 6;

pii ipt[MAX_N]; //input
LL ans[MAX_N];
LL ans2[MAX_N];

int main (){
	LL n,m,k;
	while (scanf("%I64d %I64d %I64d",&n,&m,&k) != EOF) {
		for (int x=1;k>=x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			ipt[x] = make_pair(i,j);
			ans[x] = i-j;
			ans2[x] = i+j;
		}
		map<LL,LL> mp;
		map<LL,pii> mp2;
		map<LL,LL> mp3;
		map<LL,pii> mp4;
		int dx=1,dy=1;
		mp[0]=0;
		int s=0,t=0;
		LL ti=0;
		while (1) {
			int L=0,R=MAX_N; //L is the answer
			while (R-L != 1) {
				int mid=(L+R)>>1;
				if (s+mid*dx>=0 && s+mid*dx<=n && t+mid*dy>=0 && t+mid*dy<=m) {
					L=mid;
				}
				else R=mid;
			}
//			cout<<"s = "<<s<<" , t="<<t<<endl;
//			cout<<"L="<<L<<endl;
			s += L*dx;
			t += L*dy;
			ti += L;
			if (s==0 && t==0 || s==n&&t==m||s==n&&t==0||s==0&&t==m) break;
			else if (s==0) {
				dx= -dx;
				if (dx == dy)mp[s-t]=ti;
				else mp3[s+t]=ti;
			}
			else if (s==n) {
				dx = -dx;
				if (dx == dy)mp[s-t]=ti;
				else mp3[s+t]=ti;
			}
			else if (t==0) {
				dy= -dy;
				if (dx == dy)mp[s-t]=ti;
				else mp3[s+t]=ti;
			}
			else if (t==m) {
				dy = -dy;
				if (dx == dy)mp[s-t]=ti;
				else mp3[s+t]=ti;
			}
			if (dx ==dy)mp2[s-t] = make_pair(s,t);
			else mp4[s+t] = make_pair(s,t);
		}
		for (int x=1;k>=x;x++) {
			if (ans[x] == 0) printf("%d\n",ipt[x].first);
			else if (mp[ans[x]] == 0 && mp3[ans2[x]] == 0) puts("-1");
			else {
				LL a1=1e17,a2=1e17;
				if (mp[ans[x]]) a1 = mp[ans[x]] + abs(ipt[x].first-mp2[ans[x]].first);
				if (mp3[ans2[x]]) a2 = mp3[ans2[x]] + abs(ipt[x].first - mp4[ans2[x]].first);
				printf("%I64d\n",min(a1,a2) );
			}
		}
	}
}