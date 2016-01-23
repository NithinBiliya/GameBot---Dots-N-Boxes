//		TNI39_TNI49_Ankitha_Melissa	bot code

char b2_name[]="Ankitha and Melissa";

struct LINE bot2(int grid[36][36],struct LINE llll)			//	This is where you code

{



       int i,j;



	for(i=0;i<36;i++)

		for(j=0;j<36;j++)

		{

			if(i==j-1 && j%6!=0 && grid[i][j]!=1)

			{

			    if((grid[i][i-6]==1 && grid[j][j-6]==1 && grid[i-6][j-6]==1) || (grid[i][i+6]==1 && grid[j][j+6]==1 && grid[i+6][j+6]==1))

				{

					llll.p1=i;	llll.p2=j;

					return llll;

				}

			}

			if(i==j-6 && grid[i][j]!=1)

			{

				if((grid[i][i-1]==1 && grid[j][j-1]==1 && grid[i-1][j-1]==1) || (grid[i][i+1]==1 && grid[j][j+1]==1 && grid[i+1][j+1]==1))

				{

					llll.p1=i;	llll.p2=j;

					return llll;

				}

			}

		}

	for(i=0;i<36;i++)

		for(j=0;j<36;j++)

		{

			if(i==j-1 && j%6!=0 && grid[i][j]!=1)

			{

			    if((grid[i][i-6]!=1 || grid[i-6][j-6]!=1)&&(grid[i-6][j-6]!=1 || grid[j][j-6]!=1)&&(grid[i][i+6]!=1 || grid[i+6][j+6]!=1)&&(grid[i+6][j+6]!=1 || grid[j][j+6]!=1)&&(grid[i][i+6]!=1 || grid[j][j+6]!=1)&&(grid[i][i-6]!=1 || grid[j][j-6]!=1))

			    {

				llll.p1=i;	llll.p2=j;

				return llll;

			    }

			}

			if(i==j-6 && grid[i][j]!=1)

			{
    if((grid[i][i-1]!=1 || grid[i-1][j-1]!=1)&&(grid[i-1][j-1]!=1 || grid[j][j-1]!=1)&&(grid[i][i+1]!=1 || grid[i+1][j+1]!=1)&&(grid[i+1][j+1]!=1 || grid[j][j+1]!=1)&&(grid[i][i+1]!=1 || grid[j][j+1]!=1)&&(grid[i-1][i]!=1 || grid[j-1][j]!=1))


							{

					llll.p1=i;	llll.p2=j;

					return llll;

				}

			}

		}

	for(i=0;i<36;i++)

		for(j=0;j<36;j++)

		{

			if(i==j-1 && j%6!=0 && grid[i][j]!=1)

			{

				llll.p1=i;	llll.p2=j;

				return llll;

			}

			if(i==j-6 && grid[i][j]!=1)

			{

				llll.p1=i;	llll.p2=j;

				return llll;

			}

		}

	return llll;

}
