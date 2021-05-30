/*emo.h*/

void showbits_ui( unsigned int x );
void showbits_c( char x );
char *dCPA(int count,unsigned int cps[] ); 
char *dCPV(int count, ...); 

#define PR_EMOJI(x) {char *s; s = dCPV(1,x); printf("%s\n",s); free(s);}
#define PR_EMOJIV(count,...) {char *s; s = dCPV(count,__VA_ARGS__); printf("%s\n",s); free(s);}
#define PR_EMOJIVN(n,count,...) {char *s; s = dCPV(count,__VA_ARGS__); for(int i = 0; i < n; i++) printf("%s\n",s); free(s);}
#define PR_EMOJIA(count,cps) {char *s; s = dCPA(count,cps); printf("%s\n",s); free(s);}
