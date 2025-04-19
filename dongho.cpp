#include <bits/stdc++.h>
#include <graphics.h>
#include <windows.h>
using namespace std;
float h, p, s;
int ds,dp,dh,xs,ys, xp,yp,xh,yh,l1, x, y,start, stop, vac=360, vac2=360,thoat=0;
long long tt, gio,phut, giay;
 
void resizeConsole(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}
 
void clock1();
void clockk();
void menu();
void number();
void stopwatch();
void vach();
void stopwatch1();
void display();
 
int main()
{
    resizeConsole(0,0);
    initwindow(600,600);
    clock1();
return 0;
}
 
void vach()
{
    int vx=cos((vac/180.)*acos(-1))*200+300, vy=sin((vac/180.)*acos(-1))*200+300;
    int vx2=cos((vac2/180.)*acos(-1))*200+300, vy2=sin((vac2/180.)*acos(-1))*200+300;
    setfillstyle(1,12); setfillstyle(1,12); setlinestyle(1,1,10);
    setcolor(9);fillellipse(vx,vy,1,1);
    setcolor(12);fillellipse(vx2,vy2,1,1);
    vac-=6; vac2-=30;
}
void number()
{
    setcolor(12); setbkcolor(15); settextstyle(1,0,3);
    outtextxy(380,140,"1"); outtextxy(440,200,"2"); outtextxy(460,285,"3");
    outtextxy(440,370,"4"); outtextxy(380,440,"5"); outtextxy(288,465,"6");
    outtextxy(195,435,"7"); outtextxy(140,375,"8"); outtextxy(120,285,"9");
    outtextxy(140,200,"10");    outtextxy(195,140,"11"); outtextxy(280,115,"12");
}
void clockk()
{
    //Xoa
    xh=cos((dh/180.)*acos(-1))*130+300;//tinh toa x kim gio
    yh=sin((dh/180.)*acos(-1))*130+300;//tinh toa y kim gio
    setlinestyle(1,1,8); setcolor(15); line(300,300,xh,yh);//kim gio
    xp=cos((dp/180.)*acos(-1))*160+300;//tinh toa x kim phut
    yp=sin((dp/180.)*acos(-1))*160+300;//tinh toa y kim phut
    setlinestyle(1,1,5); setcolor(15); line(300,300,xp,yp);//kim phut
    xs=cos((ds/180.)*acos(-1))*185+300;//tinh toa x kim giay
    ys=sin((ds/180.)*acos(-1))*185+300;//tinh toa y kim giay
    setlinestyle(1,1,2); setcolor(15); line(300,300,xs,ys);//kim giay
    //Khoi tao
    setcolor(3); setbkcolor(15); settextstyle(2,0,7);
    outtextxy(220,380,"clock by tanchan679"); 
    time_t cl=time(0);
    char *now=ctime(&cl);
    setcolor(14); setbkcolor(0); settextstyle(3,0,3);
    outtextxy(160,30,now);//Dong ho so
    //lay thoi gian
    p=(now[14]-48)*10+(now[15]-48);
    h=(now[11]-48)*10+(now[12]-48)+p/60;
    s=(now[17]-48)*10+(now[18]-48);
    ds=((s*6)-90);
    dp=((p*6)-90);
    dh=(h*30)-90;
    xh=cos((dh/180.)*acos(-1))*130+300;//tinh toa x kim gio
    yh=sin((dh/180.)*acos(-1))*130+300;//tinh toa y kim gio
    setlinestyle(1,1,8); setcolor(1); line(300,300,xh,yh);//kim gio
    xp=cos((dp/180.)*acos(-1))*160+300;//tinh toa x kim phut
    yp=sin((dp/180.)*acos(-1))*160+300;//tinh toa y kim phut
    setlinestyle(1,1,5); setcolor(1); line(300,300,xp,yp);//kim phut
    xs=cos((ds/180.)*acos(-1))*185+300;//tinh toa x kim giay
    ys=sin((ds/180.)*acos(-1))*185+300;//tinh toa y kim giay
    setlinestyle(1,1,2); setcolor(1); line(300,300,xs,ys);//kim giay
    setfillstyle(1,12); fillellipse(300,300,8,8); //truc xoay
}
void menu()
{
    if(ismouseclick(WM_MOUSEMOVE))
    {
        getmouseclick(WM_MOUSEMOVE, x, y);
        if(x>20&&x<200&&y>550&&y<600)
        {
            setcolor(1); setbkcolor(0); settextstyle(6,0,3);
            outtextxy(20,550,"Stopwatch");
        }
        else{
            setcolor(2); setbkcolor(0); settextstyle(6,0,3);
            outtextxy(20,550,"Stopwatch");
        }
    }
    if(ismouseclick(WM_LBUTTONDBLCLK))
    {
        getmouseclick(WM_LBUTTONDBLCLK, x, y);
        if(x>20&&x<200&&y>550&&y<600) stopwatch1();
    }
}
void clock1()
{
    setfillstyle(1,0);
    bar(0,0,600,600);
    setfillstyle(1,15); setcolor(7); setlinestyle(1,2,15);
    fillellipse(300,300,200,200); //Khung tron dong ho kim
    for(int i=0;i<60;i++) vach();
    setcolor(2); setbkcolor(0); settextstyle(6,0,3);
    outtextxy(20,550,"Stopwatch");
    while(1)
    {
        number();
        clockk();
        menu();
        delay(100);
    }
}
void click()
{
    if(ismouseclick(WM_LBUTTONDBLCLK))
    {
        getmouseclick(WM_LBUTTONDBLCLK, x, y);
        if(x>50&&x<170&&y>520&&y<570)
        {
            thoat=1; if(stop=0) stop=1; else stop=0;
        }
            else if(x>231&&x<349&&y>520&&y<570)
                {
                    tt=0; giay=0;phut=0;
                    display();
                }
                else if(x>390&&x<532&&y>520&&y<570)
                {
                        clock1();start=0;
                }
        }
}
void move()
{
    if(ismouseclick(WM_MOUSEMOVE))
    {
    getmouseclick(WM_MOUSEMOVE, x, y);
        if(x>50&&x<170&&y>520&&y<570)
        {
            setcolor(12); setbkcolor(0); settextstyle(6,0,5);
            if(stop==0) outtextxy(51,524,"Start  ");
            else if(stop==1) outtextxy(51,524,"Stop  ");
        }
        else if(x>231&&x<349&&y>520&&y<570)
        {
        setcolor(12); setbkcolor(0); settextstyle(6,0,5);
        outtextxy(220,524,"Reset");
        }
        else if(x>390&&x<532&&y>520&&y<570)
        {
            setcolor(12); setbkcolor(0); settextstyle(6,0,5);
            outtextxy(410,524,"Back");
        }
        else{
        setcolor(14); setbkcolor(0); settextstyle(6,0,5);
        if(stop==0) outtextxy(51,524,"Start  ");
        else if(stop==1) outtextxy(51,524,"Stop  ");
        outtextxy(220,524,"Reset");
        outtextxy(410, 524,"Back");
                         
        }
    }
}
void display()
{
    char tem[2];
        tem[0]=phut/10+48; tem[1]=phut%10+48; tem[2]=0;
        setcolor(15); setbkcolor(0); settextstyle(6,0,10);outtextxy(70,200,tem);
         outtextxy(275,200,":");
         tem[0]=giay/10+48; tem[1]=giay%10+48; tem[2]=0;outtextxy(340,200,tem);
         setcolor(12); setbkcolor(0); settextstyle(6,0,5);
         tem[0]=tt/10+48; tem[1]=tt%10+48; tem[2]=0;outtextxy(470,320,tem);
         setlinestyle(0,1,3); setcolor(8);
         line(0,500,600,500);
         setcolor(14); setbkcolor(0); settextstyle(6,0,5);  
          if(start==0)
          {
            outtextxy(51,524,"Start");  outtextxy(220,524,"Reset");outtextxy(410,524,"Back");
          }
}
void start1()
{
    if(start==0)
        {
            stop=0;
            start=1;
            while(thoat==0)
            {
                move();
                click();
                delay(10);
            }
            stop=1; thoat=0;
        }
}
void stopwatch()
{
        display();
        tt+=2;
        if(tt==100)
        {
            tt=0;
            giay++;
            if(giay==60)
            {
                giay=0;
                phut++;
             }
         }
    setcolor(12); setbkcolor(0); settextstyle(6,0,5);        
    start1();
    move();
    if(ismouseclick(WM_LBUTTONDBLCLK))
    {
        getmouseclick(WM_LBUTTONDBLCLK, x, y);
        if((x>50&&x<170&&y>520&&y<570))
        {
                stop=0;
            while(thoat==0)
            {
                move();
                click();
                delay(10);
            }
             thoat=0;stop=1;
        }
        else if(x>231&&x<349&&y>520&&y<570)
        {
            tt=0; giay=0;phut=0;
        }
        else if(x>390&&x<532&&y>520&&y<570)
        {
            clock1();
        }
    } 
}
void stopwatch1()
{
    tt=0; giay=0;phut=0; start=0; thoat=0;
    setfillstyle(1,0);
    bar(0,0,600,600);
     setcolor(11); setbkcolor(0); settextstyle(6,0,7);outtextxy(0,0,"Stopwatch");
     setcolor(9); setbkcolor(0); settextstyle(7,0,1);outtextxy(65,70,"~~by Tanchan679~~");
    while(1)
    {
        stopwatch();
        delay(0.0001);
    }
}
