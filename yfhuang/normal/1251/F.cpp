#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vi poly;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vi poly;
const int mod=998244353;

int qpow(int a, int n){
    int ans = 1;
    while(n > 0){
        if(n & 1){
            ans = 1LL * ans * a % mod; 
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ans;
}

namespace Poly{
	const int N=(1<<20)+5,g=3;
	inline int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	inline int fix(const int x){
		return x>=mod?x-mod:x;
	}
	void dft(poly &A,int n){
		static ull W[N<<1],*H[30],*las=W,mx=0;
		for(;mx<n;mx++){
			H[mx]=las;ull w=1,wn=power(g,(mod-1)>>(mx+1));
			REP(i,1<<mx)*las++=w,w=w*wn%mod;
		}
		if(A.size()!=(1<<n))A.resize(1<<n);
		static ull a[N];
		for(int i=0,j=0;i<(1<<n);++i){
			a[i]=A[j];
			for(int k=1<<(n-1);(j^=k)<k;k>>=1);
		}
		for(int k=0,d=1;k<n;k++,d<<=1)
			for(int i=0;i<(1<<n);i+=(d<<1)){
				ull *l=a+i,*r=a+i+d,*w=H[k],t;
				for(int j=0;j<d;j++,l++,r++){
					t=(*r)*(*w++)%mod;
					*r=*l+mod-t,*l+=t;
				}
			}
		REP(i,1<<n)A[i]=a[i]%mod;
	}
	void idft(poly &a,int n){
		a.resize(1<<n),reverse(a.begin()+1,a.end());
		dft(a,n);int inv=power(1<<n,mod-2);
		REP(i,1<<n)a[i]=(ll)a[i]*inv%mod;
	}
	poly FIX(poly a){
		while(!a.empty()&&!a.back())a.pop_back();
		return a;
	}
	poly mul(poly a,poly b,int t=1){
		if(t==1&&a.size()+b.size()<=24){
			poly c(a.size()+b.size(),0);
			REP(i,a.size())REP(j,b.size())
				c[i+j]=(c[i+j]+(ll)a[i]*b[j])%mod;
			return FIX(c);
		}
		int n=1,aim=a.size()*t+b.size();
		while((1<<n)<=aim)n++;
		dft(a,n),dft(b,n);
		if(t==1)REP(i,1<<n)a[i]=(ll)a[i]*b[i]%mod;
		else REP(i,1<<n)a[i]=(ll)a[i]*a[i]%mod*b[i]%mod;
		idft(a,n),a.resize(aim);
		return FIX(a);
	}
}
using namespace Poly;
const int maxn = N;
int fac[maxn], inv[maxn];

void pre_comb(){
    fac[0] = 1;
    for(int i = 1;i < maxn;i++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for(int i = maxn - 2;i >= 0;i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
}

int comb(int n, int m){
    if(m > n or m < 0) return 0;
    return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int n, k;
int a[maxn], b[maxn];
int Q;
int q[maxn];
int cnt[maxn];
int dp[maxn];

int main(){
    pre_comb();
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }
    for(int i = 1;i <= k;i++){
        scanf("%d", &b[i]);
    }
    cin >> Q;
    for(int i = 1;i <= Q;i++){
        scanf("%d", &q[i]);
    }
    //cout << "!!!" << endl;
    for(int i = 1;i <= k;i++){
        int m1 = 0, m2 = 0;
        for(int j = 1;j < b[i];j++){
            if(cnt[j] == 1)
               m1++;
            if(cnt[j] > 1)
               m2++; 
        } 
        poly p1(m1 + 1, 0), p2(m2 * 2 + 1, 0);
        for(int j = 0;j <= m1;j++){
            p1[j] = 1LL * comb(m1, j) * qpow(2, j) % mod;
        }
        for(int j = 0;j <= 2 * m2;j++){
            p2[j] = 1LL * comb(2 * m2, j);
        }
        poly ans = mul(p1, p2);
        for(int j = 0;j <= m1 + 2 * m2;j++){
            dp[b[i] + 1 + j] = (dp[b[i] + 1 + j] + ans[j]) % mod;    
        }
    }
    //cout << "!!!" << endl;
    for(int i = 1;i <= Q;i++){
        printf("%d\n", dp[q[i] / 2]);
    }
    return 0;
}