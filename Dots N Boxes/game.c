//	GameBot : Dots n Boxes

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

struct LINE								//	Stores a line with end points p1 and p2
{
	int p1,p2;
};

int move=1,b1_pts=0,b2_pts=0,box[5][5];
//char b1_name[100],b2_name[100];

/*	

	IMPORTANT VARIABLES USED IN THE GAME : 

All the 36 dots are considered to be nodes of a graph. So a 36X36 matrix is used to represent it.

LINE : structure that has p1 and p2 to store the starting and ending points of the line
line : variable of type line
move : variable that indicates which bot's chance to draw the line
	move=-1 : bot 1 chance to draw line
	move=1  : bot 2 chance to draw line
b1_pts : variable to store the points of bot 1 (number of squares formed by bot 1)
b2_pts : variable to store the points of bot 2 (number of squares formed by bot 2)
grid : it is a 2D integer matrix that stores the adjacency matrix of the graph.
grid2 : it is a copy of the grid. It is used for error checking. Programmer need not bother about this
box : it is a 2D 5X5 integer matrix that stores which and all squares are occupied by which bots. 
	box[i][j]=0 means the square is not yet formed
	box[i][j]=-1 means the square is formed by bot1
	box[i][j]=1 means the square is formed by bot2

NOTE : your bot function should not modify the value of move or b1_pts or b2_pts or grid or box variables. 
       It should only return the line which has to be drawn

*/


//	IMPORTANT FUNCTIONS USED IN THE GAME : 

//	This bot1() function is writter by the participant
//	The bot2() function will be writter by his opponent (another participant). But he can use some sample bot for testing purposes or he can
//	store the moves in a file and read from it.

struct LINE bot1(int[36][36],struct LINE);
struct LINE bot2(int[36][36],struct LINE);

//	The participant need not bother about these functions defined here but is free to go through it. All he need to know is what these functions does.

void clear(int[36][36]);					//	Assign 0 to grid
void clean(int[5][5]);						//	Assign 0 to box
void copy(int[36][36],int[36][36]);				//	Copies from grid to grid2
void copy2(int[5][5],int[5][5]);				//	Copies from box to box2
void check(int[36][36],struct LINE,int[36][36],int[5][5],int[5][5]);		//	Error check function
void addline(int[36][36],struct LINE,int[5][5]);		//	Adds line to the grid and checks whether a square is formed
void drawgrid(int[36][36],int[5][5]);				//	Displays the current game status on the screen
int check_end_game(int[5][5]);					//	Checks whether all the squares are marked (end game condition)
int min(int,int);						//	Returns minimun of 2 integers

/*void delay() {
	int i,j;
	for(i=0;i<=999;i++)
		for(j=0;j<=999;j++)
			;
}*/

int main(int argc,char *argv[])
{
	int grid[36][36],grid2[36][36],i,box2[5][5],move2;
	struct LINE line;

	int gd,gm=VGAMAX; gd=DETECT;
	initgraph(&gd,&gm,NULL);

	outtextxy(150,50, "GameBot : Dots N Boxes");

	clear(grid);							//	Initialize grid to 0s
	clear(grid2);							//	Initialize grid2 to 0s
	clean(box);							//	Initialize box to 0s
	clean(box2);

	drawgrid(grid,box);					//	draws the grid
	delay(1000);
	//srand(time(NULL));

	while(1)
	{
		copy(grid2,grid);					//	for error check
		copy2(box2,box);						//	for error check
		move2=move;
		if(move==-1)
			line=bot1(grid,line);				//	this is where you code
		else
			line=bot2(grid,line);				//	this is where your opponent codes
		if(move2!=move)
		{
			printf("Error : The move variable has been modified!");
			return 1;
		}
		check(grid,line,grid2,box,box2);					//	error check function
		addline(grid,line,box);					//	adds the new line to the grid
		drawgrid(grid,box);					//	draws the grid
		if(check_end_game(box))					//	check for end game
			break;
		delay(500);
		move*=-1;
	}

	if(b1_pts>b2_pts)
		outtextxy(100,370, "Bot 1 is the winner!");
	else if(b1_pts<b2_pts)
		outtextxy(100,370, "Bot 2 is the winner!");
	else
		outtextxy(100,370, "Match drawn!");

//	scanf("%d",&move);						//	uncomment to add break point at the end of game
	delay(5000);
	closegraph();

	printf("\n\nPoints : Bot1 - %d    Bot2 - %d\n",b1_pts,b2_pts);
	if(b1_pts>b2_pts)
		printf("Bot 1 is the winner!\n\n");
	else if(b1_pts<b2_pts)
		printf("Bot 2 is the winner!\n\n");
	else
		printf("Match drawn!\n\n");

	return 0;
}

