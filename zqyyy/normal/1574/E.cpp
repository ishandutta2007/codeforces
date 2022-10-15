#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return f?r:-r;
}
const int N=1e6+7,mod=998'244'353;
map<int,int>c[N];
int n,m,K,pw[N],cntr[N][2],cntc[N][2],cntx[2];
set<int>br,bc,ur,uc;
inline void upd(int x,int y,int delta,int cnt[N][2],set<int>&b,set<int>&u){
	cnt[x][y]+=delta;
	if(cnt[x][0] && cnt[x][1])b.insert(x);
	else if(b.find(x)!=b.end())b.erase(b.find(x));
	if(cnt[x][0] || cnt[x][1])u.insert(x);
	else if(u.find(x)!=u.end())u.erase(u.find(x));
}
inline void update(int x,int y,int typ){
	int z=(x&1)^(y&1);
	if(c[x].count(y)){
		int ne=z^c[x][y];cntx[ne]--;
		upd(x,ne,-1,cntr,br,ur);
		upd(y,ne,-1,cntc,bc,uc);
		c[x].erase(y);
	}
	if(~typ){
		int ne=z^typ;cntx[ne]++;
		upd(x,ne,1,cntr,br,ur);
		upd(y,ne,1,cntc,bc,uc);
		c[x][y]=typ;
	}
}
int main(){
	n=read(),m=read(),K=read(),pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=(pw[i-1]<<1)%mod;
	while(K--){
		int x=read(),y=read(),typ=read(),ans=0;update(x,y,typ);
		if(!br.empty() && !bc.empty());
		else if(!br.empty())ans=pw[m-uc.size()];
		else if(!bc.empty())ans=pw[n-ur.size()];
		else if(ur.empty() && uc.empty())ans=(pw[n]+pw[m]-2)%mod;
		else{
			ans=(pw[m-uc.size()]+pw[n-ur.size()])%mod;
			if(!cntx[0] || !cntx[1])ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}