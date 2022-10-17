#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

const long long M=1000000007;

long long keta[15],num[15];

long long modpow(long long n){
    if(n==0)return 1;
    long long ret=modpow(n/2);
    ret*=ret; ret%=M;
    if(n%2==1)ret*=10; ret%=M;
    return ret;
}

void solver(long long d,string T){
    long long m=T.size();
    long long ret=0;

    long long k=0;
    for(int i=m-1;i>=0;i--){
        ret+=modpow(k)*num[T[i]-'0']; ret%=M;
        k+=keta[T[i]-'0'];
    }

    keta[d]=k%(M-1);
    num[d]=ret;
}

int main(){
    for(int i=0;i<10;i++){
        keta[i]=1;
        num[i]=i;
    }

    static string s;
    static long long n;
    static string t[100010];

    cin>>s;
    scanf("%d",&n);
    for(long long i=0;i<n;i++){
        cin>>t[i];
    }

    for(long long i=n-1;i>=0;i--){
        long long d=t[i][0]-'0';
        string T=t[i].substr(3);

        solver(d,T);
    }

    solver(0,s);

    cout<<num[0];
}