#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,res[200010],cnt;
pii p[200010];
char tmp[4];
set<int> s;
int main(){
    cin>>n;
    for(int i=1;i<=2*n;i++){
        int x;scanf("%s",tmp);
        if(tmp[0]=='+') p[i]=mp(1,0);
        else scanf("%d",&x),p[i]=mp(2,x);
    }
    cnt=n;
    for(int i=2*n;i>=1;i--){
        if(p[i].first==1){
            if(s.empty()){
                puts("NO");
                return 0;
            }
            else{
                res[cnt--]=(*s.begin());
                s.erase(s.begin());
            }
        }
        else s.insert(p[i].second);
    }
    s.clear();cnt=1;
    for(int i=1;i<=2*n;i++){
        if(p[i].first==1) s.insert(res[cnt]),cnt++;
        else{
            int x=(*s.begin());s.erase(s.begin());
            if(x!=p[i].second){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",res[i]);
    puts("");
    return 0;
}