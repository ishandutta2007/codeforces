#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        int L=0;
        int R=0;
        int U=0;
        int D=0;
        cin>>s;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='L') L++;
            if(s[i]=='R') R++;
            if(s[i]=='U') U++;
            if(s[i]=='D') D++;
        }
        L=min(L, R);
        U=min(U, D);
        if(L==0 && U==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(L==0)
        {
            cout<<2<<endl;
            cout<<"UD"<<endl;
            continue;
        }
        if(U==0)
        {
            cout<<2<<endl;
            cout<<"LR"<<endl;
            continue;
        }
        cout<<(2*(L+U))<<endl;
        for(int i=0; i<L; i++) cout<<"L";
        for(int i=0; i<U; i++) cout<<"U";
        for(int i=0; i<L; i++) cout<<"R";
        for(int i=0; i<U; i++) cout<<"D";
        cout<<endl;
    }

    return 0;
}