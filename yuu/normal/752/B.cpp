#include <iostream>
#include <stdio.h>
using namespace std;
string s, t;
char ke[256];
bool done[256];
int cnt=0;
int main(){
//    freopen("B.INP", "r", stdin);
//f*ckyou
    cin>>s>>t;
    for(int i=0; i<s.size(); i++){
        if(ke[s[i]]){
            if(ke[s[i]]!=t[i]){
                cout<<"-1";
                return 0;
            }
        }
        else{
            if(ke[t[i]]!=s[i]&&ke[t[i]]!=0){
                cout<<"-1";
                return 0;
            }
            cnt+=s[i]!=t[i];
            ke[s[i]]=t[i];
            ke[t[i]]=s[i];
        }
    }
    cout<<cnt<<'\n';
    for(char i='a'; i<='z'; i++){
        if(!done[i]&&ke[i]!=0){
            if(ke[i]!=i){
                cout<<i<<' '<<ke[i]<<'\n';
                done[ke[i]]=1;
            }
        }
    }
}