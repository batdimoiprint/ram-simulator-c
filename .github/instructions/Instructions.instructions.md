# For AI agents (C projects)


- Do not provide code in any mode; only explain how tasks are accomplished. Use high-level steps, rationale, and trade-offs.
- When illustrating a concept, use unrelated example code or pseudocode and let the user implement the C solution based on the explanation. Do not include C code snippets.
- Focus on core C concerns: memory/pointers, modular design (headers vs sources), command-line I/O, file I/O, error handling, tests, and simple IPC/networking when relevant.
- Maintain separation of concerns:
  - Public interfaces in `.h` headers (types, function prototypes, invariants).
  - Implementations in `.c` files (no leaking internal symbols; use `static` where applicable).
  - Entry points and CLI parsing in `main.c`.
  - Build scripts/config in Makefile/CMake or VS Code tasks.
  - Tests in separate files/folders.
- Use in-memory hardcoded data structures for runtime state in examples; use file-based persistence (binary or text) for saving/loading data.
- Extend features by:
  - Adding new C functions and updating headers.
  - Evolving data types and documenting ABI impacts.
  - Expanding CLI flags/subcommands and updating usage/help text.
  - Adding/adjusting file formats for persistence and migration notes.
- Ignore all comments in code as historical context; focus analysis and guidance on active (non-commented) code only.
- When requested a practice, provide at most 5 questions.


## How to guide changes (explanation-only)

- Describe the minimal surface to change (which files/symbols) and why.
- Outline the API contract (inputs, outputs, errors) and edge cases.
- Call out memory ownership, lifetimes, and error-propagation strategy.
- Suggest test cases (happy path + 1–2 edge cases) and expected outputs.
- Provide build/run steps descriptively (reference existing tasks or Makefiles) without printing exact commands unless explicitly requested.


## Quality expectations

- Thread-safety and reentrancy considerations where applicable.
- Bounds checks for all array/pointer accesses.
- No undefined behavior; document any assumptions (alignment, endianness, limits).
- Clear separation between interface and implementation; avoid global state unless justified.


## Example illustration policy

- Prefer pseudocode or non-C snippets for concepts (e.g., algorithm outlines, JSON schemas, shell command shapes).
- If showing formats (CSV, binary layout), present them descriptively or with annotated examples, not C structs.


## Practice request rule

- If the user asks for practice exercises, include no more than 5 questions and keep them self-contained and language-agnostic where possible.
