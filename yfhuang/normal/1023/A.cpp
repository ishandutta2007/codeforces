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

int n, m;
const int maxn = 2e5 + 5;

char s[maxn], t[maxn];

int main(){
    cin >> n >> m;
    scanf("%s", s + 1);
    scanf("%s", t + 1); 
    bool flag = false;
    for(int i = 1;i <= n;i++){
        if(s[i] == '*')
            flag = true;
    }
    bool ok = true;
    if(flag){
        if(n - 1 > m)
            ok = false;
    }else{
        if(n != m)
            ok = false;
    }
    for(int i = 1;i <= n;i++){
        if(s[i] == '*')
            break;
        if(i > m)
            ok = false;
        else{
            if(s[i] != t[i])
                ok = false;
        }
    } 
    if(flag){
        for(int i = 1;i <= n;i++){
            if(s[n + 1 - i] == '*')
                break;
            if(i > m)
                ok = false;
            else{
                if(s[n + 1 - i] != t[m + 1 - i])
                    ok = false;
            }
        }
    }
    if(ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}