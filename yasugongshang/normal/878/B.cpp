#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long  LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
#include<string>
const long long N=100005;
long long a[N],k,m,n,b[N],zs,kk,r,bb[N];
inline bool check(long long l,long long r){
	for(long long i=l;i<r;i++)if(a[i]!=a[i+1])return 0;
	return 1;
}
int main(){
	cin>>n>>k>>m;
	for(long long i=1;i<=n;i++)a[i]=read();
	for(long long i=1;i<=n;i++){
		if(a[i]!=b[r])bb[r+1]=1; else bb[r+1]=bb[r]+1;
		b[++r]=a[i];
		if(bb[r]==k){r-=k;}
	}
	n=r;
	for(long long i=1;i<=n;i++)a[i]=b[i];
	long long i=n,j=1,lasti=n,lastj=1; kk=2;
	for(;j<i&&a[i]==a[j];){
		while(a[i-1]==a[i]&&kk<k){i--; kk++;}
		while(a[j+1]==b[j]&&kk<k){j++; kk++;}
		if(j<i&&kk==k){
			lasti=--i; lastj=++j; if(a[j]==a[i])kk=2; else break;
		}else break;
	}
	i=lasti; j=lastj;
	if(check(j,i)){
	    kk=2;
		if(m*(i-j+1)%k!=0){cout<<m*(i-j+1)%k+j-1+n-i<<endl; return 0;}
		lasti++; lastj--;
	    for(j--,i++;a[i]==b[j]&&i<=n&&j;){
		    while(a[j-1]==a[j]&&kk<k){j--; kk++;}
		    while(a[i+1]==a[i]&&kk<k){i++; kk++;}
		    if(kk==k){
			    lasti=++i; lastj=--j; kk=2;
		    }
	    }
        cout<<lastj+n-lasti+1<<endl;
	}
	else cout<<(i-j+1)*m+j-1+n-i<<endl;
}