#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define int long long
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
const int mod=1000000007;
int size,n,k,a[103],ans;
struct matrix{
    int a[103][103];
}zs,p;
matrix cheng(matrix x,matrix y){
    matrix tmp;
    for(int i=0;i<size;i++)
     for(int j=0;j<size;j++){tmp.a[i][j]=0;
      for(int k=0;k<size;k++){
          tmp.a[i][j]=(tmp.a[i][j]+(long long)x.a[i][k]*y.a[k][j])%mod;
      }}
    return tmp;
}
inline matrix quick(matrix zs,long long k){
    matrix ans;
    memset(ans.a,0,sizeof(ans.a)); for(int i=0;i<size;i++)ans.a[0][i]=1;
    while(k){
        if(k&1)ans=cheng(ans,zs);
        zs=cheng(zs,zs);
        k>>=1;
    }
    return ans;
}
bool check(ll x, ll y)
{
    ll temp = x^y;
    ll cnt = 0;
    while(temp)
    {
        cnt += temp&1;
        temp = temp >> 1;
    }
    return (cnt % 3 == 0);
}

signed main(){
	size=n=read(); k=read()-1; int sum=0;
	for(int i=0;i<n;i++)a[i]=read();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)if(check(a[i],a[j])){zs.a[i][j]=1; }
	}
	zs=quick(zs,k);
	for(int i=0;i<n;i++)ans=(ans+zs.a[0][i])%mod;
	cout<<ans<<endl;
}