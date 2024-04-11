#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=2005;
int n,m,s[500005],t[500005];
struct matrix{
	bitset<N> a[N];
    void clear(int n){
    	memset(a,0,sizeof(a));
    	for(int i=0;i<n;i++)a[i][i]=1;
	}
	void clear(){
    	memset(a,0,sizeof(a));
	}
}e,zs;
matrix inv(matrix a){
	matrix b; b.clear();
	for(int i=0;i<n;i++)b.a[i][i]=1;
	//for(int i=0;i<n;i++)for(int j=0;j<n;j++)cout<<b.a[i][j]<<" "<<i<<" "<<j<<endl;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)if(a.a[j][i]){
			swap(a.a[i],a.a[j]); swap(b.a[i],b.a[j]); break;
		}
		if(!a.a[i][i])while(1);
		for(int j=0;j<n;j++)if(i!=j&&a.a[j][i]){
			b.a[j]^=b.a[i]; a.a[j]^=a.a[i];// cout<<i<<" wzp "<<j<<" "<<b.a[1][0]<<" "<<b.a[1][1]<<endl;
		}
	}
	return b;
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		s[i]=read()-1; t[i]=read()-1;
		e.a[s[i]][t[i]]=1;
	}//puts("zh");
	zs=inv(e);
	//for(int i=0;i<n;i++)for(int j=0;j<n;j++)zs[i][j]=zs[i][j]*hls;
	//for(int i=0;i<n;i++)for(int j=0;j<n;j++)cout<<e.a[i][j]<<" "<<zs.a[i][j]<<" "<<i<<" "<<j<<endl;
	for(int i=1;i<=m;i++)if(!zs.a[t[i]][s[i]])puts("YES"); else puts("NO");
}
/*
1 1
0 1

1 1
0 1

1 0 1 1
0 1 0 1
*/