#include <iostream>
#include <fstream>
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
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
    cout << max(abs(a[0]-b[0]),abs(a[1]-b[1])) << endl;
    while(a != b){
        if(a[0] < b[0])cout << 'R',a[0]++;
        if(a[0] > b[0])cout << 'L',a[0]--;
        if(a[1] < b[1])cout << 'U',a[1]++;
        if(a[1] > b[1])cout << 'D',a[1]--;
        cout << endl;
    }
}