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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 2e5 + 10;

const int N = 2e5 + 5;
 
struct AhoCorasick {
	int trie[N][26];
	int fail[N];
    int val[N];
	int saiz;
 
	AhoCorasick() {
		memset(trie[0],-1,sizeof trie[0]);
        reset(val, 0);
		saiz = 0;
	}
 
	void add(string str) {
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
        val[cur] += 1;
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
            val[now] += val[fail[now]];
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
 
} ini, itu;

string s[mx];
int pref[mx], suff[mx];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string ss;
    cin >> ss >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) ini.add(s[i]);
    ini.build();
    int cur = 0;
    for(int i = 0; i < sz(ss); i++){
        cur = ini.trie[cur][ss[i] - 'a'];
        pref[i] += ini.val[cur];
    }
    for(int i = 0; i < n; i++){
        auto tmp = s[i];
        reverse(ALL(tmp));
        itu.add(tmp);
    }
    itu.build();
    auto tmp = ss;
    reverse(ALL(tmp));
    cur = 0;
    for(int i = 0; i < sz(tmp); i++){
        cur = itu.trie[cur][tmp[i] - 'a'];
        suff[sz(tmp) - i - 1] += itu.val[cur];
    }
    long long jaw = 0;
    for(int i = 0; i < sz(ss) - 1; i++){
        jaw = jaw + 1LL * pref[i] * suff[i + 1];
    }
    cout << jaw << endl;
}