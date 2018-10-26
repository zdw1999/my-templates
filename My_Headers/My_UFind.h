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
		
		struct UFind{
			vector<int>V;
			UFind(int sz=1e6+5){V.resize(sz,-1);}
			void clear(){fill(V.begin(),V.end(),-1);}
			int top(int x){return V[x]==-1?x:V[x]=top(V[x]);}
			void unite(int x,int y){x=top(x);y=top(y);if(x!=y)V[x]=y;}
			bool query(int x,int y){return top(x)==top(y);}
		};
	};
	 
#endif
