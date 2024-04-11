#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,B=sqrt(N);
int n,a[N],i,j,k,l,t,u,ans,mx,mxid,col[N],r2[N*2],a2[N],su[N],pre[N];
vector<int>aa[N],ve;
struct info{
	int v1,v2;
	inline void ins(int x){x<=v1?v2=v1,v1=x:v2=min(v2,x);}
	inline int ask(int x){return x==v1?v2:v1;}
}r1[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>a[i];memset(r1,1,sizeof r1);
	for(i=n;i;--i){
		aa[a[i]].push_back(i);
		l=aa[a[i]].size();if(l>=mx)mx=l,mxid=a[i];
		for(j=1;j<=min(B,l);++j)r1[j].ins(aa[a[i]][l-j]);
		for(l=aa[mxid].size(),j=1;j<=min(B,l);++j)
			if(t=j==l?n+1:aa[mxid][l-j-1],r1[j].ask(aa[mxid][l-j])<t)ans=max(ans,t-i);
		col[i]=mxid;
	}
	for(i=1;i<=n;++i)pre[i]=col[i]==col[i-1]?pre[i-1]:i;
	for(i=1;i<=n;++i)if(reverse(aa[i].begin(),aa[i].end()),aa[i].size()>B-2)ve.push_back(i);
	for(i=0;i<ve.size();++i)for(j=i+1;j<ve.size();++j){
		l=aa[ve[i]].size()+aa[ve[j]].size();
		merge(&aa[ve[i]][0],&aa[ve[i]].back()+1,&aa[ve[j]][0],&aa[ve[j]].back()+1,a2+1);
		for(k=1;k<=l;++k)su[k]=su[k-1]+(a[a2[k]]==ve[i]?1:-1),r2[su[k]+N]=k==l?n+1:a2[k+1];
		for(k=l;k;--k)if(col[a2[k]]==ve[i] || col[a2[k]]==ve[j])
			ans=max(ans,r2[su[k-1]+N]-max(a2[k-1]+1,pre[a2[k]]));
		for(k=1;k<=l;++k)r2[su[k]+N]=0;
	}
	cout<<ans<<endl;
}