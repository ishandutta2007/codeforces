#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

string s;
int p[10005];
int main(){
    ios::sync_with_stdio(false);
    cin >> s;
    int n = s.length();
    string t = "";
    for(int i = 0;i < n;i++){
        t += (char)(i / (26 * 26) + 'a'); 
    }
    cout << "? " << t << endl;
    fflush(stdout);
    string tmp;
    cin >> tmp;
    for(int i = 0;i < n;i++){
        p[i] = p[i] * 26 + (tmp[i] - 'a');
    } 
    t = "";
    for(int i = 0;i < n;i++){
        t += (char)((i / 26) % 26 + 'a'); 
    }
    cout << "? " << t << endl;
    fflush(stdout);
    cin >> tmp;
    for(int i = 0;i < n;i++){
        p[i] = p[i] * 26 + (tmp[i] - 'a');
    } 
    t = "";
    for(int i = 0;i < n;i++){
        t += (char)((i % 26) + 'a'); 
    }
    cout << "? " << t << endl;
    fflush(stdout);
    cin >> tmp;
    for(int i = 0;i < n;i++){
        p[i] = p[i] * 26 + (tmp[i] - 'a');
    } 
    t = "";
    for(int i = 0;i < n;i++){
        t += 'a';
    }
    for(int i = 0;i < n;i++){
        t[p[i]] = s[i];
    }
    cout << "! " << t << endl;
    fflush(stdout);
    return 0;
}