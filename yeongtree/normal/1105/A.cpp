#include <iostream>
#include <algorithm>

using namespace std;

int len(int x,int t)
{
    if(x==t) return 0;
    return ((x>t)?(x-t):(t-x))-1;
}

int main()
{
    int n; cin>>n;
    int arr[n]; for(int i=0;i<n;++i) cin>>arr[i];
    sort(arr,arr+n);
    int _ans=987654321; int _t=0;
    for(int t=arr[0];t<=arr[n-1];++t){
        int ans=0;
        for(int i=0;i<n;++i) ans+=len(arr[i],t);
        if(_ans>ans) {_ans=ans;_t=t;}
    }
    cout<<_t<<" "<<_ans<<endl;
    return 0;
}