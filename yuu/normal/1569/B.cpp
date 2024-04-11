#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char ans[51][51];
vector <int> win;
void solve(){
    cin>>n>>s;
    win.clear();
    for(int i=0; i<s.size(); i++) if(s[i]=='2') win.push_back(i+1);
    if((!win.empty()) && (win.size()<3)){
        cout<<"NO\n";
        return;
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        ans[i][j]="=X"[i==j];
    }

    for(int p=0; p<win.size(); p++){
        int i=win[p];
        int j=win[(p+1)%win.size()];
        ans[i][j]='+';
        ans[j][i]='-';
    }
    cout<<"YES\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout<<ans[i][j];
        cout<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}