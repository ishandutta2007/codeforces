#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> v;
    n*=2;
    int nn=n;
    while (n--) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    n=nn;
    if (v[n/2] != v[n/2-1]) puts("YES");
    else puts("NO");
}