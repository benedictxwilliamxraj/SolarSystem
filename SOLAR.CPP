 # include <iostream.h>
 # include <graphics.h>
 # include <stdlib.h>
 # include <conio.h>
 # include <math.h>
 # include <dos.h>

class Planet
 {
    private:
       int x;
       int y;
       int rx;
       int ry;
       int color;
       int radius;
       int position;

       float displacement;

       char* Buffer;

    public:
       Planet( )   { x=y=rx=ry=radius=0; }
       ~Planet( )  { delete Buffer; }
       Planet(int,int,int,float,int);

       void Show( );
       void Move( );
       void ShowOrbit( );
       void GetNextPosition( );
 };

 

 Planet::Planet(int _rx,int _ry,int _radius,float _displacement,int _color)
 {
    rx=_rx;
    ry=_ry;
    color=_color;

    x=(319+rx);
    y=240;

    radius=_radius;
    displacement=_displacement;
    position=0;
 }

 void Planet::ShowOrbit( )
 {
    setcolor(15);
      ellipse(320,240,0,360,rx,ry);
 }

 void Planet::Show( )
 {
    /*color=(random(14)+8);

    if(color==8 || color==14 || color==16)
       color=(random(6)+1);
    */
    Buffer=new char[imagesize((x-(radius+3)),(y-(radius+3)),(x+radius+3),(y+radius+3))];

    getimage((x-(radius+3)),(y-(radius+3)),(x+radius+3),(y+radius+3),Buffer);

    setcolor(color);
    setfillstyle(1,color);
      pieslice(x,y,0,360,radius);

    setcolor(11);
      circle(x,y,radius);
 }

 void Planet::Move( )
 {
    putimage((x-(radius+3)),(y-(radius+3)),Buffer,0);

    delete Buffer;

    GetNextPosition( );

    Buffer=new char[imagesize((x-(radius+3)),(y-(radius+3)),(x+(radius+3)),(y+(radius+3)))];

    getimage((x-(radius+3)),(y-(radius+3)),(x+(radius+3)),(y+(radius+3)),Buffer);

    setcolor(color);
    setfillstyle(1,color);
      pieslice(x,y,0,360,radius);

    setcolor((15-color));
      circle(x,y,radius);
 }

 void Planet::GetNextPosition( )
 {
    float angle=(displacement*position);

    x=(int)(rx*cosl(angle)+320+0.5);
    y=(int)(ry*sinl(angle)+240+0.5);

    if((y==240 || y==239) && x>320)
       position=1;

    position++;
 }

 void main( )
 {
    int driver=VGA;
    int mode=VGAHI;
    int error_code;

    initgraph(&driver,&mode,"C:\\TurboC4\\TC\\BGI");

    error_code=graphresult( );

    if(error_code!=grOk)
    {
       restorecrtmode( );
       textmode(BW80);
       clrscr( );

       cout<<" \n Fatal Error  : Graphic Driver not initialized"<<endl;
       cout<<" Error Reason : "<<grapherrormsg(error_code)<<endl;
       cout<<" \n Press any key to exit...";

       getch( );
       exit(1);
    }

    setlinestyle(0,0,3);

    setcolor(7);
      rectangle(0,0,getmaxx( ),getmaxy( ));

    setlinestyle(0,0,0);

    /*for(int count=0;count<5000;count++)
       putpixel(random(640),random(480),random(15));*/

   /*settextstyle(2,0,7);
      setcolor(9);
    outtextxy(15,10,"Solar");
    outtextxy(16,10,"Solar");
    outtextxy(16,11,"Solar");

      setcolor(3);
    outtextxy(72,10,"System");
    outtextxy(73,10,"System");
    outtextxy(73,11,"System");

      setcolor(11);
    outtextxy(22,27,"Simulation");
    outtextxy(23,27,"Simulation");
    outtextxy(23,28,"Simulation");

    setcolor(7);
    settextstyle(2,0,4);
      outtextxy(10,465,"Press any key to exit.");*/

    setcolor(14);
    setfillstyle(1,14);
      pieslice(320,240,0,360,12);

   setcolor(12);
     circle(320,240,12);

   setcolor(4);
     circle(320,240,13);

    Planet Mercury(50,30,5,0.0175,3);
    Planet Venus(80,55,5,0.0155,2);
    Planet Earth(110,80,5,0.0135,1);
    Planet Mars(140,105,5,0.0115,4);
    Planet Jupiter(170,130,10,0.0095,6);
    Planet Saturn(200,155,10,0.0075,7);
    Planet Uranus(230,180,8,0.0055,6);
    Planet Neptune(260,205,8,0.0035,9);
    Planet Pluto(290,230,4,0.0015,12);

    Mercury.ShowOrbit( );
    Mercury.Show( );

    Venus.ShowOrbit( );
    Venus.Show( );

    Earth.ShowOrbit( );
    Earth.Show( );

    Mars.ShowOrbit( );
    Mars.Show( );

    Jupiter.ShowOrbit( );
    Jupiter.Show( );

    Saturn.ShowOrbit( );
    Saturn.Show( );

    Uranus.ShowOrbit( );
    Uranus.Show( );

    Neptune.ShowOrbit( );
    Neptune.Show( );

    Pluto.ShowOrbit( );
    Pluto.Show( );

    do
    {
       delay(25);

       Mercury.Move( );
       Venus.Move( );
       Earth.Move( );
       Mars.Move( );
       Jupiter.Move( );
       Saturn.Move( );
       Uranus.Move( );
       Neptune.Move( );
       Pluto.Move( );
    }
    while(!kbhit( ));

    getch( );
    closegraph( );
 }