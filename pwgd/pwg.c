#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define NUM_PEOPLE 4
#define DEBUG_STMT(stmt) printf("%s line %d\n",stmt,__LINE__)
#define PRINT_FR_INT(func,name) printf("%d %s\n",func,name)
#define PRINT_I(number) printf("%d\n",number)
#define PRINT_UL(number) printf("%lu\n",number)



int *randomNumberList(size_t length, int maxnum, unsigned int seed) {


    time_t t;

    int *list = calloc(length, sizeof(int));

    srand(seed);

    for(int ii = 0; ii < length; ii++) {
        list[ii] = rand() % maxnum;
    }

    return list;
}




char *fillBufferWChar(char x, size_t bufsize) {

    char *buffer = (char *)calloc(bufsize, sizeof(char));

    char *bufferstart = buffer;

   for(int ii = 0; ii < bufsize; ii++) {
        *(bufferstart++) = x;
    }

    return buffer;

}


char *generateWordList(const char *letters, size_t numberofwords, size_t wordsize) {

    size_t wordspace = wordsize + 1;

    size_t bufsize =  numberofwords * wordspace;

    char *wordlist = (char *)calloc(bufsize, sizeof(char));

    int length = strlen(letters);


    unsigned int seed  = 0;

    for(int ii = 0 ; ii < length; ii++) {
        seed+=letters[ii];
    }

    int *randomnumbers = randomNumberList(bufsize, length, seed);

    char *bufferstart = wordlist;

    for(int ii = 0; ii < bufsize; ii++) {
        if(wordsize > 0 && ((ii + 1) % wordspace) == 0)
            *(bufferstart++) = '\n';
        else
            *(bufferstart++) =letters[randomnumbers[ii]];
    }

    free(randomnumbers);

    return wordlist;

}


int main(int argc, char **argv) {

    char *letters = "abcdefghijklmnopqrstuvwxyz";
    char *wordlist = NULL;
    int numberofwords = 10;
    int wordsize = 10;
    int c;
    if (argc < 2)
        printf("Usage: pwg -[lnw]\n");

    while ((c = getopt (argc, argv, "l:n:w:")) != -1) {
        switch (c)
        {
        case 'l':
            letters  = optarg;
            break;
        case 'n':
            numberofwords = atoi(optarg);
            break;
        case 'w':
            wordsize = atoi(optarg);
            break;
        case '?':
            if (optopt == 'c')
                fprintf (stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint (optopt))
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf (stderr,
                         "Unknown option character `\\x%x'.\n",
                         optopt);
            break;
        }

    }

    wordlist = generateWordList(letters,numberofwords,wordsize);

    printf("%s",wordlist);

    free(wordlist);

    return(0);
}

