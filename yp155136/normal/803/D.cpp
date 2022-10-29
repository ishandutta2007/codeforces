#include <iostream>
#include <stdio.h>
using namespace std;

int check(int mid,string s) {
    int ret=1;
    int left=mid;
    int last=0;
    for (int i=0;s.size()>i;i++) {
        if (s[i] == '-' || s[i]==' ') {
            last++;
            if (left >= last) {
                left-=last;
                last=0;
            }
            else {
                ret++;
                left = mid-last;
                last=0;
            }
        }
        else {
            last++;
        }
        //cout<<"i = "<<i<<" , last = "<<last<<" , left = "<<left<<endl;
    }
    //cout<<"mid = "<<mid<<" , ret = "<<ret<<endl;
    if (last <= left ) return ret;
    else return ret+1;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cin.get();
    string s;
    getline(cin,s);
    int mxx=0;
    int tmp=0;
    for (char i:s) {
        if (i=='-' || i==' ') {
            mxx = max(mxx,tmp+1);
            tmp=0;
        }
        else tmp++;
    }
    mxx = max(mxx,tmp);
    int L=mxx-1,R=1e6 + 6;   //R is the answer
    while (R-L!=1) {
        int mid=(L+R)>>1;
        if (check(mid,s) <= k) R=mid;
        else L=mid;
    }
    cout<<R<<endl;
}