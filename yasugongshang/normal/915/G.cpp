#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define int long long
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
const int p=2000005,mod=1000000007;
bool heshu[p]; int ans,n,T,k,r,miu[p],que[p],m,a[p],ycl[p];
inline int ksm(int a,int b){
	int t=1,y=a;
	while (b){
		if (b&1) t=(long long)t*y%mod;
		y=(long long)y*y%mod;
		b>>=1;
	}
	return t;
}
signed main(){
	for(int i=2;i<p;i++){
	    if(!heshu[i]){que[++r]=i; miu[i]=-1;}
        for(int j=1;j<=r&&i<=(p-1)/que[j];j++){
            heshu[k=i*que[j]]=1;
            if (i%que[j]==0){miu[k]=0; break;}
            miu[k]=-miu[i];
        }
    }
	miu[1]=1;
	cin>>n>>k;
	for(int i=1;i<=k;i++)ycl[i]=ksm(i,n);
	for(int i=1;i<=k;i++){
		for(int j=i;j<=k;j+=i){
			int t=miu[i]*ycl[j/i]; //cout<<i<<" "<<miu[i]<<" "<<j<<" "<<t<<endl;
			a[j]=(a[j]+t)%mod; a[j+i]=(a[j+i]+mod-t)%mod;
		}
	}
	for(int i=1;i<=k;i++){
		a[i]=((a[i-1]+a[i])%mod+mod)%mod;
		ans=(ans+(a[i]^i))%mod;
	}
	cout<<ans<<endl;
}