#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 2e5 + 6;

int a[MAX_N];

int main () {
    int n;
    scanf("%d",&n);
    vector<int> v;
    v.push_back(-INF);
    v.push_back(-INF+1);
    for (int i=1;n>=i;i++) {
        scanf("%d",&a[i]);
        if (a[i]==0) v.push_back(i);
    }
    v.push_back(INF);
    v.push_back(INF+1);
    //for (int i:v) cout<<i<<' ';
    //cout<<endl;
    for (int i=1;n>=i;i++) {
        int tmp=i;
        int pos=lower_bound(v.begin(),v.end(),tmp) - v.begin();
        //cout<<"pos = "<<pos<<" , i="<<i<<endl;
        printf("%d ",(int)min(abs(v[pos]-i),abs(v[pos-1]-i)));
    }
    puts("");
}