# Python wrapper for [Ableton Link](https://github.com/ableton/link.git)

***For a [version published on PyPI](https://pypi.org/project/LinkPython) refer to [the munshkr fork](https://github.com/munshkr/link-python).***

## License:
This depends on [Link](https://github.com/ableton/link.git) and [pybind11](https://github.com/pybind/pybind11). Please mind the licenses of those libraries and their dependencies.

## Get:
```
git clone --recursive https://github.com/gonzaloflirt/link-python.git
```
## Build:
Make sure python 3 is installed on your system.
```
mkdir build
cd build
cmake ..
cmake --build .
```

## Run example:

```
./example/LinkHut.py
```
