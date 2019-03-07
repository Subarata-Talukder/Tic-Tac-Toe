
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include "com_fun.cpp"

void main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    int count=1,chose,turn;
    drow_board();
    printf("Press 1 for human // 2 for computer// 3 for exit \n");
    scanf("%d",&chose);
    if(chose>2)
    {
	printf("You are not Interested to Paly \n");
	printf("Press any to exit");
	getch();
	exit(0);
    }
    if(chose==1)
    {
lavel:	while(count<10)
	{
    lavel1: if(count%2!=0)
	    {
	    gotoxy(100,20);
	    printf("Human turn (%d) \n",count);
		 scanf("%d",&turn);
		 if(board[turn]!=2)
		 goto lavel1;
		 board[turn]=3;
		 print_sign(turn,1);
		 if (count>4)
		 {
		    human_win_test(27);
		    count++;
		    goto lavel;
		 }
	    count++;
	    }
	    else
	    {     gotoxy(100,20);
		  printf("Now Computer turn(%d) \n",count);
		  delay(500);
		  com_turn(count);
		  count++;
	    }
	}

    }
    else
    {
   lab2: while(count<10)
	 {
   label_2: if(count%2==0)
	    {
		 gotoxy(100,20);
		 printf("Human turn (%d) \n",count);
		 scanf("%d",&turn);
		 if(board[turn]!=2)
		 goto label_2;
		 board[turn]=5;
		 print_sign(turn,2);
		 if (count>4)
		 {
		     human_win_test(125);
		     count++;
		     goto lab2;
		 }
	    count++;
	    }
	    else
	    {
		  gotoxy(100,20);
		  printf("Now Computer turn(%d) \n",count);
		  delay(500);
		  com_turn(count);
		  count++;
		  goto lab2;
	    }
	}
    }
    printf("The game is Over");
    getch();
    closegraph();
}
