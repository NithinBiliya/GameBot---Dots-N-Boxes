//	TNB34_Madhu_Sagar

char b2_name[]="Madhu Sagar";

void copybox(int boxsour[5][5],int boxdest[5][5]);

struct LINE bot2(int grid[36][36],struct LINE line)
 {
	int randcount= 5;
	int i,j,tempp1,tempp2;
	
	for(i=0;i<36;i++)
	 {
	  for(j=0;j<36;j++)
	  {
	    if(randcount>0)
	     {
	      tempp1=i%(rand()%18);
	      if(rand()%2==0)
	      {
	        tempp2=tempp1+6;
	      }
	      else
	      {
	       tempp2=tempp1+1;
	      }
	     
	     }
	    else
	    {
	      if(rand()%2==0)
	      {
	        tempp2=tempp1+6;
	      }
	      else
	      {
	       tempp2=tempp1+1;
	      }    
	    }
	    
	    int toproceed=0;
	    int level=0;
	    int madhubox[5][5],madhugrid[36][36];
	    
	    //callthis(toproceed,madhubox,level);
	    copy(madhugrid,grid);
	    //copybox(box,madhubox);
	    
	    toproceed = checkaddline(madhugrid,tempp1,tempp2,madhubox);
	    if(toproceed==1)
	     {
	       continue;
	     }
	     randcount--;
	     line.p1=tempp1;
	     line.p2=tempp2;
	     return line;
	     	       
	  }
	 }
    return line;

 }

int checkaddline(int madhugrid[36][36],int tempp1,int tempp2) //,int madhubox)
{
	int t,temp,flag,tmp;
	madhugrid[tempp1][tempp2]=madhugrid[tempp2][tempp1]=1;
	t=tempp1-tempp2;
	temp=min(tempp1,tempp2);
	tmp=floor(temp/6);
	if(t==-1 || t==1)
		{
			flag=0;
			if(tempp1>5 && madhugrid[tempp1-6][tempp2-6]==1 && madhugrid[tempp1][tempp1-6]==1 && madhugrid[tempp2][tempp2-6]==1)
			{
				
				//return 0; // true
				//madhubox[tmp-1][temp%6]=999;
				if((madhugrid[tempp1][tempp2]==1 || madhugrid[tempp2][tempp1]==1))
				{
				flag=1;
				}
			}
			if(tempp1<30 && madhugrid[tempp1+6][tempp2+6]==1 && madhugrid[tempp1][tempp1+6]==1 && madhugrid[tempp2][tempp2+6]==1)
			{
				//return 0;
				//madhubox[tmp][temp%6]=999;
				
				
				if((madhugrid[tempp1][tempp2]==1 || madhugrid[tempp2][tempp1]==1))
				{
				flag=1;
				}
			}
			
			if(flag)
			{
                          return 0; // true. select this line 
                        			
			}
			else
			{
			return 1; // false. don't select this line '
			}
		}
	else if(t==-6 || t==6)
		{
			flag=0;
			if(tempp1/6!=0 && madhugrid[tempp1-1][tempp2-1]==1 && madhugrid[tempp1][tempp1-1]==1 && madhugrid[tempp2][tempp2-1]==1)
			{
				//box[tmp][temp%6-1]=move;
				//b1_pts++;
				//flag=1;
				if((madhugrid[tempp1][tempp2]==1 || madhugrid[tempp2][tempp1]==1))
				{
				flag=1;
				}
			}
			if((tempp1+1)/6!=0 && madhugrid[tempp1+1][tempp2+1]==1 && madhugrid[tempp1][tempp1+1]==1 && madhugrid[tempp2][tempp2+1]==1)
			{
				//box[tmp][temp%6]=move;
				//b1_pts++;
				//flag=1;
				if((madhugrid[tempp1][tempp2]==1 || madhugrid[tempp2][tempp1]==1))
				{
				flag=1;
				}
			}
			if(flag)
			{
                          return 0; // true. select this line 
                        			
			}
			else
			{
			return 1; // false. don't select this line '
			}
		}
}
void copybox(int boxsour[5][5],int boxdest[5][5])			
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			boxdest[i][j]=boxsour[i][j];
}

