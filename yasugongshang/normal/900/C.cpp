#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=100005;
int n,a[N],f[N],g[N],mmax=-N,pos;
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
int main(){
	n=read(); 
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		it=s.lower_bound(mp(a[i],0)); 
		if(it==s.end())f[i]=1;
		else{
			it++; if(it==s.end())g[(*--it).second]++;
		}
		s.insert(mp(a[i],i));
	}
	for(int i=1;i<=n;i++){

		if(g[i]-f[i]>mmax||(g[i]-f[i]==mmax&&a[i]<a[pos])){
			pos=i; mmax=g[i]-f[i];
		}
	}
	cout<<a[pos]<<endl;
}