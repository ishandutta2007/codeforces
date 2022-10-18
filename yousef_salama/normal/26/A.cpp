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
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int main(){
    int n;
    cin >> n;
    int candidates[n];
    candidates[0] = 1;
    for(int i =1;i < n;i++)candidates[i] = i+1;
    bool v[n];
    for(int i =0;i<n;i++){
        v[i] = 0;
    }
    vector <int> primes;
    for(int i =1;i<n-1;i++){
        if(!v[candidates[i]]){
            for(int j = candidates[i]*2;j<n;j+=candidates[i]){
                v[j] = 1;
            }
            primes.push_back(candidates[i]);
        }
    }
    int m = 0;
    for(int i =1;i<n;i++){
        int cnt = 0;
        for(int j =0;j<primes.size();j++){
            if(candidates[i] % primes[j] == 0)cnt++;
        }
        if(cnt == 2)m++;
    }
    cout << m << endl;
}