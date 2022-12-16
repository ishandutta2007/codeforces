#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
const int N=1000010;
int n,h[N],a[N],cnt,st[N],pos[N],tp,s[N],r[N],flg[N];
ll ans;
int main(){
    scanf("%d",&n);
    int p=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
        if(h[p]<h[i]) p=i;
    }
    for(int i=p;i<=n;i++) a[++cnt]=h[i];
    for(int i=1;i<p;i++) a[++cnt]=h[i];
    for(int i=2;i<=n;i++){
        while(tp&&a[i]>=a[st[tp]]) tp--;
        pos[i]=st[tp];st[++tp]=i;
    }
    tp=0;st[tp]=n+1;
    for(int i=n;i>=2;i--){
        while(tp&&a[i]>=a[st[tp]]){
            if(a[i]==a[st[tp]]) s[i]=s[st[tp]]+1;
            tp--;
        }
        r[i]=st[tp];st[++tp]=i;
    }
    for(int i=2;i<=n;i++){
        if(pos[i]>0) ans++;
        if(r[i]<=n) ans++;
        ans+=s[i];
    }
    p=0;
    for(int i=2;i<=n;i++){
        if(a[i]>=p) flg[i]=1;
        p=max(p,a[i]);
    }
    p=0;
    for(int i=n;i>=2;i--){
        if(a[i]>=p) flg[i]=1;
        p=max(p,a[i]);
    }
    for(int i=2;i<=n;i++) ans+=flg[i];
    cout<<ans<<endl;
    return 0;
}