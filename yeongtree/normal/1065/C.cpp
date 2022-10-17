#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,k; cin>>n>>k;
    int h[n]; for(int i=0;i<n;i++) cin>>h[i];
    sort(h,h+n,greater<int>());
    if(h[0]==h[n-1]) {cout<<"0"; return 0;}
    int ans=1; int current_cost=0; int current_slicing=0;
    for(int i=h[0];i>h[n-1];i--)
    {
        if(h[current_slicing]==i) {while(h[++current_slicing]==i) {}}
        current_cost+=current_slicing;
        if(current_cost>k) {current_cost=current_slicing; ans++;}
    }
    cout<<ans;
    return 0;
}