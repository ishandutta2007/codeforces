#include<bits/stdc++.h>
using namespace std;
typedef vector<int>V;
void del(V&a,V b){for(int x:b)a.erase(find(a.begin(),a.end(),x));}
int rp[805];
bool ask(V v){
	printf("? %d",int(v.size()));
	for(int x:v)printf(" %d",x);puts("");fflush(stdout);
	int x;scanf("%d",&x);return x;
//	int x=0;for(int u:v)x+=rp[u];return x%v.size()==0;
}
V gett(V v){
	V u,ret;
	for(int i=0;i<v.size();++i){
		u=v;u.erase(u.begin()+i);
		if(ask(u))ret.push_back(v[i]);
	}
	return ret;
}
int n,i,j,p[805],ip[805],res[805][9];
void sett(int x,int v){p[x]=v;ip[v]=x;}
void set2(V v,int x,int y){for(int u:v)res[u][x]=y;}
V F(V a,V b){
	int tot=0;for(int x:b)tot+=p[x];
	V ret;b.push_back(0);tot=(b.size()-tot%b.size())%b.size();
	for(int x:a){
		b.back()=x;
		if(ask(b)){
			if(x==2 && b.size()==7)
++x,--x;
			ret.push_back(x);
		}
	}
	set2(ret,b.size(),tot);
	return ret;
}
void G(V v,int x){
	V u;
	for(int i=1;i<x;++i){
		V w;for(int j=1;j<=x;++j)if(j!=i)w.push_back(ip[j]);
		del(v,F(v,w));
	}
	set2(v,x,0);
}
void G7(V v){
	V u;
	del(v,F(v,{ip[2],ip[3],ip[4],ip[n-1],ip[n-2],ip[n-3]}));
	del(v,F(v,{ip[2],ip[3],ip[4],ip[n],ip[n-2],ip[n-3]}));
	del(v,F(v,{ip[2],ip[3],ip[4],ip[n],ip[n-1],ip[n-3]}));
	del(v,F(v,{ip[2],ip[3],ip[4],ip[n],ip[n-1],ip[n-2]}));
	del(v,F(v,{ip[2],ip[3],ip[5],ip[n],ip[n-1],ip[n-2]}));
	del(v,F(v,{ip[2],ip[4],ip[5],ip[n],ip[n-1],ip[n-2]}));
	del(v,F(v,{ip[3],ip[4],ip[5],ip[n],ip[n-1],ip[n-2]}));
}
void out(){
	if(p[1]>n/2)for(i=1;i<=n;++i)p[i]=n-p[i]+1;
//	for(i=1;i<=n;++i)assert(p[i]==rp[i]);
	printf("! ");for(i=1;i<=n;++i)printf("%d%c",p[i],i==n?'\n':' ');fflush(stdout);
}
int main(){
//	freopen("1","r",stdin);
	scanf("%d",&n);
//	for(i=1;i<=n;++i)scanf("%d",rp+i);
	V v(n);for(i=0;i<n;++i)v[i]=i+1;
	for(i=1;!v.empty() && i<=5;++i){
		V u=gett(v);
		if(i>1 && ask({u[1],ip[n-i+2]}))swap(u[0],u[1]);
		sett(u[0],i),sett(u[1],n-i+1);del(v,u);
	}
	if(v.empty()){out();return 0;}
	G(v,3);G(v,5);G7(v);
	for(i=1;i<=n;++i)if(!p[i]){
//		assert(rp[i]%3==res[i][3]);
//		assert(rp[i]%5==res[i][5]);
//		assert(rp[i]%7==res[i][7]);
		int x=ask({i,ip[1]});
		if(x){
			if(ask({i,ip[2],ip[n-1],ip[n-2]}))res[i][8]=ask({i,ip[2],ip[3],ip[4],ip[n-1],ip[n-2],ip[n-3],ip[n-4]})?1:5;
				else res[i][8]=ask({i,ip[1],ip[2],ip[4],ip[n-1],ip[n-2],ip[n-3],ip[n-4]})?3:7;
		}else{
			if(ask({i,ip[1],ip[n-1],ip[n-2]}))res[i][8]=ask({i,ip[1],ip[3],ip[4],ip[n-1],ip[n-2],ip[n-3],ip[n-4]})?2:6;
				else res[i][8]=ask({i,ip[1],ip[2],ip[3],ip[n-1],ip[n-2],ip[n-3],ip[n-4]})?4:0;
		}
		for(j=1;j<=n;++j)if(j%3==res[i][3] && j%5==res[i][5] && j%7==res[i][7] && j%8==res[i][8])sett(i,j);
	}
	out();
	return 0;
}