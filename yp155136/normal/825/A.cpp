#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool check=false;
    int cnt=0;
    for (int i=0;n>i;i++) {
        if (s[i] == '1') cnt++,check=false;
        else {
            if (!check) {
                check=true;
                cout<<cnt;
                cnt=0;
            }
            else {
                cout<<0;
            }
        }
    }
    if (check || cnt!=0) cout<<cnt;
    cout<<endl;
}