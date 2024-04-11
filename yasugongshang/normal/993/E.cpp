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
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
#define cp complex<long double>
const long double PI=acos(-1);
const int N=800005;
int n=1,a[N],tong[N];
long long res[N];
cp omg[N],inv[N],c[N],b[N];
void init(){
    for(int i=0;i<n;i++){
        omg[i]=cp(cos(2*PI*i/n),sin(2*PI*i/n));
        inv[i]=conj(omg[i]);
    }
}
void fft(cp *a,cp *dq){
    int lim=0;
    while((1<<lim)<n)lim++;
    for(int i=0;i<n;i++){
        int t=0;
        for(int j=0;j<lim;j++){
            if((i>>j)&1)t|=1<<(lim-j-1);
        }
        if(i<t)swap(a[i],a[t]);
    }
    for(int l=2;l<=n;l*=2){
        int m=l/2;
        for(int p=0;p<n;p+=l){
            for(int i=p;i<p+m;i++){
                cp t=dq[n/l*(i-p)]*a[i+m];
                a[i+m]=a[i]-t; a[i]+=t;
            }
        }
    }
}
int main(){
	int m=read(),x=read();
	b[0]=tong[0]=1;
	for(int i=1;i<=m;i++){
		a[i]=a[i-1]+(read()<x); tong[a[i]]++;
		int t=b[a[i]].real(); b[a[i]]=t+1;
	}
	for(int i=0;i<=m;i++)c[i]=b[i];
	reverse(&c[0],&c[m+1]);
    while(n<(m+1)*2)n*=2;
    init();
    //for(int i=0;i<n;i++)cout<<b[i].real()<<" "<<c[i].real()<<" "<<i<<endl;
    fft(b,omg); fft(c,omg);
    for(int i=0;i<n;i++)b[i]*=c[i];
    fft(b,inv);
    for(int i=0;i<n;i++){
        res[i]=floor(b[i].real()/n+0.5);
    }
	res[m]=0;
	for(int i=0;i<=m;i++)res[m]=res[m]+(long long)tong[i]*(tong[i]-1)/2;
    for(int i=0;i<=m;i++){
    	write(res[i+m]); putchar(' ');
	}
}
/*
d[i]=sigma b[j]*c[m-j+i]
*/