#include<bits/stdc++.h>
using namespace std;

int T;

long long n;

bool chk(long long x)
{
    long long y=x;
    while(x)
    {
        if(x%10!=0&&y%(x%10))
            return 0;
        x/=10;
    }
    return 1;
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(long long i=n;;i++)
        {
            if(chk(i))
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}