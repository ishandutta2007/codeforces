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
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.')
            cout << 0;
        else{
            if(s[i + 1] == '.'){
                cout << 1;
                i++;
            }else{
                cout << 2;
                i++;
            }
        }
    }
    cout << endl;
    return 0;
}