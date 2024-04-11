#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    int lab[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>lab[i][j];
    }

    bool check=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(lab[i][j]==1) continue;

            check=false;
            for(int ni=0;ni<n;ni++)
            {
                for(int nj=0;nj<n;nj++)
                {
                    if(lab[i][j]==lab[i][nj]+lab[ni][j])
                        check=true;
                }
            }

            if(!check) break;
        }
        if(!check) break;
    }

    if(check) cout<<"Yes";
    else cout<<"No";

    return 0;
}