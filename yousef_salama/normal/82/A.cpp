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
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    n--;
    int b = 1,c = 5;
    while(n >= c){
        n -= c;
        c *= 2;
        b *= 2;
    }
    string a[] = {"Sheldon","Leonard","Penny","Rajesh","Howard"};
    cout << a[n / b] << endl;
}