#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int N=200010;
ll n,m,k,p;
struct Bamboo{ll h,a;}b[N];
struct Node{
    ll day,id;
    bool operator<(const Node& a)const{return day>a.day;}
};

priority_queue<Node> q;
int cnt[N];
bool check(ll lim){
    memset(cnt,0,sizeof(cnt));
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++){
        if(lim-b[i].a*m<b[i].h) q.push((Node){lim/b[i].a,i});
    }
    for(int i=1;!q.empty()&&i<=m;i++){
        for(int j=1;!q.empty()&&j<=k;j++){
            Node x=q.top();q.pop();
            if(x.day<i) return false;
            cnt[x.id]++;
            if(lim+cnt[x.id]*p-b[x.id].a*m<b[x.id].h)
                q.push((Node){(lim+cnt[x.id]*p)/b[x.id].a,x.id});
        }
    }
    return q.empty();
}

int main(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&b[i].h,&b[i].a);
    ll l=0,r=1e14;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}