#ifndef QUEUE_H_
#define QUEUE_H_


/*
 *
 * QUEUE是一个void* 类型的指针数组,主要是存放头尾指针
 * 利用他实现双向循环链表
 *
 */

typedef void *QUEUE[2];

/*
 * 这些宏定义的主要目的是（1）保持类型 (QUEUE*),
 *                    (2)转成左值，因为在QUEUE_INIT里需要用到 
 */

#define QUEUE_NEXT(q)       ((*(q))[0])
#define QUEUE_PREV(q)       ((*(q))[1])
#define QUEUE_PREV_NEXT(q)  (QUEUE_NEXT((QUEUE *) QUEUE_PREV(q)))
#define QUEUE_NEXT_PREV(q)  (QUEUE_PREV((QUEUE *) QUEUE_NEXT(q)))


/* 
 *
 */
#define QUEUE_DATA(ptr, type, field)                                          \
  ((type *) ((char *) (ptr) - ((long) &((type *) 0)->field)))

#define QUEUE_FOREACH(q, h)                                                   \
  for ((q) = (*(h))[0]; (q) != (h); (q) = (*(q))[0])

#define QUEUE_EMPTY(q)                                                        \
  (QUEUE_NEXT(q) == (q))

#define QUEUE_HEAD(q)                                                         \
  (QUEUE_NEXT(q))

#define QUEUE_INIT(q)                                                         \
  do {                                                                        \
    QUEUE_NEXT(q) = (q);                                                      \
    QUEUE_PREV(q) = (q);                                                      \
  }                                                                           \
  while (0)

#define QUEUE_ADD(h, n)                                                       \
  do {                                                                        \
    QUEUE_PREV_NEXT(h) = QUEUE_NEXT(n);                                       \
    QUEUE_NEXT_PREV(n) = QUEUE_PREV(h);                                       \
    QUEUE_PREV(h) = QUEUE_PREV(n);                                            \
    QUEUE_PREV_NEXT(h) = (h);                                                 \
  }                                                                           \
  while (0)

#define QUEUE_SPLIT(h, q, n)                                                  \
  do {                                                                        \
    QUEUE_PREV(n) = QUEUE_PREV(h);                                            \
    QUEUE_PREV_NEXT(n) = (n);                                                 \
    QUEUE_NEXT(n) = (q);                                                      \
    QUEUE_PREV(h) = QUEUE_PREV(q);                                            \
    QUEUE_PREV_NEXT(h) = (h);                                                 \
    QUEUE_PREV(q) = (n);                                                      \
  }                                                                           \
  while (0)

#define QUEUE_INSERT_HEAD(h, q)                                               \
  do {                                                                        \
    QUEUE_NEXT(q) = QUEUE_NEXT(h);                                            \
    QUEUE_PREV(q) = (h);                                                      \
    QUEUE_NEXT_PREV(q) = (q);                                                 \
    QUEUE_NEXT(h) = (q);                                                      \
  }                                                                           \
  while (0)

#define QUEUE_INSERT_TAIL(h, q)                                               \
  do {                                                                        \
    QUEUE_NEXT(q) = (h);                                                      \
    QUEUE_PREV(q) = QUEUE_PREV(h);                                            \
    QUEUE_PREV_NEXT(q) = (q);                                                 \
    QUEUE_PREV(h) = (q);                                                      \
  }                                                                           \
  while (0)

#define QUEUE_REMOVE(q)                                                       \
  do {                                                                        \
    QUEUE_PREV_NEXT(q) = QUEUE_NEXT(q);                                       \
    QUEUE_NEXT_PREV(q) = QUEUE_PREV(q);                                       \
  }                                                                           \
  while (0)

#endif /* QUEUE_H_ */