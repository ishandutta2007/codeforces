#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int test;
int a, b;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>a>>b;
        cin>>s;
        swap(a, b);
        bool ok=true;
        int po=0;
        int big=0;
        int small=0;
        int B;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='.') po++;
            else
            {
                if(po>=a && po<b)
                {
                    ok=false;
                    break;
                }
                if(po>=2*a)
                {
                    big++;
                    B=po;
                }
                else if(po>=b) small++;
                po=0;
            }
        }
        if(po>=a && po<b)
        {
            ok=false;
        }
        if(po>=2*a)
        {
            big++;
            B=po;
        }
        else if(po>=b) small++;
        if(!ok)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(big>=2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(big==0)
        {
            if(small%2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        bool k0=false;
        bool k1=false;
        bool k2=false;
        if(B-b<=2*a-2) k0=true;
        if(b<2*a)
        {
            if(B-b>=b && B-b<=3*a-2) k1=true;
            if(B-b>=2*b && B-b<=4*a-2) k2=true;
        }
        if((k0 && k1) || (k1 && k2))
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(k0 || k2) small++;
        if(!(k0 || k1 || k2))
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(small%2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}