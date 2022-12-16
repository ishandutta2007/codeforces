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


#define rdi read<int>
#define rdl read<ll>

const int N=100010;
int n,l[N],r[N];

struct Edge{int x,y,id;}e[N];
bool cmp1(Edge a,Edge b){return a.x<b.x;}
bool cmp2(Edge a,Edge b){return a.y<b.y;}
struct TreeArray{
#define lowbit(x) (x&(-x))
    int c[N<<1];
    void add(int x,int val){
        for(;x<=(n<<1);x+=lowbit(x)) c[x]+=val;
    }
    int query(int x){
        int sum=0;
        for(;x;x-=lowbit(x)) sum+=c[x];
        return sum;
    }
}t;

int main(){
    n=rdi();
    for(int i=1;i<=n;i++){
        int a=rdi(),b=rdi();
        if(a>b) swap(a,b);
        e[i].x=a,e[i].y=b,e[i].id=i;
    }
    sort(e+1,e+n+1,cmp1);
    for(int i=1;i<=n;i++){
        int x=e[i].x,y=e[i].y;
        l[e[i].id]+=t.query(x);
        t.add(y,1);
    }
    sort(e+1,e+n+1,cmp2);
    memset(t.c,0,sizeof(t.c));
    for(int i=n;i>=1;i--){
        int x=e[i].x,y=e[i].y;
        l[e[i].id]+=t.query(x)+n-i-t.query(y);
        t.add(x,1);
    }
    memset(t.c,0,sizeof(t.c));
    for(int i=1;i<=n;i++){
        int x=e[i].x,y=e[i].y;
        r[e[i].id]+=i-1-t.query(x);
        t.add(x,1);
    }
    ll ans=(ll)n*(n-1)*(n-2)/6,sum=0;
    for(int i=1;i<=n;i++){
        ans-=(ll)l[i]*r[i];
        sum+=(ll)(l[i]+r[i])*(n-l[i]-r[i]-1);
    }
    printf("%lld\n",ans-sum/2);
    return 0;
}