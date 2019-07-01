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

		struct Point3{
			double x,y,z;
			Point3(double a=0,double b=0,double c=0):x(a),y(b),z(c){}
		};

		Point3 operator +(Point3 A,Point3 B){return Point3(A.x+B.x,A.y+B.y,A.z+B.z);}
		Point3 operator -(Point3 A,Point3 B){return Point3(A.x-B.x,A.y-B.y,A.z-B.z);}
		Point3 operator *(Point3 A,double B){return Point3(A.x*B,A.y*B,A.z*B);}
		Point3 operator *(Point3 a,Point3 b){return Point3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);}
		double abs(Point3 A){
			return sqrt(A.x*A.x+A.y*A.y+A.z*A.z);
		}
		double dis(Point3 A,Point3 B){
			return abs(B-A);
		}

		//已知3点坐标，求平面ax+by+cz+d=0;
		void get_panel(Point3 p1,Point3 p2,Point3 p3,double &a,double &b,double &c,double &d){
			a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );
			b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );
			c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );
			d = ( 0-(a*p1.x+b*p1.y+c*p1.z) );
		}
		//求由三点确定的平面的法向量
		Point3 get_Normal(Point3 p1,Point3 p2,Point3 p3){
			double a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );
			double b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );
			double c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );
			return Point3(a,b,c);
		}
		//点到平面距离
		double dis_pt2panel(Point3 pt,double a,double b,double c,double d){
			return abs(a*pt.x+b*pt.y+c*pt.z+d)/sqrt(a*a+b*b+c*c);
		}
		//点到线段距离
		double dis_Point3(Point3 A,Point3 B,Point3 C){ //A->BC
			Point3 res;
			for(int i=1;i<=100;++i){
				res=(B+C)*0.5;
				double d1=dis(A,res);
				double d2=dis(A,B);
				double d3=dis(A,C);
				if(d1<d2&&d2>d3)B=res;
				else if(d1<d3&&d3>d2)C=res;
				else break;
				//printf("%.6f %.6f %.6f\n",d1,d2,d3);
			}
			//printf("%.6f %.6f %.6f\n",res.x,res.y,res.z);
			return dis(res,A);
		}


	}

#endif
