/***************************************

	File_Name: My_console.h
	Date: 2017/11/04
	Auther: zdw1999

***************************************/

#include <conio.h>
#include <windows.h>
#include <My_Console.h>

#ifndef _MY_GAMEENGINE_H_
#define _MY_GAMEENGINE_H_

	namespace zdw{

		class button{
		private:
			int (*func)();
			int x,y,h,w;
			int color;
			std::string text;
			bool selected;
		public:
			inline button(char *s="",const int &X=0,const int &Y=0,const int &H=3,const int &W=5,int (*f)()=0,const int &c=0x07)
				:x(X),y(Y),h(H),w(W),color(c),selected(0),func(f),text(s){}
			inline void setloc(const int &X,const int &Y){x=X;y=Y;}
			inline void setsize(const int &H,const int &W){h=H;w=W;}
			inline void setcolor(const int &c){color=c;}
			inline void settext(char *s){text=s;}
			inline void settext(std::string s){text=s;}
			inline void print(){
				setconcolor(color|selected<<3|selected<<7/**/);
				int midy=(h+1>>1)-1,midx=w-text.size()>>1;
				for(int i=0;i<h;i++){
					CONLOC conloc;
					conloc.X=x;
					conloc.Y=y+i;
					setconloc(conloc);
					for(int j=0;j<w;j++)
						putchar(i==midy&&j>=midx&&j<midx+text.size()?text[j-midx]:' ');
				}
				setconcolor(0x07);
			}
			inline void setclick(int (*f)()){func=f;}
			inline void click(){func();}
			inline void select(){selected=1;}
			inline void unselect(){selected=0;}
		};

		template <class __Button>
		class menu{
		private:
			static const int _TH=2; //title hight(distance with top & other area distance with title)
			static const int _TW=3; //title width(1/_TH of w)
			int x,y,h,w,color;
			char border;
			std::string title;
			std::map<int,__Button*>buttons;
			std::map<__Button*,int>_index;
			inline menu(char *s="",const int &X=0,const int &Y=0,const int &H=3,const int &W=5,const int &c=0x07)
				:x(X),y(Y),h(H),w(W),color(c),title(s){}
		public:
			inline void settitle(const char *_TITLE){title=_TITLE;}
			inline void settitle(std::string _TITLE){title=_TITLE;}
			inline void setcolor(const int &c){color=c;}
			inline void setborder(const char &c){color=c;}
			inline void print(){
				setconcolor(color);
				setconsize(h,w);
				CONLOC conloc;
				conloc.X=conloc.Y=0;
				setconloc(conloc);
				for(int i=0;i<w;i++){
					putchar(border);
				}
			}
			inline int addbutton(__Button *B,int index){
				if(_index.find(B)!=_index.end())return 1; //Button existed
				if(buttons.find(index)!=buttons.end())return 2; //index existed
				buttons[index]=B; _index[B]=index;
				return 0;
			}
			inline int removebutton(int index){
				auto it=buttons.find(index);
				if(it==buttons.end())return 1; //index not existed
				_index.erase(it.second);
				delete it.second;
				buttons.erase(it);
				return 0;
			}
			inline int removebutton(__Button *B){
				auto it=_index.find(B);
				if(it==_index.end())return 1; //button not existed
				buttons.erase(it.second);
				_index.erase(it);
				delete B;
				return 0;
			}
		};

		template <class __Engine,class __Menu>
		class game{
			__Engine Game_Engine;
			std::vector<__Menu*>Game_Menus;

		};
	};

#endif
