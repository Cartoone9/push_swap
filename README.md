<div align="center">
  <img src="https://i.ibb.co/cmF80PB/image.png" alt="Project score">
</div>

# push_swap

 This is my push_swap project, a challenging algorithm assignment from 42 School. The core objective was to sort a stack of integers using a limited set of operations, manipulating only two stacks (A and B). This project served as an introduction to sorting algorithms, data structures, and optimization techniques, with the goal of finding the most efficient sorting solution using the fewest operations possible. 

## Table of Contents

- [About](#push_swap)
- [Usage](#usage)
- [Examples](#examples)
- [Visualizer](#visualizer)
- [Note on Project State](#note-on-project-state)
- [Known Issues & Fix Suggestions](#known-issues--fix-suggestions)
- [License](#license)

## Usage

To compile the program, navigate to the project root and run:
```bash
make
```

Then you can use the program like this:
```bash
./push_swap 2 1 3 6 5 8
# or
./push_swap "2 1 3 6 5 8"
# or
./push_swap "2 1 3" 6 5 "8"
```

To compile the bonus (checker), navigate to the project root and run:
```bash
make bonus
```

Then you can check the program output like this:
```bash
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
# or
ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
```

## Examples

Without the checker:  
![Push_swap example](https://i.ibb.co/Kp8PrghR/image.png)  
  
With the checker:  
![Push_swap and checker example](https://i.ibb.co/bjqX2nSg/image.png)  

## Performances

In order to get the highest grade you had to be under those thresholds:  
```markdown
- 3 numbers: 2 instructions
- 5 numbers: 12 instructions
- 100 numbers: 700 instructions
- 500 numbers: 5500 instructions
```

To test my program I used the project `complexity` made by [SimonCROS](https://github.com/SimonCROS/push_swap_tester), which gives me these results:  

**✅ For 3 random numbers:**
```bash
3 elements, 1000 iterations (seed 1007942458)

Worst = 2 instructions
Median = 1 instructions
Best = 0 instructions
Std. deviation = 0.7 instructions
Objective = 100 % under 2 (0 above)   
Precision = 100 % OK (0 KO)   
100 % effective
```

**✅ For 5 random numbers:**
```bash
5 elements, 1000 iterations (seed 1003452724)

Worst = 11 instructions
Median = 8 instructions
Best = 0 instructions
Std. deviation = 1.5 instructions
Objective = 100 % under 12 (0 above)   
Precision = 100 % OK (0 KO)   
100 % effective
```

**✅ For 100 random numbers:**
```bash
100 elements, 1000 iterations (seed 2765038762)

Worst = 656 instructions
Median = 589 instructions
Best = 508 instructions
Std. deviation = 24.4 instructions
Objective = 100 % under 700 (0 above)   
Precision = 100 % OK (0 KO)   
100 % effective
```

**✅ For 500 random numbers:**
```bash
500 elements, 1000 iterations (seed 2321868039)

Worst = 5078 instructions
Median = 4735 instructions
Best = 4295 instructions
Std. deviation = 131.0 instructions
Objective = 100 % under 5500 (0 above)   
Precision = 100 % OK (0 KO)   
100 % effective
```

## Visualizer

To better visualize the program's behavior, I used the `push_swap_visualizer` project made by [o-reo](https://github.com/o-reo/push_swap_visualizer):  

- For 100 random numbers:  
![Visualizer for 100 values](https://i.ibb.co/whg7VTjh/push-swap-1-clean.gif)  

- For 500 random numbers:  
![Visualizer for 500 values](https://i.ibb.co/r2x7zvNC/push-swap-2.gif)   

## Note on Project State

All projects from my 42 cursus are preserved in their state immediately following their final evaluation. While they may contain mistakes or stylistic errors, I've chosen not to alter them. This approach provides a clear and authentic timeline of my progress and learning journey as a programmer.

## Known Issues & Fix Suggestions

```bash
./push_swap 2147483649
```

If you try to use the program with a single value, and that value is above the maximum of an int (or under the minimum) it will return no error message, and just end the execution.  

The problem stems from the main function, where the program will return if there's only a single value that is passed as argument.  

In order to fix that behavior, you could do something like this:
```diff
int	main(int ac, char **av)
{
	char	**numbers;
	t_list	*list_a;
	size_t	la_size;

	if (ac >= 2)
	{
		numbers = ft_split_ncheck(av);
		if (!numbers)
			return (write(2, "Error\n", 6), 1);

-		if (ft_numbers_size(numbers) <= 1)
-			return (ft_free_strr(numbers), 0);

+		number_len = ft_numbers_size(numbers);
+		if (number_len <= 1)
+		{
+			if (number_len == 1)
+			{
+				if (ft_check_single_value(numbers[0]))
+					write(2, "push_swap: invalid arg\n", 23);
+			}
+			return (ft_free_strr(numbers), 0);

...
```

With a new function `ft_check_single_value()` to check if the given value is in the range of an int:
```C
int ft_check_single_value(const char *str)
{
	long long   num;
	int         sign;
	int         i;

	if (!str || !*str)
		return (1);
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (1);
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > 2147483647)
			|| (sign == -1 && -num < -2147483648))
			return (1);
		i++;
	}
	return (0);
}
```

`ft_fill_stash()` in my get_next_line implementation contains an unprotected `malloc()` that could cause issues in edge cases.

## License

[MIT](https://choosealicense.com/licenses/mit/)  
