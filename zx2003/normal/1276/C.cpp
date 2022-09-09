#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
typedef pair<int,int>pii;
int n,a,i,j,p,q,np,nq,ct[N],su[N],x,y,z,w;
unordered_map<int,int>mp;
vector<int>ans[999],ve[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a),++mp[a];
	for(auto u:mp)++ct[u.second],ve[u.second].push_back(u.first);
	for(i=1;i<=n;++i){
		su[i]=su[i-1]+ct[i]*i,ct[i]+=ct[i-1];
		np=i;nq=su[i]/i+mp.size()-ct[i];
		if(np<=nq && np*nq>p*q)p=np,q=nq;
	}
	for(i=0;i<p;++i)ans[i].resize(q);
	for(j=N-1;j>=0;--j)for(int v:ve[j])for(i=min(p,j);w<q && i--;){
		ans[x][y]=v;
		x=(x+1)%p;y=(y+1)%q;if(++z==p)z=0,++w,x=0,y=w;
	}
	printf("%d\n%d %d\n",p*q,p,q);
	for(i=0;i<p;++i)for(j=0;j<q;++j)printf("%d%c",ans[i][j],j==q-1?'\n':' ');
	return 0;
}