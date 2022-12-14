#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, sigma = 26;
int f[maxn],tr[maxn][sigma],mk[maxn],sz=1;//epsilon
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

vector<int> e[maxn];
int in[maxn], out[maxn], dfn;
void dfs(int x) {
	in[x] = ++dfn;
	for(int y : e[x])
		dfs(y);
	out[x] = dfn;
}
int val[maxn];
void add(int x,int v) {
	for(int i=x;i<maxn;i+=i&-i)
		val[i] += v;
}
int query(int x) {
	int res = 0;
	for(int i=x;i>0;i-=i&-i)
		res += val[i];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<string> s(n);
	vector<int> id(n);
	for(int i=0;i<n;i++) {
		cin >> s[i];
		id[i] = insert(s[i]);
	}
	build();
	for(int i=1;i<sz;i++)
		e[f[i]].emplace_back(i);
	dfs(0);
	vector<vector<int>> evtl(n), evtr(n);
	vector<int> who(q), ans(q);
	for(int i=0,l,r;i<q;i++) {
		cin >> l >> r >> who[i];
		who[i]--;
		evtl[l - 1].emplace_back(i);
		evtr[r - 1].emplace_back(i);
	}
	for(int i=0;i<n;i++) {
		int now = 0;
		for(char c : s[i])
			now = tr[now][c - 'a'], add(in[now], 1);
	}
	for(int i=0;i<q;i++)
		ans[i] = query(out[id[who[i]]]) - query(in[id[who[i]]] - 1);
	memset(val, 0, sizeof val);
	for(int i=0;i<n;i++) {
		for(int e : evtl[i])
			ans[e] -= query(out[id[who[e]]]) - query(in[id[who[e]]] - 1);
		int now = 0;
		for(char c : s[i])
			now = tr[now][c - 'a'], add(in[now], 1);
	}
	memset(val, 0, sizeof val);
	for(int i=n-1;i>=0;i--) {
		for(int e : evtr[i])
			ans[e] -= query(out[id[who[e]]]) - query(in[id[who[e]]] - 1);
		int now = 0;
		for(char c : s[i])
			now = tr[now][c - 'a'], add(in[now], 1);
	}
	for(int i=0;i<q;i++)
		cout << ans[i] << endl;
}