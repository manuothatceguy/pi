#include <stdio.h>
int main(){
    unsigned char var, var1, var2, var3, var4;
    var = getchar();
    var1 = (var >> 6) & 0x03;
    var2 = (var >> 4) & 0x03;
    var3 = (var >> 2) & 0x03;
    var4 = var & 0x03;
    printf("%x %x %x %x\n", var1, var2, var3, var4);
    return 0;
}

/*
 * Se puede hacer al revés --> primero la máscara desp. el decalaje
 *
 * var1 = (0xC0 & var)>>6;
 * var2 = (0x30 & var)>>4;
 * var3 = (0x0C & var)>>2;
 * var4 = (0x03 & var);
 *
 */