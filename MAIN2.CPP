#include <iostream.h>
#include <conio.h>
#include <dos.h>


#define VIDEO 0x10




void scrollUpWorkaround(int lines, char x1, char y1) {
    for (int i = 0; i < lines; ++i) {
        gotoxy(x1, y1 + i);
        insline();
    }
    gotoxy(x1, y1);
    cputs("\r");
}


void scrollUp(int lines, char x1, char y1, char x2, char y2) {
    union REGS regs;

    regs.h.ah = 0x07;  // Scroll up function
    regs.h.al = lines; // Number of lines to scroll
    regs.h.bh = 0x07;  // Attr (def. color)
    regs.h.ch = x1; // Upper left row
    regs.h.cl = y1; // Upper left col
    regs.h.dh = x2; // Lower right row
    regs.h.dl = y2; // Lower right col

    int86(VIDEO, &regs, &regs);
    cputs("\r");
}


int main() {
    textbackground(BLACK);
    textcolor(WHITE);
    clrscr();

    window(20, 5, 60, 15);
    for (int i = 0; i <= 7; ++i) {
        textbackground(i);
	for (int j = 0; j <= 15; ++j) {
            textcolor(j);

            //scrollUp(3, 20, 15, 59, 19);

            scrollUpWorkaround(3, 20, 15);
	    cprintf("background: %d symbol: %i ", i, j);


	    delay(500);
        }
    }

    getch();
    return 0;
}