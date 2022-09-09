#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,i;
ll b[200005];
unordered_map<ll,vector<int>>mp;
vector<int>ans,ve;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%lld",b+i),mp[b[i]&-b[i]].push_back(i);
	for(auto u:mp)if(u.second.size()>ve.size())ve=u.second;
	for(i=0;i<n;++i)if(!binary_search(ve.begin(),ve.end(),i))ans.push_back(i);
	printf("%d\n",int(ans.size()));
	for(int x:ans)printf("%lld ",b[x]);puts("");
	return 0;
}