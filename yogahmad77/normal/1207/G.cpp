#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 5e5 + 10;

const int N = 5e5 + 5;
 
vector<int> g[mx];

struct AhoCorasick {
	int trie[N][26];
	int fail[N];
	int saiz;
 
	AhoCorasick() {
		memset(trie[0],-1,sizeof trie[0]);
		saiz = 0;
	}
 
	int add(string str) {
		int cur = 0;
		for(int i = 0 ; i < str.length() ; i++) {
			//checkChar(str[i]);
			int nex = str[i] - 'a';
			if(trie[cur][nex] == -1) {
				trie[cur][nex] = ++saiz;
				memset(trie[saiz],-1,sizeof trie[saiz]);
			}
			cur = trie[cur][nex];
		}
        return cur;
	}
 
	void build() {
		queue<int> q;
		fail[0] = 0;
 
		for(int i = 0 ; i < 26 ; i++)
			if(trie[0][i] == -1)
				trie[0][i] = 0;
			else {
				int nex = trie[0][i];
				fail[nex] = 0;
				q.push(nex);
			}
 
		while(!q.empty()) {
			int now = q.front();
			q.pop();
            if(now != fail[now]) g[fail[now]].pb(now);
 
			for(int i = 0 ; i < 26 ; i++)
				if(trie[now][i] == -1)
					trie[now][i] = trie[fail[now]][i];
				else {
					int nex = trie[now][i];
					fail[nex] = trie[fail[now]][i];
					q.push(nex);
				}
		}	
	}
 
	int getIndex(string str) {
		int cur = 0;
		for(int i = 0 ; i < str.length() ; i++) {
			//checkChar(str[i]);
			cur = trie[cur][str[i] - 'a'];
		}
		return cur;
	}
 
} ini;

int n, p[mx], q, di[mx], idx, in[mx], out[mx];
char c[mx];
vector<int> query[mx];
string ss[mx];

void dfs(int now){
    in[now] = ++idx;
    for(int i : g[now]) dfs(i);
    out[now] = idx;
}

vector<int> G[mx];
int jaw[mx];

int bit[mx];

void upd(int idx, int val){
    for(; idx <= 5e5; idx += idx & -idx) bit[idx] += val;
}

int cari(int i){
    int ret = 0;
    for(; i; i -= i & -i) ret += bit[i];
    return ret;
}

void DFS(int now, int cur){
    for(int i : query[now]){
        jaw[i] = cari(out[di[i]]) - cari(in[di[i]] - 1);
    }
    for(int i : G[now]){
        int nex = ini.trie[cur][c[i] - 'a'];
        upd(in[nex], 1);
        DFS(i, nex);
        upd(in[nex], -1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int t;
        cin >> t;
        if(t == 1) cin >> c[i];
        else cin >> p[i] >> c[i];
    }
    for(int i = 1; i <= n; i++){
        G[p[i]].pb(i);
    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        int x;
        cin >> x >> ss[i];
        query[x].pb(i);
        di[i] = ini.add(ss[i]);
    }
    ini.build();
    int N = ini.saiz;
    dfs(0);
    DFS(0, 0);
    for(int i = 1; i <= q; i++) cout << jaw[i] << '\n';
}