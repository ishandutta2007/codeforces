#include<bits/stdc++.h>
using namespace std;
int a,b;
int main()
{
    cin>>a>>b;
    while(b)
    {
        if(b%a==1) b=(b-1)/a;
        else if(b%a==a-1) b=(b+1)/a;
        else if(b%a==0) b=b/a;
        else { puts("NO"); return 0;}
    }
    puts("YES");
    return 0;
}