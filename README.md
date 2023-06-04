<div align="center">
	
<h1> Push Swap </h1>

<a href="https://github.com/simon-zerisenay/42_push_swap">![42 Badge](https://github.com/mcombeau/mcombeau/blob/main/42_badges/push_swapm.png)</a>

</div>
<h2>Introduction </h2> 
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/simon-zerisenay/42_Push_Swap?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/simon-zerisenay/42_Push_Swap?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/simon-zerisenay/42_Push_Swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/simon-zerisenay/42_Push_Swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/simon-zerisenay/42_Push_Swap?color=green" />
</p>

Welcome to the Push Swap project! This project is part of the curriculum at 42 and focuses on sorting algorithms and the manipulation of stack data structures. Push Swap involves creating two programs: one that sorts a stack of integers using a specific set of operations, and another that checks if the given set of instructions properly sorts the stack.

<h2>Objective</h2>
The main objective of the Push Swap project is to develop efficient sorting algorithms that can arrange a stack of integers in ascending order using a limited set of operations. Additionally, you are required to implement a checker program that verifies if a given set of instructions correctly sorts the stack.

<h2>Features</h2>
Sorting Algorithm
Push Swap allows you to implement different sorting algorithms to arrange the stack of integers. For this project, a custom algorithm is commonly used for optimal performance:

Midpoint Algorithm: This algorithm assigns indexes to the numbers based on their order in the stack. It then calculates the midpoint by adding the indexes and finding the mean. The algorithm repeatedly sends all the numbers with indexes lower than the midpoint to stack B. This process is repeated until only 3 numbers are left on stack A. The 3 remaining numbers are used as a reference to push back from stack B to stack A. The algorithm calculates the cost of each operation and undertakes the cheapest one to minimize the number of moves required.
By utilizing this custom algorithm, you can achieve efficient sorting with a reduced number of operations.

<h2>Stack Manipulation</h2>
The project requires manipulating two stacks, stack A and stack B, using a set of predefined operations:

sa/sb: Swap the top two elements of stack A/B.
ss: Perform both sa and sb.
pa/pb: Push the top element from stack B/A onto stack A/B.
ra/rb: Rotate the stack A/B by moving the top element to the bottom.
rr: Perform both ra and rb.
rra/rrb: Reverse rotate the stack A/B by moving the bottom element to the top.
rrr: Perform both rra and rrb.
These operations allow you to rearrange the elements in the stacks and ultimately sort the integers.

<h2>Checker Program</h2>
In addition to the sorting program, you are required to create a checker program. The checker program takes a list of instructions and verifies if executing those instructions on the stack correctly sorts the integers. It displays "OK" if the stack is sorted after executing the instructions and "KO" otherwise.

<h2>Installation and Usage</h2>
To install and run the Push Swap project, follow these steps:

Clone the project repository: 

				git clone https://github.com/your_username/42-push_swap.git
Navigate to the project directory: 
				
						cd 42-push_swap
Compile the project using the provided Makefile: 
					
				     		   make
Sort the integers using the push_swap program: 

			./push_swap <Enter as many numbers as you want but separated by space>
Verify the sorting using the checker program: 
			
					  ./checker <list_of_integers>
Ensure that you have the necessary libraries and dependencies installed on your system. The project's repository may provide further instructions on any additional requirements.

<h2>Testing</h2>
To test the Push Swap project and validate its functionality, follow these steps:

Generate a random set of integers using the provided generate.sh script.
Sort the generated integers using the push_swap program.
Execute the obtained instructions on the stack using the checker program.
Verify that the checker program displays "OK" if the stack is sorted correctly.
Test the project with various sets of integers
