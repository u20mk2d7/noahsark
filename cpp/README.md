# C++ study guide

This repo holds my C++ course work and practice. It is part of my study plan (see `about.md`) and supports my project, blustone (a low-latency trading engine in C++23).

**When:** Thursday evening, 21:00–22:15.
**Why:** the quant developer / low-latency C++ path, and the HKU application portfolio.

## How to use one Thursday session

1. **50 minutes:** the next lesson in the current step, with the code typed and run myself.
2. **20 minutes:** the step's practice exercise, or a reading chapter.
3. **Last 2 minutes:** tick what you finished and write the next step at the bottom of this file.

## The order

| Step | What | Status |
| --- | --- | --- |
| 0 | Foundations already done | **Done** |
| 1 | Modern C++ Features & Concurrency + *C++ Concurrency in Action* | **Now** |
| 2 | Performance: cache, memory ordering, profiling | Next |
| 3 | Templates and generic code | When needed |

After Step 2, the Thursday slot moves to Python for a while (IBM Python, then Data Analysis), because the statistics courses need it. Step 3 can be done any time blustone needs it.

---

## Step 0: done

- [x] C++ basics series: selection and iteration; vectors, pointers, strings, files; functions, recursion, objects; inheritance and encapsulation
- [x] [Foundations of Modern C++](https://www.coursera.org/learn/packt-foundations-of-modern-cplusplus-djj1v/home/welcome) (Packt, Complete Modern C++ course 1)
- [x] [Object-Oriented Data Structures in C++](https://www.coursera.org/learn/cs-fundamentals-1/home/welcome) (UIUC, Accelerated CS Fundamentals course 1)

Courses 2–3 of the UIUC series are dropped: UCSD Data Structures covers the same ground (see the DSA repo).

---

## Step 1: concurrency

**Course:** [Modern C++ Features & Concurrency](https://www.coursera.org/learn/packt-modern-cplusplus-features-concurrency-djj1a/home/welcome) (Packt, Complete Modern C++ course 3).
**Book:** *C++ Concurrency in Action*, 2nd edition (Anthony Williams). The course stops at C++17; the book goes deeper.

**You learn:** how threads share data safely, what a data race is, how atomics and memory ordering work, and how a lock-free queue is built.

### Checklist

- [ ] Course: modern features (move semantics, lambdas, smart pointers, `std::optional`, `std::variant`)
- [ ] Course: threads, mutexes, condition variables, futures
- [ ] Book: threads and sharing data between threads
- [ ] Book: the C++ memory model and atomic operations — **the most important chapter for blustone**
- [ ] Book: lock-free data structures

### Practice

- [ ] Write a tiny single-producer, single-consumer queue from scratch in a separate folder. Run it under `-fsanitize=thread`. Then compare it with blustone's `SPSCQueue` and explain every `memory_order` in a comment.
- [ ] Break it on purpose: change one `memory_order_release` to `relaxed` and see whether TSan catches it.

**Done when:** I can explain, in English, why the consumer must use `acquire` when the producer uses `release`.

---

## Step 2: performance

**You learn:** why memory layout matters more than clever code, and how to measure instead of guess.

- [ ] Cache lines and false sharing: why blustone keeps head and tail on separate cache lines
- [ ] Memory ordering on x86-64 vs the C++ model: why code can pass tests on x86 and still be wrong
- [ ] `perf stat`, `perf record`, and flame graphs
- [ ] Benchmarks without fooling yourself: warm-up, `-O2`, check the generated assembly

### Practice

- [ ] Write a benchmark with two threads incrementing two counters: once on the same cache line, once 64 bytes apart. Measure the difference with `perf stat`.
- [ ] Measure each stage of the blustone critical path in an optimised build.

**Done when:** I have one flame graph from blustone and can explain its widest bar.

---

## Step 3: templates and generic code (when needed)

**Course:** [Advanced OO & Generic Programming in C++](https://www.coursera.org/learn/packt-advanced-object-oriented-generic-programming-in-cplusplus-dxj1v/home/welcome) (Packt, course 2), **templates sections only**. The object-oriented parts are skipped: blustone avoids `virtual` on the hot path.

- [ ] Function and class templates
- [ ] C++20 concepts (not in the course: use [cppreference](https://en.cppreference.com/w/cpp/language/constraints)) — needed for blustone's `ExchangeConnector` concept

---

## Beyond the courses: C++20 and C++23

The courses stop at C++17. blustone uses C++23. Learn these from [cppreference](https://en.cppreference.com/) when blustone needs them:

- [ ] `std::expected` (C++23): error handling without exceptions
- [ ] `std::span`, concepts, `[[likely]]` (C++20)

## Build flags

Same as blustone, so habits carry over:

```
-std=c++23 -Wall -Wextra -Wpedantic -Werror -Wconversion -Wsign-conversion -Wshadow
```

Debug with `-fsanitize=address,undefined` and, for threaded code, `-fsanitize=thread`.

## Repo layout

```
uiuc-cs-fundamentals/   instructor examples (credit below) + my notes
packt-modern-cpp/       my course exercises
concurrency-practice/   Step 1 practice
perf-practice/          Step 2 practice
```

## Credits and rules

- UIUC example code comes from [wadefagen/coursera](https://github.com/wadefagen/coursera), which accompanies the [Accelerated CS Fundamentals](https://www.coursera.org/specializations/cs-fundamentals) specialization. Check that repo's licence before republishing its code. Extra reference: [CS 225, Fall 2019](https://courses.grainger.illinois.edu/cs225/fa2019/).
- Keep solutions to **graded Coursera assignments private**. Coursera's Honor Code does not allow sharing them.

## Next step

<!-- Write the next concrete step here at the end of each session. -->
