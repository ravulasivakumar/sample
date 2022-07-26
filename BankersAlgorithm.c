#include<stdio.h>
int main()
{
    int n,r,i,j,sum=0,ch=0,tot=0,c=0,t=0;
    int avail[10],alloc[10][10],max[10][10],need[10][10],temp[10],f[10];
    printf("Enter no.of processes and resources:");
    scanf("%d%d",&n,&r);
    avail[r],alloc[n][r],max[n][r],need[n][r],f[n],temp[r];
    for(i=0;i<n;i++)
    {
        f[i]=0;
        printf("Enter allocation values of process:\n");
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        printf("Enter maximum values of process:\n");
        sum=0;
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
            sum+=need[i][j];
            if(need[i][j]<0)
            {
                printf("You have entered a wrong input.Allocation should less than max need.");
                printf("\nDeadlock Occurs");
            }
        }
    }
    printf("Enter available resources:\n");
    ch=0;
    for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
		if(avail[i]<=0)
			ch=ch+1;
	}
	if(ch==r && sum>0)
    {
        printf("No available resources.Deadlock Occurs");
    }
    tot=0;
    printf("\nAllocation \t Maximum \t\t Need\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
        {
            printf("%d ",alloc[i][j]);
        }
        printf("\t");
        for(j=0;j<r;j++)
        {
            printf("%d ",max[i][j]);
        }
        printf("\t");
        for(j=0;j<r;j++)
        {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    c=0;
    while(1)
    {
        t=0;
        if(tot==n)
			break;
		for(i=0;i<n;i++)
		{
			t=0;
			for(j=0;j<r;j++)
			{
				if(f[i]==0 && need[i][j]<=avail[j])
                {
					t=t+1;
                }
            }
			if(t==r)
            {
				break;
            }
        }
        if(t==r)
        {
            printf("\n");
            printf("process = %d\n",i);
			f[i]=1;
			tot=tot+1;
			for(j=0;j<r;j++)
            {
				temp[j]=avail[j]-need[i][j];
			}
			for(j=0;j<r;j++)
			{
				avail[j]=temp[j]+max[i][j];
			}
        }
        else
        {
			c=1;
			break;
		}
    }
    if(c==1)
		printf("\nDeadlock Occured.");
	return 0;
}
