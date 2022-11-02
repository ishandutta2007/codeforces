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

int a[N], b[N];
int n, k;
int Q;

poly solve(int l, int r){
    if(l == r){
        return {1, b[l]};
    }
    int mid = (l + r) / 2;
    return mul(solve(l, mid), solve(mid + 1, r));
}

int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        a[i] %= mod;
    }
    cin >> Q;
    for(int t = 1;t <= Q;t++){
        int tp, q, id, d, L, R;
        scanf("%d", &tp);
        for(int i = 1;i <= n;i++){
            b[i] = a[i];
        }
        if(tp == 1){
            scanf("%d%d%d", &q, &id, &d);
            q %= mod;
            b[id] = d;
        }else{
            scanf("%d%d%d%d", &q, &L, &R, &d);
            q %= mod;
            for(int i = L;i <= R;i++){
                b[i] = (b[i] + d) % mod;
            }
        }
        for(int i = 1;i <= n;i++){
            b[i] = (q - b[i] + mod) % mod;
        }
        poly ret = solve(1, n);
        cout << ret[k] << endl;
    }
    return 0;
}