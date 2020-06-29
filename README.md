# Just messing around

Notes:
* Everything in the Python header (`Python.h`) starts with the prefix `Py` of `PY`.
* The `PyObject` type is always used as a pointer to handle all the data parsing between `Python` and `C`.
* If the `C` function returns nothing, return the `Py_None` value which is equivalent to the `None` value in `Python`.
* Build the moudule using: `python setup.py build`
* Copy the built file (module.so) from `build/lib*/` folder to where you want to keep it, like other `Python` scripts (script.py).

