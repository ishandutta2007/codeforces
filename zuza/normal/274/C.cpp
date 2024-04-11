#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

/**** Dio geometrijskog libraryja --- nedovrsen jos! - tested (WF2007 Collecting Luggage)***/
// greske: imam li svugdje z? (3 dijela formule?)
// greske: (val > eps) - (val < eps) umjesto (val < -eps)
// greske: poredak parametara!

const double eps = 1e-9;
inline double eq(double a, double b) { return fabs(a-b) < eps; }

struct Pt { // 2D (z homog.) or 3D
  double x, y, z;
  Pt(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  friend Pt operator + (Pt a, Pt b) { return {a.x+b.x, a.y+b.y, a.z+b.z}; }
  friend Pt operator - (Pt a, Pt b) { return {a.x-b.x, a.y-b.y, a.z-b.z}; }
  friend Pt operator * (double k, Pt a) { return {k*a.x, k*a.y, k*a.z}; }
  friend Pt operator / (Pt a, double k) { return {a.x/k, a.y/k, a.z/k}; }
};
double get_sq_len(Pt a) { return a.x*a.x + a.y*a.y + a.z*a.z; } // check: has all 3 terms (x,y,z)
double get_len(Pt a) { return sqrt(get_sq_len(a)); }
double dot(Pt a, Pt b) { return a.x*b.x + a.y*b.y + a.z*b.z; } // check: <up>
Pt cross(Pt a, Pt b) { // 3d or homogen. cross product
  Pt ans;
  ans.x = a.y*b.z - a.z*b.y;
  ans.y = a.z*b.x - a.x*b.z;
  ans.z = a.x*b.y - a.y*b.x;
  return ans;
}

typedef Pt ABC; // LINE! 2D line in Ax + By + C = 0 format

struct Line { // 2D or 3D
  Pt a, b;
};

ABC line_to_abc(Line L) { // A*x + B*y + C = 0... 2D only!
  ABC ans = cross((Pt){L.a.x, L.a.y, 1}, {L.b.x, L.b.y, 1});
  assert(dot({L.a.x, L.a.y, 1}, ans) == 0);
  assert(dot({L.b.x, L.b.y, 1}, ans) == 0);
  return ans;
}

Pt intersect_lines(ABC a, ABC b) { // 2D only!
  Pt ans = cross(a, b);
  assert(ans.z != 0);    
  return {ans.x/ans.z, ans.y/ans.z, 0};
}

ABC abc_through_pt(ABC abc, Pt p) {
  return {abc.x, abc.y, -(abc.x*p.x + abc.y*p.y)};
}

ABC bisector(Pt a, Pt b) { // 2d only
  ABC abc = line_to_abc({a, b});
  return abc_through_pt({abc.y, -abc.x, 0}, (a + b) / 2);
}

int ccw(Pt a, Pt b, Pt c) { // 2D only!
  double sum = 0;
  sum += a.x * (b.y - c.y);
  sum += b.x * (c.y - a.y);
  sum += c.x * (a.y - b.y);
  return (sum > eps) - (sum < -eps);
}

//////////////////////// 3D //////////////////////////

struct Plane { // 3D only
  Pt norm; double d; // norm*x + d == 0
};

int get_pt_plane_side(Pt x, Plane plane) { // 3D.. 1 -> above, -1 -> below, 0 -> on plane
  double val = dot(plane.norm, x) + plane.d;
  return (val > eps) - (val < -eps); // check eps, -eps
}

Pt intersect_line_plane(Line L, Plane plane) { // 3D
  Pt delta = L.b - L.a;
  double t = ( -plane.d - dot(L.a, plane.norm) ) / dot(delta, plane.norm);
  Pt ans = L.a + t*delta;
  return ans;
}

Pt project_to_plane(Pt x, Plane plane) { // project point to plane
  Line L = {x, x+plane.norm};
  Pt ans = intersect_line_plane(L, plane);
  return ans;
}

Plane get_plane_from_pts(Pt a, Pt b, Pt c) { // plane equation from 3 points
  Plane ans;
  ans.norm = cross(c-a, b-a);
  ans.d = -dot(ans.norm, a);
  // assert(get_len(ans.norm) > eps); // they should not be collinear?
  return ans;
}

double dist_pt_plane(Pt a, Plane plane) { // 3D... point-plane distance
  double ans = fabs((dot(a, plane.norm) + plane.d) / get_len(plane.norm));
  return ans;
}

int ccw_3d(Plane plane, Pt a, Pt b, Pt c) { // 3D... a, b, c should be on the plane
  double val = dot(plane.norm, cross(b-a, c-a)); // NEMA +plane.d !
  return (val > eps) - (val < -eps); // eps, -eps
}

double triangle_area_3d(Pt a, Pt b, Pt c) {
  return get_len(cross(c-a, b-a)) / 2; // positive! check: /2
}
// tetrahedron volume
double tetra_vol(Pt a, Pt b, Pt c, Pt d) { return dot(cross(b-a, c-a), d-a) / 6; }
// tetrahedron center of mass
Pt tetra_cm(Pt a, Pt b, Pt c, Pt d) { return (a+b+c+d) / 4; }

double dist_pt_segment(Pt p, Pt a, Pt b) { // point, segment dist
  // check: order of args
  if (get_sq_len(p-b) > get_sq_len(p-a) + get_sq_len(a-b)) return get_len(p-a);
  if (get_sq_len(p-a) > get_sq_len(p-b) + get_sq_len(a-b)) return get_len(p-b);
  return 2 * triangle_area_3d(a, b, p) / get_len(a-b);
}

double dist_pt_hull_3d(Plane plane, vector<Pt> pts, Pt p) { // 3D
  // poly = polygon defined by hull of pts
  // if the p is inside poly, get pt-poly dist
  // if it's outside return -1

  int npts = pts.size();
  double ans = 1e100;
  FOR(i, 0, npts) FOR(j, i+1, npts) {
    bool plus = false, minus = false;
    REP(k, npts) {
      int val = ccw_3d(plane, pts[i], pts[j], pts[k]);
      if (val > 0) plus = true;
      if (val < 0) minus = true;
    }

    if (plus && minus) continue; // pts[i]..pts[j] isn't on the hull
    if (ccw_3d(plane, pts[i], pts[j], p) * (plus - minus) == -1) {
      // p is outside of the polygon
      return -1;
    }
    double val = dist_pt_segment(p, pts[i], pts[j]);
    if (val < ans) ans = val;
  }
  return ans;
}

////////////////////////// other geom algos ///////////////////////////////

// point STRICTLY inside a line segment (not on it's endpoints)
bool point_in_segment(Pt p, Pt a, Pt b) { // 2D !!!
  if (ccw(a, b, p) != 0) return false;

  if (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x))
    if (min(a.y, b.y) < p.y && p.y < max(a.y, b.y))
      return true;
  if (min(a.x, b.x) < p.x && p.x < max(a.x, b.x))
    if (min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y))
      return true;

  return false;
}

