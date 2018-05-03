/****************************************

	Graphic templates.
	
	Last_update: 2018-02-19 23:55

*****************************************/

#ifndef MY_MATH_H
#define MY_MATH_H
	
	#include <cmath>
	#include <My_Std.h>
	
	namespace zdw{
		
		inline int dcmp(const double &x){return x>-eps?x>eps:-1;}
		
		struct Vector{double x,y;Vector(const double &A=0,const double &B=0):x(A),y(B){}};
		inline std::istream & operator >>(std::istream &A,Vector &B){A>>B.x>>B.y;return A;}
		inline Vector operator +(const Vector &a,const Vector &b){return Vector(a.x+b.x,a.y+b.y);}
		inline Vector operator -(const Vector &a,const Vector &b){return Vector(a.x-b.x,a.y-b.y);}
		inline Vector operator *(const Vector &a,const double &b){return Vector(a.x*b,a.y*b);}
		inline Vector operator /(const Vector &a,const double &b){return Vector(a.x/b,a.y/b);}
		inline double operator ^(const Vector &a,const Vector &b){return a.x*b.y-a.y*b.x;}
		inline double operator *(const Vector &a,const Vector &b){return a.x*b.x+a.y*b.y;}
		inline double dis(const Vector &a,const Vector &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
		typedef Vector Point;
		struct Circle{Point O; double R;Circle(){}Circle(const Point &A,const double &B):O(A),R(B){}};
		inline std::istream & operator >>(std::istream &A,Circle &B){A>>B.O>>B.R;return A;}
		
		//bool tangent(const Circle &A,const Circle &B){return !(dcmp(dis(A.O,B.O)-A.R-B.R)&&dcmp(dis(A.O,B.O)-abs(A.R-B.R)));}
		inline Point *intersect(const Circle &A,const Circle &B){
			double ds=dis(A.O,B.O);
			if(A.R+B.R<ds||abs(A.R-B.R)>ds)return 0;
			Point *ret=(Point *)malloc(2*sizeof(Point));
			//if(tangent(A,B))return ret[0]=(B.O-A.O)/(A.R+B.R)*B.R,ret;
			double Acos=(ds*ds+A.R*A.R-B.R*B.R)/(2*ds*A.R),ds2=A.R*Acos;
			Vector fx=B.O-A.O; Point M=A.O+fx/ds*ds2;
			double ds3=sqrt(A.R*A.R-ds2*ds2); ret[0]=M+Point(fx.y,-fx.x)/ds*ds3;
			ret[1]=M+Point(-fx.y,fx.x)/ds*ds3; return ret;
		}
		
	}
	
#endif