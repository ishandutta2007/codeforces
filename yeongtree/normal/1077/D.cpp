#include <iostream>
#define N 200000

using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    int num[N+5]={0,}; for(int i=0;i<n;i++) num[arr[i]]++;

    int s=1; int t=n/k+1;
    while(s<t-1)
    {
        int mid=(s+t)/2;
        int ans=0;
        for(int i=1;i<=N;i++) ans+=num[i]/mid;
        if(ans<k) t=mid;
        else s=mid;
    }

    int index=1;
    for(int i=0;i<k;i++)
    {
        while(num[index]<s) index++;
        cout<<index<<" ";
        num[index]-=s;
    }

    return 0;
}