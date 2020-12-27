#include "myCustom.h"
#include "EPD_Test.h"
#include "EPD_2in7.h"

void  MyTest(void) {
    printf("My Demo\r\n");
    if(DEV_Module_Init()!=0){
        return;
    }

    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN7_Init();
    EPD_2IN7_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UBYTE *BlockImage;
    /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    UWORD Imagesize = ((EPD_2IN7_WIDTH % 8 == 0)? (EPD_2IN7_WIDTH / 8 ): (EPD_2IN7_WIDTH / 8 + 1)) * EPD_2IN7_HEIGHT;
    if((BlockImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for block memory...\r\n");
        return;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlockImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, 270, WHITE);
    Paint_Clear(WHITE);

    Paint_DrawString_EN(30, 0,"Hello", &Font36, WHITE, BLACK);
    //GUI_ReadBmp("btn1Template.bmp", 0, 0);

    EPD_2IN7_Display(BlockImage);

    free(BlockImage);
}

bool printNumber(int x, int y, int num) {
    int maxStr = 5;
    char str[maxStr];
    printf("printNumber:start\n");
    if(DEV_Module_Init()!=0){
        printf("printNumber:end:init failed\n");
        return false;
    }

    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN7_Init();
    EPD_2IN7_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UBYTE *BlockImage;
    /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    UWORD Imagesize = ((EPD_2IN7_WIDTH % 8 == 0)? (EPD_2IN7_WIDTH / 8 ): (EPD_2IN7_WIDTH / 8 + 1)) * EPD_2IN7_HEIGHT;
    if((BlockImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("printNumber:Failed to apply for block memory...\r\n");
        return false;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlockImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, 270, WHITE);
    Paint_Clear(WHITE);

    sprintf(str, "%d", num);
    Paint_DrawString_EN(x, y,str, &Font36, WHITE, BLACK);

    EPD_2IN7_Display(BlockImage);

    free(BlockImage);
    printf("printNumber:end\n");
    return true;
}


bool printString(int x, int y, char *str) {
    printf("printString:start\n");
    if(DEV_Module_Init()!=0){
        printf("printString:end:init failed\n");
        return false;
    }

    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN7_Init();
    EPD_2IN7_Clear();
    DEV_Delay_ms(500);

    //Create a new image cache
    UBYTE *BlockImage;
    /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
    UWORD Imagesize = ((EPD_2IN7_WIDTH % 8 == 0)? (EPD_2IN7_WIDTH / 8 ): (EPD_2IN7_WIDTH / 8 + 1)) * EPD_2IN7_HEIGHT;
    if((BlockImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("printString:Failed to apply for block memory...\r\n");
        return false;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlockImage, EPD_2IN7_WIDTH, EPD_2IN7_HEIGHT, 270, WHITE);
    Paint_Clear(WHITE);

    //sprintf(str, "%d", num);
    Paint_DrawString_EN(x, y,str, &Font20, WHITE, BLACK);

    EPD_2IN7_Display(BlockImage);

    free(BlockImage);
    printf("printString:end\n");
    return true;
}
