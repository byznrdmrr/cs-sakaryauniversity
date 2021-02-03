using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace DFA_Simple
{
    public class Transition  //Geçiş sınıfının StartState, Sembol ve geçişin EndState hakkındaki bilgileri tutması gerekir.
    {
        public string StartState { get; private set; }
        public char Symbol { get; private set; }
        public string EndState { get; private set; }

        public Transition(string startState, char symbol, string endState)
        {
            StartState = startState;
            Symbol = symbol;
            EndState = endState;
        }

        public override string ToString()
        {
            return string.Format("({0}, {1}) -> {2}", StartState, Symbol, EndState);
        }
    }
}
