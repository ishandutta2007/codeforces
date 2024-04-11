#include <iostream>
using namespace std;
int n, result;
int digits[15];
int cnt;
int main()
{
    cin>>n;
    cnt=0;
    while(n>0)
    {
        if(n%10==4)
        {
            digits[cnt]=0;
            n-=4;
            n/=10;
        }
        else
        {
            digits[cnt]=1;
            n-=7;
            n/=10;
        }
        cnt++;
    }
    digits[cnt]=1;
    result=0;
    for(int i=cnt; i>=0; i--)
    {
        if(digits[i]==1)
        {
            result+=(1<<i);
        }
    }
    cout<<result-1;
    return 0;
}