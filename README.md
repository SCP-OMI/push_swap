# Push_Swap *-- Because apparently, the best way to sort something is to put it in a stack :) --*

In this small project, we will learn how to sort a stack of numbers using nothing but a limited set of moves and stacks.
By following this small description hopefully you'll be able to make your own version of the project.

## Small description
  ---
Push Swap is a project about __stack__ manipulation, aiming to __sort__ a set of numbers entered by the __user__ in a full stack with a minimal set of __instructions__.

## What is a stack?
---
A stack is a conceptual structure consisting of a set of homogeneous __element__ and is based on the principle of last in first out __(LIFO)__. It is a commonly used abstract data type with two major operations, namely push and pop. Push and pop are carried out on the topmost element, which is the item most recently added to the stack. The push operation adds an element to the stack while the pop operation removes an element from the top position. The stack concept is used in programming and memory organization in computers.

>DISCLAIMER : I'm still a beginner at __code__, so everything I do is just my beginner way of doing it __at this point in time__, so if you have a better implementation; please be my guest, and please do pull me or make a better explanation of the project, because at the end of the day, helping others is the motivation

# STEPS TO FOLLOW
- [ ] Parse the numbers entered by the __user__
- [ ] Coffee break
- [ ] Sort them
- [ ] That was it :)


---
# Parsing The Numbers
The parsing part of this project is pretty simple, it can be also nerve wracking if you're planning to defend your project, since parsing numbers can be either adjusted to work with any input or a single input method.  
In my case i will use the prior in my explanation since it's more inclusive and doesn't require a lot of code __(simple joining and spliting your array)__.  

Now for the actual parsing, what I recommend is (as mentioned prior) to take every argument passed by the user,join them in one string with a space between each which would result in something like this :

```c
char *joined_array
int i = 0;

joined_array = strdup(joined_array, "");
while (av[i])
	{
		joined_array = strjoin(joined_array, av[i]);
		joined_array = strjoin(joined_array, " ");
		i++;
	}
```
> Expected input : 1 3 2 "4" "7 5 8"  
> Expected result : 1 3 2 4 7 5 8  


For the second part of the parsing, you'll need to split the string you already saved the numbers to, so you basically just split that joined array by the space we joined with, something like :

```c
char *splitted_array

splitted_array = ft_split(splitted_array, " ");
```
> Expected input : 1 3 2 4 7 5 8

```
Expected result :
1
3
2
4
7
5
8
```
At this point, you already have your stack almost made for you, but it's a string with ASCII charecters, but we need to have actual integers if wanted to sort them.  
I mean, you can have your stack consists of ASCII charecters as numbers and sort them like that, but like cmon...  
Assuming you have a single working braincell; you opted for the sain option, in that case; you can copy each element of your splitted array after atoi-ing it to an integer array which will be your __STACK A__ :

```c
int *stack_a
int i = 0;

stack_a = malloc(sizeof(int) * length_of_stack);

while (splitted_array[i])
{
	stack_a[i] = atoi(splitted_array[i]);
	i++;
}
```
>NOTE : It's a nice practice to make a vairable to keep in mind the current dynamic size of your stack since we will be manipulating it... alot  
> Keep in mind that you can have your allocate space for the second stack, call it __STACK B__ for the sake of cohersion

# Error Checking

Now, there are some cases we will come across while parsing and we need to make sure to handle them correctly, like :  

- [ ] Checking if your user input has anything but numbers
- [ ] Checking if your stack contains duplicated numbers
- [ ] Checking if your stack is already sorted

  

- [X] Checking if your user input has anything but numbers
To handle the first, there are a lot of approaches you can take, in my case I've opted to change how my AtoI function works so it returns an error while perfoming the formating;


- [X] Checking if your stack contains duplicated numbers

For the duplicated case, you can create a function that sorts the numbers without any regards for the stack rule, and comparing each element with the next in the sorted array; if the two consecutive integers happen to be equal, the function fails and returns an error, the function should look something similar to this :

```c
int	check_dupilactes(---Your data---)
{
	int	i;
	int	j;

	i = 0;
	sort(); //The function basically sorts your array 
	while (sorted_array[i])
	{
		j = i + 1;
		while (j < len)
		{
			if (sorted_array[i] == sorted_array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
```

- [X] Checking if your stack is already sorted

And for the last case, we need to make sure you actually have a scrambled  stack for your program to sort... right?
In that case... all you have to do is run a simple function to check if your stack is actually sorted already

``` c
void	 check_if_sorted(---Your data---)
{
	int	i;

	i = 0;
	//
	while (i < len_of_stack - 1)
	{
		 //Check if the previous number is bigger the next, hense not sorted
		if (stackA[i] > stackA[i + 1])
			break ;
		i++;
	}
//If the while loop finished with i reaching its max value (length of StackA) then we have an already sorted stack; therefore everything is sorted and we show an error and exit our program 
	if (i == len_of_stack)
	{	
		write(2, "Error: Your shit is sorted already\n", 35);
		exit (0);
	}
}
```

