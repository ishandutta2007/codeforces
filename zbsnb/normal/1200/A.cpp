#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

char s[100010];
int sta[10];
int main(){
    int n;cin>>n>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            for(int i=0;i<10;i++){
                if(sta[i]==0){
                        sta[i]=1;
                break;
                }
            }
        }
        else if(s[i]=='R'){
            for(int i=9;i>=0;i--){
                if(sta[i]==0){
                    sta[i]=1;
                break;
            }
            }
        }
        else sta[s[i]-'0']=0;
    }
    for(int i=0;i<10;i++)cout<<sta[i];cout<<endl;
}