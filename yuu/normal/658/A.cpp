#include <bits/stdc++.h>
using namespace std;
int n, c;
int p[51];
int t[51];
int main(){
    cin>>n>>c;
    for(int i=1; i<=n; i++) cin>>p[i];
    for(int i=1; i<=n; i++) cin>>t[i];
    int s=0;
    for(int i=1, x=0; i<=n; i++){
        x+=t[i];
        s+=max(0, p[i]-x*c);
    }
    for(int i=n, x=0; i>=1; i--){
        x+=t[i];
        s-=max(0, p[i]-x*c);
    }
    if(s>0) cout<<"Limak\n";
    else if(s<0) cout<<"Radewoosh\n";
    else cout<<"Tie\n";
}