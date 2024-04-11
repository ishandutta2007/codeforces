// LUOGU_RID: 97136082
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=1e6+10,L=40;

int n;
i64 b,p,m;
pii a[N];

int cm,pos[L],sel[L];
vector<i64> val[L],pre[L];
i64 s[L],all;

void init(){
    n=rdi(),b=rdi(),p=rdi(),m=rdi();
    for(int i=1;i<=n;i++){
        char s[3];int val;scanf("%s%d",s,&val);
        a[i]={s[0]=='+'?1:2,val};
    }
    n=remove(a+1,a+n+1,(pii){2,1})-a-1;
    a[0]={1,1},a[n+1]={2,1};

    all=1;
    for(int i=1,lst=-1;i<=n+1;i++)
        if(a[i].fi==2){
            pos[++cm]=i,all*=a[i].se;
            for(int j=lst+1;j<i;j++) val[cm].pb(a[j].se),s[cm]+=a[j].se;
            sort(val[cm].begin(),val[cm].end(),greater<>());
            partial_sum(val[cm].begin(),val[cm].end(),back_inserter(pre[cm]));
            lst=i;
        }
}

i64 ans;
i64 calc(int sel[]){
    i64 rest=b-(i64)m*count(sel+1,sel+cm+1,1);
    if(rest<0) return 0;
    rest/=p;

    auto calc = [&](i64 lim){
        int cnt=0;
        i64 sum=0,mul=all;
        for(int i=1,lst=0;i<=cm;i++){
            if(sel[i]) continue;
            for(int j=lst+1;j<=i;j++){
                int l=0,r=val[j].size();
                while(l<r){
                    int mid=(l+r+1)/2;
                    if(val[j][mid-1]*(all-mul)>=lim) l=mid;
                    else r=mid-1;
                }
                cnt+=l;
                if(l) sum+=pre[j][l-1]*all;
                if(l<val[j].size()) sum+=(s[j]-(l?pre[j][l-1]:0))*mul;
            }
            mul/=a[pos[i]].se,lst=i;
        }
        return make_pair(cnt,sum);
    };

    i64 l=0,r=1e18;
    while(l<r){
        i64 mid=(l+r)/2;
        if(calc(mid).fi<=rest) r=mid;
        else l=mid+1;
    }
    auto res=calc(l);
    return res.se+max(0ll,(rest-res.fi)*(l-1));
}

void dfs(int x,int mx=0){
    if(x>cm) {ans=max(ans,calc(sel));return;}
    dfs(x+1,max(mx,a[pos[x]].se));
    if(mx<a[pos[x]].se) sel[x]=1,dfs(x+1,mx),sel[x]=0;
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    init();dfs(1);
    cout<<ans<<endl;
    return 0;
}