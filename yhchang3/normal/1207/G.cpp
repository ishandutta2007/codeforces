#include<bits/stdc++.h>
using namespace std;

const int maxn = 400010,sigma = 26;
int f[maxn],tr[maxn][sigma],mk[maxn],sz=1;//epsilon
vector<int> FT[maxn];
int insert(string &s){
	int now=0;
	for(char c:s)
		if(tr[now][c-'a'])	now=tr[now][c-'a'];
		else	now=tr[now][c-'a']=sz++;
	mk[now]=true;
	return now;
}
void build(){
	int now=0;queue<int> q;
	for(int i=0;i<sigma;i++)if(tr[now][i])q.push(tr[now][i]);
	while(!q.empty()){
		now=q.front();q.pop();
		for(int i=0;i<sigma;i++)
			if(tr[now][i])	f[tr[now][i]]=tr[f[now]][i],q.push(tr[now][i]);
			else	tr[now][i]=tr[f[now]][i];
	}
}
void cfail(){for(int i=1;i<sz;i++)	if(!mk[f[i]])	f[i]=f[f[i]];}
vector<pair<int,int> > songs[maxn],queries[maxn];

int dt,in[maxn],out[maxn],BIT[maxn],ans[maxn];
void dfs_order(int x){
	in[x]=++dt;
	for(int it:FT[x])
		dfs_order(it);
	out[x]=dt;
}

void add(int pos,int val){
	for(;pos<=dt;pos+=pos&-pos)
		BIT[pos]+=val;
}

int sum(int pos){
	int res=0;
	for(;pos;pos-=pos&-pos)
		res+=BIT[pos];
	return res;
}

void dfs(int x,int y){
	add(in[x],1);
	for(auto it:queries[y])
		ans[it.second]=sum(out[it.first])-sum(in[it.first]-1);
	for(auto it:songs[y])
		dfs(tr[x][it.first],it.second);
	add(in[x],-1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,type,parent;i<=n;i++){
		char c;
		cin>>type;
		if(type==1){
			parent=0;
			cin>>c;
		}
		else
			cin>>parent>>c;
		songs[parent].emplace_back(make_pair(c-'a',i));
	}
	int m;
	cin>>m;
	for(int i=1,which;i<=m;i++){
		string pattern;
		cin>>which>>pattern;
		queries[which].emplace_back(make_pair(insert(pattern),i));
	}
	build();
	cfail();
	for(int i=1;i<sz;i++)
		FT[f[i]].emplace_back(i);
	dfs_order(0);
	dfs(0,0);
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';
}