//	This file Contains a sample code for the bot... This bot is very dumb... We expect you to come up with much more intelligent bots

char b2_name[]="Sample bot";

struct LINE bot2(int grid[36][36],struct LINE line)			//	Sample code for one bot
{
	int i,j;
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
		{
			if(i==j-1 && j%6!=0 && grid[i][j]!=1)
			{
				line.p1=i;	line.p2=j;
				return line;
			}
			if(i==j-6 && grid[i][j]!=1)
			{
				line.p1=i;	line.p2=j;
				return line;
			}
		}
	return line;
}

//	TND80_Deepesh Shetty

char b1_name[]="Deepesh Shetty";

struct LINE bot1(int grid[36][36],struct LINE line)			//	This is where your opponent codes
{
int temp1,i,j,rnd;

       //   The opponent bot's code is written here.
       //   You can use sample bot or code for your own opponent bot.
       /*int i,j;
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
		{
			if(i==j-1 && j%6!=0 && grid[i][j]!=1)
			{
				line.p1=i;	line.p2=j;
				return line;
			}
			if(i==j-6 && grid[i][j]!=1)
			{
				line.p1=i;	line.p2=j;
				return line;
			}
		} */
printf("start");
while(1)
{                       //srand(time(NULL));
			rnd=rand()%36; //map it to one of the 35 points
			if(rnd==0) // if point is zero
			{
			      i=rnd+1; // 1st point
			      if(grid[rnd][i]!=1)
			      {
				  if((grid[rnd][rnd+6]!=0&&grid[rnd+6][i+6]!=0)||(grid[i][i+6]!=0&&grid[rnd+6][i+6]!=0)||(grid[rnd][rnd+6]!=0&&grid[rnd+6][i+6]!=0))
				  {

			}
				else
				  {
printf(" it is 0");
					line.p1=rnd;	line.p2=i;
					return line;
				  }
			      }


			      i=rnd+6;
			      if(grid[rnd][i]!=1) // 2nd point
			      {
				  if(grid[rnd][rnd+1]!=0&&grid[i][i+1]!=0||grid[i][i+1]!=0&&grid[rnd+1][i+1]!=0||grid[rnd][rnd+1]!=0&&grid[rnd+1][i+1]!=0)
					{
						// Dont draw the line /
					}
					else
					{

					line.p1=rnd;	line.p2=i;
printf(" it is 1");
					return line;
				}
			      }
			}

			if(rnd==5) //If 5
			{

			      i=rnd-1;
			      if(grid[i][rnd]!=1)
			      {
				  if((grid[i][i+6]!=0&&grid[rnd][rnd+6]!=0)||(grid[rnd][rnd+6]!=0&&grid[i+6][rnd+6]!=0)||(grid[i][i+6]!=0&&grid[i+6][rnd+6]!=0))
					{
						// Dont draw the line /
					 }
					else
					{
						line.p1=rnd;	line.p2=i;
printf(" it is 2");
					return line;
					}
			      }

				i=rnd+6;
				if(grid[i][rnd]!=1)
				{
					if((grid[rnd][rnd-1]!=0&&grid[i][i-1]!=0)||(grid[rnd][rnd+1]!=0&&grid[rnd-1][i-1]!=0)||(grid[rnd-1][i-1]!=0&&grid[i-1][i]!=0))
					{
						// Dont draw the line /
					}
					else
					{
printf(" it is 3");
						line.p1=rnd;	line.p2=i;
					return line;
					}
				}

			}

			if(rnd==30)
			{
			      i=rnd-6;
			      if(grid[i][rnd]!=1)
			      {
				  if((grid[i][i+1]!=0&&grid[rnd][rnd+1]!=0)||(grid[i][i+1]!=0&&grid[i+1][rnd-1]!=0)||(grid[rnd][rnd-1]!=0&&grid[rnd+1][i+1]!=0))
					  {
					      // Dont draw the line /
					  }
					 else
					{
						line.p1=rnd;	line.p2=i;
printf(" it is 4");
					return line;
					}
				}
			      //or

			       i=rnd+1;
			       if(grid[i][rnd]!=1)
			       {
				   if((grid[rnd][rnd-6]!=0&&grid[i][i-6]!=0)||(grid[rnd][rnd-6]!=0&&grid[i-6][rnd-6]!=0)||(grid[i][i-6]!=0&&grid[i-6][rnd-6]!=0))
				  {
				      // Dont draw the line /
				  }
				  else
				  {
						  line.p1=rnd;	line.p2=i;
printf(" it is 5");
					return line;
				  }
			     }

			}


			if(rnd==35)
				{
				      i=rnd-1;
				       if(grid[i][rnd]!=1)
				       {
						if((grid[i][i-6]!=0&&grid[rnd][rnd-6]!=0)||(grid[i][i-6]!=0&&grid[i-6][rnd-6]!=0)||(grid[rnd][rnd-6]!=0&&grid[rnd-6][i-6]!=0))
						  {
						      // Dont draw the line /
						  }
						  else
						  {
							 line.p1=rnd;	line.p2=i;
printf(" it is 6");
					return line;
						  }

					}


				    i=rnd-6;
				    if(grid[i][rnd]!=1)
				    {
						if((grid[i][i-1]!=0&&grid[rnd][rnd-1]!=0)||(grid[i][i-1]!=0&&grid[i-1][rnd-1]!=0)||(grid[i-1][rnd-1]!=0&&grid[rnd-1][rnd]!=0))
						{
							      // Dont draw the line /
						}
						else
						{
							 line.p1=rnd;	line.p2=i;
printf(" it is 7");
					return line;
						}
				    }
}


	if(rnd<=4 && rnd >=1)
      {
	    i=rnd+6;
	    if(grid[i][rnd]!=1)
	    {
			if(((grid[rnd][rnd-1]!=0&&grid[i-1][i]!=0)||(grid[rnd][rnd-1]!=0&&grid[rnd-1][i-1]!=0)||(grid[rnd-1][i-1]!=0&&grid[i][i-1]!=0))||((grid[rnd][rnd+1]!=0&&grid[i][i+1]!=0)||(grid[rnd+1][i+1]!=0&&grid[i][i+1]!=0)||(grid[rnd][rnd+1]!=0&&grid[rnd][i+1]!=0)))
			{
				      // Dont draw the line /
			}
			else
			{
				line.p1=rnd;	line.p2=i;
printf(" it is 8");
					return line;
			}
	    }

	    i=rnd-1;
	    if(grid[i][rnd]!=1)
	    {
		      if((grid[i][i+6]!=0&&grid[rnd][rnd+6]!=0)||(grid[rnd][rnd+6]!=0&&grid[i+6][rnd+6]!=0)||(grid[i][i+6]!=0&&grid[i+6][rnd+6]!=0))
		      {
				      // Dont draw the line /
		      }
		      else
		      {
		      line.p1=rnd;	line.p2=i;
printf(" it is 9");
					return line;
		      }
	    }

	    i=rnd+1;
	    if(grid[i][rnd]!=1)
	    {
			 if((grid[rnd][rnd+6]!=0&&grid[i][i+6]!=0)||(grid[rnd][rnd+6]!=0&&grid[i+6][rnd+6]!=0)||(grid[i][i+6]!=0&&grid[i+6][rnd+6]!=0))
				  {
				      // Dont draw the line /
		      }
		      else
		      {
		       line.p1=rnd;	line.p2=i;
printf(" it is 10");
					return line;
		      }
	    }


	}
    if(rnd>=31 && rnd <= 34)
	{
			    i=rnd-6;
		if(grid[i][rnd]!=1) //vertical lines
		{
			if(((grid[rnd][rnd-1]!=0&&grid[i-1][i]!=0)||(grid[rnd][rnd-1]!=0&&grid[rnd-1][i-1]!=0)||(grid[rnd-1][i-1]!=0&&grid[i][i-1]!=0))||((grid[rnd][rnd+1]!=0&&grid[i][i+1]!=0)||(grid[rnd+1][i+1]!=0&&grid[i][i+1]!=0)||(grid[i][i+1]!=0&&grid[rnd+1][i+1]!=0)))
			{
				      // Dont draw the line /
			}
			else
			{
				 line.p1=rnd;	line.p2=i;
					return line;
			}
		}

	    i=rnd-1; // horizontal condition
	    if(grid[i][rnd]!=1)
	    {
			 if((grid[rnd][rnd-6]!=0&&grid[i][i-6]!=0)||(grid[i-6][rnd-6]!=0&&grid[rnd][rnd-6]!=0)||(grid[i][i-6]!=0&&grid[i-6][rnd-6]!=0))
				  {
				      // Dont draw the line /
				  }
		      else
		      {
			line.p1=rnd;	line.p2=i;
printf(" it is 11");
					return line;
		      }
	    }

			     i=rnd+1;
			     if(grid[i][rnd]!=1)
				{
					if((grid[rnd][rnd-6]!=0&&grid[i][i-6]!=0)||(grid[i-6][rnd-6]!=0&&grid[rnd][rnd-6]!=0)||(grid[i][i-6]!=0&&grid[i-6][rnd-6]!=0))
					{
						// Dont draw the line /
					}
					else
					{
						line.p1=rnd;	line.p2=i;
printf(" it is 12");
					return line;
					}
				}

	    }
	      if(rnd%6==0) // untill mod 6
		{
			    i=rnd+1;
			    if(grid[i][rnd]!=1) //vertical lines
			{
				if(((grid[rnd][rnd-1]!=0&&grid[i-1][i]!=0)||(grid[rnd][rnd-1]!=0&&grid[rnd-1][i-1]!=0)||(grid[rnd-1][i-1]!=0&&grid[i][i-1]!=0))||((grid[rnd][rnd+1]!=0&&grid[i][i+1]!=0)||(grid[rnd+1][i+1]!=0&&grid[i][i+1]!=0)||(grid[i][i+1]!=0&&grid[rnd+1][i+1]!=0)))
			{
				      // Dont draw the line /
			}
			else
			{
				line.p1=rnd;	line.p2=i;
printf(" it is 13");
					return line;
			}
		}

		i=rnd-6;//horizontal top lines (6-0),(12-6),(18-12),(24-18)
		if(grid[rnd][i]!=1)
		{
			if((grid[i][i+1]&&grid[rnd][rnd+1])||(grid[i][i+1]&&grid[i+1][rnd+1])||(grid[i+1][rnd+1]&&grid[rnd][rnd+1]))
			{
				//dont draw
			}
			else
			{
				line.p1=rnd;	line.p2=i;
printf(" it is 14");
					return line;
			}
		}
		   i=rnd+6;//horizontal bottom lines (6-12),(12-18),(18-24)

	if(grid[rnd][i]!=1)
	{
	     if((grid[rnd][rnd+1]&&grid[i][i+1])||(grid[rnd][rnd+1]&&grid[i+1][rnd+1])||(grid[i+1][rnd+1]&&grid[i][i+1]))
		{
			//dont draw
		}
		else
		{
		line.p1=rnd;	line.p2=i;
printf(" it is 15");
					return line;
		}
	}
}

if(rnd==11||rnd==17||rnd==23||rnd==29)
{


		i=rnd-1;//vertical lines (11-10),(17,16),(23-22),(29-28)
		if(grid[rnd][i]!=1)
		{
			if((grid[rnd][rnd-6]&&grid[i][i-6])||(grid[rnd][rnd-6]&&grid[rnd-6][i-6])||(grid[i][i-6]&&grid[rnd-6][i-6])||(grid[rnd][rnd+6]&&grid[i][i+6])||	(grid[rnd][rnd+6]&&grid[rnd+6][i+6])||(grid[i+6][rnd+6]&&grid[i][i+6]))
			{
					       //dont draw
			}
			else
			{
				line.p1=rnd;	line.p2=i;
printf(" it is 16");
					return line;
			}
		}
			i=rnd-6;//horizontal top lines(11-5),(17-11),(23-11),(29-23)
		if(grid[rnd][i]!=1)
		{
			if((grid[i][i-1]&&grid[rnd][rnd-1])||(grid[i][i-1]&&grid[i-1][rnd-1])||(grid[i-1][rnd-1]&&grid[rnd][rnd-1]))
			{
			   //dont draw
			}
			else
			{
				line.p1=rnd;	line.p2=i;
printf(" it is 17");
					return line;
			}
		}
			   i=rnd+6;//horizontal bottom lines (11-17),(17-23),(23-29)
			if(grid[rnd][i]!=1)
			{
			     if((grid[rnd][rnd-1]&&grid[i][i-1])||(grid[rnd][rnd-1]&&grid[i-1][rnd-1])||(grid[i-1][rnd-1]&&grid[i][i-1]))
				{
					//dont draw
				}
				else
				{
					line.p1=rnd;	line.p2=i;
printf(" it is 18");
					return line;
				}
			}
}
	else
	{
		i=rnd+6;
		if(grid[rnd][i]!=1)
		{
			     if(((grid[rnd][rnd-1]&&grid[i-1][i])||(grid[rnd][rnd-1]&&grid[i-1][rnd-1])||(grid[i-1][rnd-1]&&grid[i][i-1]))||((grid[rnd][rnd+1]&&grid[i+1][i])||(grid[rnd][rnd+1]&&grid[rnd][i+1])||(grid[i+1][i]&&grid[i+1][rnd-1])))
				{
					//dont draw
				}
				else
				{
					line.p1=rnd;	line.p2=i;
printf(" it is 19");
					return line;
				}

		}

		i=rnd-6;
		if(grid[rnd][i]!=1)
		{
			     if(((grid[rnd][rnd-1]&&grid[i-1][i])||(grid[rnd][rnd-1]&&grid[i-1][rnd-1])||(grid[i-1][rnd-1]&&grid[i][i-1]))||((grid[rnd][rnd+1]&&grid[i+1][i])||(grid[rnd][rnd+1]&&grid[rnd][i+1])||(grid[i+1][i]&&grid[i+1][rnd-1])))
				{
					//dont draw
				}
				else
				{
					line.p1=rnd;	line.p2=i;
printf(" it is 20");
					return line;
				}

		}
		i=rnd+1;
				if(((grid[rnd][rnd-6]&&grid[i-6][i])||(grid[i-6][rnd-6]&&grid[i-6][i])||(grid[rnd][rnd-6]&&grid[rnd-6][i-6]))||((grid[rnd][rnd+6]&&grid[i+6][i])||(grid[rnd][rnd+6]&&grid[rnd+6][i+6])||(grid[rnd+6][i+6]&&grid[i+6][i])))
				{
					//dont draw
				}
				else
				{
					line.p1=rnd;	line.p2=i;
printf(" it is 21");
					return line;
				}



		i=rnd-1;
				if(((grid[rnd][rnd-6]&&grid[i-6][i])||(grid[i-6][rnd-6]&&grid[i-6][i])||(grid[rnd][rnd-6]&&grid[rnd-6][i-6]))||((grid[rnd][rnd+6]&&grid[i+6][i])||(grid[rnd][rnd+6]&&grid[rnd+6][i+6])||(grid[rnd+6][i+6]&&grid[i+6][i])))
				{
					//dont draw
				}
				else
				{
					line.p1=rnd;	line.p2=i;
printf(" it is 22");
					return line;
				}

}

for(i=0;i<36;i++)

		for(j=0;j<36;j++)

		{

			if(i==j-1 && j%6!=0 && grid[i][j]!=1)

			{

				line.p1=i;	line.p2=j;
printf(" it is 23");

				return line;

			}

			if(i==j-6 && grid[i][j]!=1)

			{

				line.p1=i;	line.p2=j;
printf(" it is 24");

				return line;

			}




}
}


/*int i,j;
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
		{
			if(i==j-1 && j%6!=0 && grid[i][j]!=1)
			{
				line.p1=i;	line.p2=j;
				return line;
			}
			if(i==j-6 && grid[i][j]!=1)
			{
				line.p1=i;	line.p2=j;
				return line;
			}
		}
	return line;
*/	
}


