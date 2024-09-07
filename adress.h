#ifndef __ADRESS_C__
#define __ADRESS_C__
    char* getIp(char* ip);
    char* getNetmask(char* netmask);
    char* convertToBinary(char* str);
    char* getNetworkAdress(char* ip,char* netmask);
    char* getBroadcastAdress(char* ip,char* netmask);
    int computerNumber(int hostBit);
#endif