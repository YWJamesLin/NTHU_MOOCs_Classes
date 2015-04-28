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


/* global �}�C    �ΨӰO���a�Ϫ����e */
char a[HEIGHT][WIDTH];

int main(void)
{
	FILE *fp;
	char logo[] = "SAMPLE PROGRAM PROVIDED BY NTHU MOOC I2P";
	int i, j, vk;
	int px[2], py[2]; /* block �ثe�y��   �@�}�l�O���� ���� */
	int state = 2; /* 0: ���� ����, 1: ���� ����, 2: ���� */



	/* �յ۶}�ҥؿ��U�� map.txt �� */
	fp = fopen("map.txt", "r");
   /* ���p�ɮצs�b �NŪ���ɮפ��e ��}�C�������̷Ӧ�m�@�Ӥ@�ӳ]�w�n */
   	if (fp != NULL) {
      	for (i = 0; i < HEIGHT; i++) {      /* �ѩ�a�Ϫ����e�O�T�w��  �ҥH�N�����Ψ�Ӱj���Ū�� */
         	for (j = 0; j < WIDTH; j++) {
            	fscanf(fp, "%c", &a[i][j]);
            	if (a[i][j]=='S') {
            		px[0] = px[1] = j;
            		py[0] = py[1] = i;
            		a[i][j] = '@';
				}
         	}
         	fscanf(fp, "%*c");  /* �o�@�B�O���F��C�@�浲����  '\n' �Y��   "%*c" ���N��OŪ���@�Ӧr���åB�ᱼ */
      	}
      	fclose(fp);
   	} else {
		/* �_�h�p�G�ɮפ��s�b  �{���N�������� */
		return -1;
   	}

   	/* �Ұ���L���� �u�ݭn�I�s�@�� */
   	initializeKeyInput();


	/* �L�a�j��  �̭��]�t�F�o�ӵ{�����D�n�u�@
   	�ӥB�C���j��|���_��̷s���e����ܨ�ù��W  ���O���ʵe�@�� �C���j���s�@���e�� */
   	while (1) {


      	/* �� putASCII() ��a�ϵe�X��   */
      	for (i = 0; i < HEIGHT; i++) {
         	for (j = 0; j < WIDTH; j++) {
            	putASCII(j + OFFSET_X, i + OFFSET_Y, a[i][j] , 3);
         	}
      	}

      	/* current location */
        putASCII(px[0] + OFFSET_X, py[0] + OFFSET_Y, '#', state);
        putASCII(px[1] + OFFSET_X, py[1] + OFFSET_Y, '#', state);



      	/*  �� logo �� putString() ��ܥX��
         putString() �O�۩w�� function    ����b�S�w��m��ܦr��
         �o�� function ���{���X�]��b�o���ɮ׸�  �b main() ����
         �{���X����²�u  �u�O�b�j��̩I�s putASCII() �Ӥw       */
      	putString(OFFSET_X, OFFSET_Y+16, logo, 2);
      	putString(OFFSET_X, OFFSET_Y+17, "'I': Move Up", 0);
      	putString(OFFSET_X, OFFSET_Y+18, "'K': Move Down", 0);
      	putString(OFFSET_X, OFFSET_Y+19, "'J': Move Left", 0);
      	putString(OFFSET_X, OFFSET_Y+20, "'L': Move Right", 0);

      	/* ���F�n���@�s�� putASCII() ���ʧ@���ͮĪG
         �����n�I�s�@�� drawCmdWindow() �⤧�e�e���������e�@����ܨ�ù��W */
      	drawCmdWindow();


		/*
		�b�o�̥[�J �A���{���X
		�P�_�O�_�]�X�a�O���~
		�p�G�]��a�O���~�C���N����  �i�H�I�s sound(2); ���񭵮�  �M����X�L�a�j��
		���~�]�n�P�_�O�_�w�g����åB���ߦb���I��m
		�p�G�w�g�F��  �i�H�I�s sound(1); �����w�I����  �M����X�L�a�j��
		*/
		/*
		???
		*/



      	/* ��L���� */
      	if(waitForKeyDown(0.1)) {
		 	vk=getKeyEventASCII();	/* Ū����J���r�� */
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
���U�O�۩w�� functions
�]�t dalay(), putString(), sound()
***********************/

/* ���{���Ȱ� sec �� */
void delay(float sec)
{
   	clock_t startc;
   	startc = clock();
   	for ( ; ; ) {
		if ((float)(clock()-startc)/CLOCKS_PER_SEC > sec) break;
  	}
}
/* �b (x, y) �y�Ъ���m��ܦr�� p �����e  fg_color �O�C��
   �ǤJ���r�� p �O�Ϋ��Ъ��覡��r���}�C���}�Y��}�ǤJ
   �ѩ�ΨӪ�ܦr�ꪺ�r���}�C  �|�O�� '\0' �@������
   �]���i�H�ϥ� strlen() �ӧP�_�r�����?
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
      �� PlaySound() ���� wav �ɮ�
      ���] "recycle.wav" �n���ɩM�{���X��b�ۦP�ؿ�
      PlaySound("recycle.wav", NULL, SND_ASYNC|SND_FILENAME);
      �|�b�I���}�Ҩü��� recycle.wav (����� ��L��L�ʧ@���i�H�~��)

      �n�ϥ� PlaySound() �o�� function
      �p�G�O Dev-C++ �����n���� [Project] -> [Project Options] �]�w (�b Dev-C++ �̭����U  Alt+P)
      ��� Parameters ���@��  �M��b Linker �̭��[�J�@��
       -lwinmm
 	  �p�G�O Code::Blocks �h�n��   [Project]->[Build options]->[Linker settings] [other linker options]
	  �[�J�Ѽ� -lwinmm

      �A compile �N�i�H���Ͱ�����
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
