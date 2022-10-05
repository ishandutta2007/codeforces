#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, now, ans=1;
set<int>S;

int main(){
    cin>>n;
    S.insert(-1);
    cin>>now;
    for (int i=2;i<=n;++i){
        int x; scanf("%d",&x);
        if (x==now){
            if (S.size()==1&&S.count(x)){

            }else{
                S.clear();
                S.insert(x);
                now=x;
                ans++;
            }
        }else{
            if (S.size()==1&&S.count(x)){
                now=x;
                ans++;
            }else{
                S.insert(now);
                now=x;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}