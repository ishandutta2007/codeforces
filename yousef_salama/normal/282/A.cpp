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

int n;
string s;
int main(){
    cin >> n;
    
    int x = 0;
    while(n--){
        cin >> s;
        
        bool p = false;
        for(int i = 0; i < s.size() - 1; i++)
            if(s[i] == '+' && s[i + 1] == '+')p = true;
        
        if(p)x++;
        else x--;
    }
    printf("%d\n", x);
    return 0;
}