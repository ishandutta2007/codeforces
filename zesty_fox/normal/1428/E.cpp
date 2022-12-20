#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=100010;
int n,k,a[N];
ll ans;
inline ll calc(int x,int cs){
    int k=x/cs,ys=x%cs;
    return (ll)k*k*(cs-ys)+(ll)(k+1)*(k+1)*ys;
}

struct cmp{
    bool operator()(pii a,pii b){
        return calc(a.first,a.second)-calc(a.first,a.second+1)<\
               calc(b.first,b.second)-calc(b.first,b.second+1);
    }
};

priority_queue<pii,vector<pii>,cmp> q;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        q.push(mp(x,1));ans+=(ll)x*x;
    }
    for(int i=1;i<=k-n;i++){
        pii x=q.top();q.pop();
        ans-=(calc(x.first,x.second)-calc(x.first,x.second+1));
        q.push(mp(x.first,x.second+1));
    }
    cout<<ans<<endl;
    return 0;
}