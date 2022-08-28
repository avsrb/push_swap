[![ALT-Sorting 500 elements](http://img.youtube.com/vi/oUbuTOryf5o/0.jpg)](http://www.youtube.com/watch?v=oUbuTOryf5o)

## Installation:

```
git clone --recurse-submodules https://github.com/rizkyario/42-push_swap.git; cd 42-push_swap; make
```

## Usage:
```
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -vcat $ARG
