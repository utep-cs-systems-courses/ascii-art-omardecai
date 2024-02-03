#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = r, Square = s, Chars = c or w, Arrow = t) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;
 
    // Given the user answer, select which method to call
    switch (c) {
    case 'r':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:");
      for (char c = 'A'; c < 'D'; c++)
	print_char_11x16(c);
      break;
    case 'w':
      puts("You selected 5x7 font:");
      for (char w = 'A'; w < 'D'; w++)
	print_char_5x7(w);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case 't':
      puts("You selected arrow:");
      print_arrow(5,7);
      break;
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
