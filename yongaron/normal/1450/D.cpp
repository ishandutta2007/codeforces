#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int a[1234567];

int l[1234567];
int r[1234567];

int max_dist[1234567];
bool ans[1234567];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>a[i];
        vector<pair<int, int>> st;
        st.push_back({0, -1});
        for(int i = 0; i < n; i++)
        {
            while(st.back().first > a[i])
                st.pop_back();
            l[i] = st.back().second;
            st.push_back({a[i], i});
        }
        st.clear();
        st.push_back({0, n});
        for(int i = n-1; i >= 0; i--)
        {
            while(st.back().first >= a[i])
                st.pop_back();
            r[i] = st.back().second;
            st.push_back({a[i], i});
        }
        for(int i = 1; i <= n; i++)
            max_dist[i] = ans[i] = 0;
        for(int i = 0; i < n; i++)
            max_dist[a[i]] = max(max_dist[a[i]], r[i]-l[i]-1);
        int ma = 1e9;
        for(int i = n; i; i--)
        {
            ma = min(ma, max_dist[n-i+1]);
            if(i <= ma)
                ans[i] = 1;
        }
        for(int i = 1; i <= n; i++)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}