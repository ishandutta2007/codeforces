#include<bits/stdc++.h>
using namespace std;

const int maxn=500010;

vector<int> e[maxn];
int pidx[maxn];
int sz[maxn];
vector<int> sa[maxn];
int pr[maxn];
void dfsxx(int x,int p,int z){
	pidx[x]=z;
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]==p){
			swap(e[x][i],e[x].back());
			e[x].pop_back();
			i--;
		}
		else{
			dfsxx(e[x][i],x,i);
		}
	}
}

void dfsyy(int x){
	sz[x]=0;
	for(int it:e[x]){
		dfsyy(it);
		sz[x]=max(1+sz[it],sz[x]);
		sa[x].emplace_back(1+sz[it]);
	}
}

void dfszz(int x,int y){
	pr[x]=y;
	multiset<int> m;
	m.insert(y);
	for(int it:sa[x])
		m.insert(it);
	for(int i=0;i<e[x].size();i++){
		m.erase(m.find(sa[x][i]));
		dfszz(e[x][i],1+*prev(m.end()));
		m.insert(sa[x][i]);
	}
}
int ans[maxn];
int A[maxn];
void update(int x,int y){
	ans[x]=max(ans[x],y);
}
void Update(int x,int y){
	A[x]=max(A[x],y);
}

void dfs(int x){
	vector<int> v=sa[x];
	if(x!=1)
		v.emplace_back(pr[x]);
	sort(v.begin(),v.end());
	update(1,v.size()+1);
	for(int i=v.size()-1;i>=0;i--){
		if(i>0&&v[i-1]!=v[i])
			update(2*v[i-1]+1,v.size()-(i-1));
		update(2*v[i]-1,v.size()-i);
		update(2*v[i],v.size()-i);
	}
	for(int it:e[x])
		dfs(it);
	for(int it:e[x]){
		sort(sa[it].begin(),sa[it].end());
		if(sa[it].size()){
			for(int i=sa[it].size()-1;i>=0;i--){
				int z=lower_bound(v.begin(),v.end(),sa[it][i])-v.begin();
				Update(sa[it][i]*2,(int) sa[it].size()-i+(int) v.size()-z-1);
			}
			for(int i=v.size()-1;i>=0;i--){
				int z=lower_bound(sa[it].begin(),sa[it].end(),v[i])-sa[it].begin();
				Update(v[i]*2,(int) sa[it].size()-i+(int) v.size()-z-1);
				
			}
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfsxx(1,0,-1);dfsyy(1);dfszz(1,0);
	for(int i=1;i<=n;i++)
		ans[i]=1;
	dfs(1);
	for(int i=n-1;i>=1;i--)
		ans[i]=max(ans[i],ans[i+1]);
	for(int i=(n-1)/2*2;i>=2;i-=2)
		ans[i]=max(ans[i],max(ans[i+2],A[i]));
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
}