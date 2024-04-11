#include <bits/stdc++.h>
using namespace std;
string s;
const int minlength=12;
long long ans=0;
bool good[1<<minlength];
void backtrack(string s, int mask, int l){
    if(s.size()==l){
        for(int x=0; x<s.size(); x++) for(int k=1; k<s.size(); k++){
            if(x+k+k>=s.size()) break;
            if(s[x]==s[x+k]&&s[x]==s[x+k+k]){
                good[mask]=1;
                return;
            }
        }
    }
    else{
        backtrack(s+'0', mask*2, l);
        backtrack(s+'1', mask*2+1, l);
    }
}
int main(){
    cin>>s;
    for(int i=minlength; i<=s.size(); i++) ans+=s.size()-i+1;
    for(int i=3; i<minlength; i++){
        if(i>s.size()) break;
        for(int j=0; j<(1<<i); j++) good[j]=0;
        backtrack("", 0, i);
        for(int j=0; j<s.size(); j++){
            if(j+i-1>=s.size()) break;
            int m=0;
            for(int k=0; k<i; k++) m=m*2+s[j+k]-48;
            ans+=good[m];
        }
    }
    cout<<ans;
}