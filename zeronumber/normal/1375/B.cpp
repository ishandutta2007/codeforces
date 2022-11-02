#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e5+3;
const int M=1000000007;
int _,n,m,a[505][505],b[505][505];

int main(){
    cin >> _;
    while (_--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        bool flag=0;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            b[i][j]=4-(i==1)-(i==n)-(j==1)-(j==m);
            flag|=a[i][j]>b[i][j];
        }
        if (flag) puts("NO");
        else {
            puts("YES");
            for (int i=1;i<=n;i++){
                for (int j=1;j<=m;j++) printf("%d ",b[i][j]);
                puts("");
            }
        }
    }
    return 0;
}