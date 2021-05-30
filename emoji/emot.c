#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "emo.h"

int main( void )
{

    unsigned int arr[] = {0x1F92E,0x1F976,0x1F915};

    PR_EMOJIA(3,arr);
    PR_EMOJIV(2,0x1F355,0x1F382);

    PR_EMOJIV(3,0x1F382,0x1F382,0x1F382);

    PR_EMOJI(0x9060);

    PR_EMOJI(0x0154);

    PR_EMOJIV(2,0x1F1FA,0x1F1F8);

    PR_EMOJIV(4,0x1F3F3,0xFE0F,0x200D,0x1F308);

    PR_EMOJIV(4,0x2764,0xFE0F,0x200D,0x1F525 );

    
    PR_EMOJIVN(5,2,0x2764,0xFE0F);

    unsigned int emoji = 0x1F600;

    for (int i = 0; i < 16; i++ ) {
       PR_EMOJI(emoji+i);
    }

    return 0;
}
