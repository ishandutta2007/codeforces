#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long i64;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1e5+10;

struct Robot{int x,r,q;}r[N];

int n,K;
i64 ans;

using Tree=__gnu_pbds::tree<i64,__gnu_pbds::null_type,less<i64>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
map<int,Tree> buc;

int ti;
void insert(Tree &t,int x) {t.insert((i64)x<<32|(ti++));}
int query(Tree &t,int x) {return t.order_of_key(((x+1ll)<<32)-1);}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),K=rdi();
    for(int i=1;i<=n;i++) 
        r[i].x=rdi(),r[i].r=rdi(),r[i].q=rdi();
    sort(r+1,r+n+1,[&](Robot a,Robot b){return a.r>b.r;});
    for(int i=1;i<=n;i++){
        auto it=buc.lower_bound(r[i].q-K);
        while(it!=buc.end()&&it->fi<=r[i].q+K){
            ans+=query(it->se,r[i].x+r[i].r)-query(it->se,r[i].x-r[i].r-1);
            ++it;
        }
        insert(buc[r[i].q],r[i].x);
    }
    cout<<ans<<endl;
    return 0;
}