#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<int,int>
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
const int N=2005;
int n,a[N],f1[N],g1[N],f2[N],g2[N],dp1[N],dp2[N],tong[3],ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			f1[i]=f1[i-1]+1;
			f2[i]=f2[i-1];
		}else{
			f1[i]=f1[i-1];
			f2[i]=f2[i-1]+1;
		}
		f2[i]=max(f2[i],f1[i]);
	}
	for(int i=n;i;i--){
		if(a[i]==1){
			g1[i]=g1[i+1]+1;
			g2[i]=g2[i+1];
		}else{
			g1[i]=g1[i+1];
			g2[i]=g2[i+1]+1;
		}
		g1[i]=max(g2[i],g1[i]);
	}
	for(int i=1;i<=n;i++){
		tong[1]=tong[2]=0;
		for(int j=i;j;j--){
			if(a[j]==1){
				dp1[j]=dp1[j+1]+1; dp2[j]=dp2[j+1];
			}else{
				dp1[j]=dp1[j+1]; dp2[j]=dp2[j+1]+1;
			}
			dp2[j]=max(dp2[j],dp1[j]);
			ans=max(ans,f1[j-1]+dp2[j]+g2[i+1]);
		}
	}
	cout<<max(ans,f2[n])<<endl;
}