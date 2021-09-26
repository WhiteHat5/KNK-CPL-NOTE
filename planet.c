#include <stdio.h>
#include <ctype.h>

#define NUM_PLANETS 9

int case_unsensitive_compare (const char s1[], const char s2[]);

int main(int argc, char *argv[]) 
{
    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};
    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++)
            if (case_unsensitive_compare(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }
    return 0;
}

int case_unsensitive_compare (const char s1[], const char s2[])
{
	while(*s1){
		if(toupper(*s1) != toupper(*s2)) //여기서 바로 ++연산자 썼다가 '틀린 문자 바로 다음 문자가 같으면 문자열이 같다고 나오는' 오류가 떴었음 ㄷㄷ
			break;
		s1++; s2++;
	}
	
	return *s1 - *s2;
		
}