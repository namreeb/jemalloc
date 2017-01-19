#ifndef JEMALLOC_INTERNAL_MUTEX_TYPES_H
#define JEMALLOC_INTERNAL_MUTEX_TYPES_H

typedef struct malloc_mutex_s malloc_mutex_t;

#ifdef _WIN32
#define MALLOC_MUTEX_INITIALIZER
#elif (defined(JEMALLOC_OS_UNFAIR_LOCK))
#define MALLOC_MUTEX_INITIALIZER                                               \
    { OS_UNFAIR_LOCK_INIT, WITNESS_INITIALIZER("mutex", WITNESS_RANK_OMIT) }
#elif (defined(JEMALLOC_OSSPIN))
#define MALLOC_MUTEX_INITIALIZER                                               \
    { 0, WITNESS_INITIALIZER("mutex", WITNESS_RANK_OMIT) }
#elif (defined(JEMALLOC_MUTEX_INIT_CB))
#define MALLOC_MUTEX_INITIALIZER                                               \
    {                                                                          \
        PTHREAD_MUTEX_INITIALIZER, NULL,                                       \
            WITNESS_INITIALIZER("mutex", WITNESS_RANK_OMIT)                    \
    }
#else
#if (defined(JEMALLOC_HAVE_PTHREAD_MUTEX_ADAPTIVE_NP) &&                       \
     defined(PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP))
#define MALLOC_MUTEX_TYPE PTHREAD_MUTEX_ADAPTIVE_NP
#define MALLOC_MUTEX_INITIALIZER                                               \
    {                                                                          \
        PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP,                                 \
            WITNESS_INITIALIZER("mutex", WITNESS_RANK_OMIT)                    \
    }
#else
#define MALLOC_MUTEX_TYPE PTHREAD_MUTEX_DEFAULT
#define MALLOC_MUTEX_INITIALIZER                                               \
    {                                                                          \
        PTHREAD_MUTEX_INITIALIZER,                                             \
            WITNESS_INITIALIZER("mutex", WITNESS_RANK_OMIT)                    \
    }
#endif
#endif

#endif /* JEMALLOC_INTERNAL_MUTEX_TYPES_H */
