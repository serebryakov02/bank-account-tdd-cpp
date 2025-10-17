# Bank Account TDD (C++)

  A small project for exploring test-driven development in C++: implement a simple bank account API, keep the behaviour covered by tests, and iterate safely.

  ## Build & Test

  ```bash
  cmake -S . -B build
  cmake --build build
  cd build
  ctest            # add -V for verbose output
```

  ## Project Layout

  - include/BankAccount.h – header-only implementation of the banking behaviour
  - tests/BankAccountTests.cpp – GoogleTest suite exercising balances, withdrawals, and formatted output
  - CMakeLists.txt – CMake build script that wires in GoogleTest via FetchContent

