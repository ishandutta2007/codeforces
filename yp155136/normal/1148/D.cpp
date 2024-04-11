#include <bits/stdc++.h>
using namespace std;

const int N = 300006;

int a[N],b[N];

int main () {
    int n; scanf("%d",&n);
    int _ = 0, __ = 0;
    for (int i=1;i<=n;++i) {
        scanf("%d%d",&a[i],&b[i]);
        if (a[i] < b[i]) _++;
        else __++;
    }
    cout << max(_,__) << endl;
    vector<int> ans;
    if (_ >= __) {
        for (int i=1;i<=n;++i) {
            if (a[i]<b[i]) ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),[](const int &i,const int &j){
            return a[i] > a[j];
        });
    }
    else {
        for (int i=1;i<=n;++i) {
            if (a[i]>b[i]) ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),[](const int &i,const int &j){
            return b[i] < b[j];
        });
    }
    for (int i=0;i<max(_,__);++i) {
        cout << ans[i] << " \n"[i == max(_,__)-1];
    }
}