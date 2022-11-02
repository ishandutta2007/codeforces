#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<int> v;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        while(cnt<n && v[cnt]<i) cnt++;
        if(cnt>=n)
        {
            cout<<i-1<<endl;
            return 0;
        }
        cnt++;
    }
    cout<<n<<endl;
    return 0;
}