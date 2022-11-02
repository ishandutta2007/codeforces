#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

bool check(string a, string b){
    return (a[0] == b[0]) || (a[1] == b[1]);
}

int main(){
    string a;
    string b;
    cin >> a;
    bool flag = false;
    for(int i = 0;i < 5;i++){
        cin >> b;
        flag |= check(a, b);
    }
    if(flag){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}