#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

int main () {
    vector<LL> v;
    LL x,y,l,r;
    cin >> x >> y >> l >> r;
    LL sum=1;
    for (LL a=0;;a++) {
        if (a!=0) {
            if (log10(sum) + log10(x) > 18.1) break;
            sum *= x;
        }
        LL kirino = 1;
        for (int b=0;;b++) {
            if (b!=0) {
                if (log10(kirino) + log10(y) > 18.1) break;
                kirino *= y;
            }
            v.push_back(sum+kirino);
        }
    }
    sort(v.begin(),v.end());
    v.push_back(1000000000LL*2000000000LL);
    LL meruru = l;
    LL val = *lower_bound(v.begin(),v.end(),meruru);
    meruru = l;
    int pos=lower_bound(v.begin(),v.end(),meruru) - v.begin();
    if (val > r) {
        cout<<r-l+1<<endl;
        return 0;
    }
    LL ans = val - l;
    for (pos;v[pos+1]<=r;pos++) {
        ans = max(ans,v[pos+1]-v[pos]-1);
    }
    ans = max(ans,r-v[pos]);
    cout<<ans<<endl;
}