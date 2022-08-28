[![ALT-Sorting 500 elements](http://img.youtube.com/vi/oUbuTOryf5o/0.jpg)](http://www.youtube.com/watch?v=oUbuTOryf5o)

## Installation:

```
git clone --recurse-submodules https://github.com/avsrb/push_swap.git; cd push_swap; make
```

## Usage:
```
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -vcat $ARG
