#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    cin>>n;
    while(n--){
        cin>>s;
        sort(s.begin(), s.end());
        if(s.size()==s.back()-s[0]+1){
            if(unique(s.begin(), s.end())==s.end()) puts("Yes");
            else puts("No");
        }
        else puts("No");
    }
}