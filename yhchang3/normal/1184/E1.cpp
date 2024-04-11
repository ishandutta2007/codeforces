#include<bits/stdc++.h>
using namespace std;
const int MN = 1e5;
int pa[MN+1],de[MN+1];
void Init(){
   for(int i=1;i<=MN;i++)
      de[pa[i]=i]=1;
}
int Find(int x){
   return x==pa[x]?x:pa[x]=Find(pa[x]);
}
void Union(int x,int y){
   x=Find(x);y=Find(y);
   if(x!=y){
      if(de[x]<de[y])    swap(x,y);
      pa[y]=x;
      if(de[x]==de[y])    de[x]++;
   }
}

struct E{
	int u,v,w,idx;
	bool operator<(const E& rhs)const{
		return (w==rhs.w?idx<rhs.idx:w<rhs.w);
	}
}edge[1000001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
		edge[i].idx=i;
	}
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+1+r)/2;
		Init();
		for(int i=1;i<=m;i++)
			if(edge[i].idx==1){
				edge[i].w=mid;
				break;
			}
			sort(edge+1,edge+1+m);
		bool used=false;
		for(int i=1;i<=m;i++){
			if(edge[i].idx==1){
				if(Find(edge[i].u)==Find(edge[i].v))
					used=false;
				else
					used=true;
				break;
			}
			else{
				if(Find(edge[i].u)!=Find(edge[i].v))
					Union(edge[i].u,edge[i].v);
			}
		}
		if(used)
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
}