#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve(){
    cin>>n>>k;
    vector <int> digits;
    while(n>0){
        digits.push_back(n%10);
        n/=10;
    }
    reverse(digits.begin(), digits.end());
    long long ans=1;
    for(int i=0; i<digits.size(); i++) ans*=10;
    set <int> used;
    long long val=0;
    for(int prefix=0; prefix<digits.size(); prefix++){
        if(used.size()>k) break;
        for(int i=digits[prefix]+1; i<=9; i++){//first > 
            int found = used.find(i)!=used.end();
            used.insert(i);
            if(used.size()<=k){
                long long res=val*10+i;
                if(used.size()<k){
                    for(int j=prefix+1; j<digits.size(); j++) res*=10;
                }
                else{
                    for(int j=prefix+1; j<digits.size(); j++) (res*=10)+=(*used.begin());
               }
                ans=min(ans, res);
                if(!found) used.erase(i);
                break;
            }
            if(!found) used.erase(i);
        }
        used.insert(digits[prefix]); 

        (val*=10)+=digits[prefix];
    }
    if(used.size()<=k) ans=val;
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}