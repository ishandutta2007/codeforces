#include<bits/stdc++.h>
using namespace std;
int val[201000],n,x,pos;
vector<int>v[201000];

int main(){
    scanf("%d",&n);
    val[n]=2010001000;
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        pos=lower_bound(val,val+n+1,x)-val;
        while (x<=val[pos]) pos--;
        v[pos].push_back(x);
        val[pos]=x;
    }
    for (int i=n-1;i>=0;i--){
        if (!val[i]) return 0;
        for (int j=0;j<(int)v[i].size();j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
}