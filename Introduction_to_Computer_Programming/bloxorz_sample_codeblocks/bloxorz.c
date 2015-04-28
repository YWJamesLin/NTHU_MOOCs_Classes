#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
/*
  For sound effect:
  Dev C++: In [Project Options]->[Parameters]->[Linker] add the parameter -lwinmm
  Code::Blocks: In [Project]->[Build options]->[Linker settings] add the parameter -lwinmm at [other linker options]
*/

#include "console_draw.h"
#include "kb_input.h"

#define WIDTH     25
#define HEIGHT    15
#define OFFSET_X  5
#define OFFSET_Y  1
void delay(float sec);
void putString(int x, int y, char *p, int fg_color);
void sound(int select);


/* global 陣列    用來記錄地圖的內容 */
char a[HEIGHT][WIDTH];

int main(void)
{
	FILE *fp;
	char logo[] = "SAMPLE PROGRAM PROVIDED BY NTHU MOOC I2P";
	int i, j, vk;
	int px[2], py[2]; /* block 目前座標   一開始是水平 平躺 */
	int state = 2; /* 0: 水平 平躺, 1: 垂直 平躺, 2: 直立 */



	/* 試著開啟目錄下的 map.txt 檔 */
	fp = fopen("map.txt", "r");
   /* 假如檔案存在 就讀取檔案內容 把陣列的元素依照位置一個一個設定好 */
   	if (fp != NULL) {
      	for (i = 0; i < HEIGHT; i++) {      /* 由於地圖的長寬是固定的  所以就直接用兩個迴圈來讀取 */
         	for (j = 0; j < WIDTH; j++) {
            	fscanf(fp, "%c", &a[i][j]);
            	if (a[i][j]=='S') {
            		px[0] = px[1] = j;
            		py[0] = py[1] = i;
            		a[i][j] = '@';
				}
         	}
         	fscanf(fp, "%*c");  /* 這一步是為了把每一行結尾的  '\n' 吃掉   "%*c" 的意思是讀取一個字元並且丟掉 */
      	}
      	fclose(fp);
   	} else {
		/* 否則如果檔案不存在  程式就直接結束 */
		return -1;
   	}

   	/* 啟動鍵盤控制 只需要呼叫一次 */
   	initializeKeyInput();


	/* 無窮迴圈  裡面包含了這個程式的主要工作
   	而且每次迴圈會不斷把最新的畫面顯示到螢幕上  像是播動畫一樣 每次迴圈更新一次畫面 */
   	while (1) {


      	/* 用 putASCII() 把地圖畫出來   */
      	for (i = 0; i < HEIGHT; i++) {
         	for (j = 0; j < WIDTH; j++) {
            	putASCII(j + OFFSET_X, i + OFFSET_Y, a[i][j] , 3);
         	}
      	}

      	/* current location */
        putASCII(px[0] + OFFSET_X, py[0] + OFFSET_Y, '#', state);
        putASCII(px[1] + OFFSET_X, py[1] + OFFSET_Y, '#', state);



      	/*  把 logo 用 putString() 顯示出來
         putString() 是自定的 function    它能在特定位置顯示字串
         這個 function 的程式碼也放在這個檔案裡  在 main() 之後
         程式碼其實很簡短  只是在迴圈裡呼叫 putASCII() 而已       */
      	putString(OFFSET_X, OFFSET_Y+16, logo, 2);
      	putString(OFFSET_X, OFFSET_Y+17, "'I': Move Up", 0);
      	putString(OFFSET_X, OFFSET_Y+18, "'K': Move Down", 0);
      	putString(OFFSET_X, OFFSET_Y+19, "'J': Move Left", 0);
      	putString(OFFSET_X, OFFSET_Y+20, "'L': Move Right", 0);

      	/* 為了要讓一連串 putASCII() 的動作產生效果
         必須要呼叫一次 drawCmdWindow() 把之前畫的全部內容一次顯示到螢幕上 */
      	drawCmdWindow();


		/*
		在這裡加入 你的程式碼
		判斷是否跑出地板之外
		如果跑到地板之外遊戲就結束  可以呼叫 sound(2); 播放音效  然後跳出無窮迴圈
		此外也要判斷是否已經走到並且直立在終點位置
		如果已經達成  可以呼叫 sound(1); 播放歡呼音效  然後跳出無窮迴圈
		*/
		/*
		???
		*/



      	/* 鍵盤控制 */
      	if(waitForKeyDown(0.1)) {
		 	vk=getKeyEventASCII();	/* 讀取輸入的字元 */
         	switch(vk) {
            	case 'I':
            	case 'i':
					if (state == 0) {
						/*
						???
						*/
					} else if (state == 1) {
						/*
						???
						*/
					} else if (state == 2) {
						/*
						???
						*/
					}
					sound(0);
					break;
            	case 'K':
            	case 'k':
					if (state == 0) {
						/*
						???
						*/
					} else if (state == 1) {
						/*
						???
						*/
					} else if (state == 2) {
						/*
						???
						*/
					}
					sound(0);
					break;
            	case 'J':
            	case 'j':
					if (state == 0) {
						/*
						???
						*/
					} else if (state == 1) {
						/*
						???
						*/
					} else if (state == 2) {
						/*
						???
						*/
					}
					sound(0);
					break;
           		case 'L':
            	case 'l':
					if (state == 0) {
						/*
						???
						*/
					} else if (state == 1) {
						/*
						???
						*/
					} else if (state == 2) {
						/*
						???
						*/
					}
					sound(0);
					break;
         	}
      	}


		delay(0.05);

   	} /* while (1) */

	sound(3);
   	return 0;
}


