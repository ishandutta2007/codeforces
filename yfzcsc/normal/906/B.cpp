#include<bits/stdc++.h>
#define maxn 101000
#define id(i,j) (((i)-1)*m+(j))
using namespace std;
int a[200100],n,m,vis[200100];
set<int> st;
bool chk(int a,int b){
	if(!a||!b)return false;
	int ax=(a-1)/m+1,ay=(a-1)%m+1;
	int bx=(b-1)/m+1,by=(b-1)%m+1;
	return abs(ax-bx)+abs(ay-by)<=1;
}
void dfs(int x,int y){
	if(x==n+1){
		puts("YES");
		for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=m;++j)
				printf("%d ",a[id(i,j)]);
		exit(0);
	} else if(y==m+1){
		dfs(x+1,1);
		return ;
	}
	int i=0;
	for(auto it=st.begin();it!=st.end();it++)if(!chk(i=*it,a[id(x-1,y)])&&!chk(i,a[id(x,y-1)]))
		a[id(x,y)]=i,st.erase(i),dfs(x,y+1),a[id(x,y)]=0,it=st.insert(i).first;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)st.insert(i);
	dfs(1,1);
	puts("NO");
}