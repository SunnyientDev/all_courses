# Regular expressions and the Turing machine

Stanford University Course: https://plato.stanford.edu/entries/turing-machine

Moore diagram for rear solution: https://drive.google.com/file/d/1V_hESIsRAzsizxXYgQM60IuOrhuj7706/view?usp=sharing

## BUILDING A REGULAR EXPRESSION MACHINE (first/second methods .c)

Given a regular expression, you should independently build an acceptor automaton and implement it in the C language. An example and a counterexample should also be given.
The construction of an acceptor automaton was discussed in the lecture, Kleene's theorem.

### Regular expression

ffff (: 0 {1,4}) {0,1}:) {0,1} ((25 [0-5] | (2 [0-4] | 1 {0,1} [0-9] ) {0,1} [0-9]) \.) {3,3} (25 [0-5] | (2 [0-4] | 1 {0,1} [0-9]) {0 , 1} [0-9]) | ([0-9a-fA-F] {1,4}:) {1,4}: ((25 [0-5] | (2 [0-4] | 1 {0,1} [0-9]) {0,1} [0-9]) \.) {3,3} (25 [0-5] | (2 [0-4] | 1 {0 , 1} [0-9]) {0,1} [0-9]))

### SETTING THE ALGORITHM FOR THE TURING MACHINE (turing/turing1 .c)

Describe the Turing machine algorithm in tabular form. Describe the work algorithm in words. Set an example and a counterexample. Think of the algorithm as a state machine and draw a Moore diagram. Implement the resulting automaton in C.

#### Algorithm:

Given a decimal representation of a natural number n> 1. Develop a Turing machine that would decrease a given number n by 1. An automaton in state q1 looks at the right digit of the number.
