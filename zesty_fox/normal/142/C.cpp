#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int res[10][10]={\
{0,0,0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0,0,0},\
{0,0,0,0,0,0,0,0,0,0},\
{0,0,0,1,1,2,2,3,3,4},\
{0,0,0,1,2,2,3,4,4,5},\
{0,0,0,2,2,4,4,5,6,7},\
{0,0,0,2,3,4,5,6,7,8},\
{0,0,0,3,4,5,6,8,9,10},\
{0,0,0,3,4,6,7,9,10,12},\
{0,0,0,4,5,7,8,10,12,13}};
const char a[10][10][10][10]={
{{{"."}},
{{".."}},
{{"..."}},
{{"...."}},
{{"....."}},
{{"......"}},
{{"......."}},
{{"........"}},
{{"........."}}},
{{{"."},{"."}},
{{".."},{".."}},
{{"..."},{"..."}},
{{"...."},{"...."}},
{{"....."},{"....."}},
{{"......"},{"......"}},
{{"......."},{"......."}},
{{"........"},{"........"}},
{{"........."},{"........."}}},
{{{"."},{"."},{"."}},
{{".."},{".."},{".."}},
{{"AAA"},{".A."},{".A."}},
{{".AAA"},{"..A."},{"..A."}},
{{"BBBA."},{".B.A."},{".BAAA"}},
{{".BBBA."},{"..B.A."},{"..BAAA"}},
{{"CCCBAAA"},{".C.B.A."},{".CBBBA."}},
{{".CCCBAAA"},{"..C.B.A."},{"..CBBBA."}},
{{"DDDCBBBA."},{".D.C.B.A."},{".DCCCBAAA"}}},
{{{"."},{"."},{"."},{"."}},
{{".."},{".."},{".."},{".."}},
{{"..."},{"AAA"},{".A."},{".A."}},
{{".BBB"},{".AB."},{".AB."},{"AAA."}},
{{"....."},{"BBBA."},{".B.A."},{".BAAA"}},
{{"...CCC"},{"BBBAC."},{".B.AC."},{".BAAA."}},
{{".DDDCCC"},{".BD.AC."},{".BD.AC."},{"BBBAAA."}},
{{".....DDD"},{".CBBBAD."},{".C.B.AD."},{"CCCBAAA."}},
{{"...EEEDDD"},{"CCCBE.AD."},{".C.BE.AD."},{".CBBBAAA."}}},
{{{"."},{"."},{"."},{"."},{"."}},
{{".."},{".."},{".."},{".."},{".."}},
{{"BBB"},{".B."},{".BA"},{"AAA"},{"..A"}},
{{"...."},{".BBB"},{".AB."},{".AB."},{"AAA."}},
{{"DDD.C"},{".DCCC"},{"BD.AC"},{"BBBA."},{"B.AAA"}},
{{"...DDD"},{".CCCD."},{".BC.DA"},{".BCAAA"},{"BBB..A"}},
{{"..EEE.D"},{"CCCEDDD"},{".CBE.AD"},{".CBBBA."},{"..B.AAA"}},
{{"...FFF.E"},{".DDDFEEE"},{".CDBF.AE"},{".CDBBBA."},{"CCCB.AAA"}},
{{".GGGF.EEE"},{"..GDFFFE."},{".CGDFB.EA"},{".CDDDBAAA"},{"CCC.BBB.A"}}},
{{{"."},{"."},{"."},{"."},{"."},{"."}},
{{".."},{".."},{".."},{".."},{".."},{".."}},
{{"..."},{"BBB"},{".B."},{".BA"},{"AAA"},{"..A"}},
{{".CCC"},{"..C."},{"..CB"},{"ABBB"},{"AAAB"},{"A..."}},
{{"....."},{"DDD.C"},{".DCCC"},{"BD.AC"},{"BBBA."},{"B.AAA"}},
{{"...EEE"},{"DDDCE."},{".D.CE."},{"BDCCCA"},{"BBBAAA"},{"B....A"}},
{{"....FFF"},{"EEE.DF."},{".EDDDF."},{"CE.BD.A"},{"CCCBAAA"},{"C.BBB.A"}},
{{".......G"},{"F.EEEGGG"},{"FFFEDDDG"},{"FC.EBDA."},{".CBBBDA."},{"CCC.BAAA"}},
{{".....HGGG"},{"F.EEEH.G."},{"FFFEHHHGD"},{"FC.EBADDD"},{".CBBBAAAD"},{"CCC.BA..."}}},
{{{"."},{"."},{"."},{"."},{"."},{"."},{"."}},
{{".."},{".."},{".."},{".."},{".."},{".."},{".."}},
{{"CCC"},{".C."},{".CB"},{"BBB"},{".AB"},{".A."},{"AAA"}},
{{".DDD"},{".CD."},{".CD."},{"CCCB"},{"ABBB"},{"AAAB"},{"A..."}},
{{"..EEE"},{"...E."},{"DDDEC"},{".DCCC"},{"BD.AC"},{"BBBA."},{"B.AAA"}},
{{"...FFF"},{"EEE.F."},{".ED.FC"},{".EDCCC"},{"BDDDAC"},{"BBB.A."},{"B..AAA"}},
{{"HHH.GGG"},{".HFFFG."},{".HEFDG."},{"EEEFDDD"},{"C.EBD.A"},{"CCCBAAA"},{"C.BBB.A"}},
{{".III.HHH"},{".GIFFFH."},{".GI.FEH."},{"GGGDFEEE"},{"CDDDBE.A"},{"CCCDBAAA"},{"C..BBB.A"}},
{{"..JJJ.III"},{"HHHJGGGI."},{".H.JFGEI."},{"DHFFFGEEE"},{"DDDCFBE.A"},{"DCCC.BAAA"},{"...CBBB.A"}}},
{{{"."},{"."},{"."},{"."},{"."},{"."},{"."},{"."}},
{{".."},{".."},{".."},{".."},{".."},{".."},{".."},{".."}},
{{"..."},{"CCC"},{".C."},{".CB"},{"BBB"},{".AB"},{".A."},{"AAA"}},
{{"...."},{".DDD"},{".CD."},{".CD."},{"CCCB"},{"ABBB"},{"AAAB"},{"A..."}},
{{"..FFF"},{"EEEF."},{".E.F."},{"DECCC"},{"DDDC."},{"DB.CA"},{".BAAA"},{"BBB.A"}},
{{"...GGG"},{".FFFG."},{".EF.GD"},{".EFDDD"},{"EEEC.D"},{"BCCCA."},{"BBBCA."},{"B..AAA"}},
{{"...IHHH"},{"GIIIFH."},{"GGGIFH."},{"GE.FFFD"},{".EEEDDD"},{"CEBBBAD"},{"CCCB.A."},{"C..BAAA"}},
{{"...JJJ.I"},{".HHHJIII"},{".GHFJ.EI"},{".GHFFFE."},{"GGGFDEEE"},{"CCCBDDDA"},{".C.BDAAA"},{".CBBB..A"}},
{{"...LKKK.J"},{"ILLLHKJJJ"},{"IIILHKG.J"},{"I.FHHHGGG"},{"FFFEEEG.D"},{"C.FBEADDD"},{"CCCBEAAAD"},{"C.BBBA..."}}},
{{{"."},{"."},{"."},{"."},{"."},{"."},{"."},{"."},{"."}},
{{".."},{".."},{".."},{".."},{".."},{".."},{".."},{".."},{".."}},
{{"DDD"},{".D."},{".DC"},{"CCC"},{"B.C"},{"BBB"},{"BA."},{".A."},{"AAA"}},
{{".EEE"},{"..E."},{"..ED"},{"CDDD"},{"CCCD"},{"CBBB"},{".AB."},{".AB."},{"AAA."}},
{{"..GGG"},{"FFFG."},{".F.GE"},{"DFEEE"},{"DDDCE"},{"DCCC."},{"BBBCA"},{".BAAA"},{".B..A"}},
{{"...HHH"},{".GGGH."},{".FG.HE"},{".FGEEE"},{"FFFD.E"},{"CCCDDD"},{".CBD.A"},{".CBAAA"},{".BBB.A"}},
{{"..JJJ.I"},{"HHHJIII"},{".H.JG.I"},{".H.FGGG"},{"EFFFG.D"},{"EEEFDDD"},{"ECBBBAD"},{".C.B.A."},{"CCCBAAA"}},
{{".LLLKJJJ"},{".IL.K.J."},{".ILKKKJH"},{"IIIGFHHH"},{"EGGGFFFH"},{"EEEGFDDD"},{"ECBBBAD."},{".C.B.AD."},{"CCCBAAA."}},
{{"....MMM.L"},{"K.JJJMLLL"},{"KKKJIM.HL"},{"K.GJIHHH."},{"GGGIIIFH."},{"E.GDDDFFF"},{"EEECDBF.A"},{"ECCCDBAAA"},{"...CBBB.A"}}}};
int main(){
    int n,m;scanf("%d%d",&n,&m);
    printf("%d\n",res[n][m]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            putchar(a[n-1][m-1][i-1][j-1]);
        }
        puts("");
    }
    return 0;
}