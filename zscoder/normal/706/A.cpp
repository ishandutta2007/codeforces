#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;int y;
    cin >> x >>y;
    int k;cin >>k;
    double ans=1e7;
    for (int i=0;i<k;i++){
        int x1,y1,v;
        cin >> x1>>y1>>v;
        int cur;
        cur= ((x1-x)*(x1-x)+(y1-y)*(y1-y));
        double c2= sqrt(cur);
        c2=(c2/v);
        ans= min(ans,c2);
    }
    cout << fixed << setprecision(10) << ans <<endl;

return 0;
}