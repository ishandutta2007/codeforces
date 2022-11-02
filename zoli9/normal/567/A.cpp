#include <iostream>
using namespace std;
int n;
int t[100009];
int mi[100009];
int ma[100009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    mi[1]=t[2]-t[1];
    ma[1]=t[n]-t[1];
    mi[n]=t[n]-t[n-1];
    ma[n]=t[n]-t[1];
    for(int i=2; i<n; i++)
    {
        mi[i]=min(t[i+1]-t[i], t[i]-t[i-1]);
        ma[i]=max(t[n]-t[i], t[i]-t[1]);
    }
    for(int i=1; i<=n; i++)
    {
        cout<<mi[i]<<" "<<ma[i]<<endl;
    }
    return 0;
}