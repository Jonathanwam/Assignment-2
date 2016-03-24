#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 256

char* getNextWord(FILE* fd)
{
    char* word = (char*)malloc(MAX_WORD_SIZE);
    char ch;
    int size=0;

    word[0]='\0';

    while( (ch=fgetc(fd)) != ' ' )
    {
        if(ch==EOF)
            break;
        if(size > MAX_WORD_SIZE-1)
            break;
        word[size]=ch;
        size++;
    }
    if(word[0]=='\0')
        return NULL;
    word[size]='\0';
    return word;
}
int main(int argc, char **argv)
{

    int i;
    for(i=1;i<argc;i++)
    {
        FILE *fd;
        fd = fopen(argv[i],"r");


        char* str;
        while( (str=getNextWord(fd))!=NULL)
            printf("%s\n",str);

        fclose(fd);
    }



    return 0;
}
