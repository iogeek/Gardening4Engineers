using System;
using System.Runtime.InteropServices;



namespace screenTest
{
    class Program
    {
      static int WHITE = 0xFF;
      static int BLACK = 0x00;
      static int RED = BLACK;
        static int ePaperWidth = 176;  //  EPD_2IN7_WIDTH
        static int ePaperHeight = 264; // EPD_2IN7_HEIGHT
        static int Imagesize = ((ePaperWidth % 8 == 0)? (ePaperWidth / 8 ): (ePaperWidth / 8 + 1)) * ePaperHeight;
        static byte[] array = new byte[Imagesize];
      
        [DllImport("libepd.so")]
        public static extern bool printNumber(int x, int y, int num); 
        
        [DllImport("libepd.so")]
        public static extern bool printString(int x, int y, string str);
        
        [DllImport("libepd.so")]
        public static extern void DisplayBackground([In, Out] [MarshalAs(UnmanagedType.LPArray)] byte[] pImage, string bmpName, int width, int height, int rotation, int color);

        [DllImport("libepd.so")]
        public static extern void PrintString([In, Out] [MarshalAs(UnmanagedType.LPArray)] byte[] pImage, int x, int y, int x2, int y2, bool resetRect, int fontSize, string str, int width, int height, int rotation, int color);
        
        static void Main()
        {
          Console.WriteLine("Hello Pi!");
          //if (printNumber(0,0,52)) Console.WriteLine("Success!");
          //if (printString(0,40,"Merri Christmas")) Console.WriteLine("Success!");
          string bmpFile = "/home/pi/git/btn1Template.bmp";
          //int size = Marshal.SizeOf(array[0]) * array.Length;
          //IntPtr pnt = Marshal.AllocHGlobal(Imagesize);
          //Marshal.Copy(array, 0, pnt, array.Length);

          DisplayBackground(array, bmpFile, ePaperWidth, ePaperHeight, 270, WHITE);
          // font 48p =  38w x 66h
          //      36p =  27w x 48h
          //      24p =  17w x 24h
          //      20p =  14w x 20h
          //      16p =  11w x 16h
          //      12p =   7w x 12h
          //       8p =   5w x  8h

          PrintString(array, 0,0,264,44,true, 20, "Merri Christmas", ePaperWidth, ePaperHeight, 270, WHITE);
          PrintString(array, 90,109,175,176,true, 16,"Air Quality", ePaperWidth, ePaperHeight, 270, WHITE);
          PrintString(array, 90,127,175,176,false, 12,"O3      3", ePaperWidth, ePaperHeight, 270, WHITE);
          PrintString(array, 90,141,175,176,false, 12,"PM2.5  61", ePaperWidth, ePaperHeight, 270, WHITE);
          //Marshal.Copy(pnt, 0, array, array.Length);

          //Marshal.FreeHGlobal(pnt);
          Console.WriteLine("Pi Done!");
          
          
          // bitmaps has 3 rows.  Bottom row has 3 cells
          // dimension (x,y)      (x2,y2)
          // row 1 -    (0,0)     (264,44)
          // row 2 -    (0,47)    (264,105)
          // row 3 c1 - (0,109)   (86,176)
          //       c2 - (90,109)  (175,176)
          //       c3 - (179,109) (264,176)
        }
        
    }
}
