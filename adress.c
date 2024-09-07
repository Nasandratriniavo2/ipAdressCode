#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "adress.h"
#include "annex.h"

int computerNumber(int hostBit)
{
    return(((int)pow(2,hostBit))-2);
}

char* getBroadcastAdress(char* ip,char* netmask)
{
    char* broadcastAdress = NULL;
    char* opposite = NULL;
    opposite = strMirror(opposite,netmask);
    broadcastAdress = orOperation(ip,opposite);
    return(broadcastAdress);
}

char* getNetworkAdress(char* ip,char* netmask)
{
    char* networkAdress = NULL;
    networkAdress = andOperation(ip,netmask);
    return(networkAdress);
}

char* convertToBinary(char* str)
{
    char* byte1 = strtok(str,".");
    char* byte2 = strtok(NULL,".");
    char* byte3 = strtok(NULL,".");
    char* byte4 = strtok(NULL,".");

    char* binaries = NULL;
    char* bin1 = binary(byte1);
    char* bin2 = binary(byte2);
    char* bin3 = binary(byte3);
    char* bin4 = binary(byte4);

    char* binaryString = malloc(33*sizeof(char));

    sprintf(binaryString,"%s%s%s%s\n",bin1,bin2,bin3,bin4);
    
    return(binaryString);
}

char* getNetmask(char* netmask)
{
    netmask = malloc(256*sizeof(char));
    ask:
    printf("Enter netmask adress:");
    scanf("%s",netmask);
    for(int i=0 ; i<strlen(netmask) ; i++)
    {
        if(netmask[i]!='.' && strchr("0123456789",netmask[i])==NULL)
            goto ask;
        else if(occurrenceNumber(netmask,'.') != 3)
            goto ask;
    }
    return(netmask);
}

char* getIp(char* ip)
{
    ip=malloc(255*sizeof(char*));
        ask:
    printf("Enter an IPv4 adress:");
    scanf("%s",ip);
    for(int i=0 ; i<strlen(ip) ; i++){
        if(ip[i]!='.' && strchr("0123456789",ip[i])==NULL)
            goto ask;
        else if(occurrenceNumber(ip,'.') != 3)
            goto ask;
    }
    return(ip);
}
