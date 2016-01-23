//	TNH28_Shashikiran bot code

char b2_name[]="Shashikiran";

struct LINE bot2(int grid[36][36],struct LINE line)			//	This is where you code
{

       int i,j;
	for(i=0;i<29;i++)
		for(j=0;j<29;j++)   
		{
			    if(i==j&&(i!=5&&i!=11&&i!=17&&i!=23&&i!=29))
                              {  
                                 if(grid[i][j+1]==1&&grid[i+1][j+7]==1&&grid[i+7][j+6]==1&&grid[i+6][j]!=1)
				 { 
					line.p1=i+6;	line.p2=j;
					return line;
				 }
		                 if(grid[i+1][j+7]==1&&grid[i+7][j+6]==1&&grid[i+6][j]==1&&grid[i][j+1]!=1)
		                 {   
		                        line.p1=i; line.p2=j+1;
		                         return line;
		                 } 
		                 
		                 if(grid[i+7][j+6]==1&&grid[i+6][j]==1&&grid[i][j+1]==1&&grid[i+1][j+7]!=1) 
				 { 
					line.p1=i+1; line.p2=j+7;
					return line;
				 }
				 if(grid[i+6][j]==1&&grid[i][j+1]==1&&grid[i+1][j+7]==1&&grid[i+7][j+6]!=1)  
				 { 
					line.p1=i+7; line.p2=j+6;
		                        return line;
				 }
			       }                     		                                            
	        }
	for(i=6;i<36;i++)
		for(j=6;j<36;j++)
		{

			/*if(i==35)
                        {
				if(i==j && grid[i][j-6]!=1&&(grid[j-6][j-6-1]!=1&&grid[i][i-1]!=1))
				{  
		                       
					line.p1=i;	line.p2=j-6;
					return line;
				}
			}*/
                          
			if(i==j && grid[i][j-6]!=1&&((grid[j-6][j-6-1]!=1&&grid[j-6+1][j-6]!=1)||(grid[i][i-1]!=1&&grid[i+1][i]!=1)))
			{  
                               if(grid[i-1][j-6-1]!=1||grid[i+1][j-6+1]!=1)
				{
				line.p1=i;	line.p2=j-6;
				return line;
				}
			}
 			

		           
		}



	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
		{
	              if(i!=35)
			{
                           if(i==j-1 && j%6!=0 && grid[35-i][35-j]!=1)
			   {    if(grid[35-i-1][35-j-6]==1)
                                { 
                                  if(grid[35-i-6][35-j-6]!=1&&grid[35-i][35-i-6]!=1){
					
				        line.p1=35-i;	line.p2=35-j;
			        	return line;
					}
				}else if(grid[35-i-6][35-j-6]==1&&grid[35-i][35-i-6]!=1)
                                {   
                                 //  if(grid[35-i][35-i-1]!=1&&grid[35-i-6][35-i-7]!=1){
				        line.p1=35-i;	line.p2=35-j;
			        	return line;
					//}
				}else if(grid[35-i-6][35-j-6]!=1)
                                {  
                                 //  if(grid[35-i][35-i-1]!=1&&grid[35-i-6][35-i-7]!=1){
				        line.p1=35-i;	line.p2=35-j;
			        	return line;
					//}
				}
			   }
		        }
		    else
			 if(i==j-1 && j%6!=0 && grid[35-i][35-j]!=1)
			   {   
				line.p1=35-i;	line.p2=35-j;
				return line;
			   }
		}
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
		{

			if(i==j-1 && j%6!=0 && grid[35-i][35-j]!=1)
			   {   
				line.p1=35-i;	line.p2=35-j;
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
