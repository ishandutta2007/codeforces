#include <iostream>
using namespace std;
string s;
int main(){
    cin>>s;
    s='a'+s;
    int cw, ccw, ans=0;
    for(int i=1; i<s.size(); i++){
        cw=s[i]-s[i-1];
        if(cw<0) cw+=26;
        ccw=s[i-1]-s[i];
        if(ccw<0) ccw+=26;
        ans+=min(cw, ccw);
    }
    cout<<ans;
}