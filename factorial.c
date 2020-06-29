#include <Python.h>

int Cfact(int n) {
    if (n < 0)
        return -1;
    if (n <=1)
        return 1;
    
    return n * Cfact(n-1);
}


// Wrapper function(binds Python objects to C functions) to be 
// called from Python and returns the factorial value
// of the given number by calling the actual function: Cfact()

// The fact function recieves and returns one PyObject pointer
static PyObject* fact(PyObject* self, PyObject* args) {
    int n;
    
    // Parse variables from Python to C 
    // i.e. handles getting the arguments from Python
    // "i" stands for integer
    if (!PyArg_ParseTuple(args, "i", &n)) 
        return NULL;

    // Parse result from C to Python
    // i.e. handles turning values into PyObject pointers
    // Here the factorial value of n
    return Py_BuildValue("i", Cfact(n));
}


// Wrappert function to be called from Python and returns the version number
static PyObject* version(PyObject* self) {
    // Parse the version string from C to Python
    // "s" stands for string
    return Py_BuildValue("s", "version 0.1");
}


// Method definition
// PyMethodDef contains the binding information to be used by the
// PyModuleDef structure and must always end with NULL entry to
// let the init function know that that's the end of the method
// list to be bound
// Pattern: {pyMethodName, function, functionType, docstring}
static PyMethodDef factMethods[] = {
    {"fact", fact, METH_VARARGS, "Calculate factorials"},
    {"version", (PyCFunction)version, METH_NOARGS, "Returns the version"},
    {NULL, NULL, 0, NULL}
};


// Module definition
// PyModuleDef structure is used to tell the PyModule_Create()
// function what information is to be used to build the module
// Pattern: {Head of the def, module name, module docstring,
// the size of the pre-interpreter state (-1 means global state),
// method def structure}
static struct PyModuleDef factorial = {
    PyModuleDef_HEAD_INIT,
    "factorial",
    "C library to calculate factorial of a given number",
    -1,
    factMethods
};


// Initializer function
PyMODINIT_FUNC PyInit_factorial(void) {

    // Initializes the modules and wraps the method pointers
    return PyModule_Create(&factorial);
}

