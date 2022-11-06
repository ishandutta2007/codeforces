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


const ll MAX_S=2e5;

vector<ll>check(vector<ll>&x){
    vector<ll>anss(x.size());
    for(int i=0;i<int(x.size())-1;++i){
        anss[i+1]=x[i+1]-x[i];
    }
    anss[0]=x[0];
    return anss;
}


using Value=ll;
const Value ini =ll(1e18);
// Value operator +(const Value&al,const Value&ar){
// 	return al+ar;
// }
Value connect(Value al,const Value ar){
	return min(al,ar);
}
Value dat[1100001];
struct segtree {
	int N;

	segtree() {}
	
	segtree(int n)  {
		N = 1;
		while (N < n) N *= 2;
		
		for(int x=0;x<N;++x){
			dat[x+N-1] = ini;
		}
		for(int x=N-2;x>=0;--x){
			dat[x]=connect(dat[x*2+1],dat[x*2+2]);
		}
	}
	// update k th element
	void update(int k,const Value& a) {
		 k += N - 1;
		dat[k] = a;
		
		while (k > 0) {
			k = (k - 1) >>1;
			dat[k]=connect(dat[k * 2 + 1],dat[k * 2 + 2]);
		}
	}
	// min [a, b)
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return ini;
		if (a <= l && r <= b) return dat[k];
		const int m = (l + r) / 2;
		return connect(query(a, b, k * 2 + 1, l, m),query(a, b, k * 2 + 2, m, r));
	}

	
};
vector<int>nums(int(3e5));
ll to_n(string st){
    ll num=0;
    for(auto c:st){
        num*=2;
        num+=c-'0';
    }
    return num;
}
string to_s(int sz,ll num){
    string st;
    for(int i=0;i<sz;++i){
        st.push_back('0'+(num%2));
        num/=2;
    }
    reverse(st.begin(),st.end());
    return st;
}



const int mod = 998244353;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		//static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
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

#define MAX_MOD_N 1024000

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

bool check(int a){
    for(int i=2;i*i<=a;++i){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    // int N;cin>>N;
    // vector<int>vs(N);
    // for(int i=0;i<N;++i)cin>>vs[i];
    // int need=accumulate(vs.begin(),vs.end(),0);
    // need=(need+2)/2;
    // vector<int>anss;
    // for(int i=0;i<N;++i){
    //     if(i==0||vs[i]*2<=vs[0]){
    //         anss.push_back(i);
    //         need-=vs[i];
    //     }
    // }
    // if(need<=0){
    //     cout<<anss.size()<<endl;
    //     for(int i=0;i<anss.size();++i){
    //         cout<<anss[i]+1<<' ';
    //     }
    //     cout<<endl;
    // }else{
    //     cout<<0<<endl;
    // }

    // string st;cin>>st;
    // int sum=0;
    // for(int i=0;i<st.size()-1;++i){
    //     if(st[i]=='v'&&st[i+1]=='v')sum++;
    // }
    // ll l_sum=0;
    // ll answer=0;
    // for(int i=0;i<st.size()-1;++i){
    //     if(st[i]=='v'&&st[i+1]=='v')l_sum++;

    //     if(st[i]=='o'){
    //         answer+=l_sum*(sum-l_sum);
    //     }
    // }
    // cout<<answer<<endl;

    // int H,W;cin>>H>>W;
    // ll answer=1;
    // const int mod=998244353;
    // for(int i=0;i<H*W;++i){
    //     answer*=2;
    //     answer%=mod;
    // }
    // cout<<answer<<endl;

    int N;cin>>N;
    vector<pair<int,int>>answers;
    for(int i=0;i<N;++i){
        answers.push_back(make_pair(i,(i+1)%N));
    }
    int x=0;
    while(!check(int(answers.size()))){
        answers.push_back(make_pair(x,x+N/2));
        x++;
    }
    cout<<answers.size()<<endl;
    for(auto ans:answers){
        cout<<ans.first+1<<' '<<ans.second+1<<endl;
    }
    return 0;
}