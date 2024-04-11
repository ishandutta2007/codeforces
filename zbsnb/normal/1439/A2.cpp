#include<bits/stdc++.h>
using namespace std;
#define ll long long
char mp[1010][1010];
void sp(int i,int j){
    if(mp[i][j]=='1') mp[i][j]='0';
    else mp[i][j]='1';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        vector<vector<int> > vec;
        for(int i=1;i<=n-2;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j]=='1'){
                    vector<int> tmp;
                    if(j==1){
                        tmp.push_back(i);
                        tmp.push_back(j);
                        tmp.push_back(i+1);
                        tmp.push_back(j);
                        tmp.push_back(i+1);
                        tmp.push_back(j+1);
                        sp(i,j);
                        sp(i+1,j);
                        sp(i+1,j+1);
                    }
                    else{
                        tmp.push_back(i);
                        tmp.push_back(j);
                        tmp.push_back(i+1);
                        tmp.push_back(j);
                        tmp.push_back(i+1);
                        tmp.push_back(j-1);
                        sp(i,j);
                        sp(i+1,j);
                        sp(i+1,j-1);
                    }
                    vec.push_back(tmp);
                }
            }
        }
        for(int j=1;j<=m-1;j++){
            if(mp[n-1][j]=='0'&&mp[n][j]=='0') continue;
            else if(mp[n-1][j]=='1'&&mp[n][j]=='0'){
                vector<int> tmp;
                tmp.push_back(n-1);
                tmp.push_back(j);
                tmp.push_back(n-1);
                tmp.push_back(j+1);
                tmp.push_back(n);
                tmp.push_back(j+1);
                sp(n-1,j);
                sp(n-1,j+1);
                sp(n,j+1);
                vec.push_back(tmp);
            }
            else if(mp[n-1][j]=='0'&&mp[n][j]=='1'){
                vector<int> tmp;
                tmp.push_back(n);
                tmp.push_back(j);
                tmp.push_back(n-1);
                tmp.push_back(j+1);
                tmp.push_back(n);
                tmp.push_back(j+1);
                sp(n,j);
                sp(n-1,j+1);
                sp(n,j+1);
                vec.push_back(tmp);
            }
            else{
                vector<int> tmp;
                tmp.push_back(n-1);
                tmp.push_back(j);
                tmp.push_back(n);
                tmp.push_back(j);
                tmp.push_back(n);
                tmp.push_back(j+1);
                sp(n-1,j);
                sp(n,j);
                sp(n,j+1);
                vec.push_back(tmp);
            }
        }
        auto f11=[&]{
            vector<int> tmp;
            tmp.push_back(n);
            tmp.push_back(m-1);
            tmp.push_back(n-1);
            tmp.push_back(m);
            tmp.push_back(n);
            tmp.push_back(m);
            sp(n,m-1);
            sp(n-1,m);
            sp(n,m);
            vec.push_back(tmp);
        };
        auto f12=[&]{
            vector<int> tmp;
            tmp.push_back(n);
            tmp.push_back(m-1);
            tmp.push_back(n-1);
            tmp.push_back(m-1);
            tmp.push_back(n);
            tmp.push_back(m);
            sp(n,m-1);
            sp(n-1,m-1);
            sp(n,m);
            vec.push_back(tmp);
        };
        auto f21=[&]{
            vector<int> tmp;
            tmp.push_back(n-1);
            tmp.push_back(m-1);
            tmp.push_back(n-1);
            tmp.push_back(m);
            tmp.push_back(n);
            tmp.push_back(m);
            sp(n-1,m-1);
            sp(n-1,m);
            sp(n,m);
            vec.push_back(tmp);
        };
        auto f22=[&]{
            vector<int> tmp;
            tmp.push_back(n);
            tmp.push_back(m-1);
            tmp.push_back(n-1);
            tmp.push_back(m);
            tmp.push_back(n-1);
            tmp.push_back(m-1);
            sp(n,m-1);
            sp(n-1,m);
            sp(n-1,m-1);
            vec.push_back(tmp);
        };

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<mp[i][j];
        //     }
        //     cout<<endl;
        // }

        if(mp[n-1][m]=='1'&&mp[n][m]=='0'){
            f11();
            f21();
            f22();
        }
        else if(mp[n-1][m]=='0'&&mp[n][m]=='1'){
            f11();
            f21();
            f12();
        }
        else if(mp[n-1][m]=='1'&&mp[n][m]=='1'){
            f12();
            f22();
        }
        cout<<vec.size()<<endl;
        for(auto &it:vec){
            for(auto &it2:it){
                cout<<it2<<" ";
            }
            cout<<endl;
        }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<mp[i][j];
        //     }
        //     cout<<endl;
        // }
    }
}