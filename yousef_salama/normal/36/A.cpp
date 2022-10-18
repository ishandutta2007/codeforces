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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    int a = -1;
    for(int i = 0; i < n; i++)
        if(s[i] == '1')
            for(int j = i + 1; j < n; j++)
                if(s[j] == '1'){
                    if(a == -1){
                        a = j - i;
                        break;
                    }
                    else if(a != j - i){
                        cout << "NO" << endl;
                        return 0;
                    }
                    else break;
                }
    cout << "YES" << endl;
    return 0;
}