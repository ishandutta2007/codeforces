#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1001,M=60001;
int vs[M],fff,s,t,ll[N],an[3],ans,anss,anan,n,p,s1,s2,s3,m,h,flag,oo=1000000000,son[N],dfn[N],low[N],ed[M],nedge,vis[N],tot,dp[N],nextt[M],di[M];
inline void aedge(int a,int b,int c){
    nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c;
}
inline void dfs(int p,int father,int l){
    dfn[p]=low[p]=++h; dp[p]=(p==t); if(p==t)flag=1;
    for(int i=son[p];i;i=nextt[i])if(i!=((l-1)^1)+1&&!vs[i]){
        if(dfn[ed[i]]==0){
            dfs(ed[i],p,i); dp[p]|=dp[ed[i]];
            low[p]=min(low[ed[i]],low[p]);
        }else low[p]=min(low[p],dfn[ed[i]]);
    }
    //cout<<p<<' '<<low[p]<<" "<<dfn[p]<<endl;
    if(low[p]==dfn[p]&&p!=s){
    	if(dp[p]&&di[l]<ans){
    		ans=di[l]; anan=(l+1)/2;
		}
	}
}
void solve(int p){
	//cout<<p<<endl;
	if(ll[p]==0)return;
	vs[ll[p]]=vs[((ll[p]-1)^1)+1]=1; ans=1000000005; h=flag=0; memset(dfn,0,sizeof(dfn)); //cout<<p<<endl;
	dfs(s,0,0); vs[ll[p]]=vs[((ll[p]-1)^1)+1]=0;
	//for(int i=1;i<=nedge;i++)cout<<vis[i]<<" "; puts("");
	if(!flag&&di[ll[p]]<anss){
		anss=di[ll[p]]; an[0]=1; an[1]=(ll[p]+1)/2;
	}
	//cout<<ans<<" "<<flag<<endl;
	if(ans!=1000000005&&ans+di[ll[p]]<anss){
		anss=ans+di[ll[p]]; an[0]=2; an[1]=(ll[p]+1)/2; an[2]=anan; //cout<<ans<<" " <<anan<<endl;
	}
	solve(ed[((ll[p]-1)^1)+1]);
}
void dfs(int p,int last){
	vis[p]=1; ll[p]=last; 
	if(p==t){solve(p); fff=1; return;}
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]])dfs(ed[i],i);
}
int main(){
    flag=h=n=0;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
    	int s1,s2,s3;
    	scanf("%d%d%d",&s1,&s2,&s3); aedge(s1,s2,s3); aedge(s2,s1,s3);
    }
    anss=2000000005;
    dfs(s,0);
    if(!fff)puts("0\n0"); else
    if(anss>2000000000)puts("-1"); else{
    	cout<<anss<<endl<<an[0]<<endl;
    	for(int i=1;i<=an[0];i++)cout<<an[i]<<" ";
	}
}