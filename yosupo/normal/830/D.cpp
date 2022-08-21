#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

ll buf[401] = {
0,
1,
9,
245,
126565,
54326037,
321837880,
323252721,
754868154,
328083248,
838314395,
220816781,
893672292,
166441208,
251255697,
114256285,
118775501,
482714697,
11784725,
460862131,
550384565,
106742050,
425241115,
626692854,
674266678,
320014275,
345949512,
527320049,
897822749,
137190263,
491039182,
810384961,
482023334,
658099864,
886790989,
845381174,
371433224,
278969124,
420088324,
696766322,
388302635,
141033366,
46387851,
932125021,
278342766,
371131134,
922501918,
110778457,
506223573,
806353719,
391845991,
923507761,
780307355,
109951115,
830090230,
605558495,
344686604,
988110893,
944684429,
715019947,
799898820,
384672708,
907325090,
758952329,
550672104,
368337206,
394915145,
401744167,
923781939,
831857516,
407845661,
329267374,
927004007,
891609656,
897919613,
481297880,
737337940,
651873737,
287246681,
973133651,
679864988,
784719328,
820504764,
875613823,
806512665,
164851642,
500228957,
951814419,
447763649,
273141670,
979349615,
964027956,
809510400,
276634497,
116631976,
426739449,
175282420,
885948162,
62270880,
974395255,
675165056,
759589968,
837957573,
931897605,
152352780,
585420109,
1772087,
333401718,
898833639,
745874265,
786209423,
691982338,
498790927,
473374639,
274302623,
971280670,
241671319,
13070005,
302088807,
550276351,
436592588,
631667314,
548656698,
730626984,
146295220,
674398632,
400383348,
454138904,
786220712,
118620797,
233440672,
217349271,
274853536,
310607544,
105221205,
769566615,
853585061,
800665807,
695377419,
924327065,
388199705,
551624811,
721435546,
501720515,
308465454,
825369234,
396065729,
451899519,
295058424,
142088952,
473485086,
378771634,
734511215,
462404399,
959198328,
337668263,
794122911,
38911400,
951992982,
472696081,
373904752,
105884826,
630251717,
28980684,
845136347,
353665773,
691661192,
19922354,
231463797,
757917231,
242739918,
979036950,
713722080,
234689388,
2243164,
209872853,
240808787,
539523346,
425797848,
913772061,
224613100,
421742777,
222232478,
92712941,
215137570,
949901408,
274827432,
15162482,
593145989,
274574232,
239282092,
762720192,
804146934,
500629424,
565985054,
81127381,
671811155,
655565571,
890331075,
237994348,
743647404,
667160634,
713914299,
668506729,
741341289,
277636808,
762781382,
14272789,
902864131,
567443405,
149113383,
648844381,
825489976,
933016723,
192288078,
734493315,
240985733,
861817693,
762711459,
525904609,
532463481,
377133989,
620711079,
772561562,
980733194,
227599811,
162774370,
209512798,
787116594,
3509258,
748795368,
378035466,
612938915,
802091952,
857679599,
481748937,
493370392,
358420805,
48301629,
412001241,
463126722,
509578422,
967799131,
994766554,
687287243,
863623583,
771554899,
690911527,
855314994,
923686429,
246862514,
192479791,
133487041,
703444043,
295281758,
801816257,
920762934,
749306433,
973004841,
848644684,
560026478,
952127278,
616654635,
839390326,
975154012,
409583672,
635350249,
343228425,
335331602,
223826406,
952341037,
589677800,
249747234,
555694261,
137143500,
628190328,
461598392,
431912756,
29349807,
759199489,
783281228,
781971312,
915823407,
388508707,
718062705,
27424111,
309999451,
963383322,
831185229,
132910888,
347028136,
850484840,
223055285,
142335980,
144754000,
772005560,
81796039,
167696020,
79454283,
172772542,
201056991,
484957644,
716630285,
763194701,
211505841,
903448791,
926964672,
257752668,
482951716,
411539070,
620249847,
592476107,
170473128,
814662613,
898000271,
57354872,
361106091,
488697643,
889007954,
138725767,
684860983,
36248116,
304610143,
137633385,
413715776,
99010024,
779653665,
100387568,
286328069,
564731826,
621740468,
943513219,
506666491,
249987886,
553719884,
769853086,
337485319,
702455584,
809637762,
755400257,
892290368,
502180086,
364275817,
118162370,
873374339,
261271695,
970132574,
744105500,
434447173,
117975095,
383088393,
625447969,
180281249,
545367713,
133236931,
360175662,
148087453,
806871297,
498529036,
886076476,
65645000,
465138299,
967109895,
331362616,
472283705,
796894900,
199697765,
503759892,
472807906,
187586706,
941198065,
782234442,
57693411,
18678611,
82626204,
395317191,
570588915,
152519440,
449852456,
63696518,
763741345,
878748386,
494317541,
444782633,
93316211,
929164666,
529288371,
165769871,
730546850,
955877127,
994202767,
492009567,
275683011,
415902127,
95725776,
718047399,
786963365,
73091278,
986172399,
174591541,
913259286,
};


int main() {
    int n;
    cin >> n;
    cout << buf[n] << endl;
    return 0;
}