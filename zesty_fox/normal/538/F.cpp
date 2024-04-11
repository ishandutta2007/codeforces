#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=200010;
int n,a[N],cnt;
ll ans[N];
struct TreeArray{
#define lowbit(x) ((x)&(-(x)))
    int c[N];
    void add(int x,int val){
        for(;x<=n;x+=lowbit(x)) c[x]+=val;
    }
    inline ll query(int x){
        ll sum=0;
        for(;x;x-=lowbit(x)) sum+=c[x];
        return sum;
    }
    inline ll ask(int l,int r){
        return query(r)-query(l-1);
    }
}t;
pii s[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=make_pair(a[i],i);
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++){
        int id=s[i].second;
        for(int j=1;j<n;j++){
            int l=j*(id-1)+2,r=min(n,j*id+1);
            if(l>n) break;
            ans[j]+=t.ask(l,r);
        }
        t.add(id,1);
    }
    for(int i=1;i<n;i++) printf("%lld ",ans[i]);
    return puts(""),0;
}