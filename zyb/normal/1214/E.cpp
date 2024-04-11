#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define lowbit(x) x&-x
struct pa {
    int x,y;
}da[N];
int a[N],id[N],n,m,A[N];
inline bool cmp(int x,int y) {
    return a[x]<a[y];
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) id[i]=i;
    sort(id+1,id+1+n,cmp);
    int tot=0;
    int ma=0;
    for (int i=1;i<n;i++) da[++tot]=pa{2*id[i]-1,2*id[i+1]-1};
    for (int i=n;i;i--) {
        int x=id[i];
        int y=a[x];
        int p=i-y+1;
        if (p>0) {
            da[++tot]=pa{2*id[i],2*id[p]-1};
            if (p==1) A[1]=2*id[i];
        }
        else {
            p=-p+1;
            da[++tot]=pa{2*id[i],A[p]};
            A[p+1]=2*id[i];
        }
    }
    for (int i=1;i<=tot;i++) printf("%d %d\n",da[i].x,da[i].y);
}