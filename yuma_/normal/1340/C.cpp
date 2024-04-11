#define _CRT_SECURE_NO_WARNINGS
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
#include<memory>
#include<numeric>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
    
using namespace std;
    
using ll=long long;
using ld =long double;
    
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
using Graph=vector<vector<int>>;
pair<int,int>dfs(const Graph&g,int now,int from){
    pair<int,int>p;
    p.first=1;
    for(auto e:g[now]){
        if(e==from)continue;
        auto ap=dfs(g,e,now);
        p.first+=ap.second;
        p.second+=max(ap.first,ap.second);
    }
    return p;
}


const int mod = 998244353;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
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
Mod mod_pow(const Mod a, const long long  n) {
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
int have_rs[int(1e6)+1];
bool check(int x){
    if(x<0||x>int(1e6))return -1;
    else{
        return have_rs[x];
    }
}
int main() {
    for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    init();
    ios::sync_with_stdio(false);
    cin.tie();
    int N,M;cin>>N>>M;
    vector<int>rs(M);
    for(int i=0;i<M;++i){
        int r;cin>>r;
        rs[i]=r;
    }
    sort(rs.begin(),rs.end());
    ll G,R;cin>>G>>R;

    vector<vector<ll>>costs(M,vector<ll>(G,ll(1e16)));
    costs[0][0]=0;
    deque<pair<int,int>>que;
    que.emplace_back(make_pair(0,0));
    while(!que.empty()){
        auto p=que.front();
        que.pop_front();
        //WHATS(p)
        int now=p.first;
        int use=p.second;
        
        if(now){
            int place=now-1;
            int n_use=use+abs(rs[now]-rs[place]);
            if(n_use<=G){
                ll n_cost=costs[now][use]+abs(rs[now]-rs[place]);
                int nn=n_use;
                bool flag=false;
                if(n_use==G){
                    nn=0;
                    n_cost+=R;
                    flag=true;
                }

                if(costs[place][nn]>n_cost){
                    costs[place][nn]=n_cost;
                    if(flag)que.emplace_back(make_pair(place,nn));
                    else que.emplace_front(make_pair(place,nn));
                }
            }
        }
        if(now!=M-1){
            int place=now+1;
            int n_use=use+abs(rs[now]-rs[place]);
            if(n_use<=G){
                ll n_cost=costs[now][use]+abs(rs[now]-rs[place]);
                int nn=n_use;
                bool flag=false;
                if(n_use==G){
                    nn=0;
                    n_cost+=R;
                    flag=true;
                }

                if(costs[place][nn]>n_cost){
                    costs[place][nn]=n_cost;
                    if(flag)que.emplace_back(make_pair(place,nn));
                    else que.emplace_front(make_pair(place,nn));
                }
            }
        }
    }
    //WHATS(costs)
    
    ll answer=1e18;
    costs[M-1][0]-=R;
    for(int i=0;i<G;++i){
        if(costs[M-1][i]<=ll(1e15)){
            answer=min(answer,costs[M-1][i]);
        }
    }
    if(answer>=ll(1e17)){
        answer=-1;
    }
    cout<<answer<<endl;
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14