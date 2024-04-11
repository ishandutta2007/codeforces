#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

LL cnt(LL x) {
    LL ret=0;
    while (x>0) {
        ret += x%10;
        x/=10;
    }
    return ret;
}

int main () {
    LL n;
    cin >>n;
    vector<LL> ans;
    for (int i=max(1LL,n-10000);n>=i;i++) {
        if (i+cnt(i) == n) {
            ans.push_back(i);
        }
    }
    printf("%d\n",ans.size());
    for (int i:ans) {
        cout<<i<<endl;
    }
}