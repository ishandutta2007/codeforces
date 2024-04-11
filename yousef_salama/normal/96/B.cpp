#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#define oo 1 << 25
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    long long ans = -1;
    for(int itr = 0; ; itr++){
        for(long long lucky = 0; lucky < 1 << (n + itr); lucky++){
            string a = "";
            int cnt = 0;
            for(long long i = 0; i < (n + itr); i++){
                if(lucky & (1 << i))a += '7';
                else{
                    a += '4';
                    cnt++;
                }
            }
            if(((n + itr) - cnt) == cnt){
                long long m = atoll(a.c_str());
                if(m >= atoll(s.c_str()) && (m < ans || ans == -1))ans = m;
            }
        }
        if(ans != -1)break;
    }
    cout << ans << endl;
    return 0;
}