#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define ll long long 

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        char s1[10010],s2[10010];
        cin>>s1+1>>s2+1;
        char flg1=0,flg2=0;
        int flg=0;
        for(int i=1;i<=n;i++){
            if(s1[i]==s2[i])continue;
            else{
                if(flg1==0){
                    flg1=s1[i];
                    flg2=s2[i];
                    flg=1;
                }
                else{
                    if(s1[i]!=flg1||s2[i]!=flg2||flg==2){
                        flg=-1;   
                        break;
                    }
                    else flg=2;
                }
            }
        }
        //cout<<flg<<endl;
        if(flg==-1||flg==1){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
}