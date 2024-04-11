#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

bitset<4096>b[101000];
int n,k,cnt,T,t,x,y,bit,now;
pii p[101000][14];

int main(){
	cin>>n>>k>>T;
	for (int i=1;i<=k;i++){
		for (int j=1;j<=n;j++) scanf("%d",&p[j][i].fi),p[j][i].se=i;
		for (int j=0;j<(1<<k);j++) b[i][j]=!!((1<<i-1)&j);
	}
	for (int j=1;j<=n;j++) sort(p[j]+1,p[j]+k+1);
	for (cnt=k;T--;){
		scanf("%d%d%d",&t,&x,&y);
		switch (t){
			case 1: b[++cnt]=b[x]&b[y]; break;
			case 2: b[++cnt]=b[x]|b[y]; break;
			case 3: for (bit=0,now=0;!b[x][bit];bit|=1<<p[y][++now].se-1); printf("%d\n",p[y][now].fi); break;
		}
	}
}