#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector <int> v;
int n;
void solve(){
    scanf("%d",&n);
    while(n--){
        int x;
        char op[3];
        scanf("%s",op);
        if(op[0]=='a'){
            scanf("%d",&x);
            v.insert(lower_bound(v.begin(),v.end(),x),x);
        }
        if(op[0]=='d'){
            int x;
            scanf("%d",&x);
            v.erase(lower_bound(v.begin(),v.end(),x));
        }
        if(op[0]=='s'){
            long long ans=0;//????long long,?????90?
            for(int i=2;i<v.size();i+=5)
                    ans+=v[i];
            printf("%lld\n",ans);
        }
    }
}
int main(){
    solve();
    return 0;
}