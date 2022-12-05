/**********************************************************
** Program: 
** Author: 
** Date: 
** Description: 
***********************************************************/

#include <iostream>
#include <sys/time.h>
using namespace std;

/* Defined below main() */
void elapsed_time(timeval start, timeval stop);
int fib_iter(int n);

/* Implement this function */
/* Assume n >= 0 */
int fib_recur(int n) {
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fib_recur(n-1)+fib_recur(n-2);

}
int n_digits(int n){
	if(n == 0)
		return 0;
	else
		return n_digits(n/10)+1;
}

int main()
{
  timeval stop, start;
	
 /* prompt user for a number to use */
	int a = 0,b = 0;
	cout << "Enter a number: ";
	cin >> a;
	cout << "Enter a number: ";
	cin >> b;
  gettimeofday(&start, NULL); 
  /* Call the iterative function here with the user's number and
   * report the result. */
  fib_iter(a);
  gettimeofday(&stop, NULL); 
  cout << "Iterative runtime ";
  elapsed_time(start, stop);

  gettimeofday(&start, NULL); 
  /* Call your recursive function here with the user's number and 
   * report the result. */
  cout << fib_recur(a) << endl;
  cout << n_digits(b) << endl;
  gettimeofday(&stop, NULL); 
  cout << "Recursive runtime ";
  elapsed_time(start, stop);

  return 0;
}

/****************** Function definitions **************/

/* Compute elapsed time, given a start and stop */
void elapsed_time(timeval start, timeval stop) {
  if (stop.tv_sec > start.tv_sec) 
    cout << "(seconds): " << stop.tv_sec-start.tv_sec << endl; 
  else 
    cout << "(microseconds): " << stop.tv_usec-start.tv_usec << endl; 
}


/* For non-negative n, compute and return the nth Fibonacci number. 
 * This is the iterative solution */
int fib_iter(int n) {
  int cur_fib = 0;  
  /* set up preceding Fibonacci numbers for n = 1 */
  int fib_minus_1 = 0; /* F0 = 0 */
  int fib_minus_2 = 1; /* F-1 doesn't exist but enables the loop */
  /* Loop from 1 to n; if n is 0, cur_fib is already set */
  for (int i = 1; i <= n; i++) {
    cur_fib = fib_minus_1 + fib_minus_2;
    /* shift values */
    fib_minus_2 = fib_minus_1;
    fib_minus_1 = cur_fib;
  }
  return cur_fib;
}

