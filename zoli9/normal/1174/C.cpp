#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
vector<pair<pii, pii> > ans;
int n;
int t[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool ok=false;
    cin>>n;
    int c=1;
    for(int i=2; i<=n; i++)
    {
        if(t[i]!=0) continue;
        for(int j=i; j<=n; j+=i)
        {
            t[j]=c;
        }
        c++;
    }
    for(int i=2; i<=n; i++) cout<<t[i]<<" ";
    cout<<endl;
    return 0;
}