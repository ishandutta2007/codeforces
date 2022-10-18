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
#include <string.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (n * 2) - (i * 2); j++)
            cout << ' ';
        for(int j = 0; j <= i; j++){
            if(j != 0)cout << ' ';
            cout << j;
        }
        for(int j = i - 1; j >= 0; j--){
            cout << ' ' << j;
        }
        cout << endl;
    }
    for(int j = 0; j <= n; j++){
        if(j != 0)cout << ' ';
        cout << j;
    }
    for(int j = n - 1; j >= 0; j--){
        cout << ' ' << j;
    }
    cout << endl;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < (n * 2) - (i * 2); j++)
            cout << ' ';
        for(int j = 0; j <= i; j++){
            if(j != 0)cout << ' ';
            cout << j;
        }
        for(int j = i - 1; j >= 0; j--){
            cout << ' ' << j;
        }
        cout << endl;
    }
    return 0;
}