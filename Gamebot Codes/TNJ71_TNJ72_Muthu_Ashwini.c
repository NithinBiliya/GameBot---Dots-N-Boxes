//	TNJ71_TNJ72_Muthu_Ashwini

char b2_name[]="Muthu and Ashwini";

struct LINE bot2(int grid[36][36],struct LINE line)			//	This is where your opponent codes
{

      
	int i,j,x,y,my[36][36],a,b,x1=0,y1=0,z,n;
        int min,sum=0,flag=0,a1,a2,pre1,pre2;
	
                     //check to form a box.........................
			for(x=0;x<36;x++)
		          for(y=0;y<36;y++)
		             {
                                if(x==y-1 && y%6!=0 && grid[x][y]==1 && grid[x+6][y+6]!=1 && grid[x][x+6]==1 && grid[x+1][x+7]==1)
                                {
                                    
                                    line.p1=x+6;
                                    line.p2=y+6;
                                    return line;
                                 }
                                if(x==y-1 && y%6!=0 && grid[x][y]==1 && grid[x+6][y+6]==1 && grid[x][x+6]!=1 && grid[x+1][x+7]==1)
                                {
                                    
                                    line.p1=x;
                                    line.p2=x+6;
                                    return line;
                                 }
                                if(x==y-1 && y%6!=0 && grid[x][y]==1 && grid[x+6][y+6]==1 && grid[x][x+6]==1 && grid[x+1][y+6]!=1)
                                {
                                    
                                    line.p1=x+1;
                                    line.p2=y+6;
                                    return line;
                                 }
                                if(x==y-1 && y%6!=0 && grid[x][y]!=1 && grid[x+6][y+6]==1 && grid[x][x+6]==1 && grid[x+1][y+6]==1)
                                {
                                   
                                    line.p1=x;
                                    line.p2=y;
                                    return line;
                                 }
                                 
                             }
                      //avoid normal put up..................................................
                      // check for vertical lines between two horizontal lines..
                          for(x=0;x<36;x++)
		          for(y=0;y<36;y++)
		             {
                                 if(x==y-6 && y%6!=0  && grid[x][y]!=1 ) 
                                {
                                    if(grid[x-1][y-1]!=1 && grid[x+1][y+1]!=1 && (grid[x-1][x]==1 || grid[x][x+1]==1 ))
                                    {
                                        if(grid[x-1][x]==1 && grid[x][x+1]==1 && grid[y-1][y]!=1 && grid[y][y+1]!=1)
                                        {
                                         
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                        if(grid[x-1][x]==1 && grid[y-1][y]!=1)
                                        {
                                          
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                        if(grid[x][x+1]==1 && grid[y][y+1]!=1)
                                        {
					  
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                    }
                               //vertical up lines........................
                                    if(grid[x-1][y-1]!=1 && grid[x+1][y+1]!=1 && (grid[y-1][y]==1 || grid[y][y+1]==1 ))
                                    {
                                        if(grid[y-1][y]==1 && grid[y][y+1]==1 && grid[x-1][x]!=1 && grid[x][x+1]!=1)
                                        {
					  
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                        if(grid[y-1][y]==1 && grid[x-1][x]!=1)
                                        {
					  
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                        if(grid[y][y+1]==1 && grid[x][x+1]!=1)
                                        {
					  
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                    } 
                                 }
                                 
                             }
             // chec for horizontal between two vertical lines........................................
                              for(x=0;x<36;x++)
		              for(y=0;y<36;y++)
		             {
                                 if(x==y-1 && y%6!=0  && grid[x][y]!=1 ) 
                                {
                                    if(grid[x-6][y-6]!=1 && grid[x+6][y+6]!=1 && (grid[x-6][x]==1 || grid[x][x+6]==1 ))
                                    {
                                        if(grid[x-6][x]==1 && grid[x][x+6]==1 && grid[y-6][y]!=1 && grid[y][y+6]!=1)
                                        {
                                          
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                        if(grid[x-6][x]==1 && grid[y-6][y]!=1)
                                        {
                                          
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                        if(grid[x][x+6]==1 && grid[y][y+6]!=1)
                                        {
					   
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                    }
                       ///horizontal right lines...................................................
                                    if(grid[x-6][y-6]!=1 && grid[x+6][y+6]!=1 && (grid[y-6][y]==1 || grid[y][y+6]==1 ))
                                    {
                                        if(grid[y-6][y]==1 && grid[y][y+6]==1 && grid[x-6][x]!=1 && grid[x][x+6]!=1)
                                        {
                                         
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                        if(grid[y-6][y]==1 && grid[x-6][x]!=1)
                                        {
                                          
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                        if(grid[y][y+6]==1 && grid[x][x+6]!=1)
                                        {
					   
                                           line.p1=x;
                                           line.p2=y;
                                           return line;
                                        }
                                    }
                                 }
                                 
                             }
              // avoid ormal put up.. single check............................
		for(x=0;x<36;x++)
		for(y=0;y<36;y++)
		{
                         if(x==y-1 && y%6!=0 && grid[x][y]!=1)
			 {
                              if(grid[x][x+6]!=1 && grid[x+6][y+6]!=1 && grid[x-6][x]!=1 && grid[x-6][y-6]!=1 && grid[y][y+6]!=1 && grid[y][y-6]!=1)
                              {
                               
				line.p1=x;	line.p2=y;
				return line;
                              }
                               if(grid[x][x+6]!=1 && grid[x+6][y+6]!=1 && grid[x-6][x]!=1 && grid[x-6][y-6]!=1)
                              {
                               
				line.p1=x;	line.p2=y;
				return line;
                              }
                                if(grid[x-6][y-6]!=1 && grid[y-6][y]!=1 && grid[y][y+6]!=1 && grid[x+6][y+6]!=1)
                              {
                                
				line.p1=x;	line.p2=y;
				return line;
                              }
                                 if(grid[x-6][y-6]!=1 && grid[x-6][x]!=1 && grid[y][y+6]!=1 && grid[x+6][y+6]!=1)
                              {
                                
				line.p1=x;	line.p2=y;
				return line;
                              }
				 if(grid[x-6][y-6]!=1 && grid[y-6][y]!=1 && grid[x][x+6]!=1 && grid[x+6][y+6]!=1)
                              {
                               
				line.p1=x;	line.p2=y;
				return line;
                              }
                              
                              
			}
                }
             // check for least possibl give up value.........................
                min=0;
                copy(my,grid);
                //check to form a box.........................
            for(n=0;n<36;n++)
            {   
              for(z=0;z<36;z++)
               {
		for(x=0;x<36;x++)
		   for(y=0;y<36;y++)
		   {
                               if(x==y-1 && y%6!=0 && my[x][y]!=1 && flag==0)
			       {
                                   
				   my[x][y]=1;
				   flag=1;
			       }
				
                               if(x==y-1 && y%6!=0 && my[x][y]==1 && my[x+6][y+6]!=1 && my[x][x+6]==1 && my[x+1][x+7]==1)
                                {
                                   
                                    my[x+6][y+6]=1;
                                    pre1=x1; x1=x+1; 
                                    pre2=y1; y1=y+6;
                                    sum++;
 				    
                                 }
                                if(x==y-1 && y%6!=0 && my[x][y]==1 && my[x+6][y+6]==1 && my[x][x+6]!=1 && my[x+1][x+7]==1)
                                {
                                    
                                    my[x][x+6]=1;
                                    pre1=x1; x1=x; pre2=y1; y1=x+6;
                                    sum++;
                                 }
                                if(x==y-1 && y%6!=0 && my[x][y]==1 && my[x+6][y+6]==1 && my[x][x+6]==1 && my[x+1][y+6]!=1)
                                {
                                    
                                   my[x+1][y+6]=1;
                                    pre1=x1; x1=x+1; pre2=y1; y1=y+6;
                                    sum++;
                                 }
                                if(x==y-1 && y%6!=0 && my[x][y]!=1 && my[x+6][y+6]==1 && my[x][x+6]==1 && my[x+1][y+6]==1)
                                {
                                   
                                    my[x+6][y+6]=1;
                                    pre1=x1; x1=x+6; pre2=y1; y1=y+6;
                                    sum++;
                                 }
                                 
                          } 
                          if(min==0)
                              min=sum;
                          if(min>=sum && sum!=0)
                             {
                                 a1=pre1; a2=pre2;
                                 a=x1; b=y1;
                                 min=sum;
                                 
                             }
                            
                          }
                          flag=0;
                          sum=0; 
                        }
                       if(min!=0 && (grid[a][b]!=1 || grid[a1][a2]!=1 ))
                       {
                          if(grid[a][b]!=1 )
                         {
                          
                          line.p1=a;	line.p2=b;
				   return line;
                         }
                          if(grid[a1][a2]!=1 )
                         {
                          
                          line.p1=a1;	line.p2=a2;
				   return line;
                         }
                         
                       }            
             // with no option put on the way wherever its free 
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
                 
	
	
}

