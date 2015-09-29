#include<stdio.h>
#include<ncurses.h>

typedef struct dot {
	unsigned char y;
	unsigned char x;
} DOT;

//block_data[types][orientations][dots]
const DOT block_data[7][4][4] =
{
	{
		{{2,0},{2,1},{2,2},{2,3}},	/*      */
		{{0,1},{1,1},{2,1},{3,1}},	/*      */
		{{2,0},{2,1},{2,2},{2,3}},	/* XXXX */
		{{0,1},{1,1},{2,1},{3,1}}	/*      */
	},
	{	
		{{1,1},{2,1},{1,2},{2,2}},	/*      */
		{{1,1},{2,1},{1,2},{2,2}},	/*  XX  */
		{{1,1},{2,1},{1,2},{2,2}},	/*  XX  */
		{{1,1},{2,1},{1,2},{2,2}}	/*      */
	},
	{
		{{1,0},{1,1},{1,2},{2,2}},	/*      */
		{{2,0},{0,1},{1,1},{2,1}},	/* XXX  */
		{{0,0},{1,0},{1,1},{1,2}},	/*   X  */
		{{0,1},{1,1},{2,1},{0,2}}	/*      */
	},
	{
		{{1,0},{2,0},{1,1},{1,2}},	/*      */
		{{0,0},{0,1},{1,1},{2,1}},	/* XXX  */
		{{1,0},{1,1},{0,2},{1,2}},	/* X    */
		{{0,1},{1,1},{2,1},{2,2}}	/*      */
	},
	{
		{{1,0},{1,1},{2,1},{2,2}},	/*      */
		{{1,0},{2,0},{0,1},{1,1}},	/* XX   */
		{{1,0},{1,1},{2,1},{2,2}},	/*  XX  */
		{{1,0},{2,0},{0,1},{1,1}}	/*      */
	},
	{	
		{{2,0},{1,1},{2,1},{1,2}},	/*      */
		{{0,0},{1,0},{1,1},{2,1}},	/*  XX  */
		{{2,0},{1,1},{2,1},{1,2}},	/* XX   */
		{{0,0},{1,0},{1,1},{2,1}}	/*      */
	},
	{
		{{1,0},{1,1},{2,1},{1,2}},	/*  X   */
		{{1,0},{0,1},{1,1},{2,1}},	/* XXX  */
		{{1,0},{0,1},{1,1},{1,2}},	/*      */
		{{0,1},{1,1},{2,1},{1,2}}	/*      */
	}
};		



void draw_block(WINDOW *win, int y, int x)
{	
	int i;
	DOT dot; 
		
	for (i = 0; i < 4; i++) {
		dot = block_data[2][1][i];
		wattrset(win, COLOR_PAIR(1));
		mvwprintw(win, y + dot.y, 2*(x + dot.x), "##");
	}
}	

int main() {
	WINDOW *w1, *w2;
	int ch;
	keypad(w1, TRUE);
	initscr();
	if(menu() == 0) {delwin( w1 );
		endwin();
		return 0;}
	w1 = newwin( 24, 32, 0, 0);
	box(w1, ACS_VLINE, ACS_HLINE);
	wrefresh( w1 );
	mvwprintw(w1, 0, 10, "GAME WINDOW");
	mvwprintw(w1, 20, 2, "Press 'q' to quit" );
wrefresh( w1 );
	init_pair(1, COLOR_RED, COLOR_YELLOW);
wrefresh( w1 );
	draw_block(w1, 2, 2);
	wrefresh( w1 );
	while(( ch = wgetch(w1)) != 'q');
	noecho();
	delwin( w1 );
	endwin();
}
