#include <stdio.h>

int main()
{
    char terminating_character;
    char sentence[40];
    const char charset[3] = {'.' , '!', '?'};
    int end, i;
    
    printf("Enter a sentence: ");
    for(i=0; i<40; i++){
        sentence[i] = getchar();
        if(sentence[i] == charset[0] || sentence[i] == charset[1] || sentence[i] == charset[2]){
            terminating_character = sentence[i];
            end = i;
            break;
        }
    }
    while(getchar()!='\n');
    
   
    printf("Reversal of sentence: ");
    do{
        if(sentence[i] == ' '){
            for(int j = i+1 ; j < end; j++){
                putchar(sentence[j]);
            }
            putchar(sentence[i]);
            end = i;
        }
    } while(--i);
   
    for(int j=0; j<end; j++){
        putchar(sentence[j]);
    }
 
    putchar(terminating_character);
    return 0;
}
