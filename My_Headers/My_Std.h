#ifndef MY_STD_H
#define MY_STD_H

	#include <bits/stdc++.h>

	#ifndef __NO_ZDW_STD_DEF__

		/******************************************

			If you do not want single item ,
			just use "#undef" before / after
			include the header to cancle it.

		******************************************/

		#ifndef ll
			#define ll long long
		#endif

		#ifndef db
			#define db long long
		#endif

		#ifndef ull
			#define ull unsigned long long
		#endif

		#ifndef iter
			#define iter iterator
		#endif

		#ifndef pqueue
			#define pqueue priority_queue
		#endif

		#ifndef count_intbit
			#define count_intbit(x) __builtin_popcount(x)
		#endif

		#ifndef rep
			#define rep(i,x,y) for(int i=(x);i<(y);++i)
		#endif

		#ifndef dep
			#define dep(i,x,y) for(int i=(x);i>(y);--i)
		#endif

		#ifndef scan
			#define scan(i,x) for(__typeof((x).begin()) i=(x).begin();i!=(x).end();++i)
		#endif



		/*
		#ifndef random
			#define random(x,y) (((ull)rand()<<48|(ull)rand()<<32|(ull)rand()<<16|(ull)rand())%((ull)(y)-(x)+1)+(x))
		#endif
		*/


		#ifndef errmsg
			#define errmsg(...) fprintf(stderr,__VA_ARGS__)
		#endif

/*
		namespace zdw{

			#define tpl template

			tpl<class _Tp>inline _Tp abs(const _Tp &x){return x<0?-x:x;}
			tpl<class _Tp>inline _Tp max(const _Tp &a,const _Tp &b){return a>b?a:b;}
			tpl<class _Tp>inline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
			tpl<class _Tp>inline void inc(_Tp &a,const _Tp &b){if(a<b)a=b;}
			tpl<class _Tp>inline void dec(_Tp &a,const _Tp &b){if(a>b)a=b;}
			tpl<class _Tp>inline void swap(_Tp &a,_Tp &b){_Tp c=a;a=b;b=c;}
			tpl<class _Tp>inline bool operator ==(const _Tp &A,const _Tp &B){return !memcmp(&A,&B,sizeof(_Tp));}

			#undef tpl

		}
*/
	#endif
	namespace zdw{

		std::vector<std::string> split(std::string s,char c=' '){
			std::vector<std::string>res;
			std::string tmp="";
			for(auto &i:s){
				if(i!=c)tmp+=i;
				else {
					res.push_back(tmp);
					tmp="";
				}
			}
			return res;
		}

	}
#endif
