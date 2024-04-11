#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    long long int m1=0,m2=0; int index_m1;
    for(int i=0;i<n;i++)
    {
        if(m1<arr[i]) {m1=arr[i]; index_m1=i;}
    }
    for(int i=0;i<n;i++)
    {
        if(i==index_m1) continue;
        if(m2<arr[i]) m2=arr[i];
    }

    long long int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];

    vector<int> ans;

    if(2*m2==sum-m1) ans.push_back(index_m1+1);

    for(int i=0;i<n;i++)
    {
        if(i==index_m1) continue;
        if(2*m1==sum-arr[i]) ans.push_back(i+1);
    }

    int k=ans.size();
    cout<<k<<endl;
    for(int i=0;i<k;i++) cout<<ans[i]<<" ";
    return 0;
}