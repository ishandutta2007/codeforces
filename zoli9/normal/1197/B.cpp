#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
vector<int> d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    d.resize(n);
    int nw;
    for(int i=0; i<n; i++)
    {
        cin>>d[i];
        if(d[i]==n)
        {
            nw=i;
        }
    }
    int k=nw-1;
    int v=nw+1;
    for(int i=n-1; i>=1; i--)
    {
        if(k>=0 && d[k]==i)
        {
            k--;
        }
        else if(v<n && d[v]==i)
        {
            v++;
        }
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;
}