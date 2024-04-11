#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,p,w[1001000];
vector<int>v[1001000];
vector<ll>s[1001000];

ll que(int x,int y){
	if (!x||y<v[x][0]) return 0;
	p=lower_bound(v[x].begin(),v[x].end(),y)-v[x].begin();
	while (p==v[x].size()||v[x][p]>y) --p;
	return (p+1ll)*y-s[x][p];
}

int main(){
	scanf("%d%d",&n,&m);
	register int i,x,y;
	for (i=1;i<n;i++) scanf("%d",&w[i+1]);
	for (i=n;i;--i){
		for (x=i,y=0;x;y+=w[x],x>>=1){
			v[x].push_back(y);
			s[x].push_back(0);
		}
		sort(v[i].begin(),v[i].end());
		s[i][0]=v[i][0];
		for (x=1;x<v[i].size();++x) s[i][x]=s[i][x-1]+v[i][x];
	}
	for (ll ans;m--;printf("%I64d\n",ans)){
		scanf("%d%d",&x,&y);
		for (ans=que(x,y);x>1&&y>0;) ans-=que(x,y-w[x]*2)-que(x>>=1,y-=w[x]);
	}
}