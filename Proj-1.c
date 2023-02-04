//#include "DirectoryTree.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<dirent.h>
//#include<Shlobj.h>
#include <stdbool.h>
//#include<S_ISDIR>
#include<ctype.h>
#include <errno.h>
#include <windows.h>

extern int errno;
char input[1000];
char name[1000];
int size=0;
char STr[1000];

long long strToNum(char *ch)
{
    long long res = 0;
    int flag = 1;
    if(*ch == '-')
    {
        flag = -1;
        *ch = '0';
    }
    for(int i = 0; ; i++)
    {
        if(*(ch + i) >= '0' && *(ch + i) <= '9')
        {
            res = res * 10 + (int)(*(ch + i) - '0');
        }
        else
        {
            return flag * res;
        }
    }
}
int countDigit(long long int n)
{
	if (n == 0)
		return 1;
	int count = 0;
	while (n != 0) {
		n = n / 10;
		++count;
	}
	return count;
}
void createfile()
{
int i=0;
int j=0;
int ctr=0;
char y=" ";
if(input[size+8]=='"')
    size=size+1;
for(int i=size+9;i<50;i++)
   {
       if(input[i]!='"' || input[i]!='\n')
          {
             name[i-size-9]=input[i];
          }
        else
            break;
   }
 char  kal[30];
    char g="/";
    int ret=-7;
    for(int i=0;i<30;i++)
    {
        if(name[i]=='/')
        {
            ret=mkdir(kal);

            kal[i]=name[i];
        }else
        {
            kal[i]=name[i];
        }
    }if (ret == -1)
    {
        printf("Pathname already exists!\n");
    }
    }
void createffile()
{
        int size_name=strlen(name)-1;
        char path[size_name];
        for(int i=0;i<strlen(name)-1;i++)
        {
            path[i]=name[i];
        }
        FILE * fp=fopen(path,"a");
        if(fp!=NULL)
            printf("Created successfully!\n");
        fclose(fp);
    }
void insertstr()
{
        int size_input=strlen(input)-1;
        char path[size_input];
        char path1[size_input];
        char str[size_input];
        char pos[size_input];
        memset(path,0,size_input);
        memset(path1,0,size_input);
        memset(str,0,size_input);
        memset(pos,0,size_input);
        for(int i=size+9;input[i+1]!='-';i++)
       {
           path[i-size-9]=input[i];

       }
       for(int i=size+strlen(path)+16;input[i+1]!='-';i++)
       {
           path1[i-(size+strlen(path)+16)]=input[i];
       }
        int size_path1=strlen(path1);
       for(int i=size+strlen(path)+strlen(path1)+22;i<size_input;i++)
       {
           str[i-(size+strlen(path)+strlen(path1)+22)]=input[i];
        }long long int line=strToNum(str);
        int sptok=0;
        for(int i=0;i<strlen(str);i++)
       {
           if(str[i]==':')
              sptok=i;
       }
       for(int i=sptok+1;i<strlen(str);i++)
       {
           pos[i-sptok-1]=str[i];
       }long long int start_position=strToNum(pos);
       long long int apple=0;
       FILE * fp=fopen(path,"r");
       if(fp==NULL)
          {
              printf("Cannot open the target file!\n");
          }
       else{
            FILE * wf=fopen("wfsee.txt","w");
       if(wf==NULL)
          printf("Something wrong happend!\n");
       else{
       char fline[256];
       int fi=0;
       int sip=0;
       char th;
       while(fgets(fline,sizeof(fline),fp))
       {
           /*fline[strcspn( fline, "\r\n" )] = '\0';
           if ( fline[0] ==10)
           {
               printf("empty!\n");
           }else
           {
               printf("Full!\n");
           }
           printf("%s>\n",fline);*/
           fi++;
           apple=apple+strlen(fline);
       if(fi==line-1)
        {

            apple=apple+(long long int)start_position;
            fclose(fp);
            FILE * fp=fopen(path,"r");
            if(fp==NULL)
            {
                printf("I cant open it for the second time\nGet your fuck out of here!\n");
            }
            while(sip<=apple)
       {
           th=fgetc(fp);
           fputc(th,wf);
           sip++;
       }fprintf(wf,"%s",path1);
       while((th=fgetc(fp))!=EOF)
       {
           fputc(th,wf);
       }
            //fseek(path,apple,SEEK_SET);
            //ftell(fp);
}
       }
       fclose(wf);
       }
       fclose(fp);
       }

       FILE * source=fopen(path,"w");
       if(source==NULL)
       {
           printf("Something wrong happend!\n");
       }else
       {
           FILE * wf=fopen("wfsee.txt","r");
           if(wf==NULL)
           {
               printf("Oh no Oh no!\n");
           }else
           {
               char chh;
               while((chh=fgetc(wf))!=EOF)
               {
                   fputc(chh,fp);
               }
           }fclose(wf);
       }fclose(source);
        if(remove("wfsee.txt")!=0)
              printf("Sorry!Something wrong happened!\n");
    }
void cat()
{
        char file_name[strlen(input)];
        memset(file_name,0,strlen(input));
        for(int i=size+8;i<strlen(input)-1;i++)
        {
            file_name[i-size-8]=input[i];
        }
        char ch;
        FILE * fp=fopen(file_name,"r");
        if(fp==NULL)
        {
            printf("Cant open the file!\n");
        }else
        {
        do{
           ch = fgetc(fp);
           printf("%c", ch);
           }while(ch != EOF);
           printf("\n");
        }fclose(fp);
    }
