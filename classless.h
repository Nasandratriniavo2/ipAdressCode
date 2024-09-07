#ifndef __CLASSLESS_C___
#define __CLASSLESS_C__
    char* getClasslessIp(char* cidrIp);
    char* getNetworkBit(char* cidrIp);
    char* splitCidrIp(char* cidrIp);
    char* getClasslessNetmask(char* bitNetworkNUmber);
    int decoupageNumber();
    int underNetwork(int decoupe);
#endif