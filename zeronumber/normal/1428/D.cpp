#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+11;
const int M=1000000007;
int _,n,a[maxn],pre[maxn];
queue <int> q[4];
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=n;i;i--){
        if (a[i]==3){
            if (!q[2].empty()){
                int x=q[2].front(); q[2].pop();
                pre[x]=i;
            } else if (!q[3].empty()){
                int x=q[3].front(); q[3].pop();
                pre[x]=i;
            } else if (!q[1].empty()){
                int x=q[1].front(); q[1].pop();
                pre[x]=i;
            } else {
                puts("-1");
                return 0;
            }
            q[3].push(i);
        } else if (a[i]==2){
            if (!q[1].empty()){
                int x=q[1].front(); q[1].pop();
                pre[x]=i;
            } else {
                puts("-1");
                return 0;
            }
            q[2].push(i);
        } else if (a[i]==1){
            q[1].push(i);
        }
    }
    int cc=n+1;
    vector<pi> ans;
    for (int i=n;i;i--) if (a[i]==1){
        --cc;
        int x=i;
        while (1){
            ans.pb((pi){cc,x});
            if (!pre[x]) break;
            else if (a[pre[x]]==3){
                ans.pb((pi){--cc,x});
            }
            x=pre[x];
        }
    }
    cout << ans.size() << endl;
    for (auto pt:ans) printf("%d %d\n",pt.F,pt.S);
    return 0;
}