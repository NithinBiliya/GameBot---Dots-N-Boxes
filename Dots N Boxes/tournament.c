//	tournament generator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	int n,i,p1,p2;
	char name[20][100],lucky[100],name1[100],name2[100];
	printf("How many players? ");
	scanf("%d",&n);
	printf("Enter the names : \n");
	for(i=0;i<=n;i++)
//		scanf("%[^\n]s",name[i]);
		gets(name[i]);
	for(i=0;i<n;i++)
		strcpy(name[i],name[i+1]);
	printf("\nTournament generated : \n\n");
	if(n%2)
	{
		srand(time(NULL));
		p1=rand()%n;
		strcpy(lucky,name[p1]);
		for(i=p1;i<n-1;i++)
			strcpy(name[i],name[i+1]);
		n--;
		printf("%s goes to the next round...\n",lucky);
	}
	while(n)
	{
		srand(time(NULL));
		p1=rand()%n;
		strcpy(name1,name[p1]);
		for(i=p1;i<n-1;i++)
			strcpy(name[i],name[i+1]);
		n--;
		srand(time(NULL));
		p2=rand()%n;
		strcpy(name2,name[p2]);
		for(i=p2;i<n-1;i++)
			strcpy(name[i],name[i+1]);
		n--;
		printf("%s vs %s\n",name1,name2);
	}
	
	return 0;
}
