#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define int long long
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
const int N=2005;
int n,ans,a[N];
signed main(){
	n=read();
	for(int i=1;i<=2*n;i++)a[i]=read();
	for(int i=1;i<=2*n;i+=2){
		for(int j=i+1;j<=2*n;j++)if(a[j]==a[i]){
			for(int k=j-1;k>i;k--)swap(a[k],a[k+1]);
			ans+=j-i-1; break;
		}
	}
	cout<<ans<<endl;
}