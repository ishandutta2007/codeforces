#include<bits/stdc++.h>
using namespace std;

int prime1[50010];
queue<int> prime;
void getprime(){
    for(int i=2;i<=50000;i++){
        if(!prime1[i]) prime.push(i);
        for(long long int j=(long long int) i*i;j<50001;j+=i){
            prime1[j]=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getprime();
    int n,a1,b1,a11,b11,tmpf=0;
    cin>>n;
    cin>>a1>>b1;
    a11=a1;
    b11=b1;
    while(1){
        if(prime.size()==1){
            if(a1%prime.front()==0||b1%prime.front()==0)  break;
            else{
                prime.pop();
                break;
            }
        }
        if(prime.empty()||prime.front()<=tmpf)
            break;
        tmpf=prime.front();
        prime.pop();
        if(a1%tmpf==0||b1%tmpf==0){
            while(!(a11%tmpf))  a11/=tmpf;
            while(!(b11%tmpf))  b11/=tmpf;
            prime.push(tmpf);
        }
    }
    if(a11>b11) swap(a11,b11);
    if(a11!=1&&a11!=b11){
        prime.push(a11);
        prime.push(b11);
    }
    else if(a11!=1&&a11==b11)   prime.push(a11);
    else if(a11==1&&b11!=1)     prime.push(b11);
    for(int i=2;i<=n;i++){
        cin>>a1>>b1;
        tmpf=0;
        while(1){
            if(prime.size()==1){
                if(a1%prime.front()==0||b1%prime.front()==0)  break;
                else{
                    prime.pop();
                    break;
                }
            }
            if(prime.empty()||prime.front()<=tmpf)
                break;
            tmpf=prime.front();
            prime.pop();
            if(a1%tmpf==0||b1%tmpf==0)  prime.push(tmpf);
        }
    }
    if(prime.empty())   cout<<-1<<endl;
    else    cout<<prime.front()<<endl;
}