#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void WordCount(char *file){
	FILE *fp;
	char buffer[1000];
	char c;
	int bufferlen;
	int isLastBlank = 0; //�ϸ��ַ��Ƿ��ǿո�
	int chars=0;//�ַ��� 
	int words=0;//������ 
	int lines=0;//���� 
	int i;
 
	if((fp=fopen(file,"rb"))==NULL){
		printf("�ļ��޷���\n");
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
	//��� 
	printf("������%d\n",lines);
	printf("�ַ�����%d\n",chars);
	printf("��������%d\n",words);
 
	
}
int main(){
	char file[]="D://3263141306//FileRecv//zuoye//Count.txt";//D:\3263141306\FileRecv\zuoye�ļ���ַ 
	WordCount(file);
	return 0;
}
