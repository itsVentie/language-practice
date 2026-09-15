# Polyglot Systems & Language Practice (`language-practice`)

A centralized monorepo dedicated to mastering low-level mechanics, systems programming, and high-performance computing across multiple languages. This workspace serves as a hands-on playground for benchmarking, testing language-specific edge cases, and tracking daily technical insights.

## Repository Structure

```text
language-practice/
├── C#/             # CLR internals, P/Invoke, NativeAOT, and memory optimization
├── C++/            # Modern C++ (20/23), WinAPI/NTAPI, and systems security
├── Golang/         # Concurrency, eBPF telemetry, network proxies, and runtime internals
├── Julia/          # Scientific computing, SciML (PINNs), and stochastic simulations
├── Python/         # CPython internals, AST mutation, and PyO3 native bindings
├── Rust/           # Systems design, PQC, embedded (no_std), and memory safety
├── Zig/            # Comptime metaprogramming, explicit allocation, and POSIX tooling
└── shared/         # Cross-language algorithms, cryptography, and low-level notes

```

---

## Objectives & Focus Areas

* **Low-Level Mechanics:** Memory alignment, stack vs heap allocation, cache efficiency, and execution runtimes (CLR, CPython, GMP, LLVM).
* **Security Engineering & Systems:** eBPF telemetry, native interop (FFI/P/Invoke), Win32/POSIX API manipulation, and bare-metal (`no_std`) paradigms.
* **Applied Cryptography:** Post-quantum algorithms (ML-KEM, ML-DSA), RAM isolation mechanics, and zero-knowledge proxy structures.
* **High-Performance Computing:** Lock-free primitives, SIMD vectorization, and neural differential equation solvers.

---

## Directory Layout Conventions

Each language directory follows a standardized layout:

* `main.md` — Language overview, architectural characteristics, and daily execution logs.
* `01_basics/` — Core syntax, environment bootstraps, and primitive types.
* `02_advanced/` — Advanced language patterns, memory hacks, and low-level experiments.
