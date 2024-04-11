#include<iostream>
using namespace std;

// char s[100010];
int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int flg=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                flg=1;
            }
        }
        if(!flg){
            cout<<"0"<<endl;
            continue;
        }
        int l,r;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                l=i;
                break;
            }
        }
        int tmp=s.size();
        for(int i=tmp-1;i>=0;i--){
            if(s[i]=='1'){
                r=i;
                break;
            }
        }
        int ans=0;
        for(int i=l;i<=r;i++){
            if(s[i]=='0')ans++;
        }
        cout<<ans<<endl;
    }
}