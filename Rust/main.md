# Rust — Language Overview & Notes

## About the Language
- **Type:** Compiled, Systems Programming, Statically Typed.
- **Core Strengths:** Memory safety without a garbage collector, thread safety, high performance, rich type system with algebraic types.
- **Primary Use Cases:** Operating systems, cryptosystems, embedded devices (`no_std`), security tooling, low-latency networking, desktop apps (Tauri).

---

## Key Features & Mechanics
- **Ownership Model:** Memory safety enforced at compile time through strict rules of Ownership, Borrowing, and Lifetimes.
- **Zero-Cost Abstractions:** High-level language constructs (iterators, generics, traits) compile down to efficient machine code.
- **Explicit Safety Boundaries:** Strict separation between standard Safe Rust and `unsafe` blocks for low-level memory manipulation, bare-metal operations, and FFI.

---

## Repositories & Projects
| Project | Type | Description |
| :--- | :--- | :--- |
| `larp-ops` | CLI Tool | Red Team & DFIR workflow orchestrator |
| `Saccade` | Desktop App | Real-time video manipulation & face swapping (Tauri v2) |
| `PassClip` | Security Daemon | RAM-isolated clipboard manager (XChaCha20, Passkey) |
| `Marrow` | Messenger | Post-quantum resilient messenger (ML-KEM-768, QUIC) |
| `Gigafold` | Storage | Encrypted virtual drive mounting via FUSE |
| `Pneuma` | Embedded | Environmental monitor (`no_std`, ESP32-C6) |
| `nano-guard` | Engine | Ultra-low latency LLM guardrail engine |
| `probetop` | TUI / Monitoring | Process monitor and eBPF telemetry inspector |
| `JarTight` | Security Daemon | Cookie and database isolation daemon against infostealers |
