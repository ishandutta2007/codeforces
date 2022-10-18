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
using namespace std;
int k, cnt[30];
string s;
int main(){
    cin >> k >> s;
    for(int i = 0; i < s.size(); i++)
        cnt[s[i] - 'a']++;
    for(int i = 0; i < 30; i++){
        if(cnt[i] % k != 0){
            cout << -1 << endl;
            return 0;
        }else cnt[i] /= k;
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 30; j++){
            for(int k = 0; k < cnt[j]; k++)
                cout << (char)(j + 'a');
        }
    }
    cout << endl;
    return 0;
}