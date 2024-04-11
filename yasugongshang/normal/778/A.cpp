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
const int N=200005;
int n,m,p[N],vis[N];
char a[N],b[N];
bool check(int x){
	int dq=1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=x;i++)vis[p[i]]=1;
	for(int i=1;i<=n;i++)if(!vis[i]){
		if(a[i]==b[dq])dq++;
	}
	return dq>m;
}
int main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for(int i=1;i<=n;i++)p[i]=read();
	int l=0,r=n;
	while(l<r){
		int mid=(l+r)>>1; mid++;
		if(check(mid))l=mid; else r=mid-1;
	}
	cout<<l<<endl;
}