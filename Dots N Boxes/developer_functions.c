//	Contains all the functions used in the game. 
//	The participant need not bother about these functions but is free to go through it. All he need to know is what these functions does.

void check(int grid[36][36],struct LINE line,int grid2[36][36])		//	Error check function
{
	int i,j,t;
	for(i=0;i<36;i++)						//	Check if any bot has modified the grid
		for(j=0;j<36;j++)
			if(grid[i][j]!=grid2[i][j])
			{
				if(move==-1)	printf("Error : BOT1 : ");
				else	printf("Error : BOT2 : ");
				printf("Grid has been modified by bot ");
				exit(1);
			}
	if(line.p1<0 || line.p1>35 || line.p2<0 || line.p2>35)		//	Check if the returned line is invalid
	{
		if(move==-1)	printf("Error : BOT1 : ");
		else	printf("Error : BOT2 : ");
		printf("Line drawn in wrong places!");
		exit(1);
	}
	t=line.p1-line.p2;
	if(!(t==1 || t==-1 || t==6 || t==-6))				//	Check if the returned line is invalid
	{
		if(move==-1)	printf("Error : BOT1 : ");
		else	printf("Error : BOT2 : ");
		printf("Line is drawn in wrong places!");
		exit(1);
	}
	if(grid[line.p1][line.p2]==1 || grid[line.p2][line.p1]==1)	//	Checks if the line has already beed drawn in that place
	{
		if(move==-1)	printf("Error : BOT1 : ");
		else	printf("Error : BOT2 : ");
		printf("Line has been already drawn!");
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
			if(line.p1/6!=0 && grid[line.p1-1][line.p2-1]==1 && grid[line.p1][line.p1-1]==1 && grid[line.p2][line.p2-1]==1)
			{
				box[tmp][temp%6-1]=move;
				b1_pts++;
				flag=1;
			}
			if((line.p1+1)/6!=0 && grid[line.p1+1][line.p2+1]==1 && grid[line.p1][line.p1+1]==1 && grid[line.p2][line.p2+1]==1)
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
			if(line.p1/6!=0 && grid[line.p1-1][line.p2-1]==1 && grid[line.p1][line.p1-1]==1 && grid[line.p2][line.p2-1]==1)
			{
				box[tmp][temp%6-1]=move;
				b2_pts++;
				flag=1;
			}
			if((line.p1+1)/6!=0 && grid[line.p1+1][line.p2+1]==1 && grid[line.p1][line.p1+1]==1 && grid[line.p2][line.p2+1]==1)
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
	sprintf(sss,"Points : Bot 1 : %d \n\n Bot 2 : %d",b1_pts,b2_pts);	//	Print the points at every stage of the game
	outtextxy(400,200,"Points : ");
	sprintf(sss,"Bot 1 : %d",b1_pts);
	outtextxy(420,230,sss);
	sprintf(sss,"Bot 2 : %d",b2_pts);
	outtextxy(420,260,sss);
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

