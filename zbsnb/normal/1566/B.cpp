#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--) {
        string s;cin>>s;
        int pre = -1;
        int cnt = 0;
        for(auto &it:s) {
            if(it == '0') {
                if(pre != '0') {
                    cnt++;
                }
            }
            pre = it;
        }
        cout<<min(2,cnt)<<"\n";
    }
}