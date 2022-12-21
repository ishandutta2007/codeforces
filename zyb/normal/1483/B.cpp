#include<bits/stdc++.h>
#define N 300005
using namespace std;
#define pb push_back
#define lowbit(x) x&-x
int n,m,a[N];
set<int>A;
struct pa {
    long long x,y;
}b[N];
struct cmp {
    inline bool operator () (pa x,pa y) {
        return x.x<y.x;
    }
};
set<pa,cmp>B;
set<int>::iterator g;
int ans[N];
inline int gcd(int x,int y) {
    if (x%y==0) return y;
    return gcd(y,x%y);
}
inline int findnext(int x) {
    g=A.lower_bound(x);
    if (g==A.end()) return (*A.begin());
    return *g;
}
inline int findlast(int x) {
    g=A.lower_bound(x);
    if (g==A.begin()) {
        g=A.end();
    }
    g--;
    return *g;
}
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        int tot=0;
        scanf("%d",&n);
        A.clear();
        B.clear();
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            A.insert(i);
        }
        for (int i=1;i<=n;i++) b[i]=pa{0,0};
        for (int i=1;i<=n;i++) {
            if (gcd(a[i],a[i%n+1])==1) {
                B.insert(pa{i,i%n+1});
                b[i%n+1]=pa{i,i%n+1};
            }
        }
        while (B.size()) {
            pa gt=*B.begin();
            B.erase(gt);
            ans[++tot]=gt.y;
            A.erase(gt.y);
            if (!A.size()) break;
            int r=findnext(gt.y),l=findlast(gt.y);
            
            if (b[r].y) {
                B.erase(b[r]);
                b[r]=pa{0,0};
            }
            if (gcd(a[l],a[r])==1) {
                b[r]=pa{gt.x+A.size()+1,r};
                B.insert(b[r]);
            } 
        }
        printf("%d ",tot);
        for (int i=1;i<=tot;i++) printf("%d ",ans[i]);
        puts("");
    }
}