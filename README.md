# Simple Circular Buffer for GNU ARM applications

A simple implementation of a ```unsgined char``` circular list. With read and
write operations (bulk write as well).

Uses list end pointers to wrap read/write pointers.

## Usage

There's no *makefile* on the library as it's intent to be used as additional
header of a project.

Add the repository as a submodule of the desired project and add it to include
path.

## Attention

**This library has no handbonning capabilities**.
