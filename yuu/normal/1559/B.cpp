#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve(){
    cin>>n;
    cin>>s;
    int first=-1;
    for(int i=0; i<n; i++){
        if(s[i]!='?'){
            first=i;
            break;
        }
    }
    if(first==-1){
        for(int i=0; i<n; i++) s[i]="BR"[i%2];
    }
    else{
        for(int i=first-1; i>=0; i--){
            s[i]="BR"[s[i+1]=='B'];
        }
        for(int i=first+1; i<n; i++) if(s[i]=='?'){
            s[i]="BR"[s[i-1]=='B'];
        }
    }
    cout<<s<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}