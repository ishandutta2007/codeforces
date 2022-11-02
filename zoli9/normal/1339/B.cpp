#include <bits/stdc++.h>
using namespace std;
int main() {
    int test, n;
    vector<int> v, w;
    cin>>test;
    while(test--) {
        cin>>n;
        v.resize(n);
        w.clear();
        for(int i=0; i<n; i++) cin>>v[i];
        sort(v.begin(), v.end());
        int i1=0;
        int i2=n-1;
        while(i1<=i2) {
            if(w.size()%2) w.push_back(v[i1++]);
            else w.push_back(v[i2--]);
        }
        for(int i=n-1; i>=0; i--) cout<<w[i]<<" ";
        cout<<'\n';
    }
}