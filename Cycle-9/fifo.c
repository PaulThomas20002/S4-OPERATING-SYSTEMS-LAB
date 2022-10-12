#include<stdio.h>
int main(){
	int nf,np,frames[10],pages[30],count=0,fault=0,i,j,k;
	printf("no of frames : ");
	scanf("%d",&nf);
	printf("no of pages : ");
	scanf("%d",&np);
	printf("Pages : ");

	for(i=0;i<np;i++)
		scanf("%d",&pages[i]);
	for(i=0;i<nf;i++)
		frames[i]=-1;

	for(i=0;i<np;i++){
		for(j=0;j<nf;j++){
			if(frames[j]==pages[i])
				break;
		}
		if(j==nf){
			frames[count++]=pages[i];
			fault++;
		}
		for(k=0;k<nf;k++){
			printf("%d\t",frames[k]);
		}
		if(j==nf)
			printf("Fault no: %d\n",fault);
		if(count==nf)
			count=0;

		printf("\n");
		}

	printf("fault=%d",fault);
	return 0;
}
