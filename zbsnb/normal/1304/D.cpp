#include<iostream>
#include<vector>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        vector<int> ans1;
        vector<int> ans2;
        
        int k=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='<')k++;
        }
        int now1=n-k;
        int now2=now1-1;
        ans1.push_back(now1++);
        for(int i=0;i<s.size();i++){
            if(s[i]=='<')ans1.push_back(now1++);
            else ans1.push_back(now2--);
        }

        now1=n;
        now2=n-k;

        // cout<<now1<<" "<<now2<<endl;

        ans2.push_back(now2--);

        int cnt=0;
        for(int i=0;i<=s.size();i++){
            if(i!=s.size()&&s[i]=='<'){
                cnt++;
            }
            else{
                for(int i=now1-cnt+1;i<=now1;i++)ans2.push_back(i);
                now1-=cnt;
                if(i!=s.size()){
                    ans2.push_back(now2--);
                }
                cnt=0;
            }
        }

        for(auto &it:ans2)cout<<it<<" ";cout<<endl;
        for(auto &it:ans1)cout<<it<<" ";cout<<endl;

    }

}