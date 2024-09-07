#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "annex.h"
/* 
int decimal(char* str)
{
    int i, n = 7, power = 1;
    int decimal = 0;
    char* unity = malloc(10*sizeof(char));
    int unityBit = 0;
    
    
    for(i = 0; i<strlen(str); i++)
    {
        *unity = str[i];
        unityBit = atoi(unity);
        power = (int)pow(2,n) * unityBit;
        decimal += power;
        n--;
    }
    return(decimal);
}
 */
bool isValidNetmask(char* netmask) 
{    
    int i;
    bool seenZero = false;
    for (int i = 0; i < strlen(netmask); i++) 
    {
        if (netmask[i] == '0') 
            seenZero = true;
        else if (netmask[i] == '1' && seenZero) 
            return(false); 
    }

    return(true);
}

int option()
{
    int op;
    printf("Voulez vous aller dans quel exercice?\n");
    ask:
    printf("1-Exercice 1 ; 2-Exercice 2:");
    scanf("%d",&op);
    if(op > 2 || op <= 0)
        goto ask;
    return(op);
}

/* int decimal(char* str)
{
    int i, n = 7, power = 1;
    int decimal = 0;
    char* unity = malloc(10*sizeof(char));
    int unityBit = 0;
    
    
    for(i = 0; i<strlen(str); i++)
    {
        *unity = str[i];
        unityBit = atoi(unity);
        power = (int)pow(2,n) * unityBit;
        decimal += power;
        n--;
    }
    return(decimal);
} */

int getHostBit(char* str)
{
    int count = 0, i;

    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == '1')
            count++;
        else 
            break;
    }

    return count;
}

char* orOperation(char* str1,char* str2)
{
    int i;
    char* result = malloc(strlen(str1) * sizeof(char));
    for(i = 0; i < strlen(str1); i++)
    {
        if(str1[i] == '0' && str2[i] == '0')
            strcat(result,"0");
        else 
            strcat(result,"1");
    }  
    return(result);
}

char* andOperation(char* str1,char* str2)
{
    int i;
    char* result = malloc(strlen(str1) * sizeof(char));
    for(i = 0; i < strlen(str1); i++)
    {
        if(str1[i] == '1' && str2[i] == '1')
            strcat(result,"1");
        else 
            strcat(result,"0");
    }  
    return(result);
}

char* binary(char* byteToBinary)
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

    while(strlen(bin) != 8)
        strcat(bin,"0");
    byteToBinary=strMirror(tmp,bin);

    return(byteToBinary);    
}

char* strMirror(char* dest,char* src)
{
    int i,j;
    dest = malloc(strlen(src) * sizeof(char));
    for(i = 0, j = strlen(src) - 1; i < strlen(src) && j >= 0; i++, j--)
        dest[i]=src[j];
    return(dest);
}

int occurrenceNumber(const char *str, char ch)
{
    int count = 0;
    while(*str)
    {
        if(*str == ch)
            count++;
        str++;
    }
    return(count);
}