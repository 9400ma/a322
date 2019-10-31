/* Magni Jogvansson Hansen */
/* mjha19@student.aau.dk */
/* A322 Software*/

#include <stdio.h>
#include <math.h>

void run_calculator(); /* everthing runs in this function, so that int main(void) doesn't get flooded with too many function */
void scan_data(char *operator, double *opperand); /*scans for what has been written and if there needs to scanned for an opperand */
void do_next_op(char operator, double opperand, double *akkumlator); /* checks for what calculation function it shall call, depending on the operator */

/* all function for calculation depending on which operator is writte */
double addition(double opperand,double akkumlator);
double subtraktion(double opperand, double akkumlator);
double multiplikation(double opperand, double akkumlator);
double division(double opperand, double akkumlator);
double potensoploftning(double opperand, double akkumlator);
double kvadratroden(double akkumlator);
double vende_fortegnet(double akkumlator);
double dividered_med_et(double akkumlator);

/* prints all operators out, */
void help();

int main(void){
  run_calculator();
  return 0;
}

void run_calculator(){
  char operator;
  double akkumlator = 0.0, opperand = 0.0;
  
  printf("type h for info about operators\n");
  do {
    printf("Enter operator, and an optional operand:");
    scan_data(&operator, &opperand);
    if (operator == 'h' || operator == 'H')
      help();
    else if (operator != 'q' || operator != 'Q') {
      do_next_op(operator, opperand,&akkumlator);
      printf("Result so far is: %lf\n",akkumlator);
    }
    else {
      printf("final result is: %lf\n", akkumlator);
    }
    fflush(stdin);
  } while(operator != 'q' && operator != 'Q');
}

void scan_data(char *operator, double *opperand) {
  char LocalOperator;
    
  scanf("%c",&LocalOperator);
  if (LocalOperator == '+' || LocalOperator == '-'  || LocalOperator == '*' || LocalOperator == '/' || LocalOperator == '^'  ) {
    scanf("%lf", opperand);
    *operator=LocalOperator;
  }
  else {
    *operator=LocalOperator;
    *opperand=0.0;
  }
}

void do_next_op(char operator, double opperand, double *akkumlator) {
  if (operator == '+') {
    *akkumlator=addition(opperand,*akkumlator);
  }
  else if (operator == '-') {
    *akkumlator=subtraktion(opperand, *akkumlator);
  }
  else if (operator == '*') {
    *akkumlator=multiplikation(opperand, *akkumlator);
  }
  else if (operator == '/' && opperand != 0) {
    *akkumlator=division(opperand, *akkumlator);
  }
  else if (operator == '^') {
    *akkumlator=potensoploftning(opperand, *akkumlator);
  }
  else if (operator == '#' && *akkumlator >0){
    *akkumlator=kvadratroden(*akkumlator);
  }
  else if (operator == '%') {
    *akkumlator=vende_fortegnet(*akkumlator);
  }
  else if (operator == '!' && *akkumlator != 0) {
    *akkumlator=dividered_med_et(*akkumlator);
  }
  else if (operator == 'c')
    *akkumlator=0.0;
  else {}
}

double addition(double opperand,double akkumlator) {
  return akkumlator+opperand;
}

double subtraktion(double opperand, double akkumlator) {
  return akkumlator-opperand;
}

double multiplikation(double opperand, double akkumlator) {
  return akkumlator*opperand;
}

double division(double opperand, double akkumlator) {
  return akkumlator/opperand;
}

double potensoploftning(double opperand, double akkumlator) {
  return pow(akkumlator,opperand);
}

double kvadratroden(double akkumlator) {
  return sqrt(akkumlator);
}

double vende_fortegnet(double akkumlator){
  return akkumlator * -1;
}

double dividered_med_et(double akkumlator) {
  return 1/akkumlator;
}

void help() {
  printf("'+' is for adding\n");
  printf("'-' is for subtrackting\n");
  printf("'*' is for multiplying\n");
  printf("'/' is for dividing\n");
  printf("'^' is for exponenting\n");
  printf("'#' is for squareroot\n");
  printf("'%%' is for flipping the sign\n");
  printf("'!' is for dividing with one\n");
  printf("'q' is for stopping the program\n");
}
