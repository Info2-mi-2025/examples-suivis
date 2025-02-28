#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct {
    int words;
    int chars;
    int lines;
    int punctuations;
    char longest_word[64];
    int len_longest_word; // nombre de char du mot le plus long (option)
} Stats;

typedef struct{
    size_t length;
    bool in_word;
    char word[64];
} State;

void process_string(char* txt, Stats* stats, State* state){
    do{
        char c = *txt;
        txt++;
        if( c == '\0')
            break;

        // detection du début d'un mot
        if( !state->in_word && (isalpha(c) || c == '-') ){
            state->in_word = true;
            stats->words++;
            state->length = 0;
            state->word[state->length++] = c;
        }
        // détection de fin de mot
        else if( state->in_word && is_separator(c)){
            state->in_word = false;
            state->word[state->length] = '\0'; // attention marquer la fin du mot 
            if( state->length > strlen(stats->longest_word)){
            }
        }
        else if( isalpha(c) ){ // dans un mot
            state->word[state->length] = c;
            state->length++;
        }


        if( c == '\n')
            stats->lines++;

        stats->chars++;
    }while(true);

}

void check_args(int argc, char *argv[])
{
    for(int i = 0; i < argc; i++)
    {
        if( strcmp(argv[i], "--help") == 0){
            print_help();   
            exit(0);
        }
    }
}

int main(int argc, char *argv[]){
    // if( argc < 2 ){
    //     print_help();
    //     return 0; 
    // }

    //check_args(int argc, char *argv[]);

    State state = {0};
    Stats stats = {0};

    //while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
    //    process_string(buffer, &stats, &state);
   // }
   process_string(" Bonjour   , comment al", &stats, &state);
   process_string("lez vous ? ", &stats, &state);

    return 0;
}