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
#define mp make_pair
#define pb push_back

const int fib[]={1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811};
constexpr int fib_siz=sizeof(fib)/sizeof(int);

const int N=200010;

int head[N],tot=1;
struct Edge{int to,nxt,flg;}e[N<<1];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x],0};
    head[x]=tot;
}

int siz[N];
bool find_root(int x,int fa,int tofa,pii &rt,int dep){
    siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(e[i].flg||y==fa) continue;
        if(find_root(y,x,i,rt,dep)) return true;
        siz[x]+=siz[y];
    }
    if(siz[x]==fib[dep]){
        rt=mp(x,fa);
        e[tofa].flg=e[tofa^1].flg=1;
        return true;
    }
    return false;
}

bool solve(int x,int dep){
    if(dep<=2) return true;
    pii rt(0,0);
    if(find_root(x,0,0,rt,dep-2)) return solve(rt.fi,dep-2)&&solve(rt.se,dep-1);
    if(find_root(x,0,0,rt,dep-1)) return solve(rt.fi,dep-1)&&solve(rt.se,dep-2);
    return false;
}

int n;
int main(){
    n=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y);addedge(y,x);
    }
    int pos=lower_bound(fib,fib+fib_siz,n)-fib;
    if(fib[pos]!=n) puts("NO");
    else puts(solve(1,pos)?"YES":"NO");
    return 0;
}