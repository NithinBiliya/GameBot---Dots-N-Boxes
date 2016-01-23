/*Adarsh Konchady - 4NM09CS406, IV year CSE, Section A, NMAMIT*/
/*------------------------------------------------------------*/
	
	char b2_name[]="Adarsh Konchady";


struct LINE bot2(int grid[36][36],struct LINE line)			//	This is where you code
{
	/*
	Level 0 - Line at random
	Level 1 - 4th line of a box. If not possible, then at random
	Level 2 - 4th line of a box. If not possible, line
		  such that not possible to make a box. Else line at random
	*/
	/*
	Prerequisites:
	1. box[][] should be global
	2. #include <math.h> for floor function
	*/

	int i,j;
	int x,y,m,n;
	static int arrx[40];
	static int arry[40];
	static int arrxcnt=0;
	static int arrycnt=0;
	int startDot; //startdot(Dot no.) = i*6+j
				 //Box no. = i*5+j
	int level1=0;
	int xyset=0; //Indicates x,y variables are set or not

	int level2=0;
	int boxx=0,boxy=0;

	static int cntmoves=0; //Count the number of moves made

	for(i=0;i<36;i++)
	{
		for(j=0;j<36;j++)
		{
			//Initialize x
			//Check for 4th line for a box
			for(m=0;m<5;m++)
			{
			  for(n=0;n<5;n++)
			  {
			    if(box[m][n]==0) //Check for squares not yet formed
			    {
			      startDot = m*6+n;
			      if(grid[startDot][startDot+1]==1 && grid[startDot+1][startDot+7]==1 && grid[startDot][startDot+6]==1 && grid[startDot+6][startDot+7]==0)
			      {
					//Set grid[startDot+6][startDot+7]
					x = startDot + 6;
					y = startDot + 7;
					level1 = 1;
			      }
			      else if(grid[startDot][startDot+1]==1 && grid[startDot+1][startDot+7]==1 && grid[startDot][startDot+6]==0 && grid[startDot+6][startDot+7]==1)
			      {
					//Set grid[startDot][startDot+6]
					x = startDot;
					y = startDot + 6;
					level1 = 1;
			      }
			      else if(grid[startDot][startDot+1]==1 && grid[startDot+1][startDot+7]==0 && grid[startDot][startDot+6]==1 && grid[startDot+6][startDot+7]==1)
			      {
					//Set grid[startDot+1][startDot+7]
					x = startDot + 1;
					y = startDot + 7;
					level1 = 1;
			      }
			      else if(grid[startDot][startDot+1]==0 && grid[startDot+1][startDot+7]==1 && grid[startDot][startDot+6]==1 && grid[startDot+6][startDot+7]==1)
			      {
					//Set grid[startDot][startDot+1]==0
					x = startDot;
					y = startDot + 1;
					level1 = 1;
			      }
			      if(level1)
			      {
					arrx[i] = x;
					arrxcnt++;
					arry[i] = y;
					arrycnt++;
					xyset=1;
					break;
			      }
			    }
			  }
			  if(xyset)
			    break;
			}

			//Code for level2
			xyset=0;
			//Set level2 here
			//Line such that not possible to make a box
			if(!level1) //&& cntmoves>=5)
			{
			  l2: x = rand()%36;
			  for(m=0;m<arrxcnt;m++)
			  {
			    if(x == arrx[m])
				goto l2;
			  }
			  arrx[i] = x;
			  arrxcnt++;

			  //Initialize y
			  for(m=0;m<36;m++)
			  {
			    for(n=0;n<36;n++)
			    {
					if(grid[x][x+1]!=1 && ((x+1)%6!=0))
					{
					  //box[boxx,boxy] (Eg point(x): 22)
					  boxx = (int)floor(x/6);
					  boxy = x-6*boxx;
					  startDot=boxx*6+boxy;
					  if( !( (grid[startDot][startDot+6]==1 && grid[startDot+6][startDot+7]==1) || (grid[startDot][startDot+6]==1 && grid[startDot+1][startDot+7]==1) || (grid[startDot+6][startDot+7]==1 && grid[startDot+1][startDot+7]==1) ) )
					  {
						startDot-=6; //check for error condition startDot>5
						if( !( (grid[startDot][startDot+1]==1 && grid[startDot][startDot+6]==1) || (grid[startDot][startDot+1]==1 && grid[startDot+1][startDot+7]==1) || (grid[startDot][startDot+6]==1 && grid[startDot+1][startDot+7]==1) ) )
						{
							y=x+1;
							level2=1;
							xyset=1;
							break;
						}
					  }
					}
					else if(grid[x][x-1]!=1 && x%6!=0)
					{
					  boxx = (int)floor(x/6);
					  boxy = x-6*boxx;
					  startDot=(boxx*6+boxy)-1;
					  if( !( (grid[startDot][startDot+6]==1 && grid[startDot+6][startDot+7]==1) || (grid[startDot][startDot+6]==1 && grid[startDot+1][startDot+7]==1) || (grid[startDot+6][startDot+7]==1 && grid[startDot+1][startDot+7]==1) ) )
					  {
						startDot-=6;
						if( !( (grid[startDot][startDot+1]==1 && grid[startDot][startDot+6]==1) || (grid[startDot][startDot+1]==1 && grid[startDot+1][startDot+7]==1) || (grid[startDot][startDot+6]==1 && grid[startDot+1][startDot+7]==1) ) )
						{
							y=x-1;
							level2=1;
							xyset=1;
							break;
						}
					  }
					}
					else if(grid[x][x+6]!=1 && x<30)
					{
					  boxx = (int)floor(x/6);
					  boxy = x-6*boxx;
					  startDot=boxx*6+boxy;
					  if( !( (grid[startDot][startDot+1]==1 && grid[startDot+1][startDot+7]==1) || (grid[startDot][startDot+1]==1 && grid[startDot+6][startDot+7]==1) || (grid[startDot+1][startDot+7]==1 && grid[startDot+6][startDot+7]==1) ) )
					  {
						startDot--;
						if( !( (grid[startDot][startDot+1]==1 && grid[startDot+1][startDot+7]==1) || (grid[startDot][startDot+1]==1 && grid[startDot+6][startDot+7]==1) || (grid[startDot+1][startDot+7]==1 && grid[startDot+6][startDot+7]==1) ) )
						{
						  y=x+6;
						  level2=1;
						  xyset=1;
						  break;
						}
					  }
					}
					else if(grid[x][x-6]!=1 && x>5)
					{
					  boxx = (int)floor(x/6);
					  boxy = x-6*boxx;
					  boxx--; //Go one row up (Eg. 22-16 => Box 19-14)
						  //Go up in x direction. Don't decrement y
					  startDot=boxx*6+boxy;
					  if( !( (grid[startDot][startDot+1]==1 && grid[startDot+1][startDot+7]==1) || (grid[startDot][startDot+1]==1 && grid[startDot+6][startDot+7]==1) || (grid[startDot+1][startDot+7]==1 && grid[startDot+6][startDot+7]==1) ) )
					  {
						startDot--;
						if( !( (grid[startDot][startDot+1]==1 && grid[startDot][startDot+6]==1) || (grid[startDot][startDot+1]==1 && grid[startDot+6][startDot+7]==1) || (grid[startDot][startDot+6]==1 && grid[startDot+6][startDot+7]==1) ) )
						{
						  y=x-6;
						  level2=1;
						  xyset=1;
						  break;
						}
					  }

					}
			    }
			    if(xyset)
			      break;
			  }
			}

			if(!(level1 || level2))
			{
				//Random x generation. y depends on x value generated
				l1: x = rand()%36;
				for(m=0;m<arrxcnt;m++)
				{
				  if(x == arrx[m])
				    goto l1;
				}
				arrx[i]=x;
				arrxcnt++;

				//Initialize y
				if(grid[x][x+1]!=1 && ((x+1)%6!=0))
				  y=x+1;
				else if(grid[x][x-1]!=1 && x%6!=0)
				  y=x-1;
				else if(grid[x][x+6]!=1 && x<30)
				  y=x+6;
				else if(grid[x][x-6]!=1 && x>5)
				  y=x-6;
				else
				{
				  arrxcnt--;
				  goto l1;
				}
				arry[i] = y;
				arrycnt++;
			}
			line.p1=x;	line.p2=y;
			cntmoves++;
			return line;
		}	
	}
	return line;
}

