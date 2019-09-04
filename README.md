# cxx-calc-pi

```sh
# If gmp is installed in system
clang++ -std=c++11 -Wall main.cc -lgmpxx -lgmp
# Otherwise
./prepare_deps.sh
clang++ -std=c++11 -Wall -Itmp-deps/install/include -Ltmp-deps/install/lib main.cc -lgmpxx -lgmp
```
