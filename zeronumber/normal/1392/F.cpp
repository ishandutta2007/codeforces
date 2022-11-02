#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll a[maxn],sum[maxn];
struct node{
    int sz;
    ll x;
}b[maxn];
int n,top;
ll last(node u){return u.x+u.sz-1;}
ll gsum(node u){return u.x*u.sz+1ll*u.sz*(u.sz-1)/2;}
ll calc(int sz,ll sum){
    return (sum-1ll*sz*(sz-1)/2+sz-1)/sz;
}
void work(int sz,ll sum){
    ll p=calc(sz,sum);
    int m=(int)(p*sz+1ll*sz*(sz-1)/2-sum);
    if (!m) b[++top]=(node){sz,p};
    else {
        b[++top]=(node){sz-m,p};
        b[++top]=(node){m,p+(sz-m)-1};
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    b[++top]=(node){1,a[1]};
    for (int i=2;i<=n;i++){
        if (a[i]==last(b[top])){
            b[++top]=(node){1,a[i]};
            continue;
        }
        ll s=a[i];
        int tot=1;
        while (top>1&&calc(tot+b[top].sz,s+gsum(b[top]))>last(b[top-1])) {
            tot+=b[top].sz;
            s+=gsum(b[top]);
            top--;
        }
        tot+=b[top].sz; s+=gsum(b[top]); top--;
        work(tot,s);
    }
    for (int i=1;i<=top;i++)
        for (int j=0;j<b[i].sz;j++) printf("%lld ",b[i].x+j);
    puts("");
    return 0;
}