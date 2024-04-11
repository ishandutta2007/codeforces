#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n+1]; for(int i=0;i<n;i++) cin>>arr[i]; arr[n]=-1;
    sort(arr,arr+n);
    vector<int> val;
    int cur=arr[0]; int len=1;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==cur) len++;
        else
        {
            val.push_back(len);
            len=1; cur=arr[i];
        }
    }
    int gun=val[0]; int ans=0;
    for(int i=1;i<val.size();i++)
    {
        if(val[i]>=gun) {ans+=gun; gun=val[i];}
        else ans+=val[i];
    }
    cout<<ans;
    return 0;
}