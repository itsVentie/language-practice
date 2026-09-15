# C# — Language Overview & Notes

## 📌 About the Language
- **Type:** Object-Oriented, Multi-paradigm, Garbage-Collected (CLR).
- **Core Strengths:** High productivity, powerful async model (`async/await`), rich enterprise ecosystem, modern high-performance primitives (`Span<T>`).
- **Primary Use Cases:** Enterprise backend systems, desktop software (WPF/WinForms/MAUI), game development (Unity), high-performance web APIs (.NET Core).

---

## 🏗 Key Features & Mechanics
- **Virtual Machine:** Executes Managed Intermediate Language (CIL) via the Common Language Runtime (CLR) with JIT/AOT compilation.
- **Memory Management:** Automated Generational GC (Gen 0, 1, 2, LOH, POH) with manual bypass options via `stackalloc`, `Span<T>`, and `unsafe` blocks.
- **System Access:** Direct Win32 API access through P/Invoke and NativeAOT for building standalone binaries.

---

## 📂 Repositories & Projects
| Project | Type | Description |
| :--- | :--- | :--- |
| `Morrow-institute` | Game | based on UNITY |
