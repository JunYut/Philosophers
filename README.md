# Philosophers
## Rules
- One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.

  Since this is a round table, the `first` philosopher will be on the left of the `last` philosopher (assuming they are seated in `clockwise` fashion)
- The philosophers alternatively **eat**, **think**, or **sleep**.
- There are also forks on the table. **There are as many forks as philosophers**.
- **There is one fork between each pair of philosophers**.

  Therefore, if there are **more than 1** philosophers, each philosopher should have a fork on both sides.
- Philosopher uses **2 forks** when eating.

  In other words, **there will not be enough forks for all philosophers**
- When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.

## Variables
1. `number_of_philosophers`
2. `time_to_die`
3. `time_to_eat`
4. `time_to_sleep`
5. `number_of_times_each_philosopher_must_eat`

## Logs
Any state change of a philosopher must be formatted as follows:
- `timestamp_in_ms` `X` has taken a fork
- `timestamp_in_ms` `X` is eating
- `timestamp_in_ms` `X` is sleeping
- `timestamp_in_ms` `X` is thinking
- `timestamp_in_ms` `X` died

Replace `timestamp_in_ms` with the current timestamp in milliseconds
and `X` with the philosopher number.
- A displayed state message should not be mixed up with another message.
- A message announcing a philosopher died should be displayed no more than **10 ms**
after the actual death of the philosopher.

## Analysis
1. `eat` requires `2` forks.
2. Each philosopher is given `1` fork.
3. Assuming the fork is on their `right`, they have to `borrow` another fork from the `left`.\

	Which means the philosopher on the `left` wouldnt able to `eat` since they don't have enough forks (even they borrow from the left).

	**Example:** if `philosopher_1` is `eating`, `philosopher_2` cannot `eat`, but `philosopher_3` can `eat`.

4. Only `half` of the philosophers can eat at the same time.
5. `Philosopher n + 2i can eat at the same time` (let i range from 0 to half of  number_of_philosophers).
6. For `even number` of philosophers, the eating cycle will look like this:
   ```
   philosopher 1, 3, 5, ... eats
   philosopher 2, 4, 6, ... eats
   ```

7. Things are a bit different when there are `odd number` of philosophers.

	Let say there are `5` philosophers, while philosopher `1` & `3` are `eating`,
	`philosopher_5` needs to wait (think or sleep).

	This is because `philosopher_5` sit nexts to `philosopher_1`.

8. This is the eating cycle for `odd number` of philosophers:
   ```
   philosopher 1, 3, 5, ..., n - 2 eats
   philosopher 2, 4, 6, ..., n - 1 eats
   philosopher 3, 5, 7, ..., n     eats
   philosopher 4, 6, 8, ..., 1     eats
   philosopher 5, 7, 9, ..., 2     eats
   ...
   philosopher n, 2, 4, ..., n - 3 eats
   ```

9. Routines of the philosophers:
    ```
	1. eat -> sleep -> think
	2. think -> eat -> sleep
	3. sleep -> think -> eat
	```

## Pseudocode
1. Input validation
   - `argc` must be `4` or `5`
   - all arguments should be in `integer` format
   - `number_of_philosophers` should be at least `1`
2. Initialize components
	- a struct that holds the state of the `philosophers` and the availability of `forks`
	- a struct that represents the environment
3. Start simulation