# Zig — Language Overview & Notes

## About the Language
- **Type:** Compiled, Imperative, Systems Programming.
- **Core Strengths:** Extreme simplicity, no hidden control flow, explicit memory allocation, seamless C replacement and drop-in compiler.
- **Primary Use Cases:** Systems utilities, game development, OS kernels, embedded development, cross-compiling C/C++ projects.

---

## Key Features & Mechanics
- **Explicit Memory:** No hidden allocations; functions requiring memory explicitly accept an `Allocator` parameter.
- **Comptime:** Replaces preprocessors and macros with compile-time code execution using standard Zig syntax.
- **Zero Overhead:** No Garbage Collector, no hidden control flow (no operator overloading, no exceptions), complete transparency in execution.

---

## Repositories & Projects
| Project | Type | Description |
| :--- | :--- | :--- |
| `codecrafters-shell` | CLI / Systems | POSIX-compliant shell implementation (Zig 0.14+) |
