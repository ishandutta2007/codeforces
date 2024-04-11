#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m,k; cin >> n >> m >> k;
    vector< pair<int,int> > v;
    for (int i=1;i<=n;++i) {
        int x; cin >> x;
        v.push_back(make_pair(x,i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    vector<int> pos;
    long long sum=0;
    for (int i=0;i<m*k;++i) {
        sum += v[i].first;
        pos.push_back(v[i].second);
    }
    sort(pos.begin(),pos.end());
    cout << sum << endl;
    for (int i=m-1;i<m*(k-1);i+=m) {
        cout << pos[i] << ' ';
    }
}