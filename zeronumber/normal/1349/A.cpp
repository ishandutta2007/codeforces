#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+3;
long long ans;
bool p[maxn];
int mx[maxn][2],n;
map <int,int> f;
void ins(int x,int y){
    f[x]++;
    if (mx[x][0]>y) mx[x][1]=mx[x][0],mx[x][0]=y;
    else if (mx[x][1]>y) mx[x][1]=y;
}
int main(){
    ans=1;
    for (int i=2;i<maxn;i++) if (!p[i]) {
        for (int j=2;j*i<maxn;j++) p[i*j]=1;
        mx[i][0]=mx[i][1]=1000;
    }
    cin >> n;
    for (int i=0;i<n;i++){
        int x,j; cin >> x; j=2;
        while (j*j<=x){
            if (x%j==0){
                int cc=0;
                while (x%j==0) ++cc,x/=j;
                ins(j,cc);
            }
            ++j;
        }
        if (x>1) ins(x,1);
    }
    for (int i=2;i<maxn;i++) if (!p[i]){
        if (f[i]==n){
            for (int j=0;j<mx[i][1];j++) ans=ans*i;
        } else if (f[i]==n-1){
            for (int j=0;j<mx[i][0];j++) ans=ans*i;
        }
    }
    cout << ans << endl;
    return 0;
}