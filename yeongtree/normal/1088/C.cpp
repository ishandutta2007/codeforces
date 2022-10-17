#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    cout<<n+1<<endl;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
    int psum=0;
    for(int i=n-1;i>=0;i--)
    {
        int k=n+i-((arr[i]+psum)%n);
        cout<<"1 "<<i+1<<" "<<k<<endl;
        psum+=k;
        psum%=n;
    }
    cout<<"2 "<<n<<" "<<n<<endl;
    return 0;
}