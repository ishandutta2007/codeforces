#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;


vi pot;
int ans[100009];

int f(int x, int y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    fflush(stdout);
    int a1;
    cin>>a1;
    cout<<"? "<<y<<" "<<x<<endl;
    fflush(stdout);
    int a2;
    cin>>a2;
    if(a1<a2)
    {
        ans[y]=a2;
        return x;
    }
    else
    {
        ans[x]=a1;
        return y;
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;

    for(int i=1; i<=n; i++) pot.push_back(i);
    for(int i=1; i<n; i++)
    {
        int x=pot.back();
        pot.pop_back();
        int y=pot.back();
        pot.pop_back();
        int z=f(x, y);
        pot.push_back(z);
    }
    ans[pot[0]]=n;
    cout<<"!";
    for(int i=1; i<=n; i++)
    {
        cout<<" "<<ans[i];
    }
    cout<<endl;
    fflush(stdout);
    return 0;
}