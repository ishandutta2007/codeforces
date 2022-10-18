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
    char rank[] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char temp;
    cin >> temp;
    string a, b;
    cin >> a >> b;
    int a1, a2;
    for(int i = 0; i < 9; i++)
        if(a[0] == rank[i])a1 = i;
    for(int i = 0; i < 9; i++)
        if(b[0] == rank[i])a2 = i;
    if(b[1] == a[1] && a1 > a2)cout << "YES" << endl;
    else if(a[1] == temp && b[1] != temp)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}