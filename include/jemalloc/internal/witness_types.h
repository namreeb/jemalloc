#ifndef JEMALLOC_INTERNAL_WITNESS_TYPES_H
#define JEMALLOC_INTERNAL_WITNESS_TYPES_H

typedef struct witness_s witness_t;
typedef unsigned witness_rank_t;
typedef ql_head(witness_t) witness_list_t;
typedef int witness_comp_t(const witness_t *, void *, const witness_t *,
                           void *);

/*
 * Lock ranks.  Witnesses with rank WITNESS_RANK_OMIT are completely ignored by
 * the witness machinery.
 */
#define WITNESS_RANK_OMIT 0U

#define WITNESS_RANK_INIT 1U
#define WITNESS_RANK_CTL 1U
#define WITNESS_RANK_ARENAS 2U

#define WITNESS_RANK_PROF_DUMP 3U
#define WITNESS_RANK_PROF_BT2GCTX 4U
#define WITNESS_RANK_PROF_TDATAS 5U
#define WITNESS_RANK_PROF_TDATA 6U
#define WITNESS_RANK_PROF_GCTX 7U

#define WITNESS_RANK_ARENA 8U
#define WITNESS_RANK_ARENA_EXTENTS 9U
#define WITNESS_RANK_ARENA_EXTENT_CACHE 10

#define WITNESS_RANK_RTREE_ELM 11U
#define WITNESS_RANK_RTREE 12U
#define WITNESS_RANK_BASE 13U

#define WITNESS_RANK_LEAF 0xffffffffU
#define WITNESS_RANK_ARENA_BIN WITNESS_RANK_LEAF
#define WITNESS_RANK_ARENA_LARGE WITNESS_RANK_LEAF
#define WITNESS_RANK_DSS WITNESS_RANK_LEAF
#define WITNESS_RANK_PROF_ACTIVE WITNESS_RANK_LEAF
#define WITNESS_RANK_PROF_DUMP_SEQ WITNESS_RANK_LEAF
#define WITNESS_RANK_PROF_GDUMP WITNESS_RANK_LEAF
#define WITNESS_RANK_PROF_NEXT_THR_UID WITNESS_RANK_LEAF
#define WITNESS_RANK_PROF_THREAD_ACTIVE_INIT WITNESS_RANK_LEAF

#define WITNESS_INITIALIZER(name, rank)                                        \
    {                                                                          \
        name, rank, NULL, NULL, {                                              \
            NULL, NULL                                                         \
        }                                                                      \
    }

#endif /* JEMALLOC_INTERNAL_WITNESS_TYPES_H */
