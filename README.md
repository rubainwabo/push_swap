# push_swap

DESCRIPTION : 

• The game is composed of 2 stacks named a and b.

• To start with: a contains a random number of either positive or negative numbers without
any duplicates. b is empty.

• The goal is to sort in ascending order numbers into stack a.

• To do this you have the following operations at your disposal:

. sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).

. sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).

. ss : sa and sb at the same time.

. pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.

. pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

. ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.

. rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.

. rr : ra and rb at the same time.

. rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.

.rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.

.rrr : rra and rrb at the same time.

 USAGE :

- CHECKER : 
          
          ARG=`numbers`; ./checker $ARG
          //This will wait for the list of instructions which are (sa, sb, ...)
- PUSH_SWAP : 

          ARG=`numbers`; ./push_swap $ARG
- PUSH_SWAP + CHECKER : 
            
          ARG=`numbers`; ./push_swap $ARG | ./checker $ARG 
            //note that push_swap has always to give the list of instructions which is piped into the checker program

BONUS :
- Using checker -v or push_swap -v will display every state of the stacks while sorting or verifying the sort.

- PUSH_SWAP + VISUALIZER : 

          ARG=`numbers`; ./push_swap $ARG | ./visual $ARG

You can use the following script at the place of "numbers" to generate a defined range set of numbers :
          ruby -e "puts (\`minimum\`..\`maximum\`).to_a.shuffle.join(' ')"
          
- EXAMPLE : 
          
          ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./visual $ARG
          //gives the following output

![](ps.gif)
