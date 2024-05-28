# Philosophers
## Rules
- One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively **eat**, **think**, or **sleep**.
- There are also forks on the table. **There are as many forks as philosophers**.
- **There is one fork between each pair of philosophers**. Therefore, if there are **more than 1** philosophers, each philosopher should have a fork on both sides.
- Philosopher uses **2 forks** when eating
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