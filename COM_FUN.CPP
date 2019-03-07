
void print_sign(int,int);
int board[]={2,2,2,2,2,2,2,2,2,2};
char name[100];
char id[20];
//char anname[]={'S','U','B','A','R','A','T','A'};
void drow_board()
{
    setbkcolor(BLUE);
    setcolor(LIGHTGREEN);
    rectangle(300,50,450,200);
    line(298,48,452,48);
    line(298,48,298,202);
    line(298,202,452,202);
    line(452,202,452,48);
    line(300,100,450,100);
    line(300,150,450,150);
    line(350,50,350,200);
    line(400,50,400,200);
    setcolor(LIGHTMAGENTA);
    bar3d(100,384,630,388,2,2) ;
    setcolor(WHITE);
    sprintf(name,"The game is designed and developed by \b Subarata Talukder");
    outtextxy(100,400,name);
    sprintf(id,"ID is \b 092-15-796");
    outtextxy(355,415,id);
}

int free_space()
{
    if(board[5]==2)
	 return 5;
    if(board[2]==2)
	 return 2;
    if(board[4]==2)
	 return 4;
    if(board[6]==2)
	 return 6;
    else
	 return 8;

}

int com_win_test(int com_test)
{
     if(board[1]*board[2]*board[3]==com_test)
     {
	  if(board[1]==2)
	      return 1;
	  else if(board[2]==2)
	      return 2;
	  else
	      return 3;
     }
     else if(board[4]*board[5]*board[6]==com_test)
     {
	  if(board[4]==2)
	      return 4;
	  else if(board[5]==2)
	      return 5;
	  else
	      return 6;
     }
     else if(board[7]*board[8]*board[9]==com_test)
     {
	  if(board[7]==2)
	      return 7;
	  else if(board[8]==2)
	      return 8;
	  else
	      return 9;
     }
     else if(board[1]*board[4]*board[7]==com_test)
     {
	  if(board[1]==2)
	      return 1;
	  else if(board[4]==2)
	      return 4;
	  else
	      return 7;
     }
     else if(board[2]*board[5]*board[8]==com_test)
     {
	  if(board[2]==2)
	      return 2;
	  else if(board[5]==2)
	      return 5;
	  else
	      return 8;
     }
     else if(board[3]*board[6]*board[9]==com_test)
     {
	  if(board[3]==2)
	      return 3;
	  else if(board[6]==2)
	      return 6;
	  else
	      return 9;
     }
     else if(board[1]*board[5]*board[9]==com_test)
     {
	  if(board[1]==2)
	      return 1;
	  else if(board[5]==2)
	      return 5;
	  else
	      return 9;
     }
      else if(board[7]*board[5]*board[3]==com_test)
     {
	  if(board[7]==2)
	      return 7;
	  else if(board[5]==2)
	      return 5;
	  else
	      return 3;
     }
     else
     {return 0;}
}

