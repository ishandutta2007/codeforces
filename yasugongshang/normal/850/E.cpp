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
#define uint unsigned
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
const int mod=1000000007,rev=(mod+1)/2,N=20;
int ans,n,bit[1<<N];
ll a[1<<N],ycl[21];
char ch[(1<<N)+5];
void FWT(ll *a,int n){
	for(int k=1;k<n;k<<=1){
		for(int i=0;i<n;i+=k<<1){
			for(register int j=0;j<k;j++){
				ll x=a[i+j];
				a[i+j]=a[i+j]+a[i+j+k];
				a[i+j+k]=x-a[i+j+k];
			}
		}
	}
}
int main(){
	n=read();
	scanf("%s",ch);
	for(int i=0;i<(1<<n);i++)a[i]=ch[i]-'0';
	FWT(a,1<<n);
	//for(int i=0;i<(1<<n);i++)cout<<a[i]<<" "; puts("");
	for(int i=0;i<(1<<n);i++)a[i]=a[i]*a[i]%mod;
	FWT(a,1<<n);
	ycl[0]=1; for(int i=1;i<=n;i++)ycl[i]=ycl[i-1]*rev%mod;
	for(int i=0;i<(1<<n);i++){
		bit[i]=bit[i>>1]+(i&1);
		ans=(ans+a[i]%mod*ycl[bit[i]])%mod;
	}
	cout<<(ll)(ans+mod)%mod*3%mod<<endl;
}