#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;

vector<int> pos[MAX_N];
int a[MAX_N];

struct BIT {
    int a[MAX_N];
    int n;
    void init(int _n) {
        n=_n;
        for (int i=0;n>=i;i++) a[i]=0;
    }
    void modify(int pos,int x) {
        for (int i=pos;n>=i;i+=i&(-i)) {
            a[i]+=x;
        }
    }
    int query(int pos) {
        int ret=0;
        for (int i=pos;i>0;i-=i&(-i)) ret+=a[i];
        return ret;
    }
} bit;

int main () {
    int n;
    scanf("%d",&n);
    multiset<int> st;
    for (int i=1;n>=i;i++) {
        scanf("%d",&a[i]);
        pos[ a[i] ].push_back(i);
        st.insert(a[i]);
    }
    int now=0;
    LL ans=0;
    bit.init(n);
    while (!st.empty()) {
        int mn=(*st.begin());
        int tmp=now;
        auto iter=upper_bound(pos[mn].begin(),pos[mn].end(),tmp);
        if (iter==pos[mn].end()) iter=pos[mn].begin();
        int val=*iter;
        if (now <= val) {
            ans += (val-now+1) - (bit.query(val) - bit.query(now-1));
            bit.modify(val,1);
            now = val;
        }
        else {
            ans += (n-now+1) + val - (bit.query(n)-bit.query(now-1)+bit.query(val));
            bit.modify(val,1);
            now=val;
        }
        st.erase(st.begin());
    }
    printf("%lld\n",ans-1);
}