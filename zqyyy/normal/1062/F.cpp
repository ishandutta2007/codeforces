#include <bits/stdc++.h>
using namespace std;
#define pb push_back
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=3e5+5;
int n,m,cnt[N];
queue<int>Q;
inline void topsort(vector<int>*G,int *d){
	while(!Q.empty())Q.pop();
	int tot=n;
	for(int i=1;i<=n;i++)
		if(!d[i])Q.push(i),tot--;
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		if(Q.empty())cnt[x]+=tot;
		else if(Q.size()==1){
			int z=Q.front();bool flg=1;
			for(auto y:G[z])
				if(d[y]==1){flg=0;break;}
			if(flg)cnt[x]+=tot;
		}else cnt[x]=-n;
		for(auto y:G[x])
			if(!--d[y])tot--,Q.push(y);
	}
}
vector<int>G[N],_G[N];
int d[N],_d[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		G[x].pb(y),_G[y].pb(x);
		d[y]++,_d[x]++;
	}
	topsort(G,d),topsort(_G,_d);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=(cnt[i]>=n-2);
	return cout<<ans,0;
}