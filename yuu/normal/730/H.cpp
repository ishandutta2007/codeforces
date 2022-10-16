#include <iostream>
using namespace std;
int n, m;
string s[101];
string ct[101];
int a[101];
int t;
int x;
string ans;
bool check(string s){
    for(int i=0; i<x; i++){
        if(ans[i]!='?'){
            if(s[i]!=ans[i])
                return 1;
        }
    }
    return 0;
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>s[i];
    cin>>t;
    a[t]=1;
    ct[1]=s[t];
    for(int i=2; i<=m; i++){
        cin>>t;
        a[t]=1;
        ct[i]=s[t];
        if(ct[i].size()!=ct[i-1].size()){
            cout<<"No";
            return 0;
        }
    }
    x=ct[1].size();
    ans=ct[1];
    for(int i=0; i<x; i++){
        for(int j=1; j<=m; j++){
            if(ans[i]!=ct[j][i]){
                ans[i]='?';
                j=m+1;
            }
        }
    }
    for(int i=1; i<=n;i++){
        if(!a[i]&&s[i].size()==x){
            if(!check(s[i])){
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes\n"<<ans;

}