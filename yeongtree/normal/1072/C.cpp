#include <iostream>

using namespace std;

int main()
{
    long long int a,b,n=0; cin>>a>>b;
    while((n*(n+1)/2)<=(a+b)) n++; n--;
    long long int k=0;
    while((k*(k+1)/2)<=a) k++; k--;
    if(k==0)
    {
        cout<<"0"<<endl<<n<<endl;
        for(int i=1;i<=n;i++) cout<<i<<" ";
        return 0;
    }
    if(k==n)
    {
        cout<<n<<endl;
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl<<"0"<<endl;
        return 0;
    }
    long long int x=a-k*(k+1)/2; x=k-x+1;
    cout<<k<<endl;
    for(int i=1;i<x;i++) cout<<i<<" ";
    for(int i=x+1;i<=k+1;i++) cout<<i<<" ";
    cout<<endl<<n-k<<endl<<x<<" ";
    for(int i=k+2;i<=n;i++) cout<<i<<" ";
    return 0;
}