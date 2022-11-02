#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int stx=1;
    int sty=1;
    int enx=n;
    int eny=m;
    if(n==1 && m==1)
    {
        //cout<<"1 1"<<endl;
        printf("1 1\n");
        return 0;
    }
    //ans.push_back({stx, sty});
    //ans.push_back({enx, eny});
    //cout<<stx<<" "<<sty<<endl;
    printf("%d %d\n", stx, sty);
    //cout<<enx<<" "<<eny<<endl;
    printf("%d %d\n", enx, eny);
    for(int uu=3; uu<=n*m; uu++)
    {
        if(uu%2)
        {
            if(sty<m) sty++;
            else
            {
                sty=1;
                stx++;
            }
            printf("%d %d\n", stx, sty);
            //cout<<stx<<" "<<sty<<endl;
        }
        else
        {
            if(eny>1) eny--;
            else
            {
                eny=m;
                enx--;
            }
            printf("%d %d\n", enx, eny);
            //cout<<enx<<" "<<eny<<endl;
        }
    }
    return 0;
}