#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

int main () {
    vector<pii> v;
    int n;
    scanf("%d",&n);
    for (int i=0;n>i;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        v.push_back(make_pair(a,1));
        v.push_back(make_pair(b+1,-1));
    }
    sort(v.begin(),v.end());
    bool ans=true;
    int cnt=0;
    for (int i=0;v.size()>i;i++) {
        cnt += v[i].second;
        if (i+1 != v.size() && v[i].first != v[i+1].first) {
            if (cnt > 2) ans=false;
        }
    }
    if (ans) puts("YES");
    else puts("NO");
}