void com_turn(int turn_num)
{
    switch(turn_num)
    {
	case 1:
	{
	    board[1]=3;
	    print_sign(turn_num,1);
	    break;
	}
	case 2:
	{
	    if(board[5]==2)
	    {
		board[5]=5;
		print_sign(5,2);
	    }
	    else
	    {
		board[1]=5;
		print_sign(1,2);
	    }
	break;
	}
	case 3:
	{
	     if(board[9]==2)
	     {
		 board[9]=3;
		 print_sign(9,1);
	     }
	     else
	     {
		 board[3]=3;
		 print_sign(3,1);
	     }
	break;
	}
	case 4:
	{
	    int win=com_win_test(18);
	    if(win!=0)
	    {
	       board[win]=5;
	       print_sign(win,2);
	    }
	    else
	    {
	       int win=free_space();
	       board[win]=5;
	       print_sign(win,2);
	  }
	break;
	}
	case 5:
	{
	    int win=com_win_test(18) ;
	    if(win!=0)
	    {
	       print_sign(win,1);
	       printf("Hey boy u r just loss in the game\n \"Ghada\"");
	       getch();
	       exit(0);
	    }
	    win=com_win_test(50);
	    if(win!=0)
	    {
	       board[win]=3;
	       print_sign(win,1);
	    }
	    else
	    {
	       if(board[7]==2)
	       {
		  board[7]=3;
		  print_sign(5,1);
	       }
	       else
	       {
		  board[3]=3;
		  print_sign(3,1);
	       }
	    }
	break;
	}
	case 6:
	{
	    int win=com_win_test(50) ;
	    if(win!=0)
	    {
	       print_sign(win,2);
	       printf("Hey boy u r just loss in the game \"Ghada\"");
	       getch();
	       exit(0);
	    }
	    win=com_win_test(18);
	    if(win!=0)
	    {
	       board[win]=5;
	       print_sign(win,2);
	    }
	    else
	    {
	       int space=free_space();
	       board[space]=5;
	       print_sign(space,2);
	    }
	break;
	}
	case 7:
	{
	int win=com_win_test(18) ;
	    if(win!=0)
	    {
	       print_sign(win,1);
	       printf("Hey boy u r just loss in the game \"Ghada\"");
	       getch();
	       exit(0);
	    }
	    win=com_win_test(50);
	    if(win!=0)
	    {
	       board[win]=3;
	       print_sign(win,1);
	    }
	    else
	    {
	       for(int i=1;i<=9;i++)
	       {
		  if (board[i]==2)
		  {
		     board[i]=3;
		     print_sign(i,1);
		     break;
		  }
	       }
	    }

	break;
	}
	case 8:
	{

	    int win=com_win_test(50) ;
	    if(win!=0)
	    {
	       print_sign(win,2);
	       printf("Hey boy u r just loss \n in the game \"Ghada\"");
	       getch();
	       exit(0);
	    }
	    win=com_win_test(18);
	    if(win!=0)
	    {
	       board[win]=5;
	       print_sign(win,2);
	    }
	    else
	    {
	       for(int i=1;i<=9;i++)
	       {
		  if (board[i]==2)
		  {
		     board[i]=5;
		     print_sign(i,1);
		     break;
		  }
	       }
	    }
	break;
	}
	case 9:
	{
	int win=com_win_test(18) ;
	    if(win!=0)
	    {
	       print_sign(win,1);
	       printf("Hey boy u r just loss in the game \n \"Ghada\"");
	       getch();
	       exit(0);
	    }
	    win=com_win_test(50);
	    if(win!=0)
	    {
	       board[win]=3;
	       print_sign(win,1);
	    }
	    else
	    {
	       for(int i=1;i<=9;i++)
	       {
		  if (board[i]==2)
		  {
		     board[i]=3;
		     print_sign(i,1);
		     break;
		  }
	       }
	    }

	break;
	}

    }
}

void human_win_test(int test)
{
    if((board[1]*board[2]*board[3]==test)
    || (board[4]*board[5]*board[6]==test)
    || (board[7]*board[8]*board[9]==test)
    || (board[1]*board[4]*board[7]==test)
    || (board[2]*board[5]*board[8]==test)
    || (board[3]*board[6]*board[9]==test)
    || (board[1]*board[5]*board[9]==test)
    || (board[3]*board[5]*board[7]==test))
    {
	printf("Player 1 win the game");
	getch();
	exit(0);
    }
}
void print_sign(int turn_n,int sign)
{
    setcolor(WHITE);
    switch(turn_n)
    {
       case 1:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(320,75,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(320,75,10,10);
       }
       break;
       }
       case 2:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(375,75,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(375,75,10,10);
       }
       break;
       }
       case 3:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(425,75,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(425,75,10,10);
       }
       break;
       }
       case 4:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(320,125,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(320,125,10,10);
       }
       break;
       }
       case 5:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(375,125,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(375,125,10,10);
       }
       break;
       }
       case 6:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(425,125,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(425,125,10,10);
       }
       break;
       }
       case 7:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(320,175,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(320,175,10,10);
       }
       break;
       }
       case 8:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(375,175,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(375,175,10,10);
       }
       break;
       }
       case 9:
       {
       if(sign==1)
       {
	   setfillstyle(HATCH_FILL,LIGHTMAGENTA);
	   fillellipse(425,175,10,10);
       }
       else
       {
	   setfillstyle(SOLID_FILL,RED);
	   fillellipse(425,175,10,10);
       }
       break;
       }
       default:
       {
	   printf("Hey Ghadha Is this possible");
       }
    }
}
