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
#define rdl read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=110;
int n,vis[N],e[N][N];
vi seq;
set<int> s[N];
void clear(){
    seq.clear();
    for(int i=0;i<n;i++) 
        s[i].clear(),vis[i]=0,memset(e[i],0,sizeof(e[i]));
}

inline bool query1(int x,int y){
    printf("1 %d %d\n",x,y);
    fflush(stdout);
    int res;scanf("%d",&res);
    return res;
}

inline bool query2(int x,const set<int> &s){
    printf("2 %d %ld ",x,s.size());
    for(auto x:s) printf("%d ",x);
    puts("");fflush(stdout);
    int res;scanf("%d",&res);
    return res;
}

void extract(set<int> &s1,set<int> &s2){
    for(auto x:s2) s1.insert(x);
    s2.clear();
}

void merge(set<int> &s1,set<int> &s2){
    for(auto x:s2) s1.insert(x);
}

void solve(){
    n=rdi();clear();
    seq.pb(0);
    for(int i=1;i<n;i++){
        int l=0,r=seq.size();
        while(l<r){
            int mid=(l+r)>>1;
            if(query1(i,seq[mid])) r=mid;
            else l=mid+1;
        }
        seq.insert(seq.begin()+l,i);
    }
    for(int i=0;i<n;i++) s[i].insert(seq[i]);
    for(int i=n-1;i>=1;i--){
        for(auto x:s[i]){
            if(!vis[x]){
                set<int> tmp;
                for(int j=0;j<i;j++) merge(tmp,s[j]);
                if(query2(x,tmp)){
                    extract(s[i-1],s[i]);
                    break;
                }
                vis[x]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(auto x:s[i]){
                for(auto y:s[j]) e[x][y]=1;
            }
        }
    }
    printf("3\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d",e[i][j]);
        puts("");
    }
    fflush(stdout);
    rdi();
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}