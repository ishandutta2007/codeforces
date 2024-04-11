#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vll w;
vector<pair<ll, ll> >szak;

int main()
{
    ios::sync_with_stdio(false);
    cout.precision(11);
    cout<<fixed;
    cin.tie(0);
    cin>>n;
    w.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
    }
    pair<ll, ll> p;
    p.F=w[0];
    p.S=1;
    szak.push_back(p);
    for(int i=1; i<n; i++)
    {
        p.F=w[i];
        p.S=1;
        while(szak.size()>0)
        {
            pair<ll, ll> tp=szak.back();
            if(tp.F*p.S<=tp.S*p.F)
            {
                break;
            }
            else
            {
                szak.pop_back();
                p.F+=tp.F;
                p.S+=tp.S;
            }
        }
        szak.push_back(p);
    }
    for(pair<ll, ll> tp: szak)
    {
        long double ld=((long double)(tp.F))/((long double)(tp.S));
        for(int i=1; i<=tp.S; i++)
        {
            cout<<ld<<'\n';
        }
    }
    return 0;
}