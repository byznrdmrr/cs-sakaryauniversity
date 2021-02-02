using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DFA_Simple
{
    public class ConsoleWriter
    {
        public static void Failure(string message)
        {
            Console.ForegroundColor = ConsoleColor.DarkRed;
            Write(message);
        }

        public static void Success(string message)
        {
            Console.ForegroundColor = ConsoleColor.DarkGreen;
            Write(message);
        }

        private static void Write(string message)
        {
            Console.WriteLine(message);
            Console.ResetColor();
        }
    }
}
