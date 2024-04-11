#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1007;
int n,mx,tot,eu[N<<1];
vector<int>G[N];
int s,a[N<<1];
inline int query(int l,int r){
	s=0;
	for(int i=l;i<=r;i++)a[++s]=eu[i];
	sort(a+1,a+s+1),s=unique(a+1,a+s+1)-a-1;
	cout<<"? "<<s<<" ";
	for(int i=1;i<=s;i++)cout<<a[i]<<" ";
	cout<<endl;
	return read();
}
void dfs(int x,int fa){
	eu[++tot]=x;
	for(int y:G[x])
		if(y^fa)dfs(y,x),eu[++tot]=x;
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
	}
	dfs(1,0),mx=query(1,tot);int l=1,r=tot;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(query(l,mid)==mx)r=mid;
		else l=mid;
	}
	printf("! %d %d\n",eu[l],eu[r]);
	return 0;
}