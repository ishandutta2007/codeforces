#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int k;
int main()
{
    cin>>k;
    for(int i=1; i<=k; i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
sort(v.begin(), v.end());
int ans=max(0, v[v.size()-1]-25);
cout<<ans<<endl;
    return 0;
}