void check(int grid[36][36],struct LINE line,int grid2[36][36],int box[5][5],int box2[5][5])	//	Error check function
{
	int i,j,t;
	for(i=0;i<36;i++)						//	Check if any bot has modified the grid
		for(j=0;j<36;j++)
			if(grid[i][j]!=grid2[i][j])
			{
				if(move==-1)	printf("Error : BOT1 : ");
				else	printf("Error : BOT2 : ");
				printf("Grid has been modified by bot ");
				delay(10000);
				exit(1);
			}
	for(i=0;i<5;i++)						//	Check if any bot has modified the box
		for(j=0;j<5;j++)
			if(box[i][j]!=box2[i][j])
			{
				if(move==-1)	printf("Error : BOT1 : ");
				else	printf("Error : BOT2 : ");
				printf("Box has been modified by bot ");
				delay(10000);
				exit(1);
			}
	if(line.p1<0 || line.p1>35 || line.p2<0 || line.p2>35)		//	Check if the returned line is invalid
	{
		if(move==-1)	printf("Error : BOT1 : ");
		else	printf("Error : BOT2 : ");
		printf("Line drawn in wrong places!");
		delay(10000);
		exit(1);
	}
	t=line.p1-line.p2;
	if(!(t==1 || t==-1 || t==6 || t==-6))				//	Check if the returned line is invalid
	{
		if(move==-1)	printf("Error : BOT1 : ");
		else	printf("Error : BOT2 : ");
		printf("Line is drawn in wrong places!");
		delay(10000);
		exit(1);
	}
	if(grid[line.p1][line.p2]==1 || grid[line.p2][line.p1]==1)	//	Checks if the line has already beed drawn in that place
	{
		if(move==-1)	printf("Error : BOT1 : ");
		else	printf("Error : BOT2 : ");
		printf("Line has been already drawn!");
		delay(10000);
		exit(1);
	}	
}


