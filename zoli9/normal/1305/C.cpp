#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
bool volt[1009];
vi szamok;
bool jo;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    jo=true;
    szamok.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>szamok[i];
        if(volt[szamok[i]%m]) jo=false;
        volt[szamok[i]%m]=true;
    }
    if(!jo)
    {
        cout<<0<<endl;
        return 0;
    }
    int ans=1;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int uj=abs(szamok[i]-szamok[j]);
            uj%=m;
            ans=(ans*uj)%m;
        }
    }
    cout<<ans<<endl;

    return 0;
}