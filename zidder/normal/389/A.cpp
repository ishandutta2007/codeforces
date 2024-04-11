#include <iostream>
using namespace std;
int m (int a , int b)
{   
    int r;
    if (a>b) r=b;
    else r=a;
    return r;
}
int f (int a, int b)
{
    int r,k=0;
    r=m(a,b);
    while (k<1)
    {
        if (a%r==0)
        {
            if (b%r==0) k=1;
            else r--;
        }
        else r--;
    }
    return r;
}
int main ()
{
    int a[101],n,k=1,s;
    cin>>n;
    cin>>a[1];
    s=a[1];
    while (k<n)
    {
        k++;
        cin>>a[k];
        s=f(s,a[k]);
    }
    cout<<s*n;
    return 0;
}