#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
string s1, s2;
vi c, d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s1;
    cin>>s2;
    int ab=0;
    int ba=0;
    for(int i=0; i<n; i++)
    {
        if(s1[i]=='a' && s2[i]=='b')
        {
            c.push_back(i+1);
            ab++;
        }
        if(s1[i]=='b' && s2[i]=='a')
        {
            d.push_back(i+1);
            ba++;
        }
    }
    if((ab+ba)%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    int ans=ab/2+ba/2;
    if(ab%2)
    {
        ans+=2;
        cout<<ans<<'\n';
        for(int i=1; i<c.size(); i+=2)
        {
            cout<<c[i]<<" "<<c[i+1]<<'\n';
        }
        for(int i=1; i<d.size(); i+=2)
        {
            cout<<d[i]<<" "<<d[i+1]<<'\n';
        }
        cout<<c[0]<<" "<<c[0]<<'\n';
        cout<<c[0]<<" "<<d[0]<<'\n';
    }
    else
    {
        cout<<ans<<'\n';
        for(int i=0; i<c.size(); i+=2)
        {
            cout<<c[i]<<" "<<c[i+1]<<'\n';
        }
        for(int i=0; i<d.size(); i+=2)
        {
            cout<<d[i]<<" "<<d[i+1]<<'\n';
        }
    }



    return 0;
}