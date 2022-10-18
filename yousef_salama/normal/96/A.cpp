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
int main(){
    string s;
    cin >> s;
    int current = s[0], cnt = 1;
    for(int i = 1; i < s.size(); i++){
        if(current == s[i]){
            cnt++;
            if(cnt == 7){
                cout << "YES" << endl;
                return 0;
            }
        }
        else{
            cnt = 1;
            current = s[i];
        }
    }
    cout << "NO" << endl;
    return 0;
}