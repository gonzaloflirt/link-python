# Python wrapper for [Ableton Link](http://ableton.github.io/link/)

## License
This depends on [Link](https://github.com/ableton/link) and [pybind11](https://github.com/pybind/pybind11). Please mind the licenses of those libraries and their dependencies.

## Get
```
git clone --recursive https://github.com/hwestphal/link-python.git
```

## Build
Make sure python 3 and [cmake](https://cmake.org/download/) is installed on your system.
```
cmake -S . -B out
cmake --build out
```

## Run example
```
./example/LinkHut.py
```
