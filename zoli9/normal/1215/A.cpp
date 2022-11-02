#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int a1, a2, k1, k2, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a1>>a2>>k1>>k2>>n;
    int mini;
    if(n>=(a1*k1-a1+a2*k2-a2)) mini=n-(a1*k1-a1+a2*k2-a2);
    else mini=0;
    if(k1>k2)
    {
        swap(k1, k2);
        swap(a1, a2);
    }
    for(int i=1; i<=a1; i++)
    {
        if(n>=k1)
        {
            n-=k1;
        }
        else
        {
            cout<<mini<<" "<<i-1<<endl;
            return 0;
        }
    }
    for(int i=1; i<=a2; i++)
    {
        if(n>=k2)
        {
            n-=k2;
        }
        else
        {
            cout<<mini<<" "<<a1+i-1<<endl;
            return 0;
        }
    }
    cout<<mini<<" "<<a1+a2<<endl;

    return 0;
}