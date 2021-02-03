using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace DFA_Simple
{
    public class MachineDFA
    {
        private readonly List<string> Q = new List<string>();
        private readonly List<char> Sigma = new List<char>();
        private readonly List<Transition> Delta = new List<Transition>();
        private string Q0;
        private readonly List<string> F = new List<string>();

        public MachineDFA (IEnumerable<string> q, IEnumerable<char> sigma, IEnumerable<Transition> delta, string q0, IEnumerable<string> f)
        {
            Q = q.ToList();
            Sigma = sigma.ToList();
            AddTransitions(delta);
            AddInitialState(q0);
            AddFinalStates(f);
        }

        private void AddTransitions(IEnumerable<Transition> transitions)
        {
            foreach (var transition in transitions.Where(ValidTransition))
            {
                Delta.Add(transition);
            }
        }

        private bool ValidTransition(Transition transition)
        {
            return Q.Contains(transition.StartState) &&
                   Q.Contains(transition.EndState) &&
                   Sigma.Contains(transition.Symbol) &&
                   !TransitionAlreadyDefined(transition);
        }

        private bool TransitionAlreadyDefined(Transition transition)
        {
            return Delta.Any(t => t.StartState == transition.StartState &&
                                  t.Symbol == transition.Symbol);
        }

        //başlangıç durumu
        private void AddInitialState(string q0)
        {
            if (q0 != null && Q.Contains(q0))
            {
                Q0 = q0;
            }
        }

        //bitiş durumu
        private void AddFinalStates(IEnumerable<string> finalStates)
        {
            foreach (var finalState in finalStates.Where(finalState => Q.Contains(finalState)))
            {
                F.Add(finalState);
            }
        }

        public void Accepts(string /*input*/ katar)
        {
            //ConsoleWriter.Success(katar);
            if (InvalidInputOrFSM(katar))
            {
                return;
            }
            var currentState = Q0;
            var steps = new StringBuilder();
            foreach (var symbol in katar.ToCharArray())
            {
                var transition = Delta.Find(t => t.StartState == currentState &&
                                                 t.Symbol == symbol);
                if (transition == null)
                {
                    ConsoleWriter.Failure("No transitions for current state and symbol");
                    ConsoleWriter.Failure(steps.ToString());
                    return;
                }
                currentState = transition.EndState;
                steps.Append(transition + "\n");
            }
            if (F.Contains(currentState))
            {
                ConsoleWriter.Success("Accepted the input with steps:\n" + steps);
                return;
            }
            ConsoleWriter.Failure("Stopped in state " + currentState +
                                  " which is not a final state.");
            ConsoleWriter.Failure(steps.ToString());
        }

        private bool InvalidInputOrFSM(string input)
        {
            if (InputContainsNotDefinedSymbols(input))
            {
                return true;
            }
            if (InitialStateNotSet())
            {
                ConsoleWriter.Failure("No initial state has been set");
                return true;
            }
            if (NoFinalStates())
            {
                ConsoleWriter.Failure("No final states have been set");
                return true;
            }
            return false;
        }

        private bool InputContainsNotDefinedSymbols(string input)
        {
            foreach (var symbol in input.ToCharArray().Where(symbol => !Sigma.Contains(symbol)))
            {
                ConsoleWriter.Failure("Could not accept the input since the symbol " + symbol + " is not part of the alphabet");
                return true;
            }
            return false;
        }

        private bool InitialStateNotSet()
        {
            return string.IsNullOrEmpty(Q0);
        }

        private bool NoFinalStates()
        {
            return F.Count == 0;
        }
    }
}











