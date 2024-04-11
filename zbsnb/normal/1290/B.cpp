#include<iostream>
#include<cstring>
using namespace std;
int cnt[1000010][26];
char s[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            cnt[i][j]=cnt[i-1][j]+(s[i]=='a'+j);
        }
    }
    int t;cin>>t;
    while(t--){
        int l,r;cin>>l>>r;

        int tmp=0;
        for(int i=0;i<26;i++){
            tmp+=(bool)(cnt[r][i]-cnt[l-1][i]);
        }

        // cout<<t<<" "<<tmp<<endl;
        if(tmp>=3){
            cout<<"Yes\n";
        }
        else if(tmp==2){
            if(s[l]==s[r])cout<<"No\n";
            else cout<<"Yes\n";
        }
        else {
            if(l==r)cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}