>### *If the stack the user gives passes all of these tests, we can finally go to the next step of the cipher; sorting the actual stack.*

>REMARK : *I lied about the coffee break... Sorry*

---
# Sorting the Stacks 
#### Now is where the fun stuff begins

Now, if we want to sort our stack, we need to pick one method to sort them.  
There are alot of ways you can go by while trying to perform this task, notably (RADDEX, Chunks...), but we'll leave this part of the talk for later.

I personally went with the chunks method that I thank my friend and peer [Msouiyeh](https://github.com/mohamed-souiyeh) for mastering this technique and creating more ways to optimize it for the best results.

~~~ 
It is worth to mention that the scoring system of the project (which decides the final grade) is based on the amount of instructions used to solve a set of numbers (3, 5, 100, 500)
In short, less is better.
~~~
# HOW TO SORT

This is where the real fun begins.  
Personally I opted to have 3 sorting algos ("2", "3", "4<->15", "16<->500").
~~~
Yes, i understand that i've mentionned 4 different "algorithms" but like cmon..
~~~
### STACK LENGTH : 2
---
In this case; you just need to check if the stack is already sorted or not, it's basically either the stack is solved or isn't, in that case you just need to swap the stack.  
See? I told you, it's not really an algorithm now is it?

### STACK LENGTH : 3
---
Alright; in this i won't lie... I hard coded the crap out of it, I followed this Medium article where it described how to handle all the cases you can come across, five to be exact (3! = 6 - 1 "one case is already sorted")

### STACK LENGTH : 4<->15 (mid sort)
This one is a bit harder than the prior but less complicated "LIKE A LOT LESS".  
So, the way I went with it is to use a function to find the smallest number in the STACK A and push it to STACK B.  
We keep doing that untill we have 3 Numbers in STACK A, sort them using the prior algorithm and then pushing back all the numbers back to STACK A.  
Since we have pushed the smallest number repeatedly for the to STACK B, the latter will have all the numbers in it reverse sorted, so by just performing a simple push of all the numbers will sort your STACK A, easily.  
The logic should look something like this 

```c
void	mid_sort(---Your Data---)
{
	int	count; //Keeps in mind the number of elements in STACK A
	int	relay; //Keeps in mind the number of elements pushed in STACK B

	relay = 0;
	count = stack->sizea;
	while (count != 3)
	{
		wiggle_small(---Your Data---); //FCT that takes the smallest element in STACK A and makes it the Head of the STACK A
		push(B);
		count--;
		relay++;
	}
	three_sort(---Your Data---);
	while (relay != 0)
	{
		push(A);
		relay--;
	}
}
```
>ANOTHER DISCLAIMER : This is just a way i found i can do, it was used by other people aswell, but that doesn't mean there aren't other ways to go by this, you might find a better algorithm result wise; if so please don't hesitate to create a pull request and propose other methods

### STACK LENGTH : 16<->500 (chunk_sort)
This is the big one...   
Now not to be concerned; this might be somewhat complicated while reading it the first time; but after you give it your attention; you realise that it's not really that complicated.  
Before we start, i would like to refer you to my peer's [article](https://medium.com/@msouiyeh/not-your-typical-42network-push-swap-cc583f863a90) about the whole project with the chunk method explained in his own words.  
>Now to clarify, this small README is more of a walkthrough to the project and less a general idea of how the project should be handled, the approach that my peer went with; both are important, you can choose which suits you better and go with it.

Here is how it goes :

This sorting method can be summed into two steps :  
- [ ] Pushing from STACK A to STACK B (chunk sort).  
- [ ] Pushing from STACK B to STACK A (actuall sort).  


### STACK A TO STACK B
---
In this part of the logic, you need to sort the elements while pushing them to the other STACK, but this sort will be more based on the chunk level rather than the actual form.  
Now, you might be asking yourself : "WHAT?"  
And that would be a good question...  
To explain this, i'll try to vizualise this a bit.  
Imagine we have a stack of 9 Integers...

> Unsorted array -STACK A- : 2 3 1 5 6 8 7 9 4

After we finish this part of the solve, our STACK B should resemble something like this :

> Expected "Chunk sorted" array -STACK B- : 8 9 7 | 4 6 5 | 3 1 2 |

Notice how STACK B is not actually sorted, but the values in the first third are in their right approximate position, same thing for the second and third chunks of the stack B.  
This is what i meant by "this sort will be more based on the chunk level rather than the actual form". 

I think i clarified this part enough, so for the how to :
	-->




