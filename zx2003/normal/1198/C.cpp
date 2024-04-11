#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,m,u[N],v[N],i;
bool b[N],bb[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	for(cin>>T;T--;){
		cin>>n>>m;memset(b+1,0,n*3);
		int zz=0;
		for(i=1;i<=m;++i){
			cin>>u[i]>>v[i];
			if(!b[u[i]] && !b[v[i]] && zz<n)bb[i]=b[u[i]]=b[v[i]]=1,++zz;
				else bb[i]=0;
		}
		if(zz>=n){
			cout<<"Matching\n";
			for(i=1;i<=m;++i)if(bb[i])cout<<i<<' ';cout<<'\n';
		}else{
			cout<<"IndSet\n";
			zz=0;
			for(i=1;i<=n*3;++i)if(zz<n && !b[i])cout<<i<<' ',++zz;cout<<'\n';
		}
	}
	return 0;
}