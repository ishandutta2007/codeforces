#include <iostream>
#include <stdio.h>
using namespace std;
string a, b;
int cnt[50][200001];
int main(){
//    freopen("B.INP", "r", stdin);
    cin>>a>>b;
    a='a'+a;
    b='b'+b;
    for(int i=1; i<b.size(); i++){
        cnt['0'][i]=cnt['0'][i-1];
        cnt['1'][i]=cnt['1'][i-1];
        cnt[b[i]][i]=cnt[b[i]][i-1]+1;
    }
    long long ans=0;
    for(int i=1; i<a.size(); i++)
        ans+=cnt['1'+'0'-a[i]][b.size()-(a.size()-i)]-cnt['1'+'0'-a[i]][i-1];
    cout<<ans;
}