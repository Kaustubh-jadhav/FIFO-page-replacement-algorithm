#include<stdio.h>
int main(){
    int frame[10],pages[30],np,nf,i,j,flag=0,pagefaults=0;
    printf("Enter numbe of pages :");
    scanf("%d",&np);
    printf("Enter ref string :");
    for ( i = 0; i < np; i++)
        scanf("%d",&pages[i]);
    printf("Enter number of frames :");
    scanf("%d",&nf);
    for(j=0;j<nf;j++)
        frame[j]=-1;
    for(i=0;i<np;i++)
    {
        flag=0;
        for(j=0;j<nf;j++)
            if (frame[j]==pages[i])
            {
                flag++;
                pagefaults--;
            }
        pagefaults++;
        if((pagefaults<nf)&&(flag==0))
            frame[i]=pages[i];
        else if(flag==0)
            frame[(pagefaults-1)%nf]=pages[i];
        printf("\n");
        for(j=0;j<nf;j++)
            printf("%d\t",frame[j]);
        printf("\n");
        printf("page faults = %d",pagefaults);
    }
    return 0;
}