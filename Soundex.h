#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

char R(char c){
    if(c=='R'){
        return '6';
    }
    return '0';
}

char MN(char c){
    if(c=='N' || c=='M'){
        return '5';
    }
    return R(c);
}

char L(char c){
    if(c=='L'){
        return'4';
    }
   return MN(c);
}

char DT(char c){
    if(c=='D' || c=='T'){
        return '3';
    }
    return L(c);
}

char CGKKQSXZ(char c){
    if(c=='C' || c=='G' ){
        return '2';
    }
    return  DT(c);
}

char BFPV(char c){
    char c[]={'B','F','P','V'};
    for(int i=0;i<4;i++){
        if(c==char[i]){
            return '1';
        }
    }
    return CGKKQSXZ(c);
}

char getSoundexCode(char c) {
    c = toupper(c);
    return BFPV(c);
    
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
