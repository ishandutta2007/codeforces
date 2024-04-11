    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <cmath>
    #include <ctime>
     
    #include <algorithm>
    #include <vector>
    #include <map>
    #include <set>
    #include <queue>
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
    #define rdl read<ll>
    #define fi first
    #define sec second
    #define pb push_back
    #define mp make_pair
     
    const int N=200010;
    int n,m,need,tot;
    struct Edge{
        int fr,to,w,col,id;
        bool operator<(const Edge& a)const{
            return w==a.w?col<a.col:w<a.w;
        }
    }e[N];
    void addedge(int x,int y,int w,int col){
        e[++tot]=(Edge){x,y,w,col,0};
        e[tot].id=tot;
    }
     
    int f[N],sel[N];
    int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
    bool merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return 0;
        f[y]=x;return 1;
    }
     
    bool check(int val){
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=tot;i++){
            if(!e[i].col) e[i].w+=val;
        }
        sort(e+1,e+tot+1);
        int cnt=0,cntw=0;
        for(int i=1;i<=tot;i++){
            int x=e[i].fr,y=e[i].to;
            if(merge(x,y)) cntw+=(!e[i].col),cnt++;
            if(cnt==n-1){
                for(int i=1;i<=tot;i++){
                    if(!e[i].col) e[i].w-=val;
                }
                return cntw>=need;
            }   
        }
    }
     
    int main(){
        n=rdi(),m=rdi(),need=rdi();
        for(int i=1;i<=m;i++){
            int x=rdi(),y=rdi(),w=rdi();
            addedge(x,y,w,!(x==1||y==1));
        }
        int l=-100000,r=100000;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=tot;i++){
            if(!e[i].col) e[i].w+=l;
        }
        sort(e+1,e+tot+1);
        int cnt=0,cntw=0;
        ll sum=0;
        for(int i=1;i<=tot;i++){
            int x=e[i].fr,y=e[i].to;
            if(!e[i].col&&cntw==need) continue;
            if(merge(x,y)) cntw+=(!e[i].col),cnt++,sum+=e[i].w,sel[e[i].id]=1;
            if(cnt==n-1) break;
        }
        if(cntw!=need||cnt!=n-1){
            puts("-1");
            return 0;
        }
        printf("%d\n",n-1);
        for(int i=1;i<=tot;i++){
            if(sel[i]) printf("%d ",i);
        }
        puts("");
        return 0;
    }