int removestr()
{
    int size_input=strlen(input)-1;
    char path[size_input];
    char path1[size_input];
    char str[size_input];
    char pos[size_input];
    memset(path,0,size_input);
    memset(path1,0,size_input);
    memset(str,0,size_input);
    memset(pos,0,size_input);
    for(int i=size+8;input[i]!=' ';i++)
   {
       path[i-size-8]=input[i];

   }
   for(int i=size+strlen(path)+14;input[i+1]!='-';i++)
   {
       path1[i-(size+strlen(path)+14)]=input[i];
   }long long int line=strToNum(path1);
    int sptok=0;
    for(int i=0;i<strlen(path1);i++)
   {
       if(path1[i]==':')
          sptok=i;
   }
   for(int i=sptok+1;i<strlen(path1);i++)
   {
       pos[i-sptok-1]=path1[i];
   }long long int start_position=strToNum(pos);

   int size_path1=strlen(path1);
   int backward=-1;
   for(int i=size+strlen(path)+strlen(path1)+21;i<size_input;i++)
   {
       str[i-(size+strlen(path)+strlen(path1)+21)]=input[i];
       if(input[i-1]=='-')
       {
           if(input[i]=='b')
           {
               backward=1;
           }else
           {
               backward=0;
           }
       }
    }long long int del_chars=strToNum(str);
    FILE * fp=fopen(path,"r");
    if(fp==NULL)
    {
        printf("Cant open the file!\n");
    }else
    {
    FILE * wf=fopen("wfsee.txt","w");
    if(wf==NULL)
    {
        printf("Sorry,Something wrong happend!\n");
    }else
    {
        if(backward==0)//removing forward
        {
    char fline[256];
   int fi=0;
   int sip=0;
   char th;
   long long int apple=0;
   while(fgets(fline,sizeof(fline),fp))
   {
       fi++;
       apple=apple+strlen(fline);
   if(fi==line-1)
    {
        apple=apple+(long long int)start_position;
        //fseek(fp,sizeof(fline),SEEK_SET);
        fclose(fp);
        FILE * fp=fopen(path,"r");
            while(sip<=apple)
       {
           th=fgetc(fp);
           fputc(th,wf);
           sip++;
       }
       while(sip>=apple+1 && sip<=apple+del_chars)
       {
           th=fgetc(fp);
           sip++;
           continue;
       }
       while((th=fgetc(fp))!=EOF)
       {
           fputc(th,wf);
       }
    }
   }
        }else if(backward==1)
        {
    char fline[256];
   int fi=0;
   int sip=0;
   char th;
   long long int apple=0;
   while(fgets(fline,sizeof(fline),fp))
   {
       fputs(fline,wf);
       fi++;
       apple=apple+strlen(fline);
   if(fi==line-1)
    {
        apple=apple+(long long int)start_position;
        fclose(fp);
        FILE * fp=fopen(path,"r");
        //fseek(fp,sizeof(fline),SEEK_SET);
            while(sip<=apple-del_chars)
       {
           th=fgetc(fp);
           fputc(th,wf);
           sip++;
       }
       while(sip>=apple-del_chars+1 && sip<=apple)
       {
           //printf("Now\n");
           th=fgetc(fp);
           sip++;
           continue;
       }
       while((th=fgetc(fp))!=EOF)
       {
           fputc(th,wf);
       }
    }
   }
        }
        fclose(wf);
    }
    fclose(fp);
}
FILE * source=fopen(path,"w");
if(source==NULL)
{
   printf("Something wrong happend!\n");
}else
{
   FILE * wf=fopen("wfsee.txt","r");
   if(wf==NULL)
   {
       printf("Oh no Oh no!\n");
   }else
   {
       char chh;
       while((chh=fgetc(wf))!=EOF)
       {
           fputc(chh,fp);
       }
   }fclose(wf);
}fclose(source);
if(remove("wfsee.txt")!=0)
      printf("Sorry!Something wrong happened!\n");
}
int copystr()
{
char file_path[strlen(input)];
char pos1[strlen(input)];
char pos2[strlen(input)];
char chasize[strlen(input)];
memset(chasize,0,strlen(input));
memset(file_path,0,strlen(input));
memset(pos1,0,strlen(input));
memset(pos2,0,strlen(input));
for(int i=size+8;input[i]!=' ';i++)
    {
        file_path[i-size-8]=input[i];
    }
    int donogte=0;
for(int i=size+strlen(file_path)+14;input[i]!=' ';i++)
    {
        if(input[i]==':')
            donogte=i-(size+strlen(file_path)+14);
        pos1[i-(size+strlen(file_path)+14)]=input[i];
    }long long int line=strToNum(pos1);
for(int i=donogte+1;i<strlen(pos1);i++)
{
    pos2[i-donogte-1]=pos1[i];
}long long int start_position=strToNum(pos2);
int chasize2_long=0;
for(int i=size+strlen(file_path)+strlen(pos1)+21;input[i]!=' ';i++)
{
    chasize[i-(size+strlen(file_path)+strlen(pos1)+21)]=input[i];
    chasize2_long=i;
}long long int chasize2=strToNum(chasize);
int backward=-1;
if(input[chasize2_long+3]=='b')
    backward=1;
else
    backward=0;

    //char STr[chasize2+1];
    memset(STr,0,chasize2+1);
    FILE * fp=fopen(file_path,"r");
    if(fp==NULL)
    {
        printf("Cant open the file!\n");
    }else
    {
       long long int apple=0;
       char fline[256];
       memset(fline,0,256);
       int fi=0;
       int sip=0;
       char th;
       while(fgets(fline,sizeof(fline),fp))
       {
           fi++;
           apple=apple+strlen(fline);
       if(fi==line-1)
        {
            apple=apple+(long long int)start_position;
            fclose(fp);
            FILE * fp=fopen(file_path,"r");
            if(fp==NULL)
            {
                printf("I cant open it for the second time\nGet your fuck out of here!\n");
            }
            else if(backward==0){
            while(sip<=apple)
       {
           th=fgetc(fp);
           sip++;
       }
       while(sip>=apple+1 && sip<=apple+chasize2)
       {
           STr[sip-(apple+1)]=fgetc(fp);
           sip++;
       }
        }else if(backward==1)
        {
            while(sip<=apple-chasize2)
            {
                th=fgetc(fp);
                sip++;
            }while(sip>=apple-chasize2+1 && sip<=apple)
            {
                STr[sip-(apple-chasize2+1)]=fgetc(fp);
                sip++;
            }
        }
        STr[chasize2+1]='\0';
       fclose(fp);

    }
       }
    }
}
cutstr()
{
char file_path[strlen(input)];
char pos1[strlen(input)];
char pos2[strlen(input)];
char chasize[strlen(input)];
memset(chasize,0,strlen(input));
memset(file_path,0,strlen(input));
memset(pos1,0,strlen(input));
memset(pos2,0,strlen(input));
for(int i=size+8;input[i]!=' ';i++)
    {
        file_path[i-size-8]=input[i];
    }
    int donogte=0;
for(int i=size+strlen(file_path)+14;input[i]!=' ';i++)
    {
        if(input[i]==':')
            donogte=i-(size+strlen(file_path)+14);
        pos1[i-(size+strlen(file_path)+14)]=input[i];
    }long long int line=strToNum(pos1);
for(int i=donogte+1;i<strlen(pos1);i++)
{
    pos2[i-donogte-1]=pos1[i];
}long long int start_position=strToNum(pos2);
int chasize2_long=0;
for(int i=size+strlen(file_path)+strlen(pos1)+21;input[i]!=' ';i++)
{
    chasize[i-(size+strlen(file_path)+strlen(pos1)+21)]=input[i];
    chasize2_long=i;
}long long int chasize2=strToNum(chasize);
int backward=-1;
if(input[chasize2_long+3]=='b')
    backward=1;
else
    backward=0;

    //char STr[chasize2+1];
    memset(STr,0,chasize2+1);
    FILE * fp=fopen(file_path,"r");
    if(fp==NULL)
    {
        printf("Cant open the file!\n");
    }else
    {
       long long int apple=0;
       char fline[256];
       memset(fline,0,256);
       int fi=0;
       int sip=0;
       char th;
       while(fgets(fline,sizeof(fline),fp))
       {
           fi++;
           apple=apple+strlen(fline);
       if(fi==line-1)
        {
            apple=apple+(long long int)start_position;
            fclose(fp);
            FILE * fp=fopen(file_path,"r");
            if(fp==NULL)
            {
                printf("I cant open it for the second time\nGet your fuck out of here!\n");
            }
            else if(backward==0){
            while(sip<=apple)
       {
           th=fgetc(fp);
           sip++;
       }
       while(sip>=apple+1 && sip<=apple+chasize2)
       {
           STr[sip-(apple+1)]=fgetc(fp);
           sip++;
       }
        }else if(backward==1)
        {
            while(sip<=apple-chasize2)
            {
                th=fgetc(fp);
                sip++;
            }while(sip>=apple-chasize2+1 && sip<=apple)
            {
                STr[sip-(apple-chasize2+1)]=fgetc(fp);
                sip++;
            }
        }
        STr[chasize2+1]='\0';
       fclose(fp);

    }
       }
    }
    fp=fopen(file_path,"r");
    if(fp==NULL)
    {
        printf("Cant open the file!\n");
    }else
    {
    FILE * wf=fopen("wfsee.txt","w");
    if(wf==NULL)
    {
        printf("Sorry,Something wrong happend!\n");
    }else
    {
        if(backward==0)//removing forward
        {
    char fline[256];
   int fi=0;
   int sip=0;
   char th;
   long long int apple=0;
   while(fgets(fline,sizeof(fline),fp))
   {
       fi++;
       apple=apple+strlen(fline);
   if(fi==line-1)
    {
        apple=apple+(long long int)start_position;
        fclose(fp);
        fp=fopen(file_path,"r");
            while(sip<=apple)
       {
           th=fgetc(fp);
           fputc(th,wf);
           sip++;
       }
       while(sip>=apple+1 && sip<=apple+chasize2)
       {
           th=fgetc(fp);
           sip++;
           continue;
       }
       while((th=fgetc(fp))!=EOF)
       {
           fputc(th,wf);
       }
    }
   }
        }else if(backward==1)
        {
    char fline[256];
   int fi=0;
   int sip=0;
   char th;
   long long int apple=0;
   while(fgets(fline,sizeof(fline),fp))
   {
       fputs(fline,wf);
       fi++;
       apple=apple+strlen(fline);
   if(fi==line-1)
    {
        apple=apple+(long long int)start_position;
        fclose(fp);
        FILE * fp=fopen(file_path,"r");
            while(sip<=apple-chasize2)
       {
           th=fgetc(fp);
           fputc(th,wf);
           sip++;
       }
       while(sip>=apple-chasize2+1 && sip<=apple)
       {
           //printf("Now\n");
           th=fgetc(fp);
           sip++;
           continue;
       }
       while((th=fgetc(fp))!=EOF)
       {
           fputc(th,wf);
       }
    }
   }
        }
        fclose(wf);
    }
    fclose(fp);
}
FILE * source=fopen(file_path,"w");
if(source==NULL)
{
   printf("Something wrong happend!\n");
}else
{
   FILE * wf=fopen("wfsee.txt","r");
   if(wf==NULL)
   {
       printf("Oh no Oh no!\n");
   }else
   {
       char chh;
       while((chh=fgetc(wf))!=EOF)
       {
           fputc(chh,fp);
       }
   }fclose(wf);
}fclose(source);
if(remove("wfsee.txt")!=0)
      printf("Sorry!Something wrong happened!\n");
}
int pastestr() /////////////////TRY IT!!!!!!!!!!!
{
    char file_path[1000];
    char pos1[1000];
    char pos2[1000];
    memset(pos1,0,1000);
    memset(pos2,0,1000);
    memset(file_path,0,1000);
    for(int i=size+7;input[i]!=' ';i++)
    {
        file_path[i-size-7]=input[i];
    }
for(int i=strlen(file_path)+size+13;input[i]!=':';i++)
    {
        pos1[i-(strlen(file_path)+size+13)]=input[i];
    }long long int line=strToNum(pos1);
    for(int i=strlen(file_path)+size+strlen(pos1)+14;i<strlen(input);i++)
    {
        pos2[i-(strlen(file_path)+size+strlen(pos1)+14)]=input[i];
    }long long int start_position=strToNum(pos2);
    FILE * fp=fopen(file_path,"r");
    if(fp==NULL)
    {
        printf("Unable to open the file!\n");
    }else
    {
        FILE * wf=fopen("wsee.txt","w");
        if(wf=NULL)
        {
            printf("Something wrong happend!\n");
        }else
        {
            char fline[256];
            long long int apple=0;
           int fi=0;
           int sip=0;
           char th;
            while(fgets(fline,sizeof(fline),fp))
       {
           fi++;
           apple=apple+strlen(fline);
           if(fi==line-1)
            {
            apple=apple+(long long int)start_position;
            fclose(fp);
            FILE * fp=fopen(file_path,"r");
            if(fp==NULL)
            {
                printf("I cant open it for the second time\nGet your fuck out of here!\n");
            }
            while(sip<=apple)
       {
           th=fgetc(fp);
           fputc(th,wf);
           sip++;
       }fprintf(wf,STr,file_path);
       while((th=fgetc(fp))!=EOF)
       {
           fputc(th,wf);
       }
       }
       }
        }fclose(wf);
    }fclose(fp);
}
int indexOf(FILE *fptr, const char *word, int *line, int *col)
{
    char str[1000000];
    char *pos;
    *line = -1;
    *col  = -1;
    while ((fgets(str, 1000000, fptr)) != NULL)
    {
        *line += 1;
        pos = strstr(str, word);
        if (pos != NULL)
        {
            *col = (pos - str);
            break;
        }
    }
    if (*col == -1)
        *line = -1;
    return *col;
}
int wc(char* file_path, char* word,int makanha[100])
{
    FILE *fp;
    int count = 0;
    int ch, len;
    int index=0;
    if(NULL==(fp=fopen(file_path, "r")))
        return -1;
    len = strlen(word);
    for(;;){
        int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *word) continue;
        for(i=1;i<len;++i)
        {
            if(EOF==(ch = fgetc(fp)))
            {
                goto end;
            }
            if((char)ch != word[i])
            {
                fseek(fp, 1-i, SEEK_CUR);
                goto next;
            }
        }int ftell_ans=ftell(fp);
        makanha[index]=ftell_ans;
        index++;
        ++count;
        next: ;
    }
