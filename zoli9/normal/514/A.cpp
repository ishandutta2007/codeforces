#include <iostream>
using namespace std;
unsigned long long a;
int t[25];
int main()
{
    int db=0;
    cin>>a;
    while(a!=0)
    {
        db++;
        t[db]=a%10;
        a-=t[db];
        a/=10;

    }

if(t[db]>=5 && t[db]!=9)
{
    t[db]=9-t[db];
}
for(int i=db-1; i>=1; i--)
{
    if(t[i]>=5)
    {
        t[i]=9-t[i];
    }
}
for(int i=db; i>=1; i--)
{
    cout<<t[i];
}
    return 0;
}