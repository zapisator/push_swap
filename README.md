# push_swap
My push_swap project for School21 by Sberbank

The goal of the project is to write a program that sorts a set of numbers using two stacks. See file [sbj/08_push_swap.en.pdf](https://github.com/TesenDesk/push_swap/blob/master/sbj/08_push_swap.en.pdf) for more details.

A quicksort algorithm on two stacks is implemented. This algorithm is not suitable for this problem because you need to do as little as possible, so the score is not maximal. This algorithm is good for fast sorting of large numbers...

The program consists of two parts, the `push_swap` program, which takes a set of numbers and sorts them, and the `checker` program, which also takes a set of numbers, and reads the standard output, waiting for commands. It applies these commands to the set of numbers, and at the end reports whether the set is sorted or not. These programs work in pairs to check the project.

To run the program, first run `make`.    
Use the command below to run the program.    
```
./push_swap <numerical sequence>
```
The ``numeric sequence'' should contain non-repeating numbers in random order, separated by spaces. You can use bash variables.    
The program will print the set of commands needed to sort that sequence. You can read more about the commands in the project document [sbj/08_push_swap.en.pdf](https://github.com/TesenDesk/push_swap/blob/master/sbj/08_push_swap.en.pdf).    
The program will not print anything if there is an error - the entered sequence has already been sorted, contains post-entries, non-numeric values, values outside of int, or other errors.

Using the command below, you can run `checker'. It is used to check the program.
```
./checker [flag] <numeric sequence
```
Once entered, the program will wait for the commands to be entered. You can enter these commands manually. If after applying these commands the sequence is sorted, the program will print `OK`, otherwise `KO`. If an error occurs, it will print `ERROR`.    
Additional operation flags were added. The `checker` supports flags:    
`-c` - start command counter - shows the number of entered commands at the end of work.    
`-t` - shows stack tables at the beginning and end of work.    
`-v` - shows stack tables at the beginning and at the end of work, as well as prints the state of stacks after a certain number of commands.    
`-d` - debug mode. In this mode, the program prints out the state of stacks at each step, as well as some additional information.    
The presence of any flag includes printing out information about operation - program response and active flags.    
The `-c` flag can be used in conjunction with other flags. For example, `-vc`.    

The two programs can be used together by using
```
./push_swap <word sequence> | ./checker [flag] <word sequence
```
This way, checker will automatically read the commands from push_swap    
Note: for the checker to work correctly, the numeric sequences must match!

2019, Moscow, Russia
