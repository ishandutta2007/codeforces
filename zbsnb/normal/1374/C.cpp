#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int now=0;
        int minn=1e9;
        for(int i=0;i<n;i++){
            if(s[i]=='(')now++;
            else now--;
            minn=min(minn,now);
        }
        cout<<(-minn)<<endl;

    }
}