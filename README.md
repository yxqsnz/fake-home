# FAKE HOME
WARNING: This may not work outside of GLibc based programs

A Simple program to fake user home

## WHY?
Salwyyr client has filling up my home with random files, so, I've created this.


## HOW TO USE?

### Configure and generate a shared library

```sh
./genconfig.sh <NEW USER HOME>
make
cp fake.so ~/myGamingFakeHome.so
```

### And use
```sh
LD_PRELOAD=$(realpath ~/myGamingFakeHome.so) <my app>
```
## Requirements
- GCC
- Make



