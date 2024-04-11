#include<bits/stdc++.h>
using namespace std;

const int N = 2010;

int mx[N],my[N],level[N];
vector<int> e[N];
bool dfs(int x){
	for(int y:e[x]){
		int w=my[y];
		if(w==-1||(level[x]+1==level[w]&&dfs(w))){
			mx[x]=y;
			my[y]=x;
			return true;
		}
	}
	level[x]=-1;
	return false;
}
int a,b;
int matching(){
	for(int i=0;i<a-1;i++)
		mx[i]=-1;
	for(int i=0;i<b-1;i++)
		my[i]=-1;
	for(int ans=0;;){
		queue<int> q;
		for(int i=0;i<a-1;i++){
			if(mx[i]==-1){
				level[i]=0;
				q.emplace(i);
			}
			else
				level[i]=-1;
		}
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int y:e[x]){
				int w=my[y];
				if(w!=-1&&level[w]<0){
					level[w]=level[x]+1;
					q.emplace(w);
				}
			}
		}
		int delta=0;
		for(int i=0;i<a-1;i++)
			if(mx[i]==-1&&dfs(i))
				delta++;
		if(delta==0)
			return ans;
		else
			ans+=delta;
	}
	return 0;
}

vector<int> ed2[2001],ed[2001];
int p[5000];
int A[1001],B[1001];
bitset<2001> use;
bitset<1001> vis[2001];
int dev[2001];
void dfs2(int x){
	if(ed[x].size()==0){
		vis[x][dev[x]]=true;
		return;
	}
	for(int it:ed[x]){
		dfs2(it);
		vis[x]|=vis[it];
	}
}

void dfs3(int x){
	for(int it:ed2[x]){
		dfs3(it);
		use[x]=use[x]|use[it];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	cin>>a;
	for(int i=2,x;i<=a;i++){
		cin>>x;
		ed[x].emplace_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>A[i];
		dev[A[i]]=i;
	}
	dfs2(1);
	cin>>b;
	for(int i=2,x;i<=b;i++){
		cin>>x;
		ed2[x].emplace_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>B[i];
	for(int i=2;i<=a;i++){
		for(int j=1;j<=b;j++)
			use[j]=false;
		for(int j=1;j<=n;j++)
			if(vis[i][j])
				use[B[j]]=true;
		dfs3(1);
		for(int j=2;j<=b;j++)
			if(use[j])
				e[i-2].emplace_back(j-2);
	}
	cout<<a+b-2-matching()<<endl;
}