#include <stdio.h>
#include <ctype.h>

int main()
{
    int seen[26] = {0};
    int i;
    char ch;
    
    printf("Enter first word: ");
    while (isalpha(ch = getchar())) {
        seen[tolower(ch) - 'a'] ++;
    }
    
    ///while((ch = getchar())!= '\n');
    
    printf("\nEnter second word: ");
    while (isalpha(ch = getchar())) {
        seen[tolower(ch) - 'a'] --;
    }
    
    printf("\nThe words are ");
    for(i=0; i<26; i++){
        if(seen[i]!=0){
            printf("not anagrams\n");
            return 0;
        }
    }
    printf("anagrams\n");
    
    return 0;
}
