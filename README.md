1. `pthread_create()`: the order in which threads are created does not guarantee the order in which they will be scheduled or run.

2. `pthread_join()`: is used to make the calling thread wait for the termination of another thread. However it does not provide any guarantees about the order in which the threads are scheduled or run.
```
	pthread_create(&thread1, NULL, func1, &data);
	pthread_create(&thread2, NULL, func2, &data);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
```
This will cause data race.
```
pthread_create(&thread1, NULL, func1, &data);
pthread_join(thread1, NULL);
pthread_create(&thread2, NULL, func2, &data);
pthread_join(thread2, NULL);
```
This will not cause data race.

The call sequence matters.

3. How `mutexes` work:
   - before calling `pthread_mutex_lock`, initialize `1` mutex
   - calling `pthread_mutex_lock` will attempt to set `lock flag` of the mutex to a `non-zero` value to indicate the lock is in use by a thread.
   - if `lock flag` is already `non-zero`, `pthread_mutex_lock` will halt the thread until `lock flag` is set to `0`
   - to see the effect of a mutex, there must be at least `2` calls to `pthread_mutex_lock` from different threads