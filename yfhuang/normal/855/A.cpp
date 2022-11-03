#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

map<string,int> mp;

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        string s;
        cin >> s;
        if(mp.count(s)){
            puts("YES");
        }else{
            mp[s]++;
            puts("NO");
        }
    }
    return 0;
}