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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

string a, b;
int main(){
    cin >> a >> b;
    
    int c1 = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '1')c1++;
    }
    
    int c2 = 0;
    for(int i = 0; i < b.size(); i++){
        if(b[i] == '1')c2++;
    }
    
    if(c1 % 2 == 0){
        if(c2 <= c1)cout << "YES" << endl;
        else cout << "NO" << endl;
    }else{
        if(c2 <= c1 + 1)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}