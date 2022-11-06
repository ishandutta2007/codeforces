#include <bits/stdc++.h>

using namespace std;



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
Mod dp[200001];
Mod dp2[200001];
vector<Mod>ls[200001],rs[200001];

Mod dfs(int now,const vector<vector<int>>&edges){
    Mod sum=Mod(1);
    for(auto e:edges[now]){
        Mod x=dfs(e,edges);
        sum*=x;
    }
    dp[now]=sum;
    return dp[now]+(Mod(1));
}
void  dfs2(int now,int from,int k,Mod mo,const vector<vector<int>>&edges){
    ls[now].push_back(Mod(1));
    rs[now].push_back(Mod(1));
    
    if(!edges[now].empty()){
        for(auto e:edges[now]){
            ls[now].push_back(ls[now].back()*(dp[e]+Mod(1)));
        }
        for(int i=edges[now].size()-1;i>=0;--i){
            rs[now].push_back(rs[now].back()*(dp[edges[now][i]]+Mod(1)));
        }
    }
    
    reverse(rs[now].begin(),rs[now].end());
    Mod pa=0;
    if(now==0){
        dp2[now]=dp[now];
    }else{
        pa=ls[from][k]*rs[from][k+1];
        for(int i=0;i<3;++i){
            //cout<<ls[from][i]<<endl;
            //cout<<rs[from][i]<<endl;
        }
        dp2[now]=(mo*pa+Mod(1))*dp[now];

    }
    for(int i=0;i<edges[now].size();++i){
       // cout<<pa.num<<endl;
        dfs2(edges[now][i],now,i,mo*pa+Mod(1),edges);
    }

    
}
int main(){

    int N;cin>>N;
    vector<vector<int>>edges(N);
    for(int i=0;i<N-1;++i){
        int a;scanf("%d",&a);
        a--;
        edges[a].push_back(i+1);
    }
    dfs(0,edges);
    //cout<<1<<endl;
    //cout<<dp[0].num<<endl;
    dfs2(0,-1,0,Mod(1),edges);
    //cout<<1<<endl;
    for(int i=0;i<N;++i){
        printf("%d ",dp2[i].num);
    }
    cout<<endl;
    return 0;
}