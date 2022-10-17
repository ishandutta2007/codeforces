#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define C(x,y) memset(x,y,sizeof(x))
typedef pair<int,int>pii;
priority_queue<pii>q;
vector<int>e[2020];
int n,m,root,tot,bas,dep[2020],fa[2020],c[2020],w[2020];
pii b[2020];
void D_1(int x,int d){
	dep[x]=d;q.emplace(make_pair(d,x));
	for(auto p:e[x])D_1(p,d+1);
}
void D_2(int x){
	w[x]+=bas;
	b[++tot]=make_pair(w[x],x);
	for(auto p:e[x])D_2(p);
}
int main(){
	cin>>n;
	F(i,1,n)cin>>fa[i]>>c[i];
	F(i,1,n)if(!fa[i])root=i;else e[fa[i]].emplace_back(i);
	D_1(root,1);
	while(!q.empty()){
		m=q.top().second;q.pop();tot=bas=0;
		for(auto p:e[m]){
			D_2(p);sort(b+1,b+1+tot);bas=b[tot].first;
		}
		if(tot<c[m]){cout<<"NO";return 0;}
		sort(b+1,b+1+tot);w[m]=b[c[m]].first+1;
		F(i,c[m]+1,tot)w[b[i].second]++;
	}
	cout<<"YES"<<endl;
	F(i,1,n)cout<<w[i]<<" ";
	return 0;
}