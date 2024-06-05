# Sandbox
## Simulate odd number of philosophers
number_of_philosophers = 5

philosopher 1, 3 eat\
philosopher 2, 4 eat\
philosopher 3, 5 eat\
philosopher 4, 1 eat\
philosopher 5, 2 eat

--------------------------------------------------------------------------------

number_of_philosophers = 7

philosopher 1, 3, 5 eat\
philosopher 2, 4, 6 eat\
philosopher 3, 5, 7 eat\
philosopher 4, 6, 1 eat\
philosopher 5, 7, 2 eat\
philosopher 6, 1, 3 eat\
philosopher 7, 2, 4 eat

## Simulate different activity durations
time_to_die		=	3\
time_to_eat		= 	3\
time_to_sleep	=	3

time_to_die		= 	3\
time_to_eat		= 	2\
time_to_sleep	=	1

time_to_die		= 	1\
time_to_eat		= 	2\
time_to_sleep 	=	3

time_to_die		= 	1\
time_to_eat		= 	3\
time_to_sleep	=	2

time_to_die		= 	2\
time_to_eat		= 	3\
time_to_sleep	=	1

## Fork addressess
fork[1]: e0
fork[2]: e4
fork[3]: e8
fork[4]: ec
fork[5]: f0

## Modified 'id'
0: 0x7fc89cc058f0
1: 0x7fc89cc058f0
2: 0x7fc89cc05918
3: 0x7fc89cc05940
4: 0x7fc89cc05968
5: 0x7fc89cc05990
