#include<bits/stdc++.h>
#define N 1000005
using namespace std;
#define P 998244353
int n,a[N],b[N],ans,m;
struct cmp {
    inline bool operator () (int x,int y) {
        return x>y;
    }
};
set<int,cmp>A[N];
inline void check(int i) {
    if (!A[i].size() || (*A[i].begin()) < i) b[i]=1, ans++;
    else b[i]=0;
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        A[x].insert(y);
        A[y].insert(x);
    }
    for (int i=1;i<=n;i++) {
        check(i);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++) {
        int id;
        scanf("%d",&id);
        if (id==3) {
            printf("%d\n",ans);
        }
        else {
            int x,y;
            scanf("%d%d",&x,&y);
            if (id==1) {
                ans-=b[x];
                ans-=b[y];
                A[x].insert(y);
                A[y].insert(x);
                check(x);
                check(y);
            }
            else {
                ans-=b[x];
                ans-=b[y];
                A[x].erase(y);
                A[y].erase(x);
                check(x);
                check(y);
            }
        }
    }
}