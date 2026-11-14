#include<stdio.h>
int hashing(unsigned char *text){
    int hash=0;
    for(int i=0;text[i]!='\0';i++){
        hash=(hash*31+text[i])%17;
    }
    return hash;
}
int sign(int hash, int d,int n){
  int result=1;
  for(int i=d;i>0;i--){
  result=(result*hash)%n;

}
return result;
}
int gcd(int e,int z){
    if(e==0)
        return z;
    else
        return gcd(z%e,e);
}
void main(){
    unsigned char text[]="heolo";
    int hash=hashing(text);
    printf(" hash is %d",hash);

    int p=7,q=11,e=2,d=1,n,z;
    n=p*q;
    z=(p-1)*(q-1);
    while(1){
      int g=gcd(e,z);
      if(g==1)
        break;
      e++;

    }
    printf("\n encryption key  : %d",e);

 while(1){
int  k=(d*e)%z;
 if(k==1)
  break;
  d++;
}
printf("\n decryption key :%d",d);
//encryption sigining using d key
int signature=sign(hash,d,n);
printf(" \n  signed hash to signatures : %d",signature);
    while(1){
        printf("\n 1 to tmaper \n 2 to not \n 3 to exit ");
        int choice;
        scanf("%d",&choice);
        if(choice==1){
            printf("eneter the tmapered hash value ");
       
            scanf("%d",&hash);
            
        }
    //decrypt the sign
int newhash=sign(signature,e,n);
    if(newhash==hash){
        printf("\nvalid ");
    }
    else{
        printf("\ninvalid");
    }
        break;
    }
    }
