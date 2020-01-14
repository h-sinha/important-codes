#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e6+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
struct Line
{
	ld a, b, c;
};
struct Point
{
	ld x, y;
};
// returns equation of Line joining p1 and p2
Line getLine(Point p1, Point p2)
{
	// ax + by + c = 0;
	ld a = p1.y-p2.y;
	ld b = p2.x-p1.x;
	ld c = (p1.x-p2.x)*p1.y + (p2.y-p1.y)*p1.x;
	return Line{a,b,c};
}
// return distance of point p from line l
ld distFromLine(Line l, Point p)
{
	ld d = abs((l.a * p.x + l.b * p.y + l.c)) / (sqrt(l.a * l.a + l.b * l.b)); 
	return d;
}
// return foot of perpendicular drawn from Point p on Line l
Point footOfPerpendicular(Line l, Point p)
{
	ld temp = -1 * (l.a * p.x + l.b * p.y + l.c) / (l.a * l.a + l.b * l.b); 
    ld x1 = temp * l.a + p.x; 
    ld y1 = temp * l.b + p.y;
    return Point{x1, y1}; 
}
// returns point of intersection of Lines l1 and l2
Point lineIntersection(Line l1, Line l2)
{
	ld det = l1.a * l2.b - l2.a * l1.b;
	// lines are parallel
	if(det == 0)return Point{LLONG_MAX, LLONG_MAX};
	ld x = (l1.b*l2.c - l2.b*l1.c)/det; 
    ld y = (l2.a*l1.c - l1.a*l2.c)/det; 
    return Point{x,y};
}
// returns point of intersection of Lines formed by {p1, p2} and {p3, p4}
Point lineIntersection(Point p1, Point p2, Point p3, Point p4)
{
	return lineIntersection(getLine(p1, p2), getLine(p3, p4));
}
// distance between points
ld distance(Point p1, Point p2)
{
	ld x = (p1.x - p2.x) * (p1.x - p2.x);
	ld y = (p1.y - p2.y) * (p1.y - p2.y);
	return sqrt(x + y);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}