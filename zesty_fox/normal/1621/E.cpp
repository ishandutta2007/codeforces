#include <bits/stdc++.h>

using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010,INF=0x3f3f3f3f;

//~ struct Node{int ls,rs,minx,tag;};
//~ struct SGT{
//~ #define lson (now<<1)
//~ #define rson (now<<1|1)
//~ #define mid ((l+r)>>1)
    //~ Node t[N*20];int tot;
    //~ int newnode(){
        //~ t[++tot]={0,0,INF,0};
        //~ return tot;
    //~ }
    //~ void clear(){
        //~ t[0]=t[1]={0,0,INF,0};
        //~ tot=0;
    //~ }
    //~ void pushup(int now){t[now].minx=min(t[lson].minx,t[rson].minx);}
    //~ void modify(int now,int l,int r,int x,int y,int val){
        //~ if(x<=l&&r<=y){
            //~ t[now].minx+=val,t[now].tag+=val;
            
        //~ }
    //~ }
//~ #undef lson
//~ #undef rson
//~ #undef mid
//~ }t;

int n,m,a[N];
ll sum[N];
vi b[N];

int lg2(int x) {return !x?0:__lg(x);}

int mx[N][21],cnt[N],pos[N];
void init(){
    for(int i=1;i<=n;i++) mx[i][0]=cnt[i];
    for(int j=1;j<=lg2(n);j++){
        for(int i=1;i<=n-(1<<j)+1;i++) mx[i][j]=min(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    }
}

int query(int l,int r){
    if(l>r) return INF;
    int k=lg2(r-l+1);
    return min(mx[l][k],mx[r-(1<<k)+1][k]);
}

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=m;i++){
        int k=rdi();
        for(int j=1;j<=k;j++){
            int x=rdi();sum[i]+=x;
            b[i].pb(x);
        }
    }
    
    sort(a+1,a+n+1,greater<int>()),n=m,reverse(a+1,a+n+1);
    
    for(int i=1;i<=m;i++){
        int l=1,r=n+1;
        while(l<r){
            int mid=(l+r)>>1;
            if((ll)a[mid]*b[i].size()>=sum[i]) r=mid;
            else l=mid+1;
        }
        pos[i]=l,cnt[l]++;
    }
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=n;i++) cnt[i]-=i;
    init();
    
    string res;
    for(int i=1;i<=m;i++){
        for(auto x:b[i]){
            int l=1,r=n+1;
            while(l<r){
                int mid=(l+r)>>1;
                if((ll)a[mid]*(b[i].size()-1)>=sum[i]-x) r=mid;
                else l=mid+1;
            }
            int pos1=pos[i],pos2=l;
            if(pos1<pos2){
                int tmp1=query(1,pos1-1),tmp2=query(pos1,pos2-1)-1,tmp3=query(pos2,n);
                if(tmp1<0||tmp2<0||tmp3<0) res+="0";
                else res+="1";
            }
            else{
                int tmp1=query(1,pos2-1),tmp2=query(pos2,pos1-1)+1,tmp3=query(pos1,n);
                if(tmp1<0||tmp2<0||tmp3<0) res+="0";
                else res+="1";
            }
        }
    }
    cout<<res<<'\n';
    
    for(int i=1;i<=n;i++){
        pos[i]=cnt[i]=a[i]=0;
    }
    for(int i=1;i<=m;i++){
        sum[i]=0,b[i].clear();
    }
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}