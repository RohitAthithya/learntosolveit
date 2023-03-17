/**
 * Exercise 1.20 -
 *
 * Write a Program detab, which replaces tabs in the input with a proper
 * number of blanks to spaces
 *
 **/


#include<stdio.h>

#define TABINC 8

int main(void)
{
	int nb,pos,c;

	nb = 0;
	pos = 1;

	while((c=getchar())!=EOF)
	{
		if( c == '\t')
		{
			nb = TABINC - (( pos - 1) % TABINC);

			while( nb > 0)
			{
				putchar('#');
				++pos;
				--nb;
			}
		}
		else if( c == '\n')
		{
			putchar(c);
			pos = 1;
		}
		else
		{
			putchar(c);
			++pos;
		}
	}

	return 0;
}

/* //another solution

say for 4 tabstops:
tabstops look like this:
____|____|____|    (they stop at every 4 instances!)

_ represents where the input needs to go!

for 8 tabstops:
tabstops look like this:
________|________|________|    (they stop at every 8 instances!)


*/
/*
#include <stdio.h>

#define TABSTOPLEN 4

main()
{
    int chr;
    int track_length = 0; // to track the length of input
    int curr_pos;
    while ((chr = getchar()) != EOF)
    {
        track_length++;
        // need to handle only tabspaces and newlines -- otherwise just print the input character
        if (chr == '\n')
        {
            // print the next line and reset the track_length
            putchar(chr);
            track_length = 0;
        }
        else if (chr == '\t')
        {
            // check the current location - where is it from the previous tabstop
            curr_pos = (track_length % TABSTOPLEN);
            while (curr_pos != 0) //
            {
                putchar(' ');
                track_length++;
            }
            // extra space is to be put to compensate the loss in logic
            putchar(' ');
        }
        else
        {
            putchar(chr);
        }
    }
}


*/
