#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
const int maxn=1e6+10;
const int M=998244353;
struct node{
    int x,y,v;
};
vector<node> ans;
int n,a[maxn],_;
void mov(int x,int y,int v){
    ans.pb((node){x,y,v});
    a[x]-=x*v;
    a[y]+=x*v;
    assert(a[x]>=0);
}
void solve(){
    scanf("%d",&n); int sum=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if (sum%n){puts("-1");return;}
    bool flag=0;
    for (int i=1;i<=n;i++) flag|=a[i]!=sum/n;
    if (!flag){puts("0");return;}
    int p=1;
    for (int i=2;i<=n;i++) if (a[i]>=i) p=i;
    ans.clear();
    if (p>1){
        mov(p,1,a[p]/p);
        mov(1,p,p-a[p]);
        mov(p,1,a[p]/p);
    }
    for (int i=2;i<p;i++){
        mov(1,i,i-a[i]%i);
        mov(i,1,a[i]/i);
    }
    vector<pi> res; res.clear();
    for (int i=p+1;i<=n;i++) res.pb((pi){i-a[i],i});
    sort(res.begin(),res.end());
    for (auto g:res){
        int x=g.S;
        if (a[1]+a[x]<x){puts("-1");return;}
        mov(1,x,x-a[x]);
        mov(x,1,a[x]/x);
    }
    for (int i=2;i<=n;i++) mov(1,i,sum/n);
    printf("%d\n",ans.size());
    for (auto g:ans) printf("%d %d %d\n",g.x,g.y,g.v);

    //for (int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
    return 0;
}