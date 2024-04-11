#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 

pair<double, pair<int, int> > min(pair<double, pair<int, int> > a, pair<double, pair<int, int> > b){
    if(abs(a.first - b.first) < 1e-15) return a.second.first < b.second.first ? a : b;
    return std::min(a, b);
    
}


int main(void){
    double x,y,n;
    double a;
    pair<double, pair<int, int> > ans(100000000.0, pair<int, int>(0, 0));
    cin>>x>>y>>n;
    for(int b=1;b<=n;b++){
        a=(ceil(x*b/y));
        ans = min(ans, pair<double, pair<int, int> >(abs(x/y-a/b), pair<int, int>(b, (int)(a+1e-8))));
        a=(floor(x*b/y));
        ans = min(ans, pair<double, pair<int, int> >(abs(x/y-a/b), pair<int, int>(b, (int)(a+1e-8))));
    }
    cout<<ans.second.second<<"/"<<ans.second.first<<endl;
    return 0;
}