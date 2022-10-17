//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
#define mod 998244353
struct S{
	int a[102][102];
}tr,D,I;
int n,m,t;
inline S operator*(const S &x,const S &y){
	S z;
	F(i,1,n)F(j,1,n){
		unsigned ll sum=0;
		F(k,1,n){
			sum=sum+1ull*x.a[i][k]*y.a[k][j];
			if(!(k&15))sum%=mod;
		}
		z.a[i][j]=sum%mod;
	}
	return z;
}
inline S operator+(const S &x,const S &y){
	S z;
	F(i,1,n)F(j,1,n)z.a[i][j]=(x.a[i][j]+y.a[i][j])%mod;
	return z;
}
struct T{
	S a[3][3];
}base,trans,TI;
inline T operator*(const T &x,const T &y){
	T z;
	memset(z.a,0,sizeof(z.a));
	F(i,0,2)F(j,0,2){
		F(k,0,2)z.a[i][j]=z.a[i][j]+x.a[i][k]*y.a[k][j];
	}
	return z;
}
inline T pw(T x,int p){
	T rt=TI;
	while(p){
		if(p&1)rt=rt*x;
		x=x*x;
		p>>=1;
	}
	return rt;
}
int main() {
	cin>>n>>m>>t;
	F(i,1,n)I.a[i][i]=1;
	F(i,0,2)TI.a[i][i]=I;
	F(i,1,m){
		int x=read(),y=read();
		tr.a[x][y]=1;
		D.a[y][y]=(D.a[y][y]+mod-1)%mod;
		swap(x,y);
		tr.a[x][y]=1;
		D.a[y][y]=(D.a[y][y]+mod-1)%mod;
	}
	base.a[0][2]=I;
	trans.a[0][1]=trans.a[1][0]=trans.a[2][0]=I;
	trans.a[0][2]=D,trans.a[1][2]=trans.a[2][2]=tr;
	ll ans=0;
	trans=base*pw(trans,t);
	F(i,1,n)ans+=trans.a[0][2].a[i][i];//F(i,1,n)F(j,1,n)cerr<<trans.a[0][2].a[i][j]<<" \n"[j==n];
	cout<<ans%mod;
	return 0;
}
/*
4 5 3
1 3
4 2
4 1
2 1
3 4

*/