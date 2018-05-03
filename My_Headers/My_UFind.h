/**************************************

	Prog: Class_Union_Find
	Time: 2017-04-03
	Auther: zdw1999

**************************************/

#ifndef MY_UFIND_H
	
	#define MY_UFIND_H
	#ifndef UFIND_SIZE
		#define UFIND_SIZE 100000
	#endif
	
	namespace zdw{
		
		class UFind{
		private:
			int *fa,size;
			int gettop(int x){return fa[x]?fa[x]=gettop(fa[x]):x;}
		public:
			UFind(int SIZE=UFIND_SIZE){fa=(int *)malloc(sizeof(int)*(size=SIZE+1));clear();}
			~UFind(){free(fa);}
			void clear(){memset(fa,0,size);}
			void merge(int x,int y){if(gettop(x)!=gettop(y))fa[gettop(x)]=gettop(y);}
			bool check(int x,int y){return gettop(x)==gettop(y);}
		};
	};
	 
#endif
