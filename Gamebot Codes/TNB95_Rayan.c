//	TNB54 - Rayan Victar Dsouza bot code

char b2_name[]="Rayan Victar Dsouza";

struct LINE bot2(int grid[36][36],struct LINE line)			//	This is Rayan Victar Dsouza
{
	int i,j,k,x,count[30],a,b,t,cnt,m,l;                        //My code: rayan
	int mygrid[36][36],chno=0,chcount=0;
	int chain[60][3],ch[60][2],ci,chi,lench=0,flag=1;

	for(k=0;k<29;k++)
	{
		count[k]=0;
		if((k+1)%6!=0)
		{
			if(grid[k][k+1]==1) count[k]++;
			if(grid[k][k+6]==1) count[k]++;
			if(grid[k+1][k+7]==1) count[k]++;
			if(grid[k+6][k+7]==1) count[k]++;

			if(count[k]==3)
			{
				if(grid[k][k+1]==0)
				{
					line.p1=k; line.p2=k+1;
					return line;
				}
				if(grid[k][k+6]==0)
				{
					line.p1=k; line.p2=k+6;
					return line;
				}
				if(grid[k+1][k+7]==0)
				{
					line.p1=k+1; line.p2=k+7;
					return line;
				}
				if(grid[k+6][k+7]==0)
				{
					line.p1=k+6; line.p2=k+7;
					return line;
				}
			}
		}
	}
	
	for(k=0;k<29;k++)
	{
		if((k+1)%6!=0)
		{
			if(count[k]==0)
			{
				if(grid[k][k+1]==0)
				{
					if(k>5)
					{
						l=k-6;
						if((grid[l][l+1] + grid[l][l+6] + grid[l+1][l+7] + grid[l+6][l+7])!=2)
						{
							line.p1=k; line.p2=k+1;
							return line;
						}
					}
				}
				if(grid[k][k+6]==0)
				{
					if((k%6)!=0)
					{
						l=k-1;
						if((grid[l][l+1] + grid[l][l+6] + grid[l+1][l+7] + grid[l+6][l+7])!=2)
						{
							line.p1=k; line.p2=k+6;
							return line;
						}
					}

				}
				if(grid[k+1][k+7]==0)
				{
					if((k+1)%6!=0)
					{
						l=k+1;
						if((grid[l][l+1] + grid[l][l+6] + grid[l+1][l+7] + grid[l+6][l+7])!=2)
						{
							line.p1=k+1; line.p2=k+7;
							return line;
						}
					}

				}
				if(grid[k+6][k+7]==0)
				{
					if((k+6)<29)
					{
						l=k+6;
						if((grid[l][l+1] + grid[l][l+6] + grid[l+1][l+7] + grid[l+6][l+7])!=2)
						{
							line.p1=k+6; line.p2=k+7;
							return line;
						}
					}
				}
			}
		}
	}
	for(k=0;k<29;k++)
	{
		if((k+1)%6!=0)
		{
			if(count[k]==1)
			{			
				if(grid[k][k+1]==0)
				{
					if(k>5)
					{
						l=k-6;
						if((grid[l][l+1] + grid[l][l+6] + grid[l+1][l+7] + grid[l+6][l+7])!=2)
						{
							line.p1=k; line.p2=k+1;
							return line;
						}
					}
				}
				if(grid[k][k+6]==0)
				{
					if((k%6)!=0)
					{
						l=k-1;
						if((grid[l][l+1] + grid[l][l+6] + grid[l+1][l+7] + grid[l+6][l+7])!=2)
						{
							line.p1=k; line.p2=k+6;
							return line;
						}
					}

				}
				if(grid[k+1][k+7]==0)
				{
					if((k+1)%6!=0)
					{
						l=k+1;
						if((grid[l][l+1] + grid[l][l+6] + grid[l+1][l+7] + grid[l+6][l+7])!=2)
						{
							line.p1=k+1; line.p2=k+7;
							return line;
						}
					}

				}
				if(grid[k+6][k+7]==0)
				{
					if((k+6)<29)
					{
						l=k+6;
						if((grid[l][l+1] + grid[l][l+6] + grid[l+1][l+7] + grid[l+6][l+7])!=2)
						{
							line.p1=k+6; line.p2=k+7;
							return line;
						}
					}
				}
			}
		}
	}
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
			mygrid[i][j]=grid[i][j];
	for(i=0;i<=60;i++)	
	{
		chain[i][2]=-2;
		ch[i][1]=-1;
	}
	for(m=0;m<29;m++)
	{
		if((m+1)%6!=0)
		{
			if(count[m]==2)
			{
				for(i=0;i<36;i++)
				{
					for(j=0;j<36;j++)
					{
						if(i==j-1 && j%6!=0 && mygrid[i][j]!=1)
						{
							chain[lench][0]=i; chain[lench][1]=j; chain[lench][2]=-1;
							lench++;
						}
						if(i==j-6 && mygrid[i][j]!=1)
						{
							chain[lench][0]=i; chain[lench][1]=j; chain[lench][2]=-1;
							lench++;
						}
					}
				}
				chno=0;
				flag=1;
				while(flag)
				{
					for(i=0;i<lench;i++)
						if(chain[i][2]==-1)
							break;
					if(i==lench)
					{
						flag=0;
						break;
					}
					
					mygrid[chain[i][0]][chain[i][1]]=1;
					chain[i][2]=chno; ch[chno][0]=chno; ch[chno][1]=0;
					for(k=0;k<29;k++)
					{
						count[k]=0;
						if((k+1)%6!=0)
						{
							if(mygrid[k][k+1]==1) count[k]++;
							if(mygrid[k][k+6]==1) count[k]++;
							if(mygrid[k+1][k+7]==1) count[k]++;
							if(mygrid[k+6][k+7]==1) count[k]++;
									
							if(count[k]==3)
							{
								
								if(mygrid[k][k+1]==0)
								{
									mygrid[k][k+1]=1;
									for(x=0;x<lench;x++)
									{
										if(chain[x][0]==k && chain[x][1]==k+1)
										{
											chain[x][2]=chno; ch[chno][0]=chno; ch[chno][1]++;
										}
									}
								}
								if(mygrid[k][k+6]==0)
								{
									mygrid[k][k+6]=1;
									for(x=0;x<lench;x++)
									{
										if(chain[x][0]==k && chain[x][1]==k+6)
										{
											chain[x][2]=chno; ch[chno][0]=chno; ch[chno][1]++;
										}
									}
								}
								if(mygrid[k+1][k+7]==0)
								{
									mygrid[k+1][k+7]=1;
									for(x=0;x<lench;x++)
									{
										if(chain[x][0]==k+1 && chain[x][1]==k+7)
										{
											chain[x][2]=chno; ch[chno][0]=chno; ch[chno][1]++;
										}
									}
								}
								if(mygrid[k+6][k+7]==0)
								{
									mygrid[k+6][k+7]=1;
									for(x=0;x<lench;x++)
									{
										if(chain[x][0]==k+6 && chain[x][1]==k+7)
										{
											chain[x][2]=chno; ch[chno][0]=chno; ch[chno][1]++;
										}
									}
								}
								k=-1;
							}		
						}
					}
					chno++;					
				}
				
				chcount=chno;
				for(a=0;a<chcount-1;a++)
				{
					for(b=0;b<chcount-a-1;b++)
					{
						if(ch[b][1]>ch[b+1][1])
						{
							t=ch[b][1]; ch[b][1]=ch[b+1][1]; ch[b+1][1]=t;
							t=ch[b][0]; ch[b][0]=ch[b+1][0]; ch[b+1][0]=t;
						}
					}
				}
				if(chcount==1)
				{
					for(a=0;a<lench;a++)
					{
						if(chain[a][2]==ch[0][0])
						{
							line.p1=chain[a][0]; line.p2=chain[a][1];
							return line;
						}
					}
				}
				else
				{
					for(a=0;a<lench;a++)
					{
						if(chain[a][2]==ch[0][0])
						{
							line.p1=chain[a][0]; line.p2=chain[a][1];
							return line;
						}
					}
				}
			}
		}
	}


	return line;
}
