#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    pair <char, int> ans={'E', 0};
    for(int i=0; i<3; i++){
        ans=min(ans, {"DACB"[(x+i)%4], i});
    }
    cout<<ans.second<<' '<<ans.first<<'\n';
}