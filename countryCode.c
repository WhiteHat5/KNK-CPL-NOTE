#include <stdio.h>
struct dialing_code {
	char *country;
	int code;
};

const struct dialing_code country_codes[] = 
{   {"Argentina",             54},  {"Bangladesh",             880},
    {"Brazil",                55},  {"Burma (Myyanmar)",        95},
    {"China",                 86},  {"Colombia",                57},
 	{"Congo, Dem. Rep. of",  243},  {"Egypt",                   20}};


int main(void)
{
	int dial;
	for(;;) {
	printf("Enter a dialing code: ");
	
	scanf("%d", &dial);
	if(dial == 0)
		return 0;
	for(int i=0; i<sizeof(country_codes)/sizeof(country_codes[0]) ; i++) {
		if(dial == country_codes[i].code) {
			printf("Country is %s\n", country_codes[i].country);
			dial = -1;
			break;
		}
	}
	
	if(dial != -1)
		printf("NO SUCH CODE FOUND\n");
	
	}
}