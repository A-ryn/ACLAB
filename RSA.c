#include<stdio.h>
int power(int base,int exp,int mod){
    int res=1;
    while(exp>0){
        res=(res*base)%mod;
      exp--;
    }
    return res;
}
int gcd(int e,int z){
    if(e==0)
        return z;
    else
        return gcd(z%e,e);
}
void main(){
    int p=3,q=11,e,d,z,n,m,cipher,plain;
    n=p*q;
    z=(p-1)*(q-1);
    e=2;
    while(1){
      if(gcd(e,z)==1){
          break;
      }  
        e++;
    }
    printf("  encryption key  : %d",e);
    d=2;
   while(1){
int  k=(d*e)%z;
 if(k==1)
  break;
  d++;
}
    printf("  decryption key  : %d",d);
 printf("enter the messag(number bewteen 0 and 32 ) : ");
  scanf("%d",&m);
  //encryption
  cipher=power(m,e,n);
  //decryption
  plain=power(cipher,d,n);
  printf(" encrypted :%d \n dcerypted : %d \n",cipher,plain);
}
