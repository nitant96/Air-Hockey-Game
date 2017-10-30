 #include<stdio.h>
 #include<conio.h>
 #include<math.h>
 #include<graphics.h>
 #include<stdlib.h>
 #include<dos.h>
 int xmin=70,ymin=2,xmax=550,ymax=470,prad=10,count=1,start=1,stepc=25,m,n,score=0;
 float x=(xmax+xmin)/2,y=(ymin+prad),d;
 int xminc=(xmax+xmin)/2-30,xmaxc=(xmax+xmin)/2+30,ymaxc=ymax-20,yminc=ymax-2;
 int x1,x2,y1,y2,countercolor=4,bkcolor=0,framecolor=1,ballcolor=1,del,difficulty,txtcolor=4;
 char ch,result[100],name[10],scorestring[5];
 int c;
 void gridlines();
 void scores();
 void cursor();
 void gameon();
 void main()   /* main function putting gridlines and
 generating the first strike at different angles*/
 {
 clrscr();
 printf("==================WELCOME==================\n");
 printf("Do You want to play this game?? At your own RISK !! y/n\n");
 ch=getch();
 start=1;
 if(ch=='y'|| ch=='Y')
 {
 printf("Enter yor Name\n");
 scanf("%s",name);
 printf("\nEnter The Difficulty Level :\n 1. Easy\n 2. Medium\n 3. Hard\n ");
 scanf("%d",&difficulty);
 if(difficulty==1)
	del=7;
 else if (difficulty==2)
	del=5;
 else
	del=2;
 printf("Loading Game .");
 for(int i=0;i<5;i++)
	{
	printf(".");
	delay(500);
	}
 clrscr();
 int gd=DETECT,gm=DETECT;
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 setbkcolor(bkcolor);
 setcolor(framecolor);
 line(xmin,ymin,xmin,ymax);    //left line
 line(xmin,ymin,xmax,ymin);   //top line
 line(xmax,ymin,xmax,ymax);   //right line
 line(xmin,ymax,xmax,ymax);  //bottom line
 line(xmin,(ymax+ymin)/2,xmax,(ymax+ymin)/2);  //mid line
 setfillstyle(SOLID_FILL,bkcolor);
 floodfill(xmin+1,ymax-1,framecolor);
 floodfill(xmin+1,ymin+1,framecolor);
 scores();
 cursor();
 circle((xmin+xmax)/2,(ymin+prad),prad);//first counter
 randomize();
 m=rand()%2;//generating different slopes
 switch((m+1))
	{ 	case 1:d=-0.325;
			break;
		case 2:d=-0.650;
			break;
	}

 while(x>(xmin+prad)) //(d<0) means counter goes left
	{
	gridlines();
	if(d==-0.325) //angle is small so x is decremented by 1
		{
		setcolor(bkcolor);     //previous circle is removed
		circle(x,y,prad);
		x-=1;
		y=y-d;
		if(kbhit())
			{
			getch();
			c=getch();
			cursor();
			}
		setcolor(ballcolor);     //next circle is plotted
		circle(x,y,prad);
		}
	else
		{
		setcolor(bkcolor);       //angle is large so y is incremented by 1
		circle(x,y,prad);
		y+=1;
		x=x+(1.0/d);
		if(kbhit())
			{
			getch();
			c=getch();
			cursor();
			}
		setcolor(ballcolor);
		circle(x,y,prad);
		}
	delay(del);
	}
 gameon();
 }
else
printf("Press any key to EXIT");
getch();
}
void gameon()  /*funtion to move counter after generation of random angle */
{
settextstyle(0,0,2);
if(y==(ymaxc-prad))//for reflection from the bottom
	{
	sound(400);
	delay(50);
	nosound();
	count=0;
	if(d>0)
		{
		if(d==0.325)
			{
			d=-0.325;
			}
		else
			{
			d=-0.65;
			}
		}
	else
		{
		if(d==-0.325)
			{
			d=0.325;
			}
		else
			{
			d=0.65;
			}
		}
	scores();
	if(d<0)
		{
		while(x>(xmin+prad))
			{
			gridlines();
			setcolor(bkcolor);
			circle(x,y,prad);
			if(d==-0.325)
				{
				x-=1;
				y=y+d;
				}
			else
				{
				y-=1;
				x=x+(1.0/d);
				}
			if(kbhit())
				{
				getch();
				c=getch();
				cursor();
				}
			setcolor(ballcolor);
			circle(x,y,prad);
			delay(del);
			}
		}
	else
		{
		while(x<(xmax-prad))
			{
			gridlines();
			setcolor(bkcolor);
			circle(x,y,prad);
			if(d==0.325)
				{
				x+=1;
				y=y-d;
				}
			else
				{
				y-=1;
				x=x+(1.0/d);
				}
			if(kbhit())
				{
				getch();
				c=getch();
				cursor();
				}
			setcolor(ballcolor);
			circle(x,y,prad);
			delay(del);
			}
		}

	gameon();
	}
if(x<=(xmin+prad))//for left side reflection
	{
	while(x<(xmax-prad) && y<(ymaxc-prad) && y>(ymin+prad))//loop for reflected ray
		{
		gridlines();
		if(d==-0.325) //for small angle on left
			{
			setcolor(bkcolor);
			circle(x,y,prad);
			if(count==1)
				{
				y=y-d;
				x+=1;
				}
			else 	{
				y=y+d;
				x+=1;
				}
			if(kbhit())
				{
				getch();
				c=getch();
				cursor();
				}
			setcolor(ballcolor);
			circle(x,y,prad);
			delay(del);
			}
		else 	{
			setcolor(bkcolor);
			circle(x,y,prad);
			if(count==1)
				{
				y+=1;
				x=x-(1.0/d);
				}
			else
				{
				y-=1;
				x=x-(1.0/d);
				}
				if(kbhit())
					{
					getch();
					c=getch();
					cursor();
					}
				setcolor(ballcolor);
				circle(x,y,prad);
				delay(del);
			}
		}
		if(y==(y2-prad))
			{
			if(x<=x2 && x>=x1)
				{
				score+=10;
				gameon();
				}
			else
				{
				while(x<(xmax-prad) && y<(ymax-prad))  //loop for reflected ray
					{
					gridlines();
					if(d==-0.325)
						{
						setcolor(bkcolor);
						circle(x,y,prad);
						if(count==1)
							{
							y=y-d;
							x+=1;
							}
						else 	{
							y=y+d;
							x+=1;
							}
						if(kbhit())
							{
							getch();
							c=getch();
							cursor();
							}
						setcolor(ballcolor);
						circle(x,y,prad);
						delay(del);
						}
					else 	{
						setcolor(bkcolor);
						circle(x,y,prad);
						if(count==1)
							{
							y+=1;
							x=x-(1.0/d);
							}
						else
							{
							y-=1;
							x=x-(1.0/d);
							}
						if(kbhit())
							{
							getch();
							c=getch();
							cursor();
							}
						setcolor(ballcolor);
						circle(x,y,prad);
						delay(del);
						}
					}
					if(y==(ymax-prad))
					{
					sound(300);
					delay(1000);
					nosound();
					setcolor(txtcolor);
					outtextxy((xmax+xmin)/2-220,ymin+70,"Oops!! You missed It");
					sprintf(result,"your score for level %d is %d",difficulty,score);
					outtextxy((xmax+xmin)/2-220,ymin+90,result);
					outtextxy((xmax+xmin)/2-220,ymin+110,"Press any key to exit :)");
					getch();
					exit(1);
					}
				}
			}
		if(d==-0.325) //changing value of slope for further reflection
			d=0.325;
		else
			d=0.65;
		gameon();
	}
if(x>=(xmax-prad))   //for right side reflection
	{
	while(x>(xmin+prad) && y<(ymaxc-prad) && y>(ymin+prad))  //loop for reflected ray
		{
		gridlines();
		if(d==0.325)
			{
			setcolor(bkcolor);
			circle(x,y,prad);
			if(count==1)
				{
				y=y+d;
				x-=1;
				}
			else 	{
				y=y-d;
				x-=1;
				}
			if(kbhit())
				{
				getch();
				c=getch();
				cursor();
				}
			setcolor(ballcolor);
			circle(x,y,prad);
			delay(del);
			}
		else 	{
			setcolor(bkcolor);
			circle(x,y,prad);
			if(count==1)
				{
				y+=1;
				x=x-(1.0/d);
				}
			else
				{
				y-=1;
				x=x-(1.0/d);
				}
			if(kbhit())
				{
				getch();
				c=getch();
				cursor();
				}
			setcolor(ballcolor);
			circle(x,y,prad);
			delay(del);
			}
		}
		if(y==(ymaxc-prad))
			{
			if(x<=x2 && x>=x1)
				{
				score+=10;
				gameon();
				}
			else
				{
				while(y<(ymax-prad))  //loop for reflected ray
					{
					gridlines();
					if(d==0.325)
						{
						setcolor(bkcolor);
						circle(x,y,prad);
						if(count==1)
							{
							y=y+d;
							x-=1;
							}
						else 	{
							y=y-d;
							x-=1;
							}
						if(kbhit())
							{
							getch();
							c=getch();
							cursor();
							}
						setcolor(ballcolor);
						circle(x,y,prad);
						delay(del);
						}
					else 	{
						setcolor(bkcolor);
						circle(x,y,prad);
						if(count==1)
							{
							y+=1;
							x=x-(1.0/d);
							}
						else
							{
							y-=1;
							x=x-(1.0/d);
							}
						if(kbhit())
							{
							getch();
							c=getch();
							cursor();
							}
						setcolor(ballcolor);
						circle(x,y,prad);
						delay(del);
						}
					}
					if(y==(ymax-prad))
					{
					sound(300);
					delay(1000);
					nosound();
					setcolor(txtcolor);
					outtextxy((xmax+xmin)/2-220,ymin+70,"Oops!! You missed It");
					sprintf(result,"your score for level %d is %d",difficulty,score);
					outtextxy((xmax+xmin)/2-220,ymin+90,result);
					outtextxy((xmax+xmin)/2-220,ymin+110,"Press any key to exit :)");
					getch();
					exit(1);
					}
				}
			}
		if(d==0.325) //changing value of slope for further reflection
			d=-0.325;
		else
			d=-0.65;
		gameon();
	}
if(y<=(yminc+prad-1))// to edit forthe above reflection
	{
	sound(400);
	delay(50);
	nosound();
	count=1;
	if(d<0)
		{
		while(x>(xmin+prad))
			{
			gridlines();
			setcolor(bkcolor);
			circle(x,y,prad);
			if(d==-0.325)
				{
				x-=1;
				y=y-d;
				}
			else
				{
				y+=1;
				x=x+(1.0/d);
				}
			if(kbhit())
				{
				getch();
				c=getch();
				cursor();
				}
			setcolor(ballcolor);
			circle(x,y,prad);
			delay(del);
			}
		}
	else
		{
		while(x<(xmax-prad))
			{
			gridlines();
			setcolor(bkcolor);
			circle(x,y,prad);
			if(d==0.325)
				{
				x+=1;
				y=y+d;
				}
			else
				{
				y+=1;
				x=x+(1.0/d);
				}
			if(kbhit())
				{
				getch();
				c=getch();
				cursor();
				}
			setcolor(ballcolor);
			circle(x,y,prad);
			delay(del);
			}
		}

	gameon();
	}
}
void cursor()	//function to  move ccursor
  {
	if(start==1)
	{
	setcolor(8);
	line(xminc,ymaxc,xminc,yminc);//left line of  cursor
	line(xminc,ymaxc,xmaxc,ymaxc);//top line of cursor
	line(xmaxc,ymaxc,xmaxc,yminc);//right line of  cursor
	line(xmaxc,yminc,xminc,yminc);//bottom line of cursor
	setfillstyle(SOLID_FILL,countercolor);
	floodfill(xminc+1,ymaxc+1,8);
	setcolor(0);
	settextstyle(0,0,1);
	outtextxy(xminc+3,ymaxc+5,name);
	start=0;
	x1=xminc;
	x2=xmaxc;
	y1=yminc;
	y2=ymaxc;
	setcolor(ballcolor);
	}
   else
	{
		if(c==77)
			{
			if(x2<(xmax-10))
				{
				setfillstyle(SOLID_FILL,bkcolor);
				floodfill(x1+3,y1-10,8);
				line(x1,y2,x1,y1);
				line(x1,y2,x2,y2);
				line(x2,y2,x2,y1);
				line(x2,y1,x1,y1);
				x1=x1+stepc;
				x2=x2+stepc;
				y1=yminc;
				y2=ymaxc;
				setcolor(8);
				line(x1,y2,x1,y1);
				line(x1,y2,x2,y2);
				line(x2,y2,x2,y1);
				line(x2,y1,x1,y1);
				setfillstyle(SOLID_FILL,countercolor);
				floodfill(x1+3,y1-10,8);
				setcolor(0);
				settextstyle(0,0,1);
				outtextxy(x1+3,y2+5,name);
				}
			}
		if(c==75)
			{
			if(x1>(xmin+10))
				{
				setcolor(bkcolor);
				setfillstyle(SOLID_FILL,bkcolor);
				floodfill(x1+3,y1-10,8);
				line(x1,y2,x1,y1);
				line(x1,y2,x2,y2);
				line(x2,y2,x2,y1);
				line(x2,y1,x1,y1);
				x1=x1-stepc;
				x2=x2-stepc;
				y1=yminc;
				y2=ymaxc;
				setcolor(8);
				line(x1,y2,x1,y1);
				line(x1,y2,x2,y2);
				line(x2,y2,x2,y1);
				line(x2,y1,x1,y1);
				setfillstyle(SOLID_FILL,countercolor);
				floodfill(x1+3,y1-10,8);
				setcolor(0);
				settextstyle(0,0,1);
				outtextxy(x1+3,y2+5,name);
				}
			}
	}
  }
 void gridlines()       //function to maintain gridlines
 {
 setcolor(8);
 line(x1,y2,x1,y1);
 line(x1,y2,x2,y2);
 line(x2,y2,x2,y1);
 line(x2,y1,x1,y1);
 setcolor(framecolor);
 line(xmin,ymin,xmin,ymax);    //left line
 line(xmin,ymin,xmax,ymin);   //top line
 line(xmax,ymin,xmax,ymax);   //right line
 line(xmin,ymax,xmax,ymax);  //bottom line
 line(xmin,(ymax+ymin)/2,xmax,(ymax+ymin)/2);  //mid line
 }
void scores()
{setcolor(countercolor);
 rectangle(xmax+4,ymax-45,xmax+86,ymax-2);
 setcolor(bkcolor);
 setfillstyle(1,bkcolor);
 floodfill(xmax+21,ymax-15,countercolor);
 setcolor(7);
 sprintf(scorestring,"%d",score);
 settextstyle(0,0,2);
 outtextxy(xmax+6,ymax-40,"SCORE");
 outtextxy(xmax+35,ymax-20,scorestring);
 settextstyle(0,0,1);
 setcolor(ballcolor);
}
