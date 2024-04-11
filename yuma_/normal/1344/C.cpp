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
 
int main() {
    //for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    ios::sync_with_stdio(false);
    cin.tie();
    int N,M;cin>>N>>M;
    Graph g(N);
    Graph rev_g(N);
    Graph all_g(N);
    vector<int>comes(N);
    for(int i=0;i<M;++i){
        int u,v;cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        rev_g[v].push_back(u);
        all_g[u].push_back(v);
        all_g[v].push_back(u);
        comes[v]++;
    }
    bool ok=false;
    {
        vector<int>topos;
        queue<int>que;

        for(int i=0;i<N;++i){
            if(comes[i]==0){
                topos.push_back(i);
                que.emplace(i);
            }
        }
        while(!que.empty()){
            int now=que.front();
            que.pop();
            for(auto e:g[now]){
                comes[e]--;
                if(comes[e]==0){
                    topos.push_back(e);
                    que.emplace(e);
                }
            }
        }
        ok=topos.size()==N;
    }
    
    if(!ok){
        cout<<-1<<endl;
    }else{
        string answer;
        vector<int>flags(N);
        vector<int>ds(N),us(N);
        for(int i=0;i<N;++i){
            if(!flags[i]){
                answer.push_back('A');
                
                
            }else{
                
                answer.push_back('E');
            }

            queue<int>que;
            ds[i]=true;
            us[i]=true;
            flags[i]=true;
            que.emplace(i);
            while(!que.empty()){
                int now=que.front();
                que.pop();
                for(auto e:g[now]){
                    if(!ds[e]){
                        ds[e]=true;
                        flags[e]=true;
                        que.emplace(e);
                    }
                }
            }
            
            que.emplace(i);
            while(!que.empty()){
                int now=que.front();
                que.pop();
                us[now]=true;
                for(auto e:rev_g[now]){
                    if(!us[e]){
                        us[e]=true;
                        flags[e]=true;
                        que.emplace(e);
                    }
                }
            }
        }
        cout<<count(answer.begin(),answer.end(),'A')<<endl;
        cout<<answer<<endl;
    }
    return 0;
}