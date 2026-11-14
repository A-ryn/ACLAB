#include<stdio.h>
void main(){
    char str[100];
    printf("message :");
    scanf("%s",str);
    printf("\nAND\n");
    for(int i=0;str[i]!='\0';i++){
        printf("%c",str[i]&127);
    }
    printf("\nOR\n");
    for(int i=0;str[i]!='\0';i++){
        printf("%02x",str[i]|127);
    }
    printf("\nXOR\n");
    for(int i=0;str[i]!='\0';i++){
        printf("%d",str[i]^127);
    }
    
}
