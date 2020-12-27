using System;
using System.Runtime.InteropServices;



namespace screenTest
{
    class Program
    {
        [DllImport("libepd.so")]
        public static extern bool printNumber(int x, int y, int num); 
        
        [DllImport("libepd.so")]
        public static extern bool printString(int x, int y, string str);

        static void Main()
        {
          Console.WriteLine("Hello Pi!");
          if (printNumber(0,0,52)) Console.WriteLine("Success!");
          if (printString(0,40,"Merri Christmas")) Console.WriteLine("Success!");
          Console.WriteLine("Pi Done!");
        }
        
    }
}
