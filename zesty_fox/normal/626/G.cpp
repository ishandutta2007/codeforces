#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;
const double eps=1e-10,inf=1e18;
int n,t,q,p[N],c[N],l[N];
double ans;

double calc(int x,int cnt){
    if(cnt==-1) return inf;
    else if(cnt>=l[x]) return 0;
    else return p[x]*(1.0*(cnt+1)/(cnt+l[x]+1)-1.0*cnt/(cnt+l[x]));
}

struct Object{
    double res;int x,c;
    Object(){x=c=0;}
    Object(int _x,int _c){x=_x,c=_c,res=calc(x,c);}
    bool operator<(const Object &b)const{
        if(fabs(res-b.res)<eps) return x<b.x;
        else return res<b.res-eps;
    }
};
multiset<Object> sel,fut;

void add(){
    auto it=prev(fut.end());auto tmp=*it;
    ans+=tmp.res,c[tmp.x]++;
    sel.erase(Object(tmp.x,tmp.c-1)),sel.insert(Object(tmp.x,tmp.c));
    fut.erase(Object(tmp.x,tmp.c)),fut.insert(Object(tmp.x,tmp.c+1));
}

void remove(){
    auto it=sel.begin();auto tmp=*it;
    ans-=tmp.res,c[tmp.x]--;
    sel.erase(Object(tmp.x,tmp.c)),sel.insert(Object(tmp.x,tmp.c-1));
    fut.erase(Object(tmp.x,tmp.c+1)),fut.insert(Object(tmp.x,tmp.c));
}

int main(){
    n=rdi(),t=rdi(),q=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi();
    for(int i=1;i<=n;i++){
        l[i]=rdi();
        sel.insert(Object(i,-1));
        fut.insert(Object(i,0));
    }
    while(t--) add();
    while(q--){
        int typ=rdi(),x=rdi();
        sel.erase(Object(x,c[x]-1)),fut.erase(Object(x,c[x])),ans-=p[x]*1.0*min(c[x],l[x])/(min(c[x],l[x])+l[x]);
        l[x]+=typ==1?1:-1;
        sel.insert(Object(x,c[x]-1)),fut.insert(Object(x,c[x])),ans+=p[x]*1.0*min(c[x],l[x])/(min(c[x],l[x])+l[x]);
        while(sel.begin()->res < fut.rbegin()->res - eps) remove(),add();
        printf("%.10lf\n",ans);
    }
    return 0;
}