//	GameBot : Dots n Boxes

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
//#include "variables.c"
//#include "developer_function.c"

void clear(int[36][36]);
void clean(int[5][5]);
void copy(int[36][36],int[36][36]);
struct LINE bot1(int[36][36],struct LINE);
struct LINE bot2(int[36][36],struct LINE);
void check(int[36][36],struct LINE,int[36][36]);
void addline(int[36][36],struct LINE,int[5][5]);
void drawgrid(int[36][36],int[5][5]);
int check_end_game(int[5][5]);
int min(int,int);

int main(int argc,char *argv[])
{
	int grid[36][36],grid2[36][36],i,box[5][5];
	struct LINE line;

	int gd,gm=VGAMAX; gd=DETECT;
	initgraph(&gd,&gm,NULL);

	outtextxy(150,50, "GameBot : Dots N Boxes");

	clear(grid);							//	Initialize grid to 0s
	clear(grid2);							//	Initialize grid2 to 0s
	clean(box);							//	Initialize box to 0s

	while(1)
	{
		copy(grid2,grid);					//	for error check
		if(move==-1)
			line=bot1(grid,line);				//	this is where you code
		else
			line=bot2(grid,line);				//	this is where your opponent codes
		check(grid,line,grid2);					//	error check function
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

struct LINE bot1(int grid[36][36],struct LINE line)			//	This is where you code
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

struct LINE bot2(int grid[36][36],struct LINE line)			//	This is where your opponent codes
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
