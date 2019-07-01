/**************************************

	Prog: Class_SAM
	Time: 2019-3-23
	Auther: zdw1999

	Lateset Update: 2019-4-16

**************************************/

#ifndef MY_SAM_H

	#define MY_SAM_H
	#include <bits/stdc++.h>

	namespace zdw{

		struct SAM_node{
			typedef std::map<int,SAM_node*> ch_list;
			SAM_node *fa;
			ch_list *nxt;
			int len,vis; ll v;
			SAM_node(){len=vis=v=0; fa=0; nxt=0;}
			void clear_ch(){
				delete nxt;
				nxt=0;
			}
			void add_ch(int a,SAM_node* b){
				if(!nxt)nxt=new ch_list;
				(*nxt)[a]=b;
			}
			void del_ch(int a){
				if(nxt)nxt->erase(a);
			}
			SAM_node* get_ch(int a){
				if(!nxt)return 0;
				auto it=nxt->find(a);
				return it->second;
			}
			SAM_node* & operator [](int a){
				if(!nxt)nxt=new ch_list;
				return (*nxt)[a];
			}
			void clone(SAM_node* o){
				*this=*o;
				nxt=new ch_list;
				*nxt=*o->nxt;
			}
		};

		class SAM{
		private:
			typedef SAM_node node;
			node *S,*root,*last; int c;
			node *newnode(){
				return S+c++;
			}

			void set_fa(node *a,node *b){//set a's fa as b
		/*
				if(a->fa){
					lct.Add(a->fa-S+1,-lct.Query(a-S+1));
					lct.Cut(a-S+1);
				}
		*/
				a->fa = b;

		/*
				lct.Add(a->fa-S+1,lct.Query(a-S+1));
				lct.Cut(a-S+1);
		*/
			}

		public:
			SAM(int sz=0){S=0;init(sz);}
			void init(int sz){
				if(S){
					for(int i=0;i<c;++i)
						S[i].clear_ch();
					free(S);
				}
				if(sz){
					sz=sz*2; c=0;
					S=(node *)malloc(sizeof(node)*sz);
					memset(S,0,sizeof(node)*sz);
					last=root=newnode();
				} else {
					S=root=last=0;
					c=0;
				}
			}

			node* add(int c){
				node *p=last;
				node *cur=newnode(); //lct.Add(cur-S+1,1);
				cur->len=p->len+1;
				while(p&&!(*p)[c]){
					(*p)[c]=cur;p=p->fa;
				}
				if(!p){set_fa(cur,root);return last=cur;}
				node *q=(*p)[c];
				if(q->len==p->len+1){
					set_fa(cur,q);
				} else {
					node *nq=newnode();
					nq->clone(q);
					nq->len=p->len+1;
					set_fa(q,nq); set_fa(cur,nq);
					while(p&&(*p)[c]==q)(*p)[c]=nq,p=p->fa;
				}
				return last=cur;
			}
			ll getDistinctSubStringCount(node *p){
				if(p->vis==c)return p->v;
				ll & ans=p->v; ans=1;
				if(p->nxt)for(auto &it:*(p->nxt))
					ans+=getDistinctSubStringCount(it.second);
				p->vis=c;
				return ans;
			}
			//这个求法包含了空串
			ll getDistinctSubStringCount(){
				getDistinctSubStringCount(root);
			}
			//这个求法不包含空串
			ll getDistinctSubStringCount2(){
				ll ans=0;
				for(int i=1;i<c;++i)
					ans+=(S+i)->len - (S+i)->fa->len;
				return ans;
			}
		};

		class SAM_LCT{
		private:
			typedef SAM_node node;
			Directed_LCT lct;
			node *S,*root,*last; int c;
			node *newnode(){
				return S+c++;
			}

			void set_fa(node *a,node *b){//set a's fa as b

				int va=lct.Query(a-S+1);

				if(a->fa){
					lct.Add(a->fa-S+1,-va);
					lct.Cut(a-S+1);
				}

				a->fa = b;

				lct.Add(b-S+1,va);
				lct.Link(a-S+1,b-S+1);

			}

		public:
			SAM_LCT(int sz=0){S=0;init(sz);}
			void init(int sz){
				if(S){
					for(int i=0;i<c;++i)
						S[i].clear_ch();
					free(S);
					lct.init(0);
				}
				if(sz){
					lct.init(sz*2);
					sz=sz*2; c=0;
					S=(node *)malloc(sizeof(node)*sz);
					memset(S,0,sizeof(node)*sz);
					last=root=newnode();
				} else {
					S=root=last=0;
					c=0;
				}
			}

			node* add(int c){
				node *p=last;
				node *cur=newnode(); lct.Add(cur-S+1,1);
				cur->len=p->len+1;
				while(p&&!(*p)[c]){
					(*p)[c]=cur;p=p->fa;
				}
				if(!p){set_fa(cur,root);return last=cur;}
				node *q=(*p)[c];
				if(q->len==p->len+1){
					set_fa(cur,q);
				} else {
					node *nq=newnode();
					nq->clone(q);
					nq->len=p->len+1;
					nq->fa=0; set_fa(nq,q->fa);
					set_fa(q,nq); set_fa(cur,nq);
					while(p&&(*p)[c]==q)(*p)[c]=nq,p=p->fa;
				}
				return last=cur;
			}
			//这个求法不包含空串
			ll getDistinctSubStringCount(){
				ll ans=0;
				for(int i=1;i<c;++i)
					ans+=(S+i)->len - (S+i)->fa->len;
				return ans;
			}
			template <class _Tp>
			ll getSubStringCount(_Tp *str,int len){
				node *tmp=root;
				for(int i=0;i<len;++i){
					tmp=(*tmp)[str[i]];
					if(!tmp)return 0;
				}
				return lct.Query(tmp-S+1);
			}
		};

	};

#endif
