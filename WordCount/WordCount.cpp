#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void WordCount(char *file){
	FILE *fp;
	char buffer[1000];
	char c;
	int bufferlen;
	int isLastBlank = 0; //上个字符是否是空格
	int chars=0;//字符数 
	int words=0;//单词数 
	int lines=0;//行数 
	int i;
 
	if((fp=fopen(file,"rb"))==NULL){
		printf("文件无法打开\n");
		exit(0);
	}
	while(fgets(buffer,1000,fp)!=NULL){
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++){
			c=buffer[i];
			if(c==' ' || c=='\t'){
				if(isLastBlank==0){
					words++;
				}
				isLastBlank=1;
			}else if(c!='\n'&&c!='\r'){
				chars++;
				isLastBlank=0;
			}
 
		}
		if(isLastBlank==0)
			words++;
		isLastBlank=1;
		lines++;
	}
	fclose(fp);
	//输出 
	printf("行数：%d\n",lines);
	printf("字符数：%d\n",chars);
	printf("单词数：%d\n",words);
 
	
}
int main(){
	char file[]="D://3263141306//FileRecv//zuoye//Count.txt";//D:\3263141306\FileRecv\zuoye文件地址 
	WordCount(file);
	return 0;
}
