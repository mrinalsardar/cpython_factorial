from distutils.core import setup, Extension

module = Extension("factorial", sources=["factorial.c"])

setup(
    name="cfact",
    version="0.1",
    description="Factorial calculator in C",
    ext_modules=[module]
)


