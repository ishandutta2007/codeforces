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
const int mx = 1e5 + 10;

string ss, k[mx];
int n, m[mx];
vector<int> isi[mx];

const int N = 1e5 + 5;
 
struct AhoCorasick {
	int trie[N][26];
	int fail[N];
	int saiz;
	int apa[N];
	AhoCorasick() {
		memset(trie[0],-1,sizeof trie[0]);
		saiz = 0;
	}

	void res(){
		for(int i = 0; i <= saiz; i++){
			apa[i] = 0;
			for(int j = 0; j < 26; j++){
				trie[i][j] = -1;
			}
		}
		saiz = 0;
	}
 
	void add(string str, int id) {
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
		apa[cur] = id;
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
 
};


AhoCorasick ini;

vector<int> occurance[mx];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> ss >> n;
	for(int i = 1; i <= n; i++) cin >> m[i] >> k[i], isi[sz(k[i])].pb(i);
	for(int i = 1; i <= sz(ss); i++){
		if(sz(isi[i]) == 0) continue;
		ini.res();
		for(int j : isi[i]) ini.add(k[j], j);
		ini.build();
		int cur = 0;
		for(int j = 0; j < sz(ss); j++){
			cur = ini.trie[cur][ss[j] - 'a'];
			int x = ini.apa[cur];
			if(x == 0) continue;
			occurance[x].pb(j);
		}
	}
	for(int i = 1; i <= n; i++){
		if(sz(occurance[i]) < m[i]){
			cout << -1 << '\n';
			continue;
		}
		int jaw = 1e9;
		for(int l = 0; l < sz(occurance[i]); l++){
			int r = l + m[i] - 1;
			if(r >= sz(occurance[i])) break;
			jaw = min(jaw, occurance[i][r] - (occurance[i][l] - sz(k[i]) + 1) + 1);
		}
		cout << jaw << '\n';
	}
}