/**
 *
 * Exercise 1.21 - Write a Program entab that replaces strings of blanks by
 * the minimum number of tabs and blanks to achieve the same spacing.
 *
 * Use the same tab stops as for detab.
 *
 **/

#include<stdio.h>

#define TABINC 8

int main(void)
{
	int nb,nt,pos,c;
	
	nb = 0;
	nt = 0;
	
	for(pos=1;(c=getchar())!=EOF;++pos)
		if( c == ' ')
		{
			if((pos % TABINC) != 0)
				++nb;
			else
			{
				nb = 0;
				++nt;
			}
		}
		else 
		{
			for( ; nt > 0 ; --nt)
				putchar('\t');
			if( c == '\t')
				nb = 0;
			else
				for( ; nb > 0; --nb)
					putchar(' ');
			
			putchar(c);
			
			if(c == '\n')
				pos = 0;
			else if ( c == '\t')
				pos = pos + ( TABINC - (pos -1) % TABINC) - 1;
		}

	return 0;
}

/* Another solution, that implements the entab and reuses getline function. */ /*Remove the comment tags as required*/
// /**
//  * Exercise 1-21.
//  * Write a program entab that replaces strings of blanks by the
//  * minimum number of tabs and blanks to achieve the same spacing.
//  * Use the same tab stops as for detab.
//  * When either a tab or a single blank would suffice to reach a tab stop,
//  * which should be given preference?
// */

// #include <stdio.h>

// #define MAXLINE 1000
// #define TABSTOPLEN 8

// char line[MAXLINE];
// char entab_line[MAXLINE]; // no need to use these strings, just simple getchar and putchar!8676

// int getLine(void);
// void entab(void);

// main()
// {
//     int length;
//     while ((length = getLine()) > 0)
//     {
//         //printf("Normal line:\n%s", line);
//         entab();
//         printf("%s", entab_line);
//     }
// }


// int getLine(void) //uses global string: line
// {
//     extern char line[MAXLINE]; // REDUNDANT but doing it for practice
//     int ltr;
//     int iter;
//     for (iter = 0; ((iter < MAXLINE) && ((ltr = getchar()) != '\n') && (ltr != EOF)); ++iter)
//     {
//         line[iter] = ltr;
//     }
//     if ('\n' == ltr)
//     {
//         line[iter] = '\n';
//         ++iter;
//     }
//     line[iter] = '\0';

//     return iter;
// }
// /**
//  * Entab the input!
//  * Convert all the blank spaces to a tabs,
// */
// void entab(void)
// {
//     extern char line[MAXLINE];
//     extern char entab_line[MAXLINE]; // no need to use these strings, just simple getchar and putchar!8676

//     int track_length = 0;
//     int in_iter;
//     int out_iter = 0;
//     int blanks = 0;
//     int distance_from_tabstop= 0;
//     /**
//      * Need to understand where an extra blank is getting printed!
//     */
//     for (in_iter = 0; ((line[in_iter]) != '\0') ; ++in_iter )
//     {
//         track_length++; //we are incrementing here to show: we are on the 1st col. of the row
//         if (line[in_iter] == '\n')
//         {
//             entab_line[out_iter] = '\n';// = line[in_iter];
//             track_length = 0;
//             blanks = 0;
//         }
//         else if( line[in_iter] == ' ')
//         {
//             track_length--; // reduce to account for the blank detected!
//             //count amount of blanks next in the input sequnece
//             int temp_iter = in_iter;
//             while(line[temp_iter] == ' ')//increment the temp_iter till there is a non-blank character
//             {
//                 temp_iter++;
//             }
//             //temp_iter now has the no. of blanks in line after the encountered blank!
//             int blanks_available = temp_iter - in_iter;// if there are 3 blanks after the enocunter of the 1st balnk => balnks_availabale => 4!
//             distance_from_tabstop = TABSTOPLEN - (track_length % TABSTOPLEN);//note that tabstoplen = 4 => col.4 ot tracklength = 4 => is the tabstop.
//             while (blanks_available >= distance_from_tabstop)
//             {
//                 entab_line[out_iter] = '\t';
//                 out_iter++;
//                 blanks_available = blanks_available - distance_from_tabstop;
//                 track_length = track_length + distance_from_tabstop;
//                 distance_from_tabstop = TABSTOPLEN - (track_length % TABSTOPLEN);
//             }
//             while (blanks_available >0) //while (blanks_available) => can use this too!
//             {
//                 entab_line[out_iter] = ' ';
//                 out_iter++;
//                 track_length++;
//                 blanks_available--;
//             }
//             in_iter = temp_iter - 1; //we already read the blanks, so need not read that again and mess up the logic!
//         }
//         else
//         {
//             entab_line[out_iter] = line[in_iter];
//             out_iter++;
//             // track_length++;
//             blanks = 0;
//         }
//     }
//     out_iter++;
//     entab_line[out_iter];
// }