/***********************
底下是自定的 functions
包含 dalay(), putString(), sound()
***********************/

/* 讓程式暫停 sec 秒 */
void delay(float sec)
{
   	clock_t startc;
   	startc = clock();
   	for ( ; ; ) {
		if ((float)(clock()-startc)/CLOCKS_PER_SEC > sec) break;
  	}
}
/* 在 (x, y) 座標的位置顯示字串 p 的內容  fg_color 是顏色
   傳入的字串 p 是用指標的方式把字元陣列的開頭位址傳入
   由於用來表示字串的字元陣列  會是用 '\0' 作為結尾
   因此可以使用 strlen() 來判斷字串長度?
*/
void putString(int x, int y, char *p, int fg_color)
{
   	int i;
   	for(i=0; (unsigned int)i<strlen(p); i++) {
      	putASCII(x+i, y, p[i], fg_color);
   	}
}

void sound(int select)
{

   if (select == 0) {
   /*
      用 PlaySound() 播放 wav 檔案
      假設 "recycle.wav" 聲音檔和程式碼放在相同目錄
      PlaySound("recycle.wav", NULL, SND_ASYNC|SND_FILENAME);
      會在背景開啟並播放 recycle.wav (播放時 其他鍵盤動作仍可以繼續)

      要使用 PlaySound() 這個 function
      如果是 Dev-C++ 必須要先到 [Project] -> [Project Options] 設定 (在 Dev-C++ 裡面按下  Alt+P)
      選到 Parameters 那一頁  然後在 Linker 裡面加入一行
       -lwinmm
 	  如果是 Code::Blocks 則要到   [Project]->[Build options]->[Linker settings] [other linker options]
	  加入參數 -lwinmm

      再 compile 就可以產生執行檔
   */
      PlaySound(TEXT("metalplate.wav"), NULL, SND_ASYNC|SND_FILENAME);
   }
   else if (select == 1) {
      PlaySound(TEXT("applause.wav"), NULL, SND_ASYNC|SND_FILENAME);
      Sleep(4000);
   }
   else if (select == 2) {
      PlaySound(TEXT("metal.wav"), NULL, SND_ASYNC|SND_FILENAME);
      Sleep(2000);
   }
   else if (select == 3) {
      PlaySound(TEXT("recycle.wav"), NULL, SND_ASYNC|SND_FILENAME);
      Sleep(1000);
   }

}
