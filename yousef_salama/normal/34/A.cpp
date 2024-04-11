#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main()
{
    int n;
    vector <int> a;
    cin >> n;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    int max = -1,index = 0;
    for(int i = 0;i<n-1;i++){
        if(abs(a[i] - a[i+1]) < max || max == -1){
            max = abs(a[i]-a[i+1]);
            index = i;
        }
    }
    if (abs(a[0] - a[n-1]) < max)cout << 1 << ' ' << n;
    else cout << index+1 << ' ' << index+2;
    return 0;
}