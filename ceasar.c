//ceasar cipher
#include<stdio.h>
void main(){
    unsigned char msg[1024];
    int key;
    printf("message :");
    scanf("%s",msg);
    printf("key : ");
    scanf("%d",&key);
    for(int i=0;msg[i]!='\0';i++){
        if(msg[i]>='A' && msg[i]<='Z')
            msg[i]=((msg[i]-'A'+key)%26)+'A';
        else if(msg[i]>='a' && msg[i]<='z')
            msg[i]=((msg[i]-'a'+key)%26)+'a';
    }
    printf("encrypted : %s",msg);
    for(int i=0;msg[i]!='\0';i++){
        if(msg[i]>='A' && msg[i]<='Z')
            msg[i]=((msg[i]-'A'-key+26)%26)+'A';
        else if(msg[i]>='a' && msg[i]<='z')
            msg[i]=((msg[i]-'a'-key+26)%26)+'a';
    }
    printf("\ndecrypted : %s",msg);
    
}
