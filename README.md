# ToyScript
Simple math intepreter build in C++, inspired by this video series: https://www.youtube.com/watch?v=88lmIMHhYNs&amp;list=PLZQftyCk7_Sdu5BFaXB_jLeJ9C78si5_3&amp;index=1

To run the program from file, first clone and build the visual studio project, 
in terminal run: 
>ToyScript.exe [filepath]

For example:
>ToyScript.exe C:/project/test.txt

Currently it supports:


Addition:
> 1 + 1 -> 2


Subtraction:
> 2 - 1 -> 1


Mutiply:
> 2 * 2 -> 4


Divide:
> 4 / 2 -> 2


Changing of order of operation:
> 1 + 2 * 2 -> 5

>(1 + 2) * 2 -> 6

Unary operation:
> -2 - 1 -> -3

> +3 + 1 -> 4

Power:
> 4 ^ 2 -> 16

Modulus:
> 4 % 2 -> 0
