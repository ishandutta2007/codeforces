#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
 
#define fr first
#define sc second
#define mp1(a,b,c) P1(a,P(b,c))
 
const ll MOD = 998244353;
 
int CNT = 0;
vector<int> RET[1000000];
 
void add(vector<int> vec){
	sort(vec.begin(),vec.end());
	for(int i = 0 ; i < CNT ; i ++){
		if(RET[i] == vec)return;
	}
	RET[CNT++] = vec;
}
 
vector<int> f(vector<int> vec){
	sort(vec.begin(),vec.end());
	int pre = vec[0];
	int cnt = 1;
	vector<int> ret;
	for(int i = 1 ; i < vec.size() ; i ++){
		if(vec[i] != pre){
			ret.push_back(cnt);
			pre = vec[i];
			cnt = 1;
		}
		else cnt ++;
	}
	ret.push_back(cnt);
	return ret;
}
 
ll n,k;
ll x[100];
int sum = 0;
ll len = 0;
int ret = 0;
void dfs(int i,int t){
	x[i] = t;
	sum += t*(t+1)*i/2;
	sum += len*t;
	len += t*i;
	if(sum > n){
		len -= t*i;
		sum -= len*t;
		sum -= t*(t+1)*i/2;
		return;
	}
	if(k == 3)ret ++;
	else {
		vector<int> vec;
		for(int j = 1 ; j <= i ; j ++){
			vec.push_back(x[j]);
		}
		for(int j = 0 ; j < k-3 ; j ++){
			vec = f(vec);
			if(vec.size() == 1 && vec[0] == 1)break;
		}
		add(vec);
	}
	for(int j = 1 ; j <= t ; j ++){
		dfs(i+1,j);
	}
	len -= t*i;
	sum -= len*t;
	sum -= t*(t+1)*i/2;
}
 
unordered_map<int,int> M[2022][2022];
void dfs2(const int &i, const int &t){
	sum += i*t;
	auto itr = M[i][sum].find(t);
	if(itr != M[i][sum].end()){
		ret += itr->sc;
		if(ret >= MOD)ret -= MOD;
		sum -= i*t;
		return;
	}
	int memo = ret;
	ret ++;
	if(ret >= MOD)ret -= MOD;
	itr = M[i][sum].begin();
	if(itr != M[i][sum].end() && itr->fr <= t){
	    ret += itr->sc-1;
	    if(ret >= MOD)ret -= MOD;
    	for(int j = itr->fr+1 ; sum+(i+1)*j <= n && j <= t ; j ++){
    		dfs2(i+1,j);
    	}
	}
	else {
    	for(int j = 1 ; sum+(i+1)*j <= n && j <= t ; j ++){
    		dfs2(i+1,j);
    	}
	}
	memo = ret-memo;
	if(memo < 0)memo += MOD;
	M[i][sum][t] = memo;
	sum -= i*t;
}
	
 
ll dp[2022][2022];
int main(){
	cin >> n >> k;
	
	if(k == 1){
		for(int i = 0 ; i < 2022 ; i ++){
			for(int j = 0 ; j < 2022 ; j ++){
				dp[i][j] = 0;
			}
		}
		dp[0][1] = 1;
		for(int i = 0 ; i < n ; i ++){
			for(int j = 1 ; j <= n ; j ++){
				if(i+j <= n){
					dp[i+j][j] += dp[i][j];
					if(dp[i+j][j] >= MOD)dp[i+j][j] -= MOD;
				}
			}
			if(i > 0){
				for(int j = 2 ; j <= n ; j ++){
					dp[i+1][j] += dp[i][j-1];
					if(dp[i+1][j] >= MOD)dp[i+1][j] -= MOD;
				}
			}
		}
		ret = 0;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= n ; j ++){
				ret += dp[i][j];
				if(ret >= MOD)ret -= MOD;
			}
		}
		cout << ret << endl;
		return 0;
	}
	if(k == 2){
		for(int i = n ; i >= 1 ; i --){
			dfs2(1,i);
		}
		cout << ret << endl;
		return 0;
	}
	
	for(int i = 1 ; ; i ++){
		if(i*(i+1)/2 > n)break;
		dfs(1,i);
	}
	if(k == 3)cout << ret << endl;
	else cout << CNT << endl;
}