/**************************************

	Prog: Class_Heap
	Time: 2016-12-07
	Auther: zdw1999
	
	Lateset Update: 2017-06-15

**************************************/

#ifndef MY_HEAP_H
	
	#define MY_HEAP_H
	
	#ifndef DEFAULT_HEAP_SIZE
		#define DEFAULT_HEAP_SIZE 100000
	#endif
	
	namespace zdw{
		
		template<class _Tp>
		class heap{
		private:
			_Tp *A; int now_size,max_size;
			inline void swap(_Tp &a,_Tp &b){_Tp c=a;a=b;b=c;}
			void fixup(int x){while(x>1&&A[x]<A[x>>1])swap(A[x],A[x>>1]),x>>=1;}
			void fixdown(int x){
				while(x<<1<=now_size){
					_Tp *t=&A[x<<1]; if(x<<1==now_size)t=&A[x<<1];
					else t=A[x<<1]<A[x<<1|1]?&A[x<<1]:&A[x<<1|1];
					if(A[x]<*t)break; else swap(A[x],*t),x=t-&A[0];
				}
			}
			
		public:
			heap(int MAX_HEAP_SIZE=DEFAULT_HEAP_SIZE){A=(_Tp *)malloc(sizeof(_Tp)*(max_size=MAX_HEAP_SIZE));now_size=0;}
			~heap(){free(A);}
			void push(const _Tp &x){A[++now_size]=x;fixup(now_size);}
			_Tp pop(){swap(A[1],A[now_size--]);fixdown(1);return A[now_size+1];}
			_Tp top(){return A[1];}
			int size(){return now_size;}
			bool empty(){return !now_size;}
		};
		
	}
	
#endif