//	Adds line to the grid and increments the points and adjusts move if a square is formed due to the new line drawn
void addline(int grid[36][36],struct LINE line,int box[5][5])		//	Adds line to the grid and checks whether a square is formed
{
	int t,temp,flag,tmp;
	grid[line.p1][line.p2]=grid[line.p2][line.p1]=1;
	t=line.p1-line.p2;
	temp=min(line.p1,line.p2);
	tmp=floor(temp/6);
	if(move==-1)							//	For the bot1
	{
		if(t==-1 || t==1)
		{
			flag=0;
			if(line.p1>5 && grid[line.p1-6][line.p2-6]==1 && grid[line.p1][line.p1-6]==1 && grid[line.p2][line.p2-6]==1)
			{
				box[tmp-1][temp%6]=move;
				b1_pts++;
				flag=1;
			}
			if(line.p1<30 && grid[line.p1+6][line.p2+6]==1 && grid[line.p1][line.p1+6]==1 && grid[line.p2][line.p2+6]==1)
			{
				box[tmp][temp%6]=move;
				b1_pts++;
				flag=1;
			}
			if(flag)	move*=-1;
		}
		else if(t==-6 || t==6)
		{
			flag=0;
			if(line.p1%6!=0 && grid[line.p1-1][line.p2-1]==1 && grid[line.p1][line.p1-1]==1 && grid[line.p2][line.p2-1]==1)
			{
				box[tmp][temp%6-1]=move;
				b1_pts++;
				flag=1;
			}
			if((line.p1+1)%6!=0 && grid[line.p1+1][line.p2+1]==1 && grid[line.p1][line.p1+1]==1 && grid[line.p2][line.p2+1]==1)
			{
				box[tmp][temp%6]=move;
				b1_pts++;
				flag=1;
			}
			if(flag)	move*=-1;
		}
		else
		{
			printf("Error!");
			exit(1);
		}
	}
	else
	{
		if(t==-1 || t==1)
		{
			flag=0;
			if(line.p1>5 && grid[line.p1-6][line.p2-6]==1 && grid[line.p1][line.p1-6]==1 && grid[line.p2][line.p2-6]==1)
			{
				box[tmp-1][temp%6]=move;
				b2_pts++;
				flag=1;
			}
			if(line.p1<30 && grid[line.p1+6][line.p2+6]==1 && grid[line.p1][line.p1+6]==1 && grid[line.p2][line.p2+6]==1)
			{
				box[tmp][temp%6]=move;
				b2_pts++;
				flag=1;
			}
			if(flag)	move*=-1;
		}
		else if(t==-6 || t==6)
		{
			flag=0;
			if(line.p1%6!=0 && grid[line.p1-1][line.p2-1]==1 && grid[line.p1][line.p1-1]==1 && grid[line.p2][line.p2-1]==1)
			{
				box[tmp][temp%6-1]=move;
				b2_pts++;
				flag=1;
			}
			if((line.p1+1)%6!=0 && grid[line.p1+1][line.p2+1]==1 && grid[line.p1][line.p1+1]==1 && grid[line.p2][line.p2+1]==1)
			{
				box[tmp][temp%6]=move;
				b2_pts++;
				flag=1;
			}
			if(flag)	move*=-1;
		}
		else
		{
			printf("Error!");
			exit(1);
		}
	}
}

