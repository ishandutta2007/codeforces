#include <bits/stdc++.h>
using namespace std;
int test;
long long m1, m2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        long long a, b;
        char c;
        cin>>c;
        if(c=='+')
        {
            cin>>a>>b;
            if(b<a) swap(a, b);
            m1=max(a, m1);
            m2=max(b, m2);
        }
        else
        {
            cin>>a>>b;
            if(b<a) swap(a, b);
            if(a>=m1 && b>=m2)
            {
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}