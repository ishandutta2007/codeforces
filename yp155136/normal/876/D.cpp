#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

const int MAX_N = 3e5 +6;

struct BIT {
    int p[MAX_N];
    int n;
    void init(int n) {
        memset(p,0,sizeof(p));
        this->n = n;
    }
    void add(int pos,int val) {
        for (int i=pos;n>=i;i+=i&(-i)) {
            p[i] += val;
        }
    }
    int qry(int pos) {
        int ret=0;
        for (int i=pos;i>=1;i-=i&(-i)) {
            ret += p[i];
        }
        return ret;
    }
} bit;

int main () {
    int n;
    scanf("%d",&n);
    printf("1");
    set<int> st;
    for (int i=1;n>=i;i++) {
        st.insert(i);
    }
    bit.init(n);
    for (int i=1;n>=i;i++) {
        int x;
        scanf("%d",&x);
        bit.add(x,1);
        st.erase(st.find(x));
        if (i==n) printf(" 1");
        else {
            int ret=*(--st.end());
            int ans=bit.qry(ret);
            printf(" %d",ans+1);
        }
    }
    puts("");
}