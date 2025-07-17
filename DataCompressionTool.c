#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
// function to compress a file
void compressfile(){
    FILE *in = fopen("input.txt","r");  //open original file
    FILE *out = fopen("compressed.txt","w");  // create compressed file

    if(in == NULL || out == NULL)
    {
        printf("ERROR");
        return;
    }

    char ch,str;
    int count = 1;

    str = fgetc(in);  //read first letter

    while((ch = fgetc(in)) != EOF)
    {
        if(ch == str)
        {
            count ++;
        }
        else{
            // write character and count
            fprintf(out,"%c%d",str,count);
            str = ch;
            count = 1;
        }
    }
    
    fprintf(out,"%c%d",str,count);
    fclose(in);
    fclose(out);
    printf("file compressed to compressed.txt\n");
}
// function to decompress a file
void decompressfile(){
    FILE * in = fopen("compressed.txt","r");
    FILE* out = fopen("decompressed.txt","w");

    if(in == NULL || out == NULL){
        printf("ERROR\n");
         return ;
    }

    char ch;
    int count;

    while((ch = fgetc(in)) !=EOF)
    {
        fscanf(in,"%d",&count);
        for(int i=0;i<count;i++)
        {
            fputc(ch,out);
        }
    }
    fclose(in);
    fclose(out);
    printf("file decompressed to decompressed.txt\n");
}

int main(){
    int choice;
    while(1){
        printf("data compression tool\n");
        printf("1. for Compress file\n2. for Decompress File\n3.exit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        if(choice == 1){
            compressfile();
        }
        else if (choice == 2){
            decompressfile();
        }
        else if(choice == 3){
            printf("EXIT");
            break;
        }
        else{
            printf("invalid choice\n");
        }
    }
    return 0;
}
