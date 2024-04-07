#ifndef __trisLents_H_
#define __trisLents_H_
int** allouer(int N);
void fill_tab(int** tab, int N);
void show_tab(int** tab, int N);
void swap(int** tab, int x,int y,int i, int j);
int kbhit(); //https://web.archive.org/web/20180401093525/http://cc.byexamples.com/2007/04/08/non-blocking-user-input-in-loop-without-ncurses/
void nonblock(int state);
#endif