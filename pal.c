
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"
#include <conio.h>
#include <stdlib.h>

//--------------------------------------------------
// gen_num
//--------------------------------------------------
int gen_num(int lb, int ub) {
	//1. We create the output variable with an initial value.
	int res = 0;

	//2. We assign num to a random value in the desired range
	res = (rand() % (ub - lb)) + lb;

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char my_get_char() {
	//1. We create the output variable with the value the user has input by keyboard
	char res = getchar();

	//2. We discard any extra character the user has input by keyboard
	boolean finish = False;
	char dummy_char = ' ';

	while (finish == False) {
		dummy_char = getchar();
		if (dummy_char == '\n')
			finish = True;
	}

	//3. We return the output variable
	return res;
}

//--------------------------------------------------
// initialise_array
//--------------------------------------------------
void initialise_array(int a[6], int num) {
    int i = 0;
	while (i < 6)
	{
		a[i] = num % 10;
        num /= 10;
		i ++;
	}

}

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {

	boolean b = False;
int count  = 0;
	int i = 0;
	int last_index = 5;
	int check = 0;
    int elm_at_index = elm_at_index = last_index - i;

void check_fucntion( ) {

do {
		if (a[i]== a[elm_at_index]) {
           i++;
          check++;
          elm_at_index--;

          b = False;
          if (check  == 3){
            b = True;
          }
		}else{

         b = False;
         if (check > 0)
         check= 0;
         i = 0;
		}

count++;

}while (count < 3);

}
check_fucntion();







	return b;

}


//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
	char res = ' ';




printf("NEW MOVEMENT: Enter a valid command by keyword: ");
printf("\nValid commands are: a ,d, w, x\n");
printf("\n b ---> Move Right");
printf("\n\n a <--- Move Left ");
printf("\n\n w ^    Increase Num");
printf("\n   |  ");
printf("\n   | ");
printf("\n x V    Decrease Num\n\nCOMMAND    ");

res = my_get_char();



	return res;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int a[6], int** p_p, int* p_nm, char c){


    int* first_index = &a[0];
    int* last_index = &a[5];
    int max = 9;
    int min = 0;

    if ((**p_p == max) ||(**p_p == min) ||((*p_p) ==first_index) ||((*p_p) ==last_index)){

			system("cls");
		}
		else if (c != 'a' ||'A' || c  != 'w' || c  != 'd' || c != 'x'){

		system("cls");

		}

	switch (c) {

	case'a':
    case'A':
	         {

		if ((*p_p) >first_index ) {

			*p_p-=1;
			++*p_nm;

           system("cls");

		}
		break;
	}
	case 'd':
	case 'D':

		if ((*p_p) < (last_index)) {

			*p_p+=1;
			++*p_nm;

system("cls");

		}
		break;

	case 'w':
	case 'W':

		if (**p_p < max) {

			++**p_p;
			++*p_nm;

			system("cls");
		}
		break;

	case 'x':
	case 'X':

		if (**p_p > min) {

			--**p_p;
			++*p_nm;

            system("cls");

		}
		break;
	}



}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {

      int i;
      int* ptr_index =&a[0];
      //printf("vl = %d - % d", a[0],*p);
      int index = p - ptr_index;

	printf("\n======== Game Status ==========\n");

	printf(" NUMBERS = [ ");

	for (i = 0; i < 6; i++) {
		printf("%d  ", a[i]);//3 characters
	}
	printf("]\n");


    printf("             ");
	for (i = 0; i < ( 3* index); i++)//create 3 character spaces same as above{jump}

    printf(" ");// position the arrow right under the correct index
	printf("^");
	printf("\n");

	printf(" MOVES = %d\n", nm);
	//printf("vl = %d" , index);

	printf("===============================\n");
	}



//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {

	int a[6];
	initialise_array(a, pal_num);
	int* ptr_index = a + gen_num(0, 6);
	int moves = 0;



	print_status(a, ptr_index, moves);


	do {
        system("COLOR 0A");

		process_movement(a, &ptr_index, &moves,ask_for_command());

		print_status(a, ptr_index, moves);
          is_pal(a);

	}while (is_pal(a) == False );


	printf("\n===============================\n");
	printf("=========== SOLVED! ===========\n");
	printf("===============================\n");

}

