#include<stdio.h>
void main(){
  char key[]="qwertyuiopasdfghjklzxcvbnm";
  char msg[100];
  char cipher[100];
  char plain[100];
  printf("mesage : ");
  scanf("%s",msg);
  for(int i=0;msg[i]!='\0';i++){
    cipher[i]=key[msg[i]-'a'];
  }
  printf(" cipher : %s",cipher);

  for(int i=0;cipher[i]!='\0';i++){
    for(int j=0;j<26;j++){
      if(cipher[i]==key[j])
        plain[i]=j+'a';
    }
    
  }
  printf("\nplain : %s",plain);
}
