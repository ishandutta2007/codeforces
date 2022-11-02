#include <bits/stdc++.h>
using namespace std;

int digsum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=(x%10);
        x/=10;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin>>a;

    for(int i=a; i<=100000; i++)
    {
        if(digsum(i)%4==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }


    return 0;
}