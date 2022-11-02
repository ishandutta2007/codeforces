#include <bits/stdc++.h>
using namespace std;

int pt[200005];
 
bool serch(int f,int t,int find){
    if (f > t){
        return 0;
    }
    int mid = (f + t) / 2;
    if (pt[mid] == find){
        return 1;
    }
    if (pt[mid] > find){
        return serch(f,mid-1,find);
    }
    return serch(mid+1,t,find);
}
 
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>pt[i];
    }
    sort(pt+1,pt+n+1);
    int ans[3];
    int tot = 1;
    ans[0] = pt[1];
    for (int i=1;i<=n;i++){
        for (int j=0;j<31;j++){
            int step = 1<<j;
            bool fl = serch(1,n,pt[i] - step);
            bool fr = serch(1,n,pt[i] + step);
            if (fl && fr && tot < 3){
                ans[0] = pt[i] - step;
                ans[1] = pt[i];
                ans[2] = pt[i] + step;
                tot = 3;
            }
            if (fl && tot < 2){
                ans[0] = pt[i] - step;
                ans[1] = pt[i];
                tot = 2;
            }
            if (fr && tot < 2){
                ans[0] = pt[i];
                ans[1] = pt[i] + step;
                tot = 2;
            }
        }
    }
    cout<<tot<<endl;
    for (int i=0;i<tot;i++){
        cout<<ans[i]<<' ';
    }
    puts("");
    return 0;
}