void drawgrid(int grid[36][36],int box[5][5])			//	Displays the current game status on the screen
{
	int i,j,ri,ci,rj,cj;
	char sss[100];
	for(i=0;i<6;i++)					//	Display dots
		for(j=0;j<6;j++)
			circle(j*50+50,i*50+100,2);
	for(i=0;i<36;i++)					//	Display lines
		for(j=0;j<36;j++)
			if(grid[i][j]==1)
			{
				ri=floor(i/6);	ci=i%6;
				rj=floor(j/6);	cj=j%6;
				line(ci*50+50,ri*50+100,cj*50+50,rj*50+100);
			}
	for(i=0;i<5;i++)					//	Fill in the formed squares
		for(j=0;j<5;j++)
		{
			if(box[i][j]==-1)			//	RED square for bot 1
			{
				setcolor(RED);
				floodfill(j*50+52,i*50+102,WHITE);
			}
			else if(box[i][j]==1)			//	BLUE square for bot 2
			{
				setcolor(BLUE);
				floodfill(j*50+52,i*50+102,WHITE);
			}
			setcolor(WHITE);
		}
	setcolor(BLACK);
	bar(350,100,600,350);
	setcolor(WHITE);
	
	sprintf(sss,"Bot 1 : %s",b1_name);
	outtextxy(400,180,sss);
	sprintf(sss,"Bot 2 : %s",b2_name);
	outtextxy(400,200,sss);
	
	sprintf(sss,"Points : Bot 1 : %d \n\n Bot 2 : %d",b1_pts,b2_pts);	//	Print the points at every stage of the game
	outtextxy(400,240,"Points : ");
	sprintf(sss,"Bot 1 : %d",b1_pts);
	outtextxy(420,270,sss);
	sprintf(sss,"Bot 2 : %d",b2_pts);
	outtextxy(420,300,sss);
}

int check_end_game(int box[5][5])					//	Checks whether all the squares are marked (end game condition)
{
	int i,j;
	for(i=0;i<5;i++)						//	End game if all the squares are formed
		for(j=0;j<5;j++)
			if(box[i][j]==0)
				return 0;
	return 1;
}

int min(int a,int b)							//	Returns minimun of 2 integers
{
	return a<b?a:b;
}

void clear(int grid[36][36])						//	Assign 0 to grid
{
	int i,j;
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
			grid[i][j]=0;
}

void clean(int box[5][5])						//	Assign 0 to box
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			box[i][j]=0;
}

void copy(int grid2[36][36],int grid[36][36])				//	Copies from grid to grid2
{
	int i,j;
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
			grid2[i][j]=grid[i][j];
}

void copy2(int box2[5][5],int box[5][5])				//	Copies from box to box2
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			box2[i][j]=box[i][j];
}

