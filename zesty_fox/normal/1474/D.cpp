#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define int ll
#define rdi read<int>
#define rdl read<ll>
const int N=200010;
int T,n,a[N],b[N],val[N],r1[N][2],r2[N][2],minx[N];
signed main(){
    T=rdi();
    while(T--){
        n=rdi();ll sum1=0,sum2=0;
        for(int i=1;i<=n;i++){
            a[i]=rdi();
            if(i&1) sum1+=a[i];
            else sum2+=a[i];
        }
        int k=1;b[1]=a[2]-a[1];
        for(int i=3,j=2;i<=n&&j<=n;k++){
            if(k&1) b[k+1]=a[i]-b[k],j+=2;
            else b[k+1]=a[j]-b[k],i+=2;
        }
        minx[k]=b[k];
        for(int i=k-2;i>=1;i-=2) minx[i]=min(minx[i+2],b[i]);
        minx[k-1]=b[k-1];
        for(int i=k-3;i>=1;i-=2) minx[i]=min(minx[i+2],b[i]);
        if(sum1==sum2&&minx[1]>=0&&minx[2]>=0) {puts("YES");continue;}
        bool flg=0;b[0]=minx[n]=1e16;
        for(int i=1;i<=n-1;i++){
            if(i>=3&&b[i-2]<0) break;
            if(2*(a[i+1]-a[i])<=minx[i]&&(a[i+1]-a[i])*2>=max(-b[i-1]*2,-minx[i+1])){
                if((i&1)&&sum1+2*(a[i+1]-a[i])==sum2) {puts("YES");flg=1;break;}
    			if(!(i&1)&&sum2+2*(a[i+1]-a[i])==sum1) {puts("YES");flg=1;break;}
            }
        }
        if(!flg) puts("NO");
    }
    return 0;
}