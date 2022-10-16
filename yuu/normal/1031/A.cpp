#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans=0;
    int w, h, k;
    cin>>w>>h>>k;
    while(k--){
        ans+=(w+h)*2-4;
        w-=4;
        h-=4;
    }
    cout<<ans<<'\n';
}