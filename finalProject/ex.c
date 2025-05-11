/* boxdemo.c  –  draw a coloured box with ncurses ------------------------- */
#define _XOPEN_SOURCE_EXTENDED   /* for ncursesw wide-char functions */
#include <locale.h>
#include <curses.h>

int main(void)
{
    /* 1.  Start the library ------------------------------------------------*/
    setlocale(LC_ALL, "");      /* enable UTF-8 in the terminal */
    initscr();                  /* allocate stdscr & switch to alternate screen */
    cbreak(); noecho(); keypad(stdscr, TRUE);  /* raw-ish keyboard */
    curs_set(0);                /* hide cursor */

    /* 2.  Optional colour --------------------------------------------------*/
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED,   COLOR_BLACK);   /* foreground, background */
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
    }

    /* 3.  Draw a 10×30 rectangle at row 5, col 10 ------------------------- */
    attr_t redbold = COLOR_PAIR(1) | A_BOLD;
    wattr_on(stdscr, redbold, NULL);             /* enable attributes */

    for (int y = 0; y < 10; y+=5) {
        wmove(stdscr, 5 + y, 10);                /* each row start */
        for (int x = 0; x < 30; x+=4)
            waddch(stdscr, ' ');                 /* coloured “block” */
    }

    wattr_on(stdscr, COLOR_PAIR(2), NULL);       /* restore default */
    mvprintw(2, 2, "Press 'q' to quit.");        /* \n-style helpers are OK */

    wrefresh(stdscr);                            /* 4.  Flush to screen */

    /* 5.  Simple event loop -----------------------------------------------*/
    int ch;
    while ((ch = getch()) != 'q')
        ;                                        /* ignore everything else */

    /* 6.  Tear down --------------------------------------------------------*/
    endwin();                                    /* restore normal terminal */
    return 0;
}

