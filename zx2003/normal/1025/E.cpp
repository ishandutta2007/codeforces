#include<bits/stdc++.h>
using namespace std;
const int N=55;
struct opt{
	int x1,y1,x2,y2;
	void rev(){swap(x1,x2);swap(y1,y2);}
};
int n,m,i,j,k,x[N],y[N];
vector<opt>solve(){
	static bool b1[N][N],b2[N];
	static int a[N];
	for(i=1;i<=n;++i)memset(b1[i]+1,0,n);memset(b2+1,0,m);
	for(i=1;i<=m;++i)scanf("%d%d",x+i,y+i),a[i]=i,b1[x[i]][y[i]]=1;
	sort(a+1,a+m+1,[&](int p,int q){return x[p]<x[q];});
	vector<opt>ret;
	for(i=1;i<=m;++i){
		for(j=1;j<=m;++j)if(!b2[j]){
			if(x[a[j]]<j){
				for(k=x[a[j]]+1;k<=j;++k)if(b1[k][y[a[j]]])break;
				if(k>j)break;
			}else if(x[a[j]]>j){
				for(k=x[a[j]]-1;k>=j;--k)if(b1[k][y[a[j]]])break;
				if(k<j)break;
			}else break;
		}
		b2[j]=1;b1[x[a[j]]][y[a[j]]]=0;
		for(k=x[a[j]]+1;k<=j;++k)ret.push_back((opt){k-1,y[a[j]],k,y[a[j]]});
		for(k=x[a[j]]-1;k>=j;--k)ret.push_back((opt){k+1,y[a[j]],k,y[a[j]]});
		b1[j][y[a[j]]]=1;x[a[j]]=j;
	}
	for(j=1;j<=m;++j){
		for(k=y[a[j]]+1;k<=a[j];++k)ret.push_back((opt){x[a[j]],k-1,x[a[j]],k});
		for(k=y[a[j]]-1;k>=a[j];--k)ret.push_back((opt){x[a[j]],k+1,x[a[j]],k});
		y[a[j]]=a[j];
	}
	for(j=1;j<=m;++j){
		for(k=x[a[j]]+1;k<=a[j];++k)ret.push_back((opt){k-1,a[j],k,a[j]});
		for(k=x[a[j]]-1;k>=a[j];--k)ret.push_back((opt){k+1,a[j],k,a[j]});
		x[a[j]]=a[j];
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	vector<opt>v1,v2;
	v1=solve();v2=solve();for(auto&u:v2)u.rev();reverse(v2.begin(),v2.end());
	v1.insert(v1.end(),v2.begin(),v2.end());
	printf("%d\n",(int)v1.size());
	for(auto u:v1)printf("%d %d %d %d\n",u.x1,u.y1,u.x2,u.y2);
}