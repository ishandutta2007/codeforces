#include <cstdio>
#include <cstring>
#include <iostream>
#include <iostream>
#include <string>
using namespace std;

int query(string s){
    cout << s << endl;
    fflush(stdout);
    int len;
    cin >> len;
    return len;
}

int main(){
    string a(300, 'a');
    string b(300, 'b');
    int len1 = query(a);
    int len2 = query(b);
    int n = 600 - len1 - len2;
    int diff = len1 - (300 - n);
    string ans(n, 'a');
    string d(n, 'a');
    int cnt = 0;
    for(int i = 0;i < n - 1;i++){
        string c = d;
        c[i] = 'b';
        int len3 = query(c);
        if(len3 < diff){
            ans[i] = 'b';
            cnt++;
        }
    }
    if(cnt < diff){
        ans[n - 1] = 'b';
    }
    cout << ans << endl;
    fflush(stdout);
    return 0;
}