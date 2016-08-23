#include <bits/stdc++.h>

#define N 10001
#define MAX 9999.99999
#define EPS 1e-9
using namespace std;

struct Point{
        double x;
        double y;
        
        Point() {x = y = 0.0;}
        Point(double _x, double _y) : x(_x), y(_y) {}
        
        bool operator < (const Point& other) const
        {
        	if (fabs(x - other.x) < EPS)
        		return y < other.y;
        	return x < other.x;
        }
};
 
Point point[N];
 
double Closest_Pair(long a, long b);
double Distance(Point &p1, Point &p2);
double min(double a, double b);
 
int main(){
    long i, n;
    double d;
    ios_base :: sync_with_stdio(0); cin.tie(0);
    while(cin >> n){
       if(!n) break;
       for(i=0; i<n; i++) cin >> point[i].x >> point[i].y;
       sort(point, point + n);
       d = Closest_Pair(0,n-1);
        
       if(d > MAX) cout << "INFINITY\n";
       else cout << setprecision(4) << fixed << d << '\n';
    }
    return 0;
}
 
double Closest_Pair(long a, long b){
       long i, j, k;
       double d1, d2, d;
       double xp;
       if(a == b) return MAX+1.0;
       else if(b-a == 1) return Distance(point[b],point[a]);
       else {
            d1 = Closest_Pair(a,(a+b)/2);
            d2 = Closest_Pair((a+b)/2+1,b);
            d = min(d1,d2);
            j = (a+b)/2;
            xp = point[j].x;
            do{
               k = (a+b)/2 + 1;
               while(xp - point[k].x < d && k <= b){
                   d1 = Distance(point[k],point[j]);
                   d = min(d,d1);
                   k++;
               }
               j--;
            }while(xp - point[j].x < d && j >= a);
       return d;
       }
}
 
double Distance(Point &p1, Point &p2){
       double d = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
       if(d > MAX) d = MAX + 1.0;
       return d;
}
 
double min(double a, double b){
       if(a < b) return a;
       return b;
}
 
int compare(const void *a, const void *b){
    Point *sp1 = (Point *)a;
    Point *sp2 = (Point *)b;
    if(sp1->x > sp2->x) return 1;
    else if(sp1->x < sp2->x) return -1;
    else{
         if(sp1->y > sp2->y) return 1;
         else return -1;
    }
    return -1;
}
