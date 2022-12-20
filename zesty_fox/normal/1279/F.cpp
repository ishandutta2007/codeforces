#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1000010,INF=0x3f3f3f3f;

int n,k,len,a[N];

int f[N],c[N],minx;
int calc(int mid){
    minx=INF;int ret;
    for(int j:{0,1}){
        for(int i=1;i<=n;i++){
            f[i]=f[i-1]+(a[i]==j),c[i]=c[i-1];
            int tmp=f[max(i-len,0)]-mid;
            if(tmp<f[i]) f[i]=tmp,c[i]=c[max(i-len,0)]+1;
        }
        if(f[n]<minx) minx=f[n],ret=c[n];
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi(),len=rdi();
    //k=min(k,(n+len-1)/len);

    static char s[N];scanf("%s",s+1);
    for(int i=1;i<=n;i++) a[i]=isupper(s[i])?1:0;

    int l=-2*n,r=0;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(calc(mid)<=k) l=mid;
        else r=mid-1;
    }

    calc(l);
    int ans=max(minx+k*l,0);
    cout<<ans<<endl;
    return 0;
}