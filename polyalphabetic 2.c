#include<stdio.h>
#include<stdlib.h>
char matrix[26][26];
void constmatrix()
{
int i=0,j=0,ch=0,h=0;
for(i=0;i<26;i++)
{
ch=h++;
for(j=0;j<26;j++)
{
matrix[i][j]=ch;

if(ch==25)
ch=-1;

ch++;
}
}
}
int main()
{
char mes[100],k[100];
int i=0,j=0;
constmatrix();
printf("ENTER THE PLAIN TEXT :\n");
scanf("%s",mes);
printf("ENTER THE KEY :\n");
scanf("%s",k);
int mi=0,ki=0;
while(mes[i]!='\0'){ i++;}
mi=i,i=0;
while(k[i]!='\0'){ i++;}
ki=i;
int lk=i;
i=0;
if(mi!=ki)
{
while(ki<mi)
{
k[ki++]=k[i];
if(lk-1==i)
i=-1;
i++;
}
}
char en[100];
char de[100];
i=0;
printf("ENCRPTED MESSAGE = ");
while(mes[i]!='\0')
{
int c=mes[i]-97;
int r=k[i]-97;
en[i]=97+matrix[c][r];
printf("%c",en[i++]);
}
i=0;
printf("\nDECRPTED MESSAGE = ");
while(en[i]!='\0')
{
de[i]=(((en[i]-k[i])+26)%26)+97;
i++;
}
printf("%s",de);
return 0;
}