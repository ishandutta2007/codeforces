#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
    int m=0; int k=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]*2<arr[i])
        {
            if(m<k) m=k;
            k=0;
        }
        else k++;
    }
    if(m<k) m=k;
    cout<<m+1;
    return 0;
}