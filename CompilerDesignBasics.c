#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//keywords

char keyword [][10] = {"int","float","if","else","char"};

//function to check if word is a keyword

int isKeyword(char word[]){
    for(int i=0;i<5;i++)
    {
        if(strcmp(word,keyword[i])==0)
        {
            return 1; //  it is a keyword 
        }
    }
    return 0; //  it is not 
}

// funtion to check if a character is operator

int isOperator (char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>')
    {
        return 1;
    }
    return 0;
}

int main(){
    FILE *ptr;
    char ch;
    char word[50];
    int i = 0;

    // inputs from file 

    ptr = fopen("input.txt","r");
    if(ptr == NULL){
        printf("ERROR\n");
        return 1;
    }

    printf("Lexical Analysis\n");

    while((ch = fgetc(ptr)) != EOF){
    
        if(isalnum(ch)){
            word[i++] = ch;
        }
        else{
            word[i] = '\0';
            i = 0;
            // chech the word and print
            if(strlen(word)>0){
            
             if (isKeyword(word))
             {
                printf("Keyword: %s\n", word);
             }
             else {
                printf("Identifier: %s\n", word);
             }
        }
            // check if current character is an operator
         if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>') 
        {
            printf("Operator: %c\n", ch);
        }
      }
  }
    fclose(ptr);
    return 0;
}
    

