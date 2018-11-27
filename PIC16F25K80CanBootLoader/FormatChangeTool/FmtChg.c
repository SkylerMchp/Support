#include "stdio.h"
int main(int argc,char **argv)
{
unsigned char startpoint[]={0x00,0xEF,0x02,0xF0};
char *chfname;
char *chfnameinput;
FILE *fps,*fpo;

unsigned int j;
char ch,chend;
unsigned long i=0;
	j =(strlen(*(argv+2)));	//取第二个参数的长度，将最后四个字符变成.bin
	if(j<=4)
	{
		printf("Para error please type as follow format: a.exe E:\\P25K80CanBoot\\AppTest.X dist\\default\\production\\AppTest.X.production.bin");
		return;
	}
	chfname=malloc(j);
	printf("project path is :\n");
	printf("%s\n\n",*(argv+1));
	printf("image path in next line: by the way, please use bin file, if your name is hex, program will change to bin automaticly:\n");
	printf("%s\n\n",*(argv+2));
	sprintf(chfname,"%s\0",*(argv+2));
	*(chfname+j-4)='\0';
	sprintf(chfname,"%s.bin\0",chfname);
	printf("%s\n",chfname);
	chfnameinput=malloc(strlen(*(argv+1))+strlen(chfname)+3);
	sprintf(chfnameinput,"%s\\%s",*(argv+1),chfname);
	free(chfname);
	printf("Final input file is : %s\n",chfnameinput);
	fpo=fopen("CanBootLoader.cbt","wb");
	fps=fopen(chfnameinput,"rb");
	free(chfnameinput);
	if ((fps==NULL)||(fpo==NULL))
	{
		printf("program open error, please check bin file name is okey and readable, and cbl file is using\n");
		printf("sorce file is: %s\n",*(argv+1));
		fclose(fps);
		fclose(fpo);
		return ;
	}
	while(!feof(fps))
	{
		ch=fgetc(fps);
		if((0<=i)&&(i<=3))
		{
			fprintf(fpo,"%c",startpoint[i]);	//将程序指针强制跳入0x400BootLoader位置
		}
		else
		{
			fprintf(fpo,"%c",ch);
		}
		i++;
		if(i>=0x8000)
		{
			fclose(fps);
			fclose(fpo);
			printf("Change successful, please use CanBootLoader.cbt as bootloader file");
			return;
		}	
	}
	printf("Error!\n");
	return 0;
}
