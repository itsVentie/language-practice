# Go — Language Overview & Notes

## About the Language
- **Type:** Compiled, Statically Typed, Concurrent, Garbage-Collected.
- **Core Strengths:** Exceptional concurrency model, lightning-fast compilation, simple language specification, static single-binary outputs.
- **Primary Use Cases:** Cloud-native infrastructure (Docker, K8s), microservices, high-throughput network proxies, security tools, eBPF agents.

---

## Key Features & Mechanics
- **Concurrency Model:** CSP-based concurrency using lightweight Goroutines managed by an M:N user-space scheduler (GMP model) and channels.
- **Runtime:** Low-pause concurrent tri-color mark-sweep garbage collector optimized for low latency over throughput.
- **Low-Level Access:** Unsafe pointer manipulation (`unsafe.Pointer`), direct syscalls, and seamless integration with C/eBPF.

---

## Repositories & Projects
| Project | Type | Description |
| :--- | :--- | :--- |
| `Latch` | Security / Network | Post-quantum proxy tunneling (X25519 & ML-KEM-768) |
| `Nearcloud` | Network / P2P | Local-first P2P file sharing platform |
| `ebpf-llm-firewall` | Security | Telemetry firewall proxy using eBPF |
| `MarsGo` | Library | Marseille Chess rule engine |
