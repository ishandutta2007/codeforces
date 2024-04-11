#include<bits/stdc++.h>
#define ll long long
#define N 100100
#define S 2000
using namespace std;
int n,m;
map<int,int>mp[N];
int bcnt,L[55],R[55],pre[N],nex[N],bel[N],a[N]={0};
ll ans[55][55]={0};

ll A(int x,int y,int f){
	for (int i=1;i<=bel[x];i++)
		for (int j=bel[y];j<=bcnt;j++)
			ans[i][j]+=f*(y-x);
}
ll C(int x,int v){
	A(pre[x],x,-1);A(x,nex[x],-1);
	nex[pre[x]]=nex[x];pre[nex[x]]=pre[x];
	A(pre[x],nex[x],1);
	mp[a[x]].erase(x);
	map<int,int>::iterator it=mp[v].lower_bound(x);
	int p2=it->first,p1=(--it)->first;
	A(p1,p2,-1);
	pre[x]=p1;nex[x]=p2;nex[p1]=pre[p2]=x;
	A(p1,x,1);A(x,p2,1);
	mp[a[x]=v][x]=1;
}
ll Q(int st,int en){
	int b1=bel[st],b2=bel[en];
	ll t= b1+1<=b2-1?ans[b1+1][b2-1]:0;
	if (b1==b2){
		for (int i=st;i<en;i++)
			if (nex[i]<=en) t+=nex[i]-i;
	}else{
		for (int i=st;i<=R[b1];i++)
			if (nex[i]<L[b2]) t+=nex[i]-i;
		for (int i=L[b2];i<=en;i++)
			if (pre[i]>=st) t+=i-pre[i];
	}
	return t;
}

int main(){
	scanf("%d%d",&n,&m);
	bel[0]=1;
	for (int i=1;i<=n;i++) bcnt=bel[i]=(i-1)/S+2;
	bel[n+1]=++bcnt;
	for (int i=2;i<bcnt;i++) L[i]=(R[i]=(i-1)*S)-S+1;
	R[bcnt-1]=n;
	L[1]=R[1]=0;L[bcnt]=R[bcnt]=n+1;
	pre[nex[0]=n+1]=0;
	for (int i=1;i<=n;i++) mp[0][pre[i]=nex[i]=i]=1;
	for (int i=0;i<=n;i++) {
		mp[i].clear();
		mp[i][0]=1;
		mp[i][n+1]=1;
		A(0,n+1,1);
	}
	int x,y,t;
	for (int i=1;i<=n;C(i++,x)) scanf("%d",&x);
	for (;m--;){
		scanf("%d%d%d",&t,&x,&y);
		t==1?C(x,y):printf("%I64d\n",Q(x,y));
	}
}