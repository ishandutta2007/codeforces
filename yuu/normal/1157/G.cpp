#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[201][201];
int t[201][201];
int row[201];
int col[201];
void check(int u){
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) t[i][j]=1;
    for(int i=1; i<=u; i++) t[1][i]=0;
    for(row[1]=0; row[1]<=1; row[1]++){
        bool good=1;
        for(int i=1; i<=m; i++) col[i]=t[1][i]^row[1]^a[1][i];
        for(int i=2; i<=n; i++) row[i]=t[i][1]^col[1]^a[i][1];
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(t[i][j]^row[i]^col[j]^a[i][j]){
            good=0;
            goto line0;
        }
        line0:;
        if(good){
            puts("YES");
            for(int i=1; i<=n; i++) cout<<row[i];
            cout<<'\n';
            for(int i=1; i<=m; i++) cout<<col[i];
            cout<<'\n';
            exit(0);
        }
    }
}
void check2(int u){
    for(int i=2; i<=u; i++) row[i]=a[i][1]^col[1];
    for(int i=u+1; i<=n; i++) row[i]=a[i][1]^col[1]^1;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) t[i][j]=a[i][j]^row[i]^col[j];
    bool one=0;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(t[i][j]) one=1;
    else if(one) return;
    puts("YES");
    for(int i=1; i<=n; i++) cout<<row[i];
    cout<<'\n';
    for(int i=1; i<=m; i++) cout<<col[i];
    cout<<'\n';
    exit(0);
}
void check_full(){
    for(row[1]=0; row[1]<=1; row[1]++){
        bool good=1;
        for(int i=1; i<=m; i++) col[i]=row[1]^a[1][i];
        for(int i=1; i<=n; i++) check2(i);
    }
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>a[i][j];
    for(int i=0; i<m; i++) check(i);
    check_full();
    puts("NO");
}