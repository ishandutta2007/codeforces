#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=5e5+7;
int pa[N];
int find(int x){return pa[x]^x?pa[x]=find(pa[x]):x;}
int n,m;
vector<int>ans;
int main(){
	n=read(),m=read();
	for(int i=0;i<=m;i++)pa[i]=i;
	for(int i=1;i<=n;i++){
		int k=read(),x,y;
		if(k==1){
			x=read();
			if(find(0)!=find(x))pa[find(0)]=find(x),ans.push_back(i);
		}else{
			x=read(),y=read();
			if(find(y)!=find(x))pa[find(y)]=find(x),ans.push_back(i);
		}
	}
	int res=1;
	for(int i=0;i<(int)ans.size();i++)res=(res<<1)%1000000007;
	printf("%d %lu\n",res,ans.size());
	for(int x:ans)printf("%d ",x);
	return 0;
}