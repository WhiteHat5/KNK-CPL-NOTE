/* 파츠 데이터 베이스를 관리한다 (배열 버전) */
/* 
	changelog 1.1.
	이제 파츠는 파츠번호를 기준으로 정렬되어 데이터베이스에 입력됩니다

	changelog 1.2.
	파츠 구조체에 가격을 표현하는 price멤버를 추가했습니다
	이제 c 커맨드로 가격을 수정할 수 있습니다
*/
#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	double price; //1.2. 가격을 의미하는 멤버 추가
} inventory[MAX_PARTS+1];

//1.1 p가 파츠들을 파츠 넘버 순서대로 정렬해서 출력하게 만들어라
//1.2 part 구조체에 price 멤버를 더하라. insert는 이제 사용자에게 가격을 물어본다. search 와 print 는 가격도 출력한다. 가격을 변경할 수 있는 커맨드도 더해라

int num_parts = 0; /* 현재 저장된 파츠의 개수 */

int find_part (int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void price_change(void); //1.2.가격을 변경하기 위한 함수

/*************************************************************
  main: 사용자가 커맨드를 입력하게 하고 커맨드에 맞는 함수를 불러온다 
  사용자가 'q'커맨드를 입력할 때까지 프롬프트를 반복한다.            
  잘못된 커맨드를 입력하면 에러메세지를 출력한다                    
 *************************************************************/
int main(void)
{
	char code;
	for (;;) {
		printf("커맨드를 입력하세요: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* 나머지 입력을 모두 무시 */
			;
		switch(code) {
			case 'i': insert();
					  break;
			case 's': search();
					  break;
			case 'u': update();
					  break;
			case 'p': print();
					  break;
			case 'c': price_change(); //가격 변경 커맨드
					  break;
			case 'q': return 0;
			default: printf("잘못된 커맨드입니다\n");
		}
		printf("\n");
	}
}

/**************************************************
	find_part: inventory 배열에서 파츠 번호를 찾는다.
	파츠 번호를 찾으면 파츠의 배열 인덱스를 반환한다.
	찾지 못하면 -1을 반환한다.
***************************************************/
int find_part(int number)
{
	int i;
	
	for(i = 0; i < num_parts; i++) 
		if(inventory[i].number == number)
			return i;
	return -1;
}

/*********************************************************************************
	insert: 사용자에게 새로운 파츠에 대한 정보를 입력하게 하고 파츠를 데이터베이스에 넣는다.
	파츠가 이미 존재하거나 데이터베이스가 가득 찼으면 에러를 출력한다.
**********************************************************************************/
void insert(void)
{
	int part_number;
	
	if (num_parts == MAX_PARTS) {
		printf("데이터베이스가 가득 찼습니다; 더이상 파츠를 추가할 수 없습니다.\n");
		return;
	}
	
	printf("파츠 번호를 입력하세요: ");
	scanf("%d", &part_number);
	if(find_part(part_number) >= 0) {
		printf("이미 존재하는 파츠입니다.\n");
		return;
	}
	
	inventory[num_parts].number = part_number;
	printf("파츠 이름: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("파츠 개수를 입력하세요: ");
	scanf("%d", &inventory[num_parts].on_hand);
	//1.2. 가격을 입력하는 라인 추가
	printf("파츠 가격을 입력하세요: ");
	scanf("%lf", &inventory[num_parts].price);
	
	//1.1. 이후 코드는 정렬을 위한 코드 
	for (int i = 0; i < num_parts; i++) {
		if (inventory[num_parts].number < inventory[i].number) {
			for(int j = num_parts ; j >= i; j--) {
				inventory[j+1] = inventory[j];
			}
			inventory[i] = inventory[num_parts+1];
		}
	}
	//1.1. 여기까지 정렬을 위한 코드
	
	num_parts++;
}

/*********************************************************
	search: 사용자에게 파츠 번호를 입력하게 하고 데이터베이스에서
	파츠를 검색한다. 파츠가 존재하면 파츠 이름과 개수를 출력한다.
	존재하지 않을 시 에러메세지를 출력한다.
**********************************************************/
void search(void)
{
	int i, number;
	
	printf("파츠 번호를 입력하세요: ");
	scanf("%d", &number);
	i = find_part(number);
	if(i >= 0){
		printf("파츠 이름: %s\n", inventory[i].name);
		printf("개수: %d\n", inventory[i].on_hand);
		printf("가격: $%f\n", inventory[i].price); //1.2. 가격을 출력하는 라인 추가
	} else
		printf("요청한 파츠를 찾을 수 없습니다\n");
}

/*********************************************
	update: 사용자에게 파츠 번호를 입력하게 한다.
	파츠가 존재하지 않으면 에러메세지를 출력한다.
	파츠가 존재하면 개수의 변화를 입력하게 한 뒤
	데이터베이스를 업데이트한다.
**********************************************/
void update(void)
{
	int i, number, change;
	
	printf("파츠 번호를 입력하세요: ");
	scanf("%d", &number);
	i = find_part(number);
	if(i >= 0) {
		printf("개수의 변화를 입력하세요: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	} else
		printf("요청한 파츠를	찾을 수 없습니다\n");
}

/*********************************************************
	print: 데이터베이스에 있는 모든 파츠를 출력한다.
	파츠 번호, 파츠 이름, 파츠 개수를 출력합니다.
	파츠는 데이터베이스에 입력된 순서대로 출력됩니다.
**********************************************************/
void print(void)
{
	int i;
	
	printf("파츠 번호     파츠 이름                    "
		   "파츠 개수  파츠 가격\n");
	for (i = 0; i < num_parts; i++)
		printf("%8d  %-25s%11d%11.1f\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price); //1.2.가격을 나타냄
}

void price_change(void)
{
	int i, number;
	double change;
	
	printf("파츠 번호를 입력하세요: ");
	scanf("%d", &number);
	i = find_part(number);
	if(i >= 0) {
		printf("가격의 변화를 입력하세요: ");
		scanf("%lf", &change);
		inventory[i].price += change;
	} else
		printf("요청한 파츠를	찾을 수 없습니다\n");
}