#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

ll w[1234567];
int d[1234567];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll ans = 0;
        vector<ll> sorted;
        for(int i = 1; i <= n; i++)
        {
            cin>>w[i];
            ans += w[i];
            d[i] = 0;
        }
        int a, b;
        for(int i = 0; i < n-1; i++)
        {
            cin>>a>>b;
            if(d[a]++)
                sorted.push_back(w[a]);
            if(d[b]++)
                sorted.push_back(w[b]);
        }
        sort(sorted.begin(), sorted.end());
        cout<<ans<<" ";
        for(int i = sorted.size()-1; i >= 0; i--)
        {
            ans += sorted[i];
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}