#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "adress.h"
#include "annex.h"
#include "classless.h"
#include "decoupage.h"

int main()
{
    int choice = option();
//Exercice 1
    char* cpyNetmask = malloc(8 * sizeof(char));
    char* cpyIp = malloc(8 * sizeof(char));
    char* ip = malloc(100 * sizeof(char));
    char* netmask = malloc(100 * sizeof(char));
    char* binaryNetmask =  malloc(32 * sizeof(char));
    char* binaryIp = malloc(32 * sizeof(char));
    int hostBit = 0;
//Exercice 2-1
    char* cidrIp = malloc(100 * sizeof(char));
    char* networkBit = malloc(2 * sizeof(char));
    char* classlessNetmask = malloc(32 * sizeof(char));
    char* binaryCidrIp = malloc(32 * sizeof(char));
//Exercice 2-2
    int nombreDecoupage = 0;

    if(choice == 1)
    {
        cpyNetmask = malloc(9 * sizeof(char));
        cpyIp = malloc(9 * sizeof(char));
        ip = getIp(ip);
        netmask = getNetmask(netmask);
        strcpy(cpyNetmask,netmask);
        strcpy(cpyIp,ip);
        binaryNetmask = convertToBinary(cpyNetmask);
        binaryIp = convertToBinary(cpyIp);
        hostBit = getHostBit(binaryNetmask);
        if (isValidNetmask(binaryNetmask))
        {
            printf("Ip adress:%s\n",binaryIp);
            printf("Netmask adress:%s\n",binaryNetmask);
            printf("Network adress:%s\n",getNetworkAdress(binaryIp,binaryNetmask));
            printf("Broadcast adress:%s\n",getBroadcastAdress(binaryIp,binaryNetmask));
            printf("Computer number:%d\n",computerNumber(hostBit));
        }
        else 
            printf("It's not a netmask.\n");
    
         
    }

    else
    {
        cidrIp = getClasslessIp(cidrIp);
        networkBit = getNetworkBit(cidrIp);
        classlessNetmask = getClasslessNetmask(networkBit);
        binaryCidrIp = convertToBinary(splitCidrIp(cidrIp));
        hostBit = getHostBit(classlessNetmask);

        printf("%s\n",classlessNetmask);
        printf("%s\n",binaryCidrIp);

        printf("Network adress:%s\n",getNetworkAdress(binaryCidrIp,classlessNetmask));
        printf("Broadcast adress:%s\n",getBroadcastAdress(binaryCidrIp,classlessNetmask));
        printf("Computer number:%d\n",computerNumber(hostBit));
        
        nombreDecoupage = decoupageNumber();
        printf("You have %d underNetwork\n",underNetwork(nombreDecoupage));  
        adresseReseauxEtBroadcast(cidrIp,nombreDecoupage);
    }
    return (0);
}