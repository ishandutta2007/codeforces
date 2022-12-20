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

const int N=1010;

int n,m;
ll k;
string s;

const ll INF=0x3f3f3f3f3f3f3f3f;

int lcp[N][N];

int compare(pii a,pii b){
    int len=min({lcp[a.fi][b.fi],a.se-a.fi+1,b.se-b.fi+1});
    if(a.se-a.fi==b.se-b.fi&&len==a.se-a.fi+1) return 0;
    if(b.fi+len-1==b.se) return 1;
    else if(a.fi+len-1==a.se) return -1;
    return s[a.fi+len-1]<s[b.fi+len-1]?-1:1;
}

vector<pii> seq;
void init(){
    for(int i=n;i>=1;i--)
        for(int j=n;j>=1;j--)
            lcp[i][j]=(s[i-1]==s[j-1]?lcp[i+1][j+1]+1:0);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) seq.pb({i,j});
    sort(seq.begin(),seq.end(),[&](pii a,pii b){return compare(a,b)<0;});
    seq.erase(unique(seq.begin(),seq.end(),[&](pii a,pii b){return compare(a,b)==0;}),\
            seq.end());
}

ll f[N][N],sum[N][N];
ll count(pii x){
    f[n+1][0]=sum[n+1][0]=1;
    for(int i=n;i>=1;i--){
        int l=i,r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(compare({i,mid},x)>=0) r=mid;
            else l=mid+1;
        }
        for(int j=0;j<=n-i+1;j++){
            f[i][j]=0,sum[i][j]=sum[i+1][j];
            if(!j||compare({i,n},x)<0) continue;
            f[i][j]=min(sum[l+1][j-1],INF),sum[i][j]=min(sum[i+1][j]+f[i][j],INF);
        }
    }
    return f[1][m];
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi(),k=rdll();
    cin>>s;init();
    
    int l=0,r=seq.size()-1;
    while(l<r){
        int mid=(l+r+1)/2;
        if(count(seq[mid])>=k) l=mid;
        else r=mid-1;
    }
    cout<<s.substr(seq[l].fi-1,seq[l].se-seq[l].fi+1)<<endl;
    return 0;
}