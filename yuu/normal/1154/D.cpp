#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main(){
    cin>>n>>b>>a;
    int x=a;
    int ans=0;
    for(int i=1, s; i<=n; i++){
        cin>>s;
        if(x+b==0) break;
        ans=i;
        if(s&&(x<a)&&b){
            b--;
            x++;
        }
        else if(x) x--;
        else b--;
    }
    cout<<ans;
}