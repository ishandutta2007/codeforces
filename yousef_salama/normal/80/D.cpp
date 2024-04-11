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
int t;
double a, b;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(b == 0)printf("%.10f\n", 1.0);
        else if(a == 0)printf("%.10f\n", 0.5);
        else{
            if(a < b * 4)printf("%.10f\n", 0.5 + a / (b * 16));
            else printf("%.10f\n", (a - b) / a);
        }
    }
    return 0;
}