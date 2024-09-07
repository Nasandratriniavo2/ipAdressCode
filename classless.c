#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "adress.h"
#include "annex.h"

char* getClasslessNetmask(char* bitNetworkNUmber)
{
    int bitsNetworkNumber = atoi(bitNetworkNUmber);
    int i = 1;
    char* binaryNetmask = malloc(32 * sizeof(char));
    while(i <= 32)
    {
        if(i <= bitsNetworkNumber)
            strcat(binaryNetmask,"1");
        else
            strcat(binaryNetmask,"0");
        i++;
    }
    return(binaryNetmask);
}

char* splitCidrIp(char* cidrIp)
{
    int i;
    char* ip = malloc(32 * sizeof(char));

    for(i = 0; i<strlen(cidrIp); i++)
    {
        if(cidrIp[i] != '/')
        {
            char chr[1] = {cidrIp[i]}; 
            strcat(ip,chr);
        }
        else
            break;
    }
    return(ip);
}

char* getNetworkBit(char* cidrIp)
{
    int i;
    char* bitNetworkNUmber = malloc(2 * sizeof(char));
    
    for(i = 0; i<strlen(cidrIp) - 1; i++)
    {
        if(cidrIp[i] == '/')
            strcat(bitNetworkNUmber,&cidrIp[i+1]);
    }

    return(bitNetworkNUmber);
}

char* getClasslessIp(char* cidrIp)
{
    cidrIp = malloc(32*sizeof(char));
    ask:
    printf("Enter a CIDR Ip:");
    scanf("%s",cidrIp);
    if(strchr(cidrIp,'/') == NULL)
        goto ask;
    else if(occurrenceNumber(cidrIp,'.') != 3)
        goto ask;
    else if(atoi(getNetworkBit(cidrIp)) > 32)
        goto ask;
    return(cidrIp);
}