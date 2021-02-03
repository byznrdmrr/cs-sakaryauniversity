using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DFA_Simple
{
    internal class Program
    {

        private static void Main(string[] args)
        {
            var Q = new List<string> { "q0", "q1", "q2", "q3", "q4", "q5", "q6", "q7", "q8", "q9", "q10", "q11","q12" }; //makinanın durumları
            var Sigma = new List<char> { 'a', 'b'};  //alfabe
            var Delta = new List<Transition>{   //geçişlerin listesi
            new Transition("q0", 'a', "q2"),
            new Transition("q0", 'b', "q1"),

            new Transition("q1", 'a', "q5"),
            new Transition("q1", 'b', "q1"),

            new Transition("q2", 'a', "q3"),
            new Transition("q2", 'b', "q4"),

            new Transition("q3", 'a', "q2"),
            new Transition("q3", 'b', "q1"),

            new Transition("q4", 'a', "q6"),
            new Transition("q4", 'b', "q8"),

            new Transition("q5", 'a', "q3"),
            new Transition("q5", 'b', "q10"),

            new Transition("q6", 'a', "q7"),
            new Transition("q6", 'b', "q9"),

            new Transition("q7", 'a', "q8"),
            new Transition("q7", 'b', "q4"),

            new Transition("q8", 'a', "q8"),
            new Transition("q8", 'b', "q8"),

            new Transition("q9", 'a', "q11"),
            new Transition("q9", 'b', "q8"),

            new Transition("q10", 'a', "q6"),
            new Transition("q10", 'b', "q9"),

            new Transition("q11", 'a', "q8"),
            new Transition("q11", 'b', "q12"),

            new Transition("q12", 'a', "q8"),
            new Transition("q12", 'b', "q9"),



         };
            var Q0 = "q0";  //başlangıç durumu 
            var F = new List<string> { "q0", "q1", "q3", "q6", "q10","q12" }; //kabul durumları
            var dFSM = new MachineDFA(Q, Sigma, Delta, Q0, F);

            //bazı girdilerin makinanın bir parçası olup olmadığını kontrol ediyoruz
            for (int i= 0; i < 20; i++)
            {                
               Console.WriteLine("Please enter an input");
               string katar = Console.ReadLine();
               dFSM.Accepts(katar);
               
            }          
            Console.ReadKey();
        }
       

    }
}
