#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const ll MOD = 1000000007;

#define fr first
#define sc second

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= MOD;
	if(k%2 == 1){
		ret *= x;
		ret %= MOD;
	}
	return ret;
}

int n,m;
vector<P> G[100010];

P color[100010];
bool used[100010];
bool ok[100010];
int ng[100010][32];
void dfs(int v,int par,P c){
	if(used[v]){
		ng[c.fr][c.sc^color[v].sc] ++;
		return;
	}
	used[v] = true;
	color[v] = c;
	for(int i = 0 ; i < G[v].size() ; i ++){
		if(G[v][i].fr == par)continue;
		P p = c;
		p.sc ^= G[v][i].sc;
		dfs(G[v][i].fr,v,p);
	}
}

int CNT = 0;
ll st[1000010];
map<ll,int> M;
int nex[1000010][32];
int att(ll x){
	map<ll,int>::iterator itr = M.find(x);
	if(itr != M.end())return itr->sc;
	st[CNT] = x;
	M[x] = CNT;
	int memo = CNT;
	CNT ++;
	for(int i = 0 ; i < 32 ; i ++){
		ll nx = x;
		for(int j = 0 ; j < 32 ; j ++){
			if((1LL<<j)&x){
				if((1LL<<(i^j))&x){
					nx = -1;
					break;
				}
				else {
					nx |= 1LL<<(i^j);
				}
			}
		}
		if(nx == -1){
			nex[memo][i] = -1;
		}
		else {
			nex[memo][i] = att(nx);
		}
	}
	return memo;
}

int cnt[100010][32] = {};

