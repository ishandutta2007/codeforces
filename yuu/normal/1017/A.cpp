#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    int r=1;
    int s=0;
    for(int i=1, a; i<=n; i++){
        int now=0;
        for(int j=0; j<4; j++){
            cin>>a;
            now+=a;
        }
        if(i==1) s=now;
        if(now>s) r++;
    }
    cout<<r<<'\n';
}