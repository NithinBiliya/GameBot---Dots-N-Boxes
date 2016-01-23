#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
	int a,i,j,grid[36][36],ri,ci,rj,cj,box[5][5];
	int gd,gm=VGAMAX; gd=DETECT;
	initgraph(&gd,&gm,NULL);
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
			grid[i][j]=0;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			box[i][j]=0;
	for(i=0;i<36;i++)
	{
		if(!(i>=0 && i<=5))
			grid[i][i-6]=grid[i-6][i]=1;
		if(i%6)
			grid[i][i-1]=grid[i-1][i]=1;
		if((i+1)%6)
			grid[i][i+1]=grid[i+1][i]=1;
		if(!(i>=30 && i<=35))
			grid[i][i+6]=grid[i+6][i]=1;
	}
//	grid[34][28]=1;
	box[1][3]=-1;
	box[3][2]=1;
	for(i=0;i<6;i++)
		for(j=0;j<6;j++)
			circle(j*50+50,i*50+50,2);
	for(i=0;i<36;i++)
		for(j=0;j<36;j++)
			if(grid[i][j]==1)
			{
				ri=floor(i/6);	ci=i%6;
				rj=floor(j/6);	cj=j%6;
				line(ci*50+50,ri*50+50,cj*50+50,rj*50+50);
			}
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			if(box[i][j]==-1)
			{
				setcolor(RED);
				floodfill(j*50+52,i*50+52,WHITE);
			}
			else if(box[i][j]==1)
			{
				setcolor(BLUE);
				floodfill(j*50+52,i*50+52,WHITE);
			}
			setcolor(WHITE);
		}

	delay(2500);

	return 0;
}