int main(){
	att(1);
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < m ; i ++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		if(a>b)swap(a,b);
		G[a].push_back(P(b,w));
		if(a != 1)G[b].push_back(P(a,w));
		/*if(m == 59){
			cout << a << " " << b << " " << w << " ";
		}*/
	}
	for(int i = 1 ; i <= n ; i ++){
		used[i] = false;
		ok[i] = true;
		for(int j = 0 ; j < 32 ; j ++){
			ng[i][j] = 0;
		}
	}
	static vector<int> vec[100010];
	for(int i = 0 ; i < G[1].size() ; i ++){
		int v = G[1][i].fr;
		if(!used[v]){
			dfs(v,0,P(v,0));
		}
	}
	
	/*for(int i = 1 ; i <= n ; i ++){
		cout << color[i].fr << " " << color[i].sc << endl;
	}*/
	
	for(int i = 0 ; i < G[1].size() ; i ++){
		int v = G[1][i].fr;
		int w = color[v].fr;
		int t = color[v].sc;
		/*int pre = -1;
		while(pre != t){
			pre = t;
			for(int j = 0 ; j < 32 ; j ++){
				if(ng[w][j] == 0)continue;
				if((t^j)<t)t ^= j;
			}
		}*/
		vec[w].push_back(t^G[1][i].sc);
	}
	/*vector<P> xx;
	for(int i = 0 ; i < CNT ; i ++){
		for(int j = i ; j < CNT ; j ++){
			if(i == j)continue;
			if((st[i]&st[j])==st[i])xx.push_back(P(i,j));
		}
	}
	int CNT2 = xx.size();*/
	static ll dp[2][400][33] = {};
	int t = 0, t_ = 1;
	dp[t][0][32] = 1;
	for(int i = 0 ; i < G[1].size() ; i ++){
		vector<int> ss;
		ss.push_back(32);
		int v = G[1][i].fr;
		int loc = 0;
		vector<int> vv;
		for(int j = 0 ; j < 32 ; j ++){
			if(ng[v][j] == 0)continue;
			if(ng[v][j] > 2){
				loc = -1;
				break;
			}
			//if(nex[loc][j] != -1){
				loc = nex[loc][j];
				//cout << j << " " << loc << endl;
				vv.push_back(j);
			//}
			if(loc == -1)break;
		}
		if(loc == -1)continue;
		/*cout << i << endl;
		for(int j = 0 ; j < vv.size() ; j ++){
			cout << vv[j] << " ";
		}
		cout << endl;*/
		/*if(m == 59 && vec[v].size() > 0){
			cout << "v=" << v << endl;
			for(int j = 0 ; j < vv.size() ; j ++){
				cout << vv[j] << " ";
			}cout << endl;
			for(int j = 0 ; j < vec[v].size() ; j ++){
				cout << vec[v][j] << " ";
			}cout << endl;
		}*/
		for(int j = 0 ; j < vec[v].size() ; j ++){
			/*for(int k = 0 ; k < CNT ; k ++){
				for(int l = 0 ; l <= 32 ; l ++){
					dp[t_][k][l] = 0;
				}
			}*/
			//cout << i << " " << j << endl;
			for(int k = 0 ; k < CNT ; k ++){
				for(int l = 0 ; l < ss.size() ; l ++){
					dp[t_][k][ss[l]] = dp[t][k][ss[l]];
				}
			}
			for(int k = 0 ; k < CNT ; k ++){
				int hoge = ss.size();
				for(int l = 0 ; l < hoge ; l ++){
					if(ss[l] == 32){
						int loc = k;
						for(int s = 0 ; s < vv.size() ; s ++){
							loc = nex[loc][vv[s]];
							if(loc == -1)break;
						}
						//if(loc != -1)loc = nex[loc][vec[v][j]];
						if(loc != -1){
							bool ne = true;
							for(int ll = 0 ; ll < ss.size() ; ll ++){
								if(ss[ll] == vec[v][j]){
									ne = false;
									break;
								}
							}
							if(!ne){
								dp[t_][loc][vec[v][j]] += dp[t][k][32];
								if(dp[t_][loc][vec[v][j]] >= MOD)dp[t_][loc][vec[v][j]] -= MOD;
							}
							else{
								for(int kk = 0 ; kk < CNT ; kk ++){
									dp[t_][kk][vec[v][j]] = 0;
								}
								dp[t_][loc][vec[v][j]] = dp[t][k][32];
								ss.push_back(vec[v][j]);
							}
						}
					}
					else {
						int loc = k;
						loc = nex[loc][vec[v][j]^ss[l]];
						if(loc != -1){
							dp[t_][loc][ss[l]] += dp[t][k][ss[l]];
							if(dp[t_][loc][ss[l]] >= MOD)dp[t_][loc][ss[l]] -= MOD;
						}
					}
				}
			}
			swap(t,t_);
			int ccc = 0;
			for(int k = 0 ; k < CNT ; k ++){
				for(int l = 0 ; l < ss.size() ; l ++){
					ccc += dp[t][k][ss[l]];
					//if(m == 59 && dp[t][k][ss[l]] != 0)cout << k << " " << ss[l] << " " << dp[t][k][ss[l]] << endl;
				}
			}
			//if(m == 59)cout << "ccc=" << ccc << endl;
		}
		int ccc = 0;
		for(int j = 0 ; j < CNT ; j ++){
			dp[t_][j][32] = 0;
			for(int k = 0 ; k < ss.size() ; k ++){
				dp[t_][j][32] += dp[t][j][ss[k]];
			}
			dp[t_][j][32] %= MOD;
			ccc += dp[t_][j][32];
			/*for(int k = 0 ; k < 32 ; k ++){
				dp[t_][j][k] = 0;
			}*/
		}
		/*if(m == 59){
			cout << ccc << endl;
		}*/
		swap(t,t_);
	}
	ll ret = 0;
	for(int i = 0 ; i < CNT ; i ++){
		ret += dp[t][i][32];
	}
	ret %= MOD;
	cout << ret << endl;
	
	/*int T = 0;
	for(int i = 0 ; i < CNT ; i ++){
		for(int j = i ; j < CNT ; j ++){
			if(i == j)continue;
			if((st[i]&st[j])==st[i])T++;
		}
	}
	cout << T << endl;*/
}