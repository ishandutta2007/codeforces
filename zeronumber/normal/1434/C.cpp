#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
ll a,b,c,d,x,ans;
int _;
int main(){
    cin >> _;
    while (_--){
        cin >> a >> b >> c >> d;
        if (a>b*c){puts("-1");continue;}
        x=a/(b*d);
        ans=(a+a-x*b*d)*(x+1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}