#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
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
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int p=3000005;
int n,tong[p],q;
long long sum[p];
int main(){
	n=read();
	for(int i=1;i<=n;i++)tong[read()]++;
	for(int i=1;i<p;i++)if(tong[i]){
		int meiju=min(i-1,(p-1)/i); tong[i]*=2;
		for(int j=1,k=i;j<=meiju;j++,k+=i)if(i!=j){
			sum[k]+=(ll)tong[i]*tong[j];
			//if(tong[i]&&tong[j])cout<<i*j<<" "<<i<<endl;
		}
		tong[i]/=2;
		if(i*i<p)sum[i*i]+=(ll)tong[i]*(tong[i]-1);
	}
	for(int i=2;i<p;i++)sum[i]+=sum[i-1];
	q=read();
	while(q--){
		writeln((ll)n*(n-1)-sum[read()-1]);
	}
}