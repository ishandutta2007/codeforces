#include<stdio.h>
#include<bits/stdc++.h>
inline int Min(int a,int b){return a<b?a:b;}
long long a[100002];int n,ans=1e8,k[100002],top=0;int p[64][4];
int Last[100002],Next[100002],End[100002],dis[100002],vis[100002],tot=0;
inline bool chk(int t){
	for(int i=0;i<t;i++)if(p[i][2]==p[t][2]&&p[i][1]==p[t][1])return 0;return 1;
}
int dij(int s,int t){
	std::priority_queue<std::pair<int,int> >Q;
	for(int i=1;i<=n;i++)dis[i]=1e8,vis[i]=0;
	Q.push(std::make_pair(-(dis[s]=0),s));
	while(!Q.empty()){
		int p=Q.top().second;Q.pop();
		if(vis[p])continue;vis[p]=1;int i=Last[p];
		while(i){
			if(dis[End[i]]>dis[p]+1)Q.push(std::make_pair(-(dis[End[i]]=dis[p]+1),End[i]));
			i=Next[i];
		}
	}return dis[t]+1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<63;i++){int cnt=0;
		for(int j=1;j<=n;j++)cnt+=(a[j]>>i&1)!=0;
		if(cnt>=3)return printf("3")&0;
		for(int j=1;j<=n;j++)if(a[j]>>i&1)p[i][++p[i][0]]=j;
		if(p[i][0]==2)if(chk(i)){ans=Min(ans,dij(p[i][1],p[i][2]));
			End[++tot]=p[i][1];Next[tot]=Last[p[i][2]];Last[p[i][2]]=tot;
			End[++tot]=p[i][2];Next[tot]=Last[p[i][1]];Last[p[i][1]]=tot;
		}
	}
	printf("%d",ans>=1e8?-1:ans);
}