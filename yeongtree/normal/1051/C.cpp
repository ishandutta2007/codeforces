#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n]; int check[101];
    for(int i=1;i<=100;i++) check[i]=0;
    for(int i=0;i<n;i++) {cin>>arr[i]; check[arr[i]]++;}
    char ans[n+1]; bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(check[arr[i]]==1)
        {
            if(flag) ans[i]='B';
            else ans[i]='A';
            flag=!flag;
        }
        else ans[i]='A';
    }
    if(flag)
    {
        for(int i=1;i<=100;i++)
        {
            if(check[i]>=3)
            {
                for(int j=0;j<n;j++)
                {
                    if(arr[j]==i) {ans[j]='B'; break;}
                }
                flag=false;
                break;
            }
        }
    }
    if(flag)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++) cout<<ans[i];
    }
    return 0;
}