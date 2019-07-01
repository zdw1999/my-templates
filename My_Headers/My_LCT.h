/**************************************

	Prog: Class_LCT
	Time: 2019-3-20
	Auther: zdw1999

	Lateset Update: 2019-3-20

**************************************/

#ifndef MY_LCT_H

	#define MY_LCT_H
	#include <bits/stdc++.h>

	namespace zdw{

		struct Directed_LCT_node{//edit string,query single point
			Directed_LCT_node *ch[2],*fa;
			int lazy,val;
			Directed_LCT_node(){
				ch[0]=ch[1]=fa=0;
				lazy=val=0;
			}
			void add(int v){
				lazy+=v;
				val+=v;
			}
			void pushdown(){
				if(lazy){
					if(ch[0])ch[0]->add(lazy);
					if(ch[1])ch[1]->add(lazy);
					lazy = 0;
				}
			}
		};

		class Directed_LCT{
		private:
			typedef Directed_LCT_node node;
			node *T;
			bool IsRoot(node *x){
				return !x->fa || x->fa->ch[0] != x && x->fa->ch[1] != x;
			}
			void PushDown(node *x){
				if(!IsRoot(x))PushDown(x->fa);
				x->pushdown();
			}
			void Rotate(node *x){
				node *y=x->fa,*z=y->fa;
				int l=(y->ch[0]!=x),r=l^1;
				if(!IsRoot(y)){
					if(z->ch[0]==y)z->ch[0]=x;
					else z->ch[1]=x;
				}
				x->fa=z; y->fa=x;
				if(x->ch[r])x->ch[r]->fa=y;
				y->ch[l]=x->ch[r]; x->ch[r]=y;
			}
			void Splay(node *x){
				PushDown(x);
				while(!IsRoot(x)){
					node *y=x->fa,*z=y->fa;
					if(!IsRoot(y)){
						if(y->ch[0]==x ^ z->ch[0]==y)
							Rotate(x);
						else Rotate(y);
					}
					Rotate(x);
				}
			}
			node* Access(node *x){
				node *y=0;
				for(;x;x=x->fa){
					Splay(x); x->ch[1]=y; y=x;
				}
				return y;
			}
			void Link(node *x, node *y){// set y as x's fa
				Access(x); Splay(x);
				x->fa=y;
			}
			void Cut(node *x){//cut x - fa
				Access(x); Splay(x);
				if(!(x->ch[0]))return;// x is root
				x->ch[0]=x->ch[0]->fa=0;
			}
			node *GetRoot(node *x){
				Access(x); Splay(x);
				while(x->ch[0])x=x->ch[0];
				return x;
			}
			void Add(node *x,int v){
				Access(x); Splay(x);
				x->add(v);
			}
		public:
			Directed_LCT(int sz=0){T=0;init(sz);}
			void init(int sz){
				if(T)free(T); //clear old
				T=(sz?(node*)malloc(sizeof(node)*sz):0);
				if(T)memset(T,0,sizeof(node)*sz);
			}
			void Link(int x,int y){
				Link(T+x-1,T+y-1);
			}
			void Cut(int x){
				Cut(T+x-1);
			}
			void Add(int x,int v){
				Add(T+x-1,v);
			}
			int Query(int x){
				Splay(T+x-1);
				return T[x-1].val;
			}
			int GetRoot(int x){
				return GetRoot(T+x-1)-T+1;
			}
		};

		struct LCT_node{
			LCT_node *ch[2],*fa;
			int lazy,val,rev;
			LCT_node(){
				ch[0]=ch[1]=fa=0;
				lazy=val=0;
			}
			void add(int v){
				lazy+=v;
				val+=v;
			}
			void pushdown(){
				if(lazy){
					if(ch[0])ch[0]->add(lazy);
					if(ch[1])ch[1]->add(lazy);
					lazy = 0;
				}
				if(rev){
					if(ch[0])ch[0]->rev^=1;
					if(ch[1])ch[1]->rev^=1;
					std::swap(ch[0],ch[1]);
					rev = 0;
				}
			}
		};

		class LCT{
		private:
			typedef LCT_node node;
			node *T;
			bool IsRoot(node *x){
				return !x->fa || x->fa->ch[0] != x && x->fa->ch[1] != x;
			}
			void PushDown(node *x){
				if(!IsRoot(x))PushDown(x->fa);
				x->pushdown();
			}
			void Rotate(node *x){
				node *y=x->fa,*z=y->fa;
				int l=(y->ch[0]!=x),r=l^1;
				if(!IsRoot(y)){
					if(z->ch[0]==y)z->ch[0]=x;
					else z->ch[1]=x;
				}
				x->fa=z; y->fa=x;
				if(x->ch[r])x->ch[r]->fa=y;
				y->ch[l]=x->ch[r]; x->ch[r]=y;
			}
			void Splay(node *x){//zigzag
				PushDown(x);
				while(!IsRoot(x)){
					node *y=x->fa,*z=y->fa;
					if(!IsRoot(y)){
						if(y->ch[0]==x ^ z->ch[0]==y)
							Rotate(x);
						else Rotate(y);
					}
					Rotate(x);
				}
			}
			node* Access(node *x){
				node *y=0;
				for(;x;x=x->fa){
					Splay(x); x->ch[1]=y; y=x;
				}
				return y;
			}
			void SetRoot(node *x){
				Access(x); Splay(x);
				x->rev^=1;
			}
			void Link(node *x, node *y){// set y as x's fa
				SetRoot(x);//avoid multi root
				Access(y); Splay(y);
				x->fa=y;
			}
			void Cut(node *x){//cut x - fa
				Access(x); Splay(x);
				if(!x->ch[0])return;// x is root
				x->ch[0]->fa=x->ch[0]=0;
			}
			node *GetRoot(node *x){
				Access(x); Splay(x);
				while(x->ch[0])x=x->ch[0];
				return x;
			}
			void Add(node *x,int v){
				Access(x); Splay(x);
				x->add(v);
			}
		public:
			LCT(int sz=0){T=0;init(sz);}
			void init(int sz){
				if(T)free(T); //clear old
				T=(sz?(node*)malloc(sizeof(node)*sz):0);
				if(T)memset(T,0,sizeof(node)*sz);
			}
			void Link(int x,int y){
				Link(T+x-1,T+y-1);
			}
			void Cut(int x){
				Cut(T+x-1);
			}
			void Add(int x,int v){
				Add(T+x-1,v);
			}
			int Query(int x){
				Splay(T+x-1);
				return T[x-1].val;
			}
			void SetRoot(int x){
				SetRoot(T+x-1);
			}
			int GetRoot(int x){
				return GetRoot(T+x-1)-T+1;
			}
		};

	};

#endif
