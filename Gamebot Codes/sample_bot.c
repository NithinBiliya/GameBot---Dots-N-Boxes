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
