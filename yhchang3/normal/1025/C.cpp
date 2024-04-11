#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans=0,anstmp;
    string s;
    cin>>s;
    int l=s.size();
    s+=s;
    for(int i=0;i<l;i++){
        anstmp=0;
        for(int j=i;j<2*l;j++){
            anstmp++;
            if(s[j]==s[j+1]||anstmp==l){
                i=j;
                break;
            }
        }
        if(ans<anstmp)  ans=anstmp;
    }
    cout<<ans<<endl;
}