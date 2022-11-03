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
const int mx = 2e6 + 100;

struct AhoCorasick {
	int trie[mx][26];
	int fail[mx];
	int saiz;
	int val[mx];
	AhoCorasick() {
		memset(trie[0],-1,sizeof trie[0]);
		reset(val, 0);
		saiz = 0;
	}
 
	void add(string str, int x) {
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
		val[cur] = x;
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
 
} ini;

int n, k, g;
string ss, s[mx];
int ada[mx];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	cin >> ss;
	cin >> g;
	for(int i = 1; i <= g; i++){
		cin >> s[i];
		ini.add(s[i], i);
	}
	ini.build();
	ss += ss;
	int cur = 0;
	for(int i = 0; i < sz(ss); i++){
		cur = ini.trie[cur][ss[i] - 'a'];
		if(ini.val[cur] > 0){
			ada[i % (n * k)] = ini.val[cur];
			// debug(i, ini.val[cur]);
		}
	}
	for(int i = 0; i < k; i++){
		set<int> ini;
		int ya = 1;
		for(int j = i; j < n * k; j += k) if(ada[j] > 0) ini.insert(ada[j]); 
		if(sz(ini) == n){
			// debug(i);
			cout << "YES\n";
			for(int j = i; j < n * k; j += k) cout << ada[j] << ' ';
			cout << '\n';
			return 0;
		}
	}
	cout << "NO\n";
}