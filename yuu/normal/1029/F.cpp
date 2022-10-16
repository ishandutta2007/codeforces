#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long n;
deque <pair <long long, long long>> dA;
deque <pair <long long, long long>> dB;
long long mind=1e18;
int main(){
    cin>>a>>b;
    for(long long i=1; i*i<=a; i++) if(a%i==0){
        dA.push_back(make_pair(i, a/i));
        dA.push_back(make_pair(a/i, i));
    }
    sort(dA.begin(), dA.end());
    for(long long i=1; i*i<=b; i++) if(b%i==0){
        dB.push_back(make_pair(i, b/i));
        dB.push_back(make_pair(b/i, i));
    }
    sort(dB.begin(), dB.end());
    n=(a+b);
    int bA=0, bB=0;
    for(long long x=1; x*x<=n; x++) if(n%x==0){
        long long y=n/x;
        while((dA.size()>1)&&(dA[1].first<=x)) dA.pop_front();
        while((dB.size()>1)&&(dB[1].first<=x)) dB.pop_front();
        if((dA[0].first<=x)&&(dA[0].second<=y)) mind=min(mind, x+y);
        if((dB[0].first<=x)&&(dB[0].second<=y)) mind=min(mind, x+y);
    }
    mind*=2;
    cout<<mind<<'\n';
}