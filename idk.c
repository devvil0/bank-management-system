#include <stdio.h>
#include <conio.h>
char a[100];
int main()
{
    FILE *f;
    f = fopen("C:\\Users\\idkmy\\OneDrive\\Desktop\\newfile.txt","r");

    if(f == NULL)  
    printf("File does not exist \n");

    else 
    printf("File does exists\n");

    while((fgets(a,100,f)) != NULL)
    {
        printf("%s",a);
    }
    fclose(f);
    return 0;
}