// point STRICTLY in polygon
bool point_in_poly(const vector<Pt>& P, Pt p) { 
  int np = P.size();
  int wind = 0;

  REP(i, np) {
    Pt a = P[i];
    Pt b = P[(i+1)%np];
    if (point_in_segment(p, a, b)) return false;

    if (b.y > a.y) { // rising segments
      if (a.y <= p.y && p.y < b.y)
        if (ccw(a, b, p) > 0)
          ++wind;
    } else if (b.y < a.y) { // falling segments
      if (a.y > p.y && p.y >= b.y)
        if (ccw(a, b, p) <= 0)
          --wind;
    } if (a.y == b.y && a.y == p.y) { // horizontal segments
      if (a.x < b.x) { // to the right
        if (a.x < p.x && p.x <= b.x) --wind;        
      }
    }
  }

  return (wind > 0);
}

// does the segment (a, b) only touch the polygon P?
// no point on P can lie strictly within, but touching at endpoints is allowed
bool intersects_inside(const vector<Pt>& P, Pt a, Pt b) {
  int np = P.size();
  REP(i, np) if (point_in_segment(P[i], a, b)) return true;

  REP(i, np) {
    int j = (i+1) % np;
    int abi = ccw(a, b, P[i]);
    int abj = ccw(a, b, P[j]);
    int ija = ccw(P[i], P[j], a);
    int ijb = ccw(P[i], P[j], b);

    if (abi*abj == -1 && ija*ijb == -1) return true;
  }

  Pt mid = {a.x+b.x, a.y+b.y}; mid.x /= 2; mid.y /= 2; // DOUBLE!!?!
  return point_in_poly(P, mid); // point in poly -> return yes
}


int main(void)
{
  int n; scanf("%d", &n);
  vector<Pt> pts;
  REP(i, n) {
    int x, y; scanf("%d %d", &x, &y);
    pts.push_back(Pt(x, y));
  }

  double ans = -1;
  REP(i, n) REP(j, i) REP(k, j) {
    double asq = get_sq_len(pts[i] - pts[j]);
    double bsq = get_sq_len(pts[j] - pts[k]);
    double csq = get_sq_len(pts[k] - pts[i]);
    if (asq > bsq) swap(asq, bsq);
    if (asq > csq) swap(asq, csq);
    if (bsq > csq) swap(bsq, csq);
    if (asq + bsq > csq) {
      Pt ab = bisector(pts[i], pts[j]);
      Pt bc = bisector(pts[i], pts[k]);
      Pt sred = cross(ab, bc);
      assert(sred.z != 0);
      sred.x /= sred.z; sred.y /= sred.z; sred.z = 0;

      double sol_R = get_len(sred - pts[i]);
      double closest = 1e100;
      REP(iter, n) {
        closest = min(closest, get_len(sred - pts[iter]));
      }
      if (eq(sol_R, closest)) ans = max(ans, closest);
    }
  }

  auto pravi = [](Pt a, Pt b, Pt c) -> bool {
    return eq(get_sq_len(a - b) + get_sq_len(b - c), get_sq_len(a-c));
  };

  REP(i, n) REP(j, n) {
    REP(k, n) {
      if (!pravi(pts[i], pts[j], pts[k])) continue;
      REP(l, n) {
        if (i == j || i == k || i == l || j == k || j == l || k == l) continue;
        if (pravi(pts[j], pts[k], pts[l]) && pravi(pts[k], pts[l], pts[i]) && pravi(pts[l], pts[i], pts[j])) {
          Pt sred = (pts[i] + pts[k]) / 2;
          double closest = 1e100;
          REP(iter, n) {
            closest = min(closest, get_len(sred - pts[iter]));
          }
          if (eq(closest, get_len(pts[i] - pts[j])/sqrt(2))) ans = max(ans, closest);
        }
      }
    }
  }

  if (ans == -1) printf("-1\n");
  else printf("%.8lf\n", ans);

  return 0;
}