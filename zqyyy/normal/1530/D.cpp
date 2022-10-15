#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N],pa[N],b[N],c[N];
int find(int x){return pa[x]?pa[x]=find(pa[x]):x;}
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)b[i]=pa[i]=0;
	int ans=0;vector<int>vec;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(!pa[a[i]]){
			ans++,pa[a[i]]=c[a[i]]=i;
			b[i]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
		if(!b[i]){
			if(i!=find(i))b[i]=find(i);
			else vec.push_back(i);
		}
	if((int)vec.size()==1)b[vec[0]]=a[vec[0]],b[c[a[vec[0]]]]=vec[0];
	else if(vec.size()){
		for(int i=0;i<(int)vec.size()-1;i++)b[vec[i]]=vec[i+1];
		b[*vec.rbegin()]=vec[0];
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}