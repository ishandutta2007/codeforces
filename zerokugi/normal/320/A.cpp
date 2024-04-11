#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 1;
    if(s[0] != '1') ans = 0;
    for(char c : s){
        if(c != '1' && c != '4') ans = 0;
    }
    if(s.find("444") != string::npos) ans = 0;
    puts(ans ? "YES" : "NO");
    return 0;
}