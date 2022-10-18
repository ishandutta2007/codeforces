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
int a, b, c;
int main(){
    cin >> a >> b >> c;
    for(int t = 0; ; t++){
        bool wrong = false;
        for(int i = t; i <= c + t; i++)
            if(i * b < (i - t) * a)wrong = true;
        if(!wrong){
            cout << t << endl;
            break;
        }
    }
    return 0;
}