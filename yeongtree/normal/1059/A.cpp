#include <iostream>

using namespace std;

int main()
{
    int n,l,a; cin>>n>>l>>a;
    int arr[2*n+2]; arr[0]=0; arr[2*n+1]=l;
    for(int i=1;i<2*n;i+=2)
    {
        cin>>arr[i]>>arr[i+1];
        arr[i+1]+=arr[i];
    }
    int ans=0;
    for(int i=0;i<=2*n;i+=2)
    {
        ans+=(arr[i+1]-arr[i])/a;
    }
    cout<<ans;
    return 0;
}