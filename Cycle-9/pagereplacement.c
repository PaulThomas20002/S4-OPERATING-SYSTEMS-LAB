#include<stdio.h>
int i,j,n,p[50],f;
int fifo();
int lru();
int lfu();
int main(){
    int pf1,pf2,pf3;
    printf("Enter no of pages : ");
    scanf("%d",&n);
    printf("Enter the reference string : ");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter no of frames : ");
    scanf("%d",&f);
    pf1=fifo();
    pf2=lru();
    pf3=lfu();
    printf("\n\nPage fault : ");
    printf("\nfifo = %d",pf1);
    printf("\nlru = %d",pf2);
    printf("\nlfu = %d\n\n",pf3);
    return 0;
}
int fifo(){
    int q[10],c = 0,s;
    printf("\nFirst In First Out");
    for(i=0;i<f;i++)
    q[i] = -1;
    for(i=0;i<n;i++){
    s=0;
    for(j=0;j<f;j++){
    if(p[i] == q[j]){
    s++;
    c--
    ;
    }
    }
    c++;
    if((c <= f) && (s == 0))
    q[i] = p[i];
    else if(s == 0)
    q[(c- 1) % f] = p[i];

    printf("\n");
    for(j = 0; j < f; j++){
    if(q[j]==-1)
    printf("-\t");
    else
    printf("%d\t", q[j]);

    }
    }
    return c; 
}
int lru() {
int q[20],c=0,c1,d,k=0,r,t,b[20],c2[20];
printf("\nLeast Recently Used");

q[k]=p[k];
printf("\n%d\t",q[k]);
for(i=1;i<f;i++)
printf("-\t");
printf("\n");
c++;
k++;
for(i=1;i<n;i++)

{

c1=0;
for(j=0;j<f;j++)

{

if(p[i]!=q[j])
c1++;

}
if(c1==f)
{

c++;
if(k<f)
{

q[k]=p[i];
k++;
for(j=0;j<k;j++)
printf("%d\t",q[j]);
for(i=0;i<f-k;i++)
printf("-\t");
printf("\n");
}
else
{
for(r=0;r<f;r++)
{
c2[r]=0;
for(j=i-1;j<n;j--)
{
if(q[r]!=p[j])
c2[r]++;
else
break;
}
}
for(r=0;r<f;r++)
b[r]=c2[r];
for(r=0;r<f;r++)
{
for(j=r;j<f;j++)
{
if(b[r]<b[j])
{
t=b[r];
b[r]=b[j];
b[j]=t;
}
}
}
for(r=0;r<f;r++)
{
if(c2[r]==b[0])
{
q[r]=p[i];
}
printf("%d\t",q[r]);
}
printf("\n");
}
}
}

return c;
}
int lfu()
{
int q[50],k, cntr[20], min, c=0;
for(i=0;i<f;i++)
{
cntr[i]=0;
q[i]=-1;
}
printf("\nLeast Frequently Used");
for(i=0;i<n;i++)
{
for(j=0;j<f;j++)
if(p[i]==q[j])
{
cntr[j]++;
break;
}
if(j==f)
{
min = 0;
for(k=1;k<f;k++)
if(cntr[k]<cntr[min])
min=k;
q[min]=p[i];
cntr[min]=1;
c++;
}
printf("\n");
for(j=0;j<f;j++){
if(q[j]==-1)
printf("-\t");
else
printf("%d\t",q[j]);
}
}
return c;
}
