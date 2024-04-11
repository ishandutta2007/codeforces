#include<bits/stdc++.h>
using namespace std;
const int N=75005;
typedef long long ll;
int k,len[19],bel[N],a[N],pre[N],i,j,nn,pr[N];
vector<pair<int,int>>ve[N],tmp;
bool f[N];
unordered_map<ll,int>mp;
ll tot,su[19];
int c[19],p[19];
void dfs(int x){
	if(pr[x])return dfs(pr[x]),dfs(x^pr[x]);
	for(auto u:ve[x])c[bel[u.first]]=a[u.first],p[bel[u.first]]=u.second+1;
}
int main(){
	scanf("%d",&k);
	for(i=0;i<k;++i)for(scanf("%d",len+i),j=len[i];j--;)
		scanf("%d",a+nn),bel[nn]=i,mp[a[nn]]=nn,su[i]+=a[nn],tot+=a[nn++];
	if(tot%k){puts("No");return 0;}
	tot/=k;
	for(i=0;i<nn;++i){
		auto it=mp.find(tot-su[bel[i]]+a[i]);
		pre[i]=it==mp.end()?-1:it->second;
	}
	for(i=0;i<nn;++i)if(pre[i]!=-1){
		int S=0;tmp.clear();
		for(j=i;;){
			tmp.push_back({pre[j],bel[j]});S|=1<<bel[j];
			if(pre[j]==-1 || (S>>bel[pre[j]]&1))break;
			j=pre[j];
		}
		if(pre[j]==i)f[S]=1,ve[S]=tmp;
	}
	for(i=1;i<1<<k;++i)for(j=i;j && !f[i];j=(j-1)&i)if(f[j] && f[i^j])f[i]=1,pr[i]=j;
	if(!f[i-1]){puts("No");return 0;}
	dfs(i-1);
	puts("Yes");
	for(i=0;i<k;++i)printf("%d %d\n",c[i],p[i]);
	return 0;
}