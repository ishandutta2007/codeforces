#include <iostream>
using namespace std;
int main ()
{
    int n,k=0,r=1;
    char a[10010];
    cin>>n;
    while (k<n*n)
    {
        k++;
        cin>>a[k];
    }
    k=0;
    while (k<n*n)
    {
        k++;
        if (a[k]=='#')
        {
            if (k%n==0) r=0;
            else if (k%n==1) r=0;
            else if (k>(n-2)*n) r=0;
            else
            {
                if (a[k+n]!='#') r=0;
                else if (a[k+n+1]!='#') r=0;
                else if (a[k+n-1]!='#') r=0;
                else if (a[k+n+n]!='#') r=0;
                else {
                a[k]='.';
                a[k+n]='.';
                a[k+n+1]='.';
                a[k+n-1]='.';
                a[k+n+n]='.';
                }
            }
        }
    }
    if (r==0) {cout<<"NO";}
    else cout<<"YES";
    return 0;
}