end:
    fclose(fp);
    return count;
}
int wc_all(char* file_path, char* word)
{
    FILE *fp;
    int count = 0;
    int ch, len;
    if(NULL==(fp=fopen(file_path, "r")))
        return -1;
    len = strlen(word);
    for(;;){
        int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *word) continue;
        for(i=1;i<len;++i)
        {
            if(EOF==(ch = fgetc(fp)))
            {
                goto end;
            }
            if((char)ch != word[i])
            {
                fseek(fp, 1-i, SEEK_CUR);
                goto next;
            }
        }int ftell_ans=ftell(fp);
        printf("%d,",ftell_ans-strlen(word));
        ++count;
        next: ;
    }
end:
    fclose(fp);
    return count;
}
int find()
{
    char given_str[1000];
    char file_path[1000];
    memset(file_path,0,1000);
    memset(given_str,0,1000);
    int makanha[100]={0};
    int flag=0;
    if(input[size+6]=='"')
    {
        flag=1;
        for(int i=size+7;input[i+1]!='"';i++)
        {
            given_str[i-(size+7)]=input[i];
        }
    }else{
    for(int i=size+6;input[i+1]!='-';i++)
    {
        given_str[i-(size+6)]=input[i];
    }}
    given_str[strlen(input)-1]='\0';
    if(flag==0)
    {int i=size+strlen(given_str)+14;
    for(i;input[i+1]!='-' && input[i+1]!='\0';i++)
    {
        file_path[i-(size+strlen(given_str)+14)]=input[i];
    }file_path[i+1]='\0';
    if(strlen(input)>=size+strlen(given_str)+16+strlen(file_path))
    {
        if(input[size+strlen(given_str)+16+strlen(file_path)]=='c')
    {
        makanha[100]=0;
        int count=wc(file_path,given_str,makanha);
        printf("%d\n",count);
        return 0;
    }else if(input[size+strlen(given_str)+16+strlen(file_path)]=='a' && input[size+strlen(given_str)+16+strlen(file_path)]=='t')
            {
                char at_size[100];
                long long int at_adad=0;
                memset(at_size,0,100);
                for(int i=size+strlen(given_str)+19+strlen(file_path);i<strlen(input)-1;i++)
                {
                    at_size[i-(size+strlen(given_str)+19+strlen(file_path))]=input[i];
                }at_adad=strToNum(at_size);
                if(at_adad>wc(file_path,given_str,makanha))
                {
                    printf("There are less than %lld '%s' in this file!\n-1\n",at_adad,given_str);
                    //return -1;
                }else
                {
                    makanha[100]=0;
                    wc(file_path,given_str,makanha);
                    printf("%d\n",makanha[at_adad-1]-strlen(given_str));
                    return 0;
                }
           }
            else if(input[size+strlen(given_str)+16+strlen(file_path)]=='b')
            {
    int ftell_ans;
    FILE *fp;
    int count = 0;
    int ch, len;
    if(NULL==(fp=fopen(file_path, "r")))
        printf("Unable to open the file!\n");
    else{
    len = strlen(given_str);
    for(;;){
        int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *given_str) continue;
        for(i=1;i<len;++i)
        {
            if(EOF==(ch = fgetc(fp)))
            {
                goto end;
            }
            if((char)ch != given_str[i])
            {
                fseek(fp, 1-i, SEEK_CUR);
                goto next;
            }
        }ftell_ans=ftell(fp);
        fclose(fp);
        break;
        ++count;
        next: ;
    }
end:
    fclose(fp);}
                    char buffer_1[1000];
                    int space_counter=0;
                    FILE * wfp=fopen(file_path,"r");
                    if(wfp==NULL)
                    {
                        printf("Unable to open the file!\n");
                    }else{
                    fgets(buffer_1,1000,fp);
                    for(int i=0;i<=ftell_ans-strlen(given_str);i++)
                    {
                        if(buffer_1[i]==' ')
                            space_counter++;
                    }}
                    fclose(wfp);
                    printf("%d\n",space_counter+1);
                    return 0;
            }
            else if(input[size+strlen(given_str)+16+strlen(file_path)]=='a' && input[size+strlen(given_str)+17+strlen(file_path)]=='l')
            {
                int count_2=wc_all(file_path,given_str);
                printf("\n");
                return 0;
            }
    }
    }
    else
        {
            int i=size+strlen(given_str)+17;
            for(i;input[i+1]!='-' && input[i+1]!='\0';i++)
            {
                file_path[i-(size+strlen(given_str)+17)]=input[i];
            }file_path[i+1]='\0';
            if(strlen(input)>=size+strlen(given_str)+19+strlen(file_path))
            {
                if(input[size+strlen(given_str)+19+strlen(file_path)]=='c')
            {
                makanha[100]=0;
                int count=wc(file_path,given_str,makanha);
                printf("%d\n",count);
                return 0;
            }else if(input[size+strlen(given_str)+19+strlen(file_path)]=='a' && input[size+strlen(given_str)+20+strlen(file_path)]=='t')
            {
                char at_size[100];
                long long int at_adad=0;
                memset(at_size,0,100);
                for(int i=size+strlen(given_str)+22+strlen(file_path);i<strlen(input)-1;i++)
                {
                    at_size[i-(size+strlen(given_str)+22+strlen(file_path))]=input[i];
                }at_adad=strToNum(at_size);
                if(at_adad>wc(file_path,given_str,makanha))
                {
                    printf("There are less than %lld '%s' in this file!\n-1\n",at_adad,given_str);
                    //return -1;
                }else
                {
                    makanha[100]=0;
                    wc(file_path,given_str,makanha);
                    printf("%d\n",makanha[at_adad-1]-strlen(given_str));
                    return 0;
                }
            }
            else if(input[size+strlen(given_str)+19+strlen(file_path)]=='b')
            {
    int ftell_ans;
    FILE *fp;
    int count = 0;
    int ch, len;
    if(NULL==(fp=fopen(file_path, "r")))
        printf("Unable to open the file!\n");
    else{
    len = strlen(given_str);
    for(;;){
        int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *given_str) continue;
        for(i=1;i<len;++i)
        {
            if(EOF==(ch = fgetc(fp)))
            {
                goto end;
            }
            if((char)ch != given_str[i])
            {
                fseek(fp, 1-i, SEEK_CUR);
                goto next;
            }
        }ftell_ans=ftell(fp);
        fclose(fp);
        break;
        ++count;
        next_1: ;
    }
end_1:
    fclose(fp);}
                    char buffer_1[1000];
                    int space_counter=0;
                    FILE * wfp=fopen(file_path,"r");
                    if(wfp==NULL)
                    {
                        printf("Unable to open the file!\n");
                    }else{
                    fgets(buffer_1,1000,fp);
                    for(int i=0;i<=ftell_ans-strlen(given_str);i++)
                    {
                        if(buffer_1[i]==' ')
                            space_counter++;
                    }}
                    fclose(wfp);
                    printf("%d",space_counter+1);
                    return 0;
            }else if(input[size+strlen(given_str)+19+strlen(file_path)]=='a' && input[size+strlen(given_str)+20+strlen(file_path)]=='l')
            {
                int count_2=wc_all(file_path,given_str);
                printf("\n");
                return 0;
            }
            }
        }
        int setare=-1;
        if(given_str[0]=='*')
            setare=1;
        else if(given_str[strlen(given_str)-1]=='*')
            setare=2;
        else
            setare=0;
        FILE *fptr= fopen(file_path, "r");
        int line, col;
        if (fptr == NULL)
        {
            printf("Unable to open file.\n");
            printf("Please check you have read/write previleges.\n");
        }else{
            if(setare==0){
            int n, m, i, j, line;
            line=1;
            m=strlen(given_str);
            char buffer[1000];
            memset(buffer,0,1000);
            int flag=1;
            while (fgets(buffer,1000, fptr) != NULL)
                {
                    i=0;
                    n=strlen(buffer);
                    int iflag=0;
                    while (i <= n)
                        {
                            j = 0;
                    while (i < n && j < m && buffer[i] == given_str[j])
                        {
                            flag=0;
                            if(j==m-1)
                            {
                                flag=1;
                            }
                            i++,j++;
                        }
                        if(j==m)
                        {
                            printf("%d\n", i - m);
                            iflag=1;
                            return 0;
                        }
                    else if(flag!=0)
                    {
                        i++;
                    }
                    }
                    if(iflag!=1)
                    {
                        printf("Not found!\n");
                        return 0;
                    }
                        ++line;
                        }
        }else if(setare==1)
        {
            int n, m, i, j, line;
            line=1;
            m=strlen(given_str);
            char buffer[1000];
            memset(buffer,0,1000);
            int flag=1;
            while (fgets(buffer,1000, fptr) != NULL)
                {
                    i=0;
                    n=strlen(buffer);
                    while (i <= n)
                        {
                            j = 1;
                    while (i < n && j < m && buffer[i] == given_str[j])
                        {
                            flag=0;
                            if(j==m-1)
                            {
                                flag=1;
                            }
                            i++,j++;
                        }
                        if(j==m)
                        {
                            int answer=i-m;
                            int bee=-1;
                            for(int iii=answer-1;iii>=0;iii--)
                            {
                                bee++;
                                if(buffer[iii]==' '||buffer[iii]=='\0')
                                {
                                    answer=answer-bee;
                                }
                            }
                            if(buffer[answer+m]==' ' || buffer[answer+m]=='\0')
                            {
                                printf("%d\n",answer);
                                break;
                            }else
                            {
                                printf("No such string in this file!\n");
                                break;
                            }
                        }
                    else if(flag!=0)
                    {
                        i++;
                    }
                    }
                        ++line;
                        }
        }else if(setare==2)
        {
            int n, m, i, j, line;
            line=1;
            m=strlen(given_str);
            char buffer[1000];
            memset(buffer,0,1000);
            int flag=-1;
            int zflag=0;
            while (fgets(buffer,1000, fptr) != NULL)
                {
                    i=0;
                    n=strlen(buffer);
                    while (i <= n)
                        {
                            j = 0;
                    while (i < n && j <= m-1 && buffer[i] == given_str[j])
                        {
                            flag=0;
                            if(j==m-2)
                            {
                                flag=1;
                            }
                            i++,j++;
                        }
                        if(j==m-1)
                        {
                            int answer=i-m;
                           //printf("%d ",i);
                            int bee=-1;
                            for(int iii=answer+1;iii<strlen(buffer);iii++)
                            {
                                if(buffer[iii]!=' '&& buffer[iii]!='\0')
                                {
                                    bee++;
                                }
                            }
                            printf("%d\n",answer);
                            zflag=1;
                            break;
                        }
                    else if(flag!=0)
                    {
                        i++;
                    }
                    }
                    if(zflag!=1)
                        printf("Not found!\n");
                        ++line;
                        }
        }
        }fclose(fptr);
}
void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[100];
    int index = 0;
    int owlen;
    owlen = strlen(oldWord);
    if (!strcmp(oldWord, newWord))
    {
        printf("They are same!\n");
        return;
    }
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, temp + index + owlen);
    }
}
void replaceAt(char *str, const char *oldWord, const char *newWord,int at_adad,char* file_path)
{
    char *pos, temp[100];
    int index = 0;
    int owlen;
    owlen = strlen(oldWord);
    int time=0;
    if (!strcmp(oldWord, newWord))
    {
        printf("They are same!\n");
        return;
    }char makanha[100]={0};
    wc(file_path,oldWord,makanha);
    int flag=0;
    while ((pos=strstr(str,oldWord))!=NULL)
    {
        time++;
        if(time<at_adad)
        {
            char * second_word="rasoraso";
            strcpy(temp, str);
            index = pos - str;
            str[index] = '\0';
            strcat(str, second_word);
            strcat(str, temp + index + owlen);

        }else if(time==at_adad)
        {   flag=1;
            strcpy(temp, str);
            index = pos - str;
            str[index] = '\0';
            strcat(str, newWord);
            strcat(str, temp + index + owlen);
        }
    }if(flag==1)
        {
            replaceAll(str,"rasoraso",oldWord);
        }
}
int replace()
{
    char file_path[100];
    char given_str_1[100];
    char given_str_2[100];
    char atribute[5];
    memset(file_path,0,100);
    memset(given_str_1,0,100);
    memset(given_str_2,0,100);
    memset(atribute,0,5);
    int i_1;
    for(i_1=size+7;input[i_1+1]!='-';i_1++)
    {
        given_str_1[i_1-(size+7)]=input[i_1];
    }given_str_1[i_1+1]='\0';
    int i_2;
    for(i_2=size+strlen(given_str_1)+14;input[i_2+1]!='-';i_2++)
    {
        given_str_2[i_2-(size+strlen(given_str_1)+14)]=input[i_2];
    }given_str_2[i_1+1]='\0';
    int i_3;
    for(i_3=size+strlen(given_str_1)+strlen(given_str_2)+22;input[i_3+1]!='-';i_3++)
    {
        file_path[i_3-(size+strlen(given_str_1)+strlen(given_str_2)+22)]=input[i_3];
    }file_path[i_3+1]='\0';
    if(input[size+strlen(given_str_1)+strlen(given_str_2)+strlen(file_path)+25]=='l')//all
    {
    char buffer[256];
    memset(buffer,0,256);
    FILE * fPtr  = fopen(file_path, "r");
    FILE * fTemp = fopen("replace.tmp", "w");
    if (fPtr == NULL || fTemp == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }
    while ((fgets(buffer, 256, fPtr)) != NULL)
    {
        replaceAll(buffer, given_str_1, given_str_2);
        fputs(buffer, fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);
    remove(file_path);
    rename("replace.tmp", file_path);
    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", given_str_1, given_str_2);
    return 0;
}else if(input[size+strlen(given_str_1)+strlen(given_str_2)+strlen(file_path)+25]=='t')//at
    {
        char at_size[10];
        memset(at_size,0,10);
        int i_4;
        for(i_4=size+strlen(given_str_1)+strlen(given_str_2)+strlen(file_path)+27;i_4<strlen(input);i_4++)
        {
            at_size[i_4-(size+strlen(given_str_1)+strlen(given_str_2)+strlen(file_path)+27)]=input[i_4];
        }int at_adad=strToNum(at_size);
        char makanha[100];
        if(at_adad>wc(file_path,given_str_1,makanha))
        {
            printf("There are only %d '%s' in this file!\n",wc(file_path,given_str_1,makanha),given_str_1);
            return 0;
        }else
        {
    char buffer[256];
    memset(buffer,0,256);
    FILE * fPtr  = fopen(file_path, "r");
    FILE * fTemp = fopen("replace.tmp", "w");
    if (fPtr == NULL || fTemp == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }
    while ((fgets(buffer, 256, fPtr)) != NULL)
    {
        replaceAt(buffer, given_str_1, given_str_2,at_adad,file_path);
        fputs(buffer, fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);
    remove(file_path);
    rename("replace.tmp", file_path);
    printf("\nSuccessfully replaced %dth occurrences of '%s' with '%s'.\n",at_adad, given_str_1, given_str_2);
    return 0;
        }
    }
}
int wizard(char *checkingString, char *mainString)
{
    //If checking string exists at the beginning of the input deletes it and returns 0
    //1 means there was nut such part in the input given
    int size = (int)strlen(checkingString);
    int inputSize = (int)strlen(mainString);
    if(inputSize < size)
        return 1;
    for (int i = 0; i < size; ++i)
    {
        if(checkingString[i] != mainString[i])
            return 1;
    }
    for (int i = 0; i < inputSize - size; ++i)
    {
        mainString[i] = mainString[i + size];
    }
    mainString[inputSize - size] = '\0';
    return 0;
}
int grep()//1460
{
    char file_path_1[100];
    char pattern[100];
    char pattern_star[100];
    char option[10];
    memset(file_path_1,0,100);
    memset(pattern,0,100);
    memset(pattern_star,0,100);
    memset(option,0,10);
    char text[1024];
    int star=0;
    int opt=0;
    if(input[6]=='c')
    {
        opt=1;
        for(int i=13;input[i+1]!='-';i++)
    {
        pattern[i-13]=input[i];
    }if(pattern[0]=='"' && pattern[strlen(pattern)]=='"')
    {
        star=1;
        for(int i=1;i<strlen(pattern)-1;i++)
        {
            pattern_star[i-1]=pattern[i];
        }pattern_star[strlen(pattern)-1]='\0';
    }
    for(int i=20+strlen(pattern);i<strlen(input)-1;i++)
    {
        file_path_1[i-(strlen(pattern)+20)]=input[i];
    }
    }else if(input[6]=='l')
    {
        opt=2;
        for(int i=13;input[i+1]!='-';i++)
    {
        pattern[i-13]=input[i];
    }if(pattern[0]=='"' && pattern[strlen(pattern)]=='"')
    {
        star=1;
        for(int i=1;i<strlen(pattern)-1;i++)
        {
            pattern_star[i-1]=pattern[i];
        }pattern_star[strlen(pattern)-1]='\0';
    }
    for(int i=20+strlen(pattern);i<strlen(input)-1;i++)
    {
        file_path_1[i-(strlen(pattern)+20)]=input[i];
    }
    }else{
    for(int i=10;input[i+1]!='-';i++)
    {
        pattern[i-10]=input[i];
    }

    /*char temp[1024];
    int tempIndex = 0;
    if(input[0] == '\"')
    {
        wizard("\"", input);
        int a = 0;
        for (int i = 0; ; ++i)
        {
            if(input[i] == '\n')
                return 1;
            if(input[i] == '\"' && (i == 0 || input[i - 1] != '\\'))
            {
                text[i - a] = '\0';
                temp[tempIndex] = '\0';
                break;
            }
            if(input[i] == '\"' && input[i - 1] == '\\')
            {
                a++;
                text[i - a] = '\"';
            }
            text[i - a] = input[i];
            temp[tempIndex] = input[i];
            tempIndex++;
        }
        wizard(temp, input);
        wizard("\"", input);
        return 0;
    }
    else
    {
        for (int i = 0; ; ++i)
        {
            if(input[i] == ' ' || input[i] == '\n')
            {
                text[i] = '\0';
                break;
            }
            text[i] = input[i];
        }
        wizard(text, input);
        return 0;
    }*/


    if(pattern[0]=='"' && pattern[strlen(pattern)]=='"')
    {
        star=1;
        for(int i=1;i<strlen(pattern)-1;i++)
        {
            pattern_star[i-1]=pattern[i];
        }pattern_star[strlen(pattern)-1]='\0';
    }
    for(int i=17+strlen(pattern);i<strlen(input)-1;i++)
    {
        file_path_1[i-(strlen(pattern)+17)]=input[i];
    }
}
        char * token_1 = strtok(file_path_1, " ");
        while( token_1 != NULL )
            {
            FILE * fp=fopen(token_1,"r");
            if(fp==NULL)
            {
                printf("Unable to open the file!\n");
            }else
            {
                int num =0;
                char word[2000];
                char * string;
                char * ggf=pattern;
                /*char student[100] = {0};
                if(star==0)
                {
                    size_t destination_size = sizeof (student);
                    strncpy(student, pattern, destination_size);
                    student[destination_size - 1] = '\0';
                }else if(star==1)
                {
                    size_t destination_size = sizeof (student);
                    strncpy(student, pattern_star, destination_size);
                    student[destination_size - 1] = '\0';
                }*/
                while (fgets(string,500,fp)!=NULL)
                {
                    int line=0;
                    char buffer[strlen(string)];
                    memset(buffer,0,strlen(string));
                    for(int i=0;i<strlen(string);i++)
                    {
                        buffer[i]=string[i];
                    }buffer[strlen(string)-1]='\0';
                    /*char* token = strtok(string, " ");
                    while (token !=NULL) {
                            char* des=token;
                            char source[]=" ";
                    strcat(des,source);
        printf("%s>\t%s>\t%d\n-----------------\n",des,pattern,strcmp(des,text));
                    if(strcmp(des, pattern)!=0) {//if match found
                                num++;
                                line=1;
                        }
                        token = strtok(NULL, " ");
                    }*/
                    if(star==1)
                    {
                        ggf=pattern;
                    }else if(star==0)
                    {
                        ggf=pattern_star;
                    }
                    char *pch = strstr(string,ggf);

if(pch)
{
    num++;
    if(opt==1)//c
                        {
                            printf("%d\n",num);
                        }else if(opt==2)
                        {
                            printf("%s\n",token_1);
                        }else
                        {
                            printf("%s: %s\n",token_1,buffer);
                        }
}
                    }
                //printf("we found the word %s in the file %d times\n",student,num );
                num = 0;
                fclose(fp);
            }
            token_1 = strtok(NULL, " ");
        }
}
int auto_indent()
{
    char file_path[100];
    memset(file_path,0,100);
    for(int i=size+1;i<strlen(input)-1;i++)
    {
        file_path[i-(1+size)]=input[i];
    }file_path[strlen(input)-1]='\0';
    FILE * fp=fopen(file_path,"r");
    if(fp==NULL)
    {
        printf("Unable to open the file!\n");
    }else
    {
        FILE * wf=fopen("indent_test.txt","w");
        if(wf==NULL)
        {
            printf("Sorry!We have a problem!\n");
        }else
        {
            char ch='\0';
            char new_line="/n";

            int flag1=0;

            while((ch=fgetc(fp))!=EOF)
            {
                if(ch==123)
                    {
                        //fputs(" ",wf);
                        fputc(ch,wf);
                        //puts(new_line,wf);
                        flag1=1;
                    }
                    else if(ch==125)
                    {
                        //fputs(new_line,wf);
                        fputc(ch,wf);
                        //fputs(new_line,wf);
                        flag1=2;
                    }else
                    {
                        flag1=0;
                        fputc(ch,wf);
                        if(fseek(fp,ftell(fp)+1,SEEK_SET)==125)
                        {
                            fputc(new_line,wf);
                        }
                    }if(flag1==1)
                    {
                        fprintf(wf,"\n    ");
                    }
                    else if(flag1==2)
                    {
                        fprintf(wf,"\n");
                    }
            }
                fclose(wf);
            }
        fclose(fp);
    }
   char dr;// source_file[20], target_file[20];
   FILE *source, *target;
   source = fopen("indent_test.txt", "r");
   if (source == NULL) {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
   target = fopen(file_path, "w");
   if (target == NULL) {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
   while ((dr = fgetc(source)) != EOF)
      fputc(dr, target);
   printf("File copied successfully.\n");
   fclose(source);
   fclose(target);
   return 0;
}
int countOfLinesFromFile(char *filename)
{
FILE* myfile = fopen(filename, "r");
int ch, number_of_lines = 0;
do
{
    ch = fgetc(myfile);
    if(ch == '\n')
        number_of_lines++;
}
while (ch != EOF);
if(ch != '\n' && number_of_lines != 0)
    number_of_lines++;
fclose(myfile);
return number_of_lines;
}
int compare()//1705
{
    char file_path1[100];
    char file_path2[100];
    memset(file_path1,0,100);
    memset(file_path2,0,100);
    for(int i=size+1;input[i]!=' ';i++)
    {
        file_path1[i-(size+1)]=input[i];
    }
    for(int i=size+strlen(file_path1)+2;i<strlen(input)-1;i++)
    {
        file_path2[i-(size+strlen(file_path1)+2)]=input[i];
    }

    int line_f1=countOfLinesFromFile(file_path1);
    int line_f2=countOfLinesFromFile(file_path2);
    int min_line=0;
    if(line_f1<line_f2)
    {
        min_line=line_f1;
    }else
    {
        min_line=line_f2;
    }

    int xat_shomar=0;
    FILE * fptr1=fopen(file_path1,"r");
    if(fptr1==NULL)
    {
        printf("Something wrong happend!\n");
    }else
    {
        FILE * fptr2=fopen(file_path2,"r");
        if(fptr2==NULL)
        {
            printf("The file cant be opend!\n");
        }else
        {
            char buf_1[1024];
            char buf_2[1024];
            while((fgets(buf_1,1024,fptr1))!=EOF)
            {
                xat_shomar++;
                memset(buf_2,0,1024);
                fgets(buf_2,1024,fptr2);
                if(strcmp(buf_1,buf_2)!=0 && xat_shomar<=min_line)
                {
                    printf("============ #%d ============\n%s\n%s\n",xat_shomar,buf_1,buf_2);
                }else if(strcmp(buf_1,buf_2)!=0 && xat_shomar>min_line)
                {
                    if(line_f1>min_line)
                        printf(">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>\n%s\n",min_line+1,line_f1,buf_1);
                    else
                        printf(">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>\n%s\n",min_line+1,line_f2,buf_2);
                }
                memset(buf_1,0,1024);
            }
            fclose(fptr2);
        }
        fclose(fptr1);
    }
}
void listFiles(const char *path)
{
    struct dirent *dp;
    DIR *dir = opendir(path);
    if (!dir)
        return;
    while ((dp = readdir(dir)) != NULL)
    {
        printf("%s\n", dp->d_name);
    }
    closedir(dir);
}
void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    if (!dir)
        return;
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            listFilesRecursively(path);
        }
    }
    closedir(dir);
}
void tree_list(char *basePath, const int root)
{

    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++)
            {
                if (i%2 == 0 || i == 0)
                    printf("%c", 179);
                else
                    printf(" ");

            }

            printf("%c%c%s\n", 195, 196, dp->d_name);

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree_list(path, root + 2);
        }
    }

    closedir(dir);
}
int tree()
{
    //directoryTree(".", stdout, 1, false);
    char depth[5];
    memset(depth,0,5);
    for(int i=size+1;i<strlen(input)-1;i++)
    {
        depth[i-(size+1)]=input[i];
    }depth[strlen(input)-1]='\0';
    int omg=strToNum(depth);
    if(omg<-1)
    {
        printf("Invalide Depth!\n");
    }else if(omg==-1)//Hameye Zir Address Ha
    {
        ///listFilesRecursively("root");
        tree_list("root",0);
    }else
    {
        //tree_list("root",omg);
    }
}
int main()
{
                   while(1)
                         {
                             memset(input,0,100);
                             size=0;
                             fgets(input, 100, stdin);
                             char command[30];
                             memset(command,0,30);
                             char ch='0';
                             for(int i=0;i<100;i++)
                             {
                                 if(input[i]!=' ')
                                    {
                                        command[i]=input[i];
                                        size++;
                                    }
                                 else
                                    break;
                             }
                             if(strcmp(command,"createfile")==0)//createfile
                                ch='1';
                             else if(strcmp(command,"insertstr")==0)//insertstr
                                ch='2';
                             else if(strcmp(command,"cat")==0)//cat
                                ch='3';
                             else if(strcmp(command,"removestr")==0)//removestr
                                ch='4';
                             else if(strcmp(command,"copystr")==0)//copy
                                ch='5';
                             else if(strcmp(command,"cutstr")==0)//cut
                                ch='6';
                             else if(strcmp(command,"pastestr")==0)//paste
                                ch='7';
                             else if(strcmp(command,"find")==0)//find
                                ch='8';
                             else if(strcmp(command,"replace")==0)//replace
                                ch='9';
                            else if(strcmp(command,"grep")==0)//grep
                                ch='A';
                            else if(strcmp(command,"auto-indent")==0)//auto-indent
                                ch='B';
                            else if(strcmp(command,"compare")==0)//compare
                                ch='C';
                            else if(strcmp(command,"tree")==0)//tree
                                ch='D';
                            else if(strcmp(command,"end")==0)
                                return 0;
                            switch(ch)
                                        {
                                               case '1': createfile();
                                                         createffile();
                                                          break;
                                               case '2': insertstr();
                                                          break;
                                               case '3': cat();
                                                          break;
                                               case '4': removestr();
                                                          break;
                                               case '5': copystr();
                                                           break;
                                               case '6': cutstr();
                                                           break;
                                               case '7': pastestr();////////
                                                           break;
                                               case '8': find();////////
                                                           break;
                                               case '9': replace();
                                                           break;
                                               case 'A': grep();
                                                           break;
                                               case 'B': auto_indent();
                                                           break;
                                               case 'C': compare();
                                                           break;
                                               case 'D': tree();
                                                           break;
                                               default :
                                                          printf("Invalid input\n");
                                                          break;
                                         }
                        }
                        return 0;
         }


         /*
indexOf(fptr, given_str, &line, &col);
if (line != -1)
    printf("'%s' found at line: %d, col: %d\n", given_str, line + 1, col + 1);
else
    printf("'%s' does not exists.", given_str);
*/
   /*
        int line,col;
        FILE * fp=fopen(file_path,"r");
        if(fp==NULL)
        {
            printf("Unable to open the file!\n");
        }else
        {
            int n, m, i, j, line;
            m=strlen(given_str);
            char buffer[256];
            memset(buffer,0,256);
            while (fgets(buffer, 256, fp) != NULL)
                {
                    i=0;
                    n=strlen(buffer);
                    while (i < n)
                        {
                            j = 0;
                    while (i < n && j < m && buffer[i] == given_str[j])
                        {
                            ++i, ++j;printf("i=%d n=%d\n",i,n);
                        }
                    if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
                        {
                            printf("Line: %d ", line);
                            printf("Column: %d\n", i - m);
                        }
                    while (i < n && buffer[i] != ' ')
                        {
                            ++i;
                        }
                        ++i;
                        }
                        ++line;
                        }
                        }*/
            //const char * ptr_str;
            //strcpy(given_str,ptr_str);
            //ptr_str=given_str;
