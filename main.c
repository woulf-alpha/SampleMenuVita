
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <sys/time.h>

#include <psp2/ctrl.h>
#include <psp2/display.h>
#include <psp2/gxm.h>
#include <psp2/types.h>
#include <psp2/moduleinfo.h>
#include <psp2/kernel/processmgr.h>

#include "utils.h"
#include "draw.h"

PSP2_MODULE_INFO(0, 0, "SampleMenu");

int menu_select = 0;

char *label[3] = {"New Game", "Credits", "Exit"};

void Start_Game()
{
    font_draw_string(10, 130, BLACK, "Start Game" );
}


void View_Credits()
{
    font_draw_string(10, 130, BLACK, "View Credits");
}



void Draw_Menu()
{

     font_draw_string(10, 10, GREEN, "Sample Menu by Woulf_Alpha v.0.0.1");

     if (menu_select == 0)
     {
         font_draw_string(10, 40, RED, label[0]);

     } else 
     {
        font_draw_string(10, 40, BLACK, label[0]);
     }


     if (menu_select == 1)
     {
         font_draw_string(10, 70, RED, label[1]);
     } else 
     {
        font_draw_string(10, 70, BLACK, label[1]);
     }

     if ( menu_select == 2)
     {
        font_draw_string(10, 100, RED, label[2]);
     } else
     {
         font_draw_string(10, 100, BLACK, label[2]);
     }

    //font_draw_stringf(10,  150, BLACK, "%d",  menu_select);

}


int main()
{
    init_video();
    int frame = 0;
    SceCtrlData pad;
    while(1)
    {
        frame ++;

        clear_screen();
        sceCtrlPeekBufferPositive(0, &pad, 1);

        Draw_Menu();

        if (pad.buttons & PSP2_CTRL_CROSS) 
            {
                if (menu_select == 0)
                {
                    Start_Game();

                } else if( menu_select == 1)
                {
                    View_Credits();
                } else if ( menu_select == 2)
                {
                    break;
                    break;
                }

            }


        if (frame == 10)
        {
            frame = 0;
            if (pad.buttons & PSP2_CTRL_UP)
            {
               if (menu_select != 0)
               {
                    menu_select -= 1;
               }
                

            } else if (pad.buttons & PSP2_CTRL_DOWN)
            {
                if (menu_select != 2)
                {
                    menu_select += 1;
                } 

            }

            
     
        }
        
        swap_buffers();
        sceDisplayWaitVblankStart();

    }

    end_video();
    return 0;
	
}
