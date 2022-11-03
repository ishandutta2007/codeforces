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
const int mx = 4e5 + 10;


struct suffixArray{
	int cnt[mx];
	int SA[mx],tmpS[mx];
	int RA[mx],tmpR[mx];
	int phi[mx],PLCP[mx],LCP[mx];
	string s;
	int len;

	void init(string ss){ s = ss; }
	
	void radixSort(int k){
		int maxx = max(len,300);
		for(int i = 0 ; i < maxx ; i++)
			cnt[i] = 0;
		for(int i = 0 ; i  < len ; i++)
			cnt[i + k < len ? RA[i + k] : 0]++;
		int tot = 0;
		for(int i = 0 ; i < maxx ; i++){
			int tmp = cnt[i];
			cnt[i] = tot;
			tot += tmp;
		}    
		for(int i = 0 ; i < len ; i++)
			tmpS[cnt[SA[i] + k < len ? RA[SA[i] + k] : 0]++] = SA[i];
		for(int i = 0 ; i < len ; i++)
			SA[i] = tmpS[i];           
	}
	void buildSA(){
		s += '$';
		len = sz(s);
		for(int i = 0 ; i < len ; i++){
			SA[i] = i;
			RA[i] = s[i];
		}
		for(int lg = 1 ; lg < len ; lg <<= 1){
			radixSort(lg);
			radixSort(0);
			int tot = 0;
			tmpR[SA[0]] = 0;
			for(int i = 1 ; i < len ; i++)
				tmpR[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && SA[i] + lg < len && SA[i - 1] + lg < len 
								&& RA[SA[i] + lg] == RA[SA[i - 1] + lg]) ? tot : ++tot;
			
			for(int i = 0 ; i < len ; i++)
				RA[i] = tmpR[i];
			if(RA[SA[len - 1]] == len - 1) break;                        
		}
	}

	void buildLCP(){
		phi[SA[0]] = -1;
		for(int i = 1 ; i < len ; i++)
			phi[SA[i]] = SA[i - 1];
		for(int i = 0, l = 0 ; i < len ; i++){
			if(phi[i] == -1)
				PLCP[i] = 0;
			else{
				while(s[i + l] == s[phi[i] + l]) l++;
				PLCP[i] = l;
				l = max(0,l - 1);
			}    
		}
		for(int i = 0 ; i < len ; i++)
			LCP[i] = PLCP[SA[i]];
	}

};
//SA[x] = y -> rank ke x adalah indeks y

suffixArray ini; 

int n, par[mx], sz[mx], sudah[mx];
string ss, s;

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> ss >> s;
	int exist = 0;
	for(auto i : s)  if(i == '0') exist = 1;
	if(!exist){
		cout << 0 << endl;
		return 0;
	}
	reverse(ALL(ss));
	reverse(ALL(s));
	ini.init(ss);
	ss += '$';
	ini.buildSA();
	ini.buildLCP();
	int ada = 0, mini = 1e9;
	vector<int> ve;
	for(int i = 1; i < ini.len; i++){
		if(ada == 0){
			if(s[ini.SA[i]] == '1') continue;
			ada = 1;
			mini = 1e9;
		}
		else{
			if(s[ini.SA[i]] == '1'){
				mini = min(mini, ini.LCP[i]);
				continue;
			}
			mini = min(mini, ini.LCP[i]);
			ve.pb(mini);
			mini = 1e9;
		}
	}
	for(int i = 0; i < sz(ve); i++) par[i] = i, sz[i] = 1;
	vector<int> lala(sz(ve));
	iota(ALL(lala), 0);
	long long jaw = 0;
	for(int i = 0; i < sz(s); i++){
		if(s[i] == '0'){
			jaw = sz(s) - i;
			break;
		}
	}
	sort(ALL(lala), [&](int x, int y){
		return ve[x] > ve[y];
	});
	for(int i : lala){
		if(i > 0 && sudah[i - 1]){
			int x = find(i - 1);
			int y = find(i);
			par[x] = y;
			sz[y] += sz[x];
		}
		if(i + 1 < sz(ve) && sudah[i + 1]){
			int x = find(i + 1);
			int y = find(i);
			par[x] = y;
			sz[y] += sz[x];
		}
		sudah[i] = 1;
		jaw = max(jaw, 1LL * ve[i] * (sz[find(i)] + 1));
	}
	cout << jaw << endl;
}