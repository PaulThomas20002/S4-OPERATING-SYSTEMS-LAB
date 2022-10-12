#include<stdio.h>
int main(){
	int nf,np,flag1,flag2,flag3,frames[10],pages[30],temp[30],pos,max,fault=0,i,j,k;
	printf("no of frames : ");
	scanf("%d",&nf);
	printf("no of pages : ");
	scanf("%d",&np);
	printf("Pages : ");
	for(i=0;i<np;++i){
		scanf("%d",&pages[i]);
	}
	for(i=0;i<nf;++i){
		frames[i]=-1;
	}
	for(i=0;i<np;++i){
		flag1=flag2=0;
		for(j=0;j<nf;++j){
			if(frames[j]==pages[i]){
				flag1=flag2=1;
				break;
			}
		}
		if(flag1==0){
			for(j=0;j<nf;++j){
				if(frames[j]==-1){
					fault++;
					frames[j]=pages[i];
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0){
			flag3=0;
			for(j=0;j<nf;++j){
				temp[j]=-1;
				for(k=i+1;k<np;++k){
					if(frames[j]==pages[k]){
						temp[j]=k;
						break;
					}
				}
			}
			for(j=0;j<nf;++j){
				if(temp[j]==-1){
					pos=j;
					flag3=1;
					break;
				}
			}
			if(flag3==0){
				pos=0;
				max=temp[0];
				for(j=1;j<nf;++j){
					if(temp[j]>max){
						max=temp[j];
						pos=j;
					}
				}
			}
			frames[pos]=pages[i];
			fault++;
		}
		printf("\n");
		for(j=0;j<nf;++j){
			printf("%d\t",frames[j]);
		}
	}

	printf("fault=%d",fault);
	return 0;
}
