#include <bits/stdc++.h>
using namespace std;

int main (){
    vector<int> v;
    int n;cin>>n;
    for (int i=0;i<n;++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    cout << min(v[n-1]-v[1],v[n-2]-v[0])<<endl;
}