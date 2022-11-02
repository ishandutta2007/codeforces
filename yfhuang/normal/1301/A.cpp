#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int t;

string a, b, c;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        bool flag = true;
        int n = a.length();
        for(int i = 0;i < n;i++){
            if(a[i] != c[i] and b[i] != c[i]){
                flag = false;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}