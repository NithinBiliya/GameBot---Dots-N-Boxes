//	TND80_Deepesh Shetty

char b2_name[]="Deepesh Shetty";

struct LINE bot2(int grid[36][36],struct LINE line)			//	This is where your opponent codes
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
}gcc


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

