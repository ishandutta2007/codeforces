#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int prev=0; int pos=0; bool flag=false;
    for(int i=0;i<k;i++)
    {
        flag=true;
        while(pos<n)
        {
            if(arr[pos]==prev) {pos++; continue;}
            cout<<arr[pos]-prev<<endl;
            prev=arr[pos];
            pos++;
            flag=false;
            break;
        }
        if(flag) cout<<"0"<<endl;
    }
}