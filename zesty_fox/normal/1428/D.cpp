#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define sec second
using namespace std;
typedef pair<int,int> pii;
int n,a[100010],row;
vector<pii> c[4],ans;
void fail(){
    puts("-1");
    exit(0);
}

int main(){
    cin>>n;row=n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
        if(a[i]==0) continue;
        else if(a[i]==1){
            c[1].push_back(mp(row,i));
            ans.push_back(mp(row,i));
            row--;
        }
        else if(a[i]==2){
            if(c[1].empty()) fail();
            pii x=c[1].back();
            c[1].pop_back();
            c[2].push_back(mp(x.fi,i));
            ans.push_back(mp(x.fi,i));
        }
        else if(a[i]==3){
            if(c[1].empty()&&c[2].empty()&&c[3].empty()) fail();
            for(int j=3;j>=1;j--){
                if(c[j].size()){
                    pii x=c[j].back();
                    c[j].pop_back();
                    c[3].push_back(mp(row,i));
                    ans.push_back(mp(row,i));
                    ans.push_back(mp(row,x.sec));
                    row--;
                    break;
                }
            }
        }
    }
    printf("%ld\n",ans.size());
    for(auto i:ans) printf("%d %d\n",i.fi,i.sec);
    return 0;
}