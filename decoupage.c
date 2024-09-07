#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "adress.h"
#include "annex.h"
#include "classless.h"
#include "decoupage.h"

char* getNetworkPart(char* cidrIp)
{
    int i = 0;
    char* networkBit = malloc(2 * sizeof(char));
    networkBit = getNetworkBit(cidrIp);
    cidrIp = convertToBinary(cidrIp);
    char* tmp = malloc(32 * sizeof(char));

    while(i < atoi(networkBit))
    {
        tmp[i] = cidrIp[i];
        i++;
    }
    return(tmp);
}

void adresseReseauxEtBroadcast(char* cidrIp,int number)
{
    int i = 0;
    char* tmp = malloc(32 * sizeof(char));
    int count = 0;
    char* tmp2 = malloc(32 * sizeof(char));
    char* ajout;
    char* netPart = getNetworkPart(cidrIp);
    char* tmp3 = malloc(32 * sizeof(char));

    for(i = 0; i < pow(2,number); i++)
    {
        strcpy(tmp,netPart);  
        strcpy(tmp3,netPart);      
                
        sprintf(tmp2,"%d",count);
        ajout = binaryNBits(tmp2,number);     
        count++;
        strcat(tmp,ajout);
        strcat(tmp3,ajout);

        while (strlen(tmp) != 32)
            strcat(tmp,"0");
        while (strlen(tmp3) != 32)
            strcat(tmp3,"1");
        
        printf("Les adresses réseaux de chaque sous réseaux:");
        printf("%s\n",tmp);
        printf("Les adresses broadcast de chaque sous réseaux:");
        printf("%s\n",tmp3);
        printf("\n");

    }   
}
    
char* binaryNBits(char* byteToBinary,int decoupe)
{
    int i,j;
    int bytes = atoi(byteToBinary);
    int reste = 0;  
    int quotient = 1;

    char bin[9] = "";
    char restes[10];
    char tmp[9];
    
    
    quotient = bytes;
    
    while(quotient != 0)
    {
        reste = quotient % 2;
        sprintf(restes,"%d",reste);
        quotient /= 2;
        strcat(bin,restes); 
    }

    while(strlen(bin) != decoupe)
        strcat(bin,"0");
    byteToBinary=strMirror(tmp,bin);

    return(byteToBinary);    
}

/* void combinaison(int n)
{
    int i;
    int count = 0;
    char tmp [100];
    for(i = 0;i< pow(2,n); i++)
    {
        sprintf(tmp,"%d",count);
        printf("temp for i=%d -> %s\n",i,tmp);
        printf("%s\n",binaryNBits(tmp,n));     
        count++;
    }
}
 */
int underNetwork(int decoupe)
{
    return((int)pow(2,decoupe));
}

int decoupageNumber()
{
    int decoupage;
    printf("How often do you decoupe:");
    scanf("%d",&decoupage);
    return(decoupage);
}