#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
char s[200010];
int main(){

    int n;cin>>n;
    cin>>s;
    int x=-1,y=-1;
    for(int i=0;i<n;i++){
        if(x==-1&&s[i]==')')x=i;
    }
    if(x!=-1){
        for(int i=x;i<n-1;i++){
            s[i]=s[i+1];
        }
        s[n-1]=')';
    }
    int ans=0;
    int now=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(')now++;
        else now--;
        if(now<0){
            ans=1;
            break;
        }
    }
    if(now!=0||ans)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}