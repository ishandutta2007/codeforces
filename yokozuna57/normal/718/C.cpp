#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

const ll M = 1000000007;

struct matrix{
	ll a; ll b;
	ll c; ll d;
	bool operator !=(matrix y) const {
		if(this->a != y.a)return true;
		if(this->b != y.b)return true;
		if(this->c != y.c)return true;
		if(this->d != y.d)return true;
		return false;
	}
};

matrix f(matrix x,matrix y){
	matrix ret;
	ret.a = x.a*y.a + x.b*y.c; ret.a %= M;
	ret.b = x.a*y.b + x.b*y.d; ret.b %= M;
	ret.c = x.c*y.a + x.d*y.c; ret.c %= M;
	ret.d = x.c*y.b + x.d*y.d; ret.d %= M;
	return ret;
}

matrix I[32];
void init(){
	I[0].a = 1; I[0].b = 0;
	I[0].c = 0; I[0].d = 1;
	I[1].a = 1; I[1].b = 1;
	I[1].c = 1; I[1].d = 0;
	for(int i = 2 ; i < 32 ; i ++){
		I[i].a = I[i-1].a*I[i-1].a + I[i-1].b*I[i-1].c; I[i].a %= M;
		I[i].b = I[i-1].a*I[i-1].b + I[i-1].b*I[i-1].d; I[i].b %= M;
		I[i].c = I[i-1].c*I[i-1].a + I[i-1].d*I[i-1].c; I[i].c %= M;
		I[i].d = I[i-1].c*I[i-1].b + I[i-1].d*I[i-1].d; I[i].d %= M;
	}
}

matrix matpow(int k){
	matrix ret = I[0];
	for(int t = 0 ; t < 30 ; t ++){
		if((k>>t)&1)ret = f(ret,I[t+1]);
	}
	return ret;
}

struct SEG{
	int siz;
	ll s[1<<18],t[1<<18];
	matrix u[1<<18];
	void init(){
		siz = 1<<17;
		rep(i,2*siz-1){
			s[i] = 0;
			t[i] = 0;
			u[i] = I[0];
		}
	}
	void run(){
		rrep(i,siz-1){
			s[i] = s[2*i+1]+s[2*i+2]; if(s[i] >= M)s[i] %= M;
			t[i] = t[2*i+1]+t[2*i+2]; if(t[i] >= M)t[i] %= M;
		}
	}
	void updata(int a,int b,matrix x,int k,int l,int r){
		if(b <= l || r <= a)return;
		if(a <= l && r <= b){
			ll S = s[k]*x.a + t[k]*x.b; S %= M;
			ll T = s[k]*x.c + t[k]*x.d; T %= M;
			s[k] = S;
			t[k] = T;
			u[k] = f(u[k],x);
			return;
		}
		if(u[k] != I[0]){
			updata(l,r,u[k],2*k+1,l,(l+r)/2);
			updata(l,r,u[k],2*k+2,(l+r)/2,r);
			u[k] = I[0];
		}
		updata(a,b,x,2*k+1,l,(l+r)/2);
		updata(a,b,x,2*k+2,(l+r)/2,r);
		s[k] = s[2*k+1]+s[2*k+2]; if(s[k] >= M)s[k] %= M;
		t[k] = t[2*k+1]+t[2*k+2]; if(t[k] >= M)t[k] %= M;
	}
	ll sum(int a,int b,int k,int l,int r){
		if(b <= l || r <= a)return 0;
		if(a <= l && r <= b)return s[k];
		if(u[k] != I[0]){
			updata(l,r,u[k],2*k+1,l,(l+r)/2);
			updata(l,r,u[k],2*k+2,(l+r)/2,r);
			u[k] = I[0];
		}
		ll vl = sum(a,b,2*k+1,l,(l+r)/2);
		ll vr = sum(a,b,2*k+2,(l+r)/2,r);
		ll ret = vl+vr; if(ret >= M)ret %= M;
		return ret;
	}
}seg;

int main(){
	init();
	seg.init();
	
	static int n,m;
	static int a[100010];
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n){
		matrix mat = matpow(a[i]-1);
		seg.s[i+seg.siz-1] = mat.a;
		seg.t[i+seg.siz-1] = mat.c;
	}
	seg.run();
	
	rep(ppp,m){
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		l --;
		if(t == 1){
			int x;
			scanf("%d",&x);
			matrix mat = matpow(x);
			seg.updata(l,r,mat,0,0,seg.siz);
		}
		else {
			printf("%I64d\n",seg.sum(l,r,0,0,seg.siz));
		}
		
		/*rep(i,n){
			printf("%I64d ",seg.sum(i,i+1,0,0,seg.siz));
		}*/
	}
}