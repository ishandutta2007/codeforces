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
int x,y;
vector<int>a,b,c,d,ans;
int main() {
	F(asfd,1,read()){ans.clear();
		read(x);read(y);
		a.clear(),b.clear(),c.clear(),d.clear();
		--x;--y;
		F(i,1,sqrt(x)){
			if(x%i==0){
				a.push_back(i);
				b.push_back(x/i);
				if((y+1)%i==0&&(y-1)%i==0)ans.push_back(i);
				if((y+1)%(x/i)==0&&(y-1)%(x/i)==0)ans.push_back(x/i);
			}
		}
		F(i,1,sqrt(y)){
			if(y%i==0){
				c.push_back(i);
				d.push_back(y/i);
				if((x+1)%i==0&&(x-1)%i==0)ans.push_back(i);
				if((x+1)%(y/i)==0&&(x-1)%(y/i)==0)ans.push_back(y/i);
			}
		}
		reverse(b.begin(),b.end());
		reverse(d.begin(),d.end());
		for(auto i:b)a.push_back(i);
		for(auto i:d){
			c.push_back(i);
		}
		{
		int x=0,y=0;
		while(x<a.size()&&y<c.size()){
			if(a[x]==c[y])ans.push_back(a[x]),++x,++y;
			else if(a[x]<c[y])++x;
			else ++y;
		}	
		}
		a.clear(),b.clear(),c.clear(),d.clear();
		--x;++y;
		F(i,1,sqrt(x)){
			if(x%i==0){
				a.push_back(i);
				b.push_back(x/i);
			}
		}
		F(i,1,sqrt(y)){
			if(y%i==0){
				c.push_back(i);
				d.push_back(y/i);
			}
		}
		reverse(b.begin(),b.end());
		reverse(d.begin(),d.end());
		for(auto i:b)a.push_back(i);
		for(auto i:d){
			c.push_back(i);
		}
		{
		int x=0,y=0;
		while(x<a.size()&&y<c.size()){
			if(a[x]==c[y])ans.push_back(a[x]),++x,++y;
			else if(a[x]<c[y])++x;
			else ++y;
		}	
		}
		a.clear(),b.clear(),c.clear(),d.clear();
		x+=2;y-=2;
		F(i,1,sqrt(x)){
			if(x%i==0){
				a.push_back(i);
				b.push_back(x/i);
			}
		}
		F(i,1,sqrt(y)){
			if(y%i==0){
				c.push_back(i);
				d.push_back(y/i);
			}
		}
		reverse(b.begin(),b.end());
		reverse(d.begin(),d.end());
		for(auto i:b)a.push_back(i);
		for(auto i:d){
			c.push_back(i);
		}
		{
		int x=0,y=0;
		while(x<a.size()&&y<c.size()){
			if(a[x]==c[y])ans.push_back(a[x]),++x,++y;
			else if(a[x]<c[y])++x;
			else ++y;
		}	
		}
		sort(ans.begin(),ans.end());
		ans.resize(unique(ans.begin(),ans.end())-ans.begin());
		write(ans.size(),' ');
		for(auto i:ans)write(i,' ');
		puts("");
	}
	return 0;
}