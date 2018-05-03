/**************************************

	Prog: Class_SET
	Time: 2016-12-07
	Auther: zdw1999
	
	Lateset Update: 2017-06-15

**************************************/

#ifndef MY_SET_H
	
	#define MY_SET_H
	#include "My_Treap.h"
	
	namespace zdw{
	
		template<class T>
		class Set{
		private:
			zdw::Treap<T,bool>__set;
		public:
			Set(){}
			bool &operator [](const T &a){
				__set[a];
				if(__set.Get_Err_Num()){
					__set.insert(a,0);
				}
				return __set[a];
			}
			int Get_Size(){return __set.Get_Treap_Size();}
			void erase(const T &a){__set.erase(a);}
			void clear(){__set.clear();}
		};
		
		template<class T>
		class Mul_Set{
		private:
			zdw::Treap<T,int>__set;
		public:
			Mul_Set(){}
			int &operator [](const T &a){
				__set[a];
				if(__set.Get_Err_Num()){
					__set.insert(a,0);
				}
				return __set[a];
			}
			int Get_Size(){return __set.Get_Treap_Size();}
			void erase(const T &a){__set.erase(a);}
		};
		
	}
	
#endif
