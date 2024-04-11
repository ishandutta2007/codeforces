#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
	
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}
	
using ll=long long ;
	
	
const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};
	
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}
	
#define MAX_MOD_N 402400
	
Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}
void solve(const vector<vector<int>>watchs){
	int N=watchs.size();
	vector<int>comes(N);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(watchs[i][j]){
				comes[j]++;
			}
		}
	}
	queue<int>que;
	for(int i=0;i<N;++i){
		if(!comes[i]){
			que.emplace(i);
		}
	}
	vector<int>anss;
	while(!que.empty()){
		int now(que.front());
		que.pop();
		anss.push_back(now+1);
		for(int i=0;i<N;++i){
			if(watchs[now][i]){
				comes[i]--;
				if(!comes[i]){
					que.emplace(i);
				}
			}
		}
	}
	if(anss.size()!=N)anss.clear();
	if(anss.empty()){
		cout<<-1<<endl;
	}else{
		for(int i=0;i<N;++i){
			cout<<anss[i]<<' ';
		}
		cout<<endl;
	}
}
struct person{
	int x;
	int y;
	int a;
	int r;
};
bool watch(person l,person r){
	int dx=r.x-l.x;
	int dy=r.y-l.y;
	const ld pi=acos(-1.0);
	ld theta=atan2(dy,dx);
	ld kaku=theta/pi*180;
	
	ld dis=l.a-kaku;
	while(dis>=180)dis-=360;
	while(dis<=-180)dis+=360;
	//WHATS(dis);
	if(abs(dis)<l.r+1e-9)return true;
	else return false;
}
int memo[41][41][41][41];

void solve(){
	int H,W,Q;cin>>H>>W>>Q;
	vector<string>field(H);
	for(int i=0;i<H;++i)cin>>field[i];
	vector<vector<int>>nums(H,vector<int>(W));
	for(int y=0;y<H;++y){
		for(int x=0;x<W;++x){
			if(field[y][x]=='1'){

			}else{
				if(y==0)nums[y][x]=1;
				else nums[y][x]=nums[y-1][x]+1;
			}
		}
	}
	//WHATS(nums)
	for(int d=H;d>=1;--d){
		for(int u=0;u<d;++u){
			for(int l=0;l<W;++l){
				deque<pair<int,int>>que;
				for(int r=l+1;r<=W;++r){
					int h=min(d-u,nums[d-1][r-1]);
					pair<int,int>p=make_pair(h,r-1);
					
					while(true){
						if(!que.empty()&&que.back().first>=h){
							p=make_pair(h,que.back().second);
							que.pop_back();
						}else{
							que.emplace_back(p);
							break;
						}
					}
					memo[u][d][l][r]=memo[u][d][l][r-1];
					for(auto it=que.begin();it!=que.end();++it){
						int ah=it==que.begin()?it->first:it->first-(prev(it))->first;
						//WHATS(ah)
						//WHATS(it->second)
						memo[u][d][l][r]+=ah*(r-it->second);
					}
				}	
			}
		}
		
	}
	// for(int i=0;i<=H;++i){
	// 	for(int j=0;j<=H;++j){
	// 		for(int k=0;k<=W;++k){
	// 			for(int l=0;l<=W;++l){
	// 				cout<<memo[i][j][k][l]<<' ';
	// 			}
	// 			cout<<endl;
	// 		}
	// 	}
	// }
	while(Q--){
		int u,l,d,r;cin>>u>>l>>d>>r;
		u--;
		l--;
		ll ans=0;
		for(int y=u+1;y<=d;++y){
			ans+=memo[u][y][l][r];
			//WHATS(memo[u][y][l][r]);
		}
		cout<<ans<<endl;
	}
	
}
int main() {
	solve();

	return 0;
}