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

vector<ld>quadratic_equation(ld A,ld B,ld C){
    const ld eps=1e-9;
    if(B*B-4*A*C<-eps){
        return vector<ld>();
    }else if(B*B-4*A*C>eps){
        ld bo=2*A;
        ld x=-B;
        ld y=sqrt(B*B-4*A*C);
        auto vv= vector<ld>{(x-y)/bo,(x+y)/bo};
        sort(vv.begin(),vv.end());
        return vv;
    }else{
        return vector<ld>{-B/(2*A)};
    }
}
ll aget(ll A,ll B){
    assert(B<100000);
    return -B*B*B+B*A;
}
struct project{
    ll A;
    ll max_B;
    project(ll _A):A(_A){
        ll kou_B=ll(sqrt(ld(A)/3));
        if(aget(A,kou_B)<aget(A,kou_B+1)){
            kou_B++;
        }
        max_B=kou_B;
    }
};
vector<ll> aget(ll ok_down,const vector<project>&pros,bool to_up,int rest=0){
    vector<ll>answers;
    for(auto& pro:pros){
        ll A=pro.A;
        ll aB;
        WHATS(A)
        WHATS(to_up)
        if(to_up){
            
            ld ok_b=quadratic_equation(3,3,-A+1-ok_down)[1];
            if(ok_b>1e7)ok_b=1e7;
            if(ok_b<-1e7)ok_b=-1e7;
            aB=min(A,ll(ok_b+1e-9));
            //WHATS(aB)
            //WHATS(A)
            if(A!=aB){
                
                assert(3*aB*aB+3*aB-A+1<=ok_down);
                assert(3*(aB+1)*(aB+1)+3*(aB+1)-A+1>ok_down);
            }
            if(3*aB*aB+3*aB-A+1==ok_down&&rest){
                WHATS(pro.max_B);
                rest--;
                aB--;
            }
        }else{
            auto mmm=quadratic_equation(-3,3,A-1-ok_down);
            ld ng_b=(mmm.empty()) ? -3 : mmm.front();
            if(ng_b>1e7)ng_b=1e7;
            if(ng_b<-1e7)ng_b=-1e7;
            
            aB=max(0ll,ll(ng_b-1e-9+1));
            WHATS(mmm)
            WHATS(aB);
            WHATS(ok_down)
            if(aB!=0){
                
                assert(-3*aB*aB+3*aB+A-1<=ok_down);
                assert(aB==0||-3*(aB-1)*(aB-1)+3*(aB-1)+A-1>ok_down);
            }
            if(-3*aB*aB+3*aB+A-1<=ok_down==ok_down&&rest){
                rest--;
                aB++;
            }
        }
        answers.push_back(aB);
    }
    return answers;
}
ll get_sum(ll ok_down,const vector<project>&pros,bool to_up){
    auto vs=aget(ok_down,pros,to_up);
    return accumulate(vs.begin(),vs.end(),0ll);
}


int H,W;
ll memo[10000][100][2];
void cl(int x,int need=-1){
    if(need==-1)need=H*W;
    for(int i=0;i<need;++i){
        {
            for(int k=0;k<100;++k){
                memo[i][k][x]=2e18;
            }
        }
    }
}
int main() {
    //for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    if(N<=2){
        cout<<-1<<endl;
    }else{
        vector<vector<int>>field(N,vector<int>(N,-1));
        bool flag=N%2;
        int now=1;
        for(int y=0;y<N-2;++y){
            if(!flag){
                for(int x=0;x<N;++x){
                    field[y][x]=now++;
                }
            }else{
                for(int x=0;x<N;x++){
                    field[y][N-1-x]=now++;
                }
            }
            flag=!flag;
        }
        for(int x=0;x<N-3;++x){
            if(x%2==0){
                field[N-2][x]=now++;
                field[N-1][x]=now++;
            }else{
                field[N-1][x]=now++;
                field[N-2][x]=now++;

            }
        }
        vector<int>xs={N-2,N-1,N-2,N-3,N-1,N-3};
        vector<int>ys={N-1,N-1,N-2,N-2,N-2,N-1};
        if(N%2==1){
            for(auto&y:ys)y=2*N-3-y;
        }
            for(int i=0;i<6;++i){
                field[ys[i]][xs[i]]=now++;
            }
        
        if(N==3){
            field=vector<vector<int>>{
                {1,2,4},
                {7,3,8},
                {9,6,5}
            };
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cout<<field[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}