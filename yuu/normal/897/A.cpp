#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    string s;
    cin>>n>>m>>s;
    for(int i=0; i<m; i++){
        int l, r;
        char f, t;
        cin>>l>>r>>f>>t;
        l--;
        r--;
        while(l<=r){
            if(s[l]==f) s[l]=t;
            l++;
        }
    }
    cout<<s<<'\n';
}