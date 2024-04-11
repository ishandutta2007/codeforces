#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

vector<int> G[300010];
vector<int> chi[300010];
int num[300010];

void mkg(int v,int p){
	num[v]=0;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]!=p){
			chi[v].push_back(G[v][i]);
			mkg(G[v][i],v);
			num[v]=max(num[v],num[G[v][i]]);
		}
	}
	num[v]++;
}

pair<int,int> Ans(int v,int c){
	if(chi[v].size()==0)return pair<int,int>(v,c);
	int a1=c,a2=0,k1=v;

	for(int i=0;i<chi[v].size();i++){
		if(num[chi[v][i]]>a1){
			a2=a1;
			a1=num[chi[v][i]];
			k1=chi[v][i];
		}
		else a2=max(a2,num[chi[v][i]]);
	}

	if(k1==v){
		return pair<int,int>(v,a1+a2);
	}
	if(a1>a2+1){
		return Ans(k1,a2+1);
	}
	return pair<int,int>(v,a1+a2);
}

pair<int,int> solver(int root){
	mkg(root,root);
	return Ans(root,0);
}

int par[300010],r[300010],len[300010];

void init(){ for(int i=0;i<300010;i++){ par[i]=i; r[i]=0; len[i]=0; } }
int find(int x){ if(x==par[x])return x; return par[x]=find(par[x]); }
bool same(int x,int y){ return find(x)==find(y); }
void unit(int x,int y){ if(same(x,y))return; x=find(x); y=find(y); if(r[x]<r[y])par[x]=y; else { par[y]=x; if(r[x]==r[y])r[x]++; } }
void merge(int x,int y){
	if(same(x,y))return; x=find(x); y=find(y);
	if(len[x]<len[y])swap(x,y);
	par[y]=x;
	len[x]=max(len[x],((len[x]+1)/2)+((len[y]+1)/2)+1);
}
int query(int x){ return len[find(x)]; }

int main(){
	init();

	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		unit(a,b);
	}

	static bool used[300010];
	for(int i=0;i<300010;i++)used[i]=false;

	for(int i=1;i<=n;i++){
		if(find(i)==i&&!used[i]){
			pair<int,int> p=solver(i);
			par[i]=p.first;
			par[p.first]=p.first;
			len[p.first]=p.second;
			used[p.first]=true;
		}
	}

	for(int i=0;i<q;i++){
		int t;
		scanf("%d",&t);

		if(t==1){
			int x;
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
		else {
			int a,b;
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
	}
}