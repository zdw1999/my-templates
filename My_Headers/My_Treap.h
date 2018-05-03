/**************************************

	Prog: Class_Treap
	Time: 2016-12-01
	Auther: zdw1999
	
	Lateset Update: 2017-06-15

**************************************/

#ifndef MY_TREAP_H
	 
	#define MY_TREAP_H
	#include <cstdlib>
	 
	namespace zdw{
		template <class __pre, class __nxt>
		class __treap__node{
		public:
			__treap__node *son[2];
			int fix,sz;
			__pre pre;
			__nxt nxt;
			__treap__node(){}
		};
		template <class __pre, class __nxt>
		class Treap{
		private:
			__treap__node<__pre, __nxt>*Root,*__NULL;
			char __Err__Num;
			/**************************************
				
				0:No Error Before.
				1:Target Request Not Found.
				2.Target NOT inserted before use [].
				3.Target is exist when inserting.
				.
				.
				.
				.
				.
				.~255.Unknown Error.(Exception)
				
			**************************************/
			void updata(__treap__node<__pre, __nxt> *&a){
				__treap__node<__pre, __nxt> *&_l=a->son[0], *&_r=a->son[1];
				a->sz=(_l?_l->sz:0)+(_r?_r->sz:0)+1;
			}
			void Rotate(__treap__node<__pre, __nxt> *&a,int lr){
				__treap__node<__pre, __nxt> *t=a->son[!lr];
				if(!t)return;
				a->son[!lr]=t->son[lr];
				t->son[lr]=a;
				updata(a); updata(t);
				a=t;
			}
			void delnode(__treap__node<__pre, __nxt> *&a){
				__treap__node<__pre, __nxt> *&_l=a->son[0], *&_r=a->son[1],*t=a;
                if(!_l&&!_r){delete a;a=0;}
                else if(!_l&&_r){a=_r;delete t;}
                else if(_l&&!_r){a=_l;delete t;}
				else{
					if(_l->fix>_r->fix){
						Rotate(a,0);
						delnode(a->son[0]);
						updata(a);
					} else {
						Rotate(a,1);
						delnode(a->son[1]);
						updata(a);
					}
				}
			}
			void insert(__treap__node<__pre, __nxt> *&a,const __pre &pre,const __nxt &nxt){
				if(!a){
					a=new __treap__node<__pre, __nxt>;
					a->pre=pre; a->nxt=nxt; a->fix=rand();
					a->son[0]=a->son[1]=0; a->sz=1;
				} else {
					if(pre==a->pre){
						__Err__Num = 3;
						a->nxt=nxt;
						return;
					}
					int lr=a->pre<pre?1:0;
					insert(a->son[lr],pre,nxt);
					if((*a->son[lr]).fix<a->fix)
						Rotate(a,!lr);
					updata(a);
				}
			}
			void erase(__treap__node<__pre, __nxt> *&a,const __pre &pre){
				if(!a){__Err__Num=1; return;}
				if(a->pre==pre){delnode(a); return;}
				if(a->pre<pre){erase(a->son[1],pre);}
				else{erase(a->son[0],pre);}
				updata(a);
			}
			void clear(__treap__node<__pre, __nxt> *&a){
				if(!a)return;
				clear(a->son[0]);
				clear(a->son[1]);
				delete a;
			}
			bool find(__treap__node<__pre, __nxt> *&a,const __pre &pre){
				if(!a){__Err__Num=1; return 0;}
				if(a->pre==pre)return 1;
				if(a->pre<pre)return find(a->son[1],pre);
				else return find(a->son[0],pre);
			}
			__nxt &__find(__treap__node<__pre, __nxt> *&a,const __pre &pre){
				if(!a){
					__Err__Num = 2;
					a=new __treap__node<__pre, __nxt>;
					memset(&a->nxt,0,sizeof(a->nxt));//set nxt as 0
					a->pre=pre; /*a->nxt=nxt;*/ a->fix=rand();
					a->son[0]=a->son[1]=0; a->sz=1;
					return a->nxt;
				} else {
					if(pre==a->pre){return a->nxt;}
					int lr=a->pre<pre?1:0;
					__nxt &ret=__find(a->son[lr],pre);
					if((*a->son[lr]).fix<a->fix)
						Rotate(a,!lr);
					updata(a);
					return ret;
				}
			}
		public:
			Treap(){insert(__NULL,__pre(),__nxt());Root=0;__Err__Num=0;}
			void insert(const __pre &pre,const __nxt &nxt){__Err__Num=0; insert(Root,pre,nxt);}
			void erase(const __pre &pre){__Err__Num=0; erase(Root,pre);}
			void clear(){clear(Root); Root=0;}
			bool find(const __pre &pre){__Err__Num=0; return find(Root,pre);}
			__nxt & operator[](const __pre &pre){__Err__Num=0; return __find(Root,pre);}
			char Get_Err_Num(){return __Err__Num;}
			int Get_Treap_Size(){return Root?(*Root).sz:0;}
			__treap__node<__pre, __nxt> *Get_Root(){return Root;}
			//must insert first before using [] ....
			
			/*******************************************************************
			//not using now.
			__nxt getrank(__treap__node<__pre, __nxt> *&a,int rk){
				if(!a){__Err__Msg=1; return __nxt(0);}
				__treap__node<__pre, __nxt> *&_l=a->son[0], *&_r=a->son[1];
				if(rk-1==(_l?(*_l).sz:0))return a->nxt;
				if(rk>(_l?(*_l).sz:0))return getrank(_r,rk-(_l?(*_l).sz:0)-1);
				return getrank(_l,rk);
			}
			*******************************************************************/
		};
	}
	 
#endif
