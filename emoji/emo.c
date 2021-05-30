#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
    
void showbits_ui( unsigned int x )
{
    int i=0;
    for (i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

void showbits_c( char x )
{
    int i=0;
    for( i = 0; i < 24; i++) {
	    if (i > 0 && i % 8 == 0) putchar(' ');
	    putchar('0');
    }
    putchar(' ');
    for (i = (sizeof(char) * 8) - 1; i >= 0; i--)
    {
       putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}


char *dCPA(int count,unsigned int cps[] ) {
	
	char *m = malloc(4 * count + 1);

	int i = 0;

        for (int j = 0; j < count; j++) {
	     unsigned int cp = cps[j];

		if (cp < 0x0080) {
		    m[i++] = 0x7F & cp;
		}
		if (cp > 0x007F && cp < 0x0800) {
		    m[i++] = ((0x7C0 & cp) >> 6) | 0xC0; 
		    m[i++] = (0x3F & cp)| 0x80;
		}
		if (cp > 0x07FF && cp < 0x10000) {
		    m[i++] = ((0xF000 & cp) >> 12) | 0xE0;            
		    m[i++] = ((0xFC0 & cp) >> 6)  | 0x80; 
		    m[i++] = (0x3F  & cp)| 0x80;
		}
		if (cp > 0xFFFF && cp < 0x110000) {

		   m[i++] = ((0x1C0000 & cp) >> 18) | 0xF0;
		   m[i++] = ((0x3F000 & cp) >> 12) | 0x80;
		   m[i++] = ((0xFC0 & cp) >> 6)  | 0x80;
		   m[i++] = (0x3F  & cp)| 0x80;
		}
	}
	m[i++] = 0;

	return m;
}

char *dCPV(int count, ...) {
	
	unsigned int  *cps = malloc(sizeof(unsigned int) * count);

	int i = 0;
	va_list args;
	va_start(args,count);

        for (int j = 0; j < count; j++) {
	     unsigned int cp = va_arg(args,unsigned int);
	     cps[j] = cp;
	}

	va_end(args);

	char *s = dCPA(count,cps);

	free(cps);

	return s;
}
