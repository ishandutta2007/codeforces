#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n,a[102];
    vector<int> x;
    bool m=true,M=true;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        x.push_back(a[i]);
    }
    sort(x.begin(),x.end());
    printf("%d",x[n-1]);
    for(int i=1;i<=n-2;i++){
        printf(" %d",x[i]);
    }
    printf(" %d\n",x[0]);
}