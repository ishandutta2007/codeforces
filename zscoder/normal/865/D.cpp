#include <bits/stdc++.h>
using namespace std;main(){int n;cin>>n;multiset<int> s;long long a=0;int x;while(n--){cin>>x;s.insert(x);s.insert(x);a+=x-*s.begin();s.erase(s.begin());}cout<<a;}