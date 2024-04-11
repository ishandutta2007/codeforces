#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long
#define db double
#define inf 0x7fffffff
#define rg register int

using namespace std;

int n,m,t,u,v;
bool a[19][19]; //
ll ans,f[600001][19]; //

inline int qr(){ //
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int res=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+(ch^48);
	return res;
}

int main(){
	//freopen("hamilton.in","r",stdin);
	//freopen("hamilton.out","w",stdout);
	n=qr(),m=qr();t=1<<n;
	for(rg i=1;i<=m;++i){
		u=qr()-1;v=qr()-1;
		a[u][v]=a[v][u]=1;//
	}
	for(rg i=0;i<n;++i)
		f[1<<i][i]=1; //i
	for(rg i=1;i<=t;++i){
		for(rg j=0;j<n;++j){
			if(!f[i][j])continue; //
			for(rg k=0;k<n;++k){
				if(!a[j][k])continue; //
				if((i&-i)>1<<k)continue; //
				if(1<<k&i){ //
					if(1<<k==(i&-i)) //
						ans+=f[i][j];
				}else f[i|1<<k][k]+=f[i][j]; //
			}
		}
	}printf("%lld",(ans-m)/2); //
	return 0;
}