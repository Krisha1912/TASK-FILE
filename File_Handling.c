//TASK - 1
// FILE HANDLING PROGRAM 
#include<stdio.h>
int main(){
    FILE* ptr ;
    char str[100];

    //create a file 

     ptr = fopen("example.txt","w");
    if (ptr == NULL){
       printf("ERROR to create a file \n");
    }
    else{
        printf("File created\n");
    }
    //fclose(ptr);

    //write 

    //char str[100];
    printf("enter data : ");
    fgets(str,sizeof(str),stdin);
    
    fprintf(ptr,"%s",str);
    fclose(ptr);

    //read the file 

    ptr = fopen("example.txt","r");
    if(ptr == NULL){
        printf("ERROR : could not open the file \n");
    }
    while(fgets(str,sizeof(str),ptr)!=NULL){
        printf("%s",str);
    }
    fclose(ptr);
    
    //append
    
     ptr = fopen("example.txt", "a");
    if (ptr == NULL) {
        printf("ERROR: Could not open file to append.\n");
        return 1;
    }

    printf("\nEnter data to append to the file: ");
    fgets(str, sizeof(str), stdin);
    fprintf(ptr, "%s", str);
    fclose(ptr);
}