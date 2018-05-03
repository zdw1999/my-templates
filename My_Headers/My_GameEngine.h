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
			void (*func)();
			int x,y,h,w;
			int color;
			char text[32];
			bool selected;
		public:
			inline button():x(0),y(0),h(0),w(0),color(0x07),selected(0){func=0;}
			inline button(const int &X,const int &Y,const int &H,const int &W,const int &c,char *s):x(X),y(Y),h(H),w(W),color(c),selected(0)
				{*text=0;while(text[1+*text]=*(s+*text))++(*text);}
			inline void setloc(const int &X,const int &Y){x=X;y=Y;}
			inline void setsize(const int &H,const int &W){h=H;w=W;}
			inline void setcolor(const int &c){color=c;}
			inline void settext(char *s){*text=0;while(text[1+*text]=*(s+*text))++(*text);}
			inline void print(){
				setconcolor(color|selected<<3|selected<<7/**/);
				int midy=(h+1>>1)-1,midx=w-text[0]>>1;
				for(int i=0;i<h;i++){
					CONLOC conloc;
					conloc.X=x;
					conloc.Y=y+i;
					setconloc(conloc);
					for(int j=0;j<w;j++)
						putchar(i==midy&&j>=midx&&j<midx+text[0]?text[1+j-midx]:' ');
				}
				setconcolor(0x07);
			}
			inline void setclick(void (*f)()){func=f;}
			inline void click(){func();}
			inline void select(){selected=1;}
			inline void unselect(){selected=0;}
		};
		
		template <class __Button>
		class menu{
		private:
			static const int _TH=2; //title hight(distance with top & other area distance with title)
			static const int _TW=3; //title width(1/_TH of w)
			int h,w,color,btot;
			char title[64],border;
			__Button *buttons[32];
			menu(){*title=btot=h=w=0;border='#';color=0x07;}
			menu(const char *_TITLE,const int &H,const int &W):h(H),w(W),border('#'),color(0x07)
				{*title=btot=0;while(title[1+*title]=*(_TITLE+*title))++(*title);}
		public:
			inline void settitle(const char *_TITLE){
				*title=0;while(title[1+*title]=*(_TITLE+*title))++(*title);
			}
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
			inline int addbutton(__Button *B){
				if(btot>=32)return 1;
				buttons[btot++]=B;
			}
			inline int addbutton(__Button *B){
				if(btot>=32)return 1;
				buttons[btot++]=B;
			}
		};
		
		template <class __Engine,class __Menu>
		class game{
			__Engine Game_Engine;
			__Menu *Game_Menus;
			
		};
	};
	
#endif
