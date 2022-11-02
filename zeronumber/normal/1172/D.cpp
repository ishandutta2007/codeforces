#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=2005;
int a[maxn],b[maxn],p[maxn],q[maxn],n;
struct node{
    int x,y,xx,yy;
};
vector <node> ans;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }
    for (int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        q[b[i]]=i;
    }
    for (int i=n;i>1;i--){
        if (a[i]==i&&b[i]==i) continue;
        if (a[i]==i){
            ans.pb((node){i,i,i,b[i]});
            q[b[i]]=q[i];
            b[q[i]]=b[i];
        } else if (b[i]==i){
            ans.pb((node){i,i,a[i],i});
            p[a[i]]=p[i];
            a[p[i]]=a[i];
        } else {
            ans.pb((node){a[i],i,i,b[i]});
            p[a[i]]=p[i];
            a[p[i]]=a[i];
            q[b[i]]=q[i];
            b[q[i]]=b[i];
        }
    }
    printf("%d\n",ans.size());
    for (auto x:ans) printf("%d %d %d %d\n",x.x,x.y,x.xx,x.yy);
    return 0;
}