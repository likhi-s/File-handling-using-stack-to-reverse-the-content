#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    char s[100];
    char stack[10][100];
    int top = -1;
    //writing the content
    file = fopen("Likhitha.txt", "a");
    if(file == NULL)
    {
        puts("cannot open file");
    }
    else
    {
        printf("enter required content:\n");
        while(strlen(gets(s)) > 0)
        {
            fputs(s, file);
            fputs("\n", file);
        }
        fclose(file);
    }
    //reading the content
    printf("contents are being read now...\n",s);
    file = fopen("Likhitha.txt","r");
    if(file==NULL)
    {
        puts("cannot open file");
    }
    else
    {
        while(fgets(s,sizeof(s),file)!=NULL)
            printf("%s",s);
    }
    fclose(file);
    //pushing the content into stack
    file = fopen("Likhitha.txt", "r");

    while(fgets(s, sizeof(s), file) != NULL)
    {

        if (top < 10)
        {
            top++;
            strcpy(stack[top], s);
        }
    }
    fclose(file);

    //popping the stored content
    printf("Reversed content of the file:\n");
    while(top >= 0)
    {
        printf("%s", stack[top]);
        top--;
    }


    return 0;
}
