//diffie hellman key exchange
#include<stdio.h>
int power(int base,int exp,int mod){
    int result=1;
    while(exp>0){
        result=(result*base)%mod;
        exp--;
    }
    return result;
}
void main(){
int g=6,p=23;
int alice_prk=4,bob_prk=7;
int alice_pbk,bob_pbk;
alice_pbk=power(g,alice_prk,p);
bob_pbk=power(g,bob_prk,p);
printf("alice publickey :%d \n bob public key : %d",alice_pbk,bob_pbk);
//share public key 
//calculate secrete key
int alice_sk=power(bob_pbk,alice_prk,p);
int bob_sk=power(alice_pbk,bob_prk,p);
 printf("alice secret key :%d \n bob secret key : %d",alice_sk,bob_sk);
    
}
