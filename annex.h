#ifndef __ANNEX_C__
#define __ANNEX_C__
    int occurrenceNumber(const char *str, char ch);
    char* strMirror(char* dest,char* src);
    char* binary(char* byte);
    char* andOperation(char* str1,char* str2);
    char* orOperation(char* str1,char* str2);
    int getHostBit(char* str);
    int decimal(char* str);
    int option();
    bool isValidNetmask(char